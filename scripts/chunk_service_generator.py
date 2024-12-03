from doc_template import textHeader
from tools import find_in_folders, extract_archetype_id

# Constants and paths
INCLUDE_PATH = "../../../include/upgine"
HEADER_OUTPUT_PATH = "../../../include/upgine/auto_generate/chunk_service.h"
SOURCE_OUTPUT_PATH = "../../../src/upgine/auto_generate/chunk_service.cpp"
ARCHETYPE_PATTERN = "CREATE_ARCHETYPE"
ISYSTEM_PATTERN = " : public ISystem"

def main():
    print("--------------------------------------")
    print("-- Checking Archetypes Dependencies --")
    print("--------------------------------------")

    # 1. Retrieve archetype lines
    lines_with_archetype = find_in_folders(INCLUDE_PATH, ARCHETYPE_PATTERN)
    # Filter out lines containing "#define"
    lines_with_archetype = [s for s in lines_with_archetype if "#define" not in s]

    # 2. Retrieve system lines and extract system names
    lines_with_system = find_in_folders(INCLUDE_PATH, ISYSTEM_PATTERN)
    system_to_be_added = [
        each.split(" : public ISystem")[0].split("class ")[-1] for each in lines_with_system
    ]

    # 3. Extract archetype IDs and detect duplicates
    archetypes_id = extract_archetype_id(INCLUDE_PATH)
    unique_archetypes, duplicate_archetypes = detect_duplicate_archetypes(archetypes_id)

    # If there are duplicates, raise an error
    if duplicate_archetypes:
        print("\033[91mERROR\033[0m")
        print("Duplicate Archetypes found:")
        print(duplicate_archetypes)
        print("Please remove the duplicates and try again")
        print("Step 1/2: Error in Archetypes Generator")
        raise ValueError("\033[91mSome archetypes are duplicate, use one of the already created\033[0m")

    # Use only unique archetypes
    archetypes_id = unique_archetypes

    # 4. Construct used archetypes and chunks
    used_archetypes = [
        "Upgine::ECS::Archetypes::" + each.split("(")[1].split(",")[0]
        for each in lines_with_archetype
    ]

    used_chunks = [
        "Chunks<Chunk<Archetypes::" + each.split("(")[1].split(",")[0] + ">>"
        for each in lines_with_archetype
    ]

    # 5. Print info
    print(f"-- Found a number of {len(used_archetypes)} Archetypes")
    print(f"-- Found a number of {len(used_chunks)} Chunks")
    print(f"-- Archetypes names: {used_archetypes}")
    print("--------------------------------------\n")

    # 6. Generate header and source files
    generate_header_file(used_archetypes, used_chunks)
    generate_source_file(used_archetypes, used_chunks, archetypes_id, system_to_be_added)

    print("Archetypes Generator finished")
    print("Step 1/2: Archetypes Generator finished\n")

def detect_duplicate_archetypes(archetypes_id):
    """
    Detect duplicate archetypes based on their IDs.
    Returns a tuple (unique_archetypes, duplicate_archetypes).
    """
    unique_archetypes = []
    duplicate_archetypes = []
    seen_archetypes = set()

    for elem in archetypes_id:
        archetype_tuple = tuple(elem[1])
        if archetype_tuple in seen_archetypes:
            duplicate_archetypes.append(elem)
        else:
            unique_archetypes.append(elem)
            seen_archetypes.add(archetype_tuple)

    return unique_archetypes, duplicate_archetypes

def generate_header_file(used_archetypes, used_chunks):
    """
    Generate the content for chunk_service.h file.
    """
    header_data = textHeader[:]

    header_data.extend([
        "//This file is generated automatically by archetypes_generator.py\n\n",
        "#ifndef INCLUDE_UPGINE_AUTO_GENERATE_CHUNK_SERVICE_H_\n",
        "#define INCLUDE_UPGINE_AUTO_GENERATE_CHUNK_SERVICE_H_\n\n",
        "#include \"upgine/core/services/service_interface.h\"\n",
        "#include \"upgine/memory/smart_pointer/reference.h\"\n\n",
        "#include \"upgine/core/types/basic_types.h\"\n\n",
        "#include \"upgine/ecs/memory/memory_chunks.h\"\n\n",
        "namespace Upgine::ECS::DTO { class ComponentDTO; }\n\n",
        "namespace Upgine::Core::Services{\n",
        "  class ChunkService : public IService, public Upgine::Memory::SmartPointer::Reference {\n",
        "   public:\n",
        "    ChunkService();\n",
        "    ~ChunkService() override;\n\n",
        "    void Init() override;\n",
        "    void Update() override;\n",
        "    void Shutdown() override;\n\n",
        "    template<typename T>\n",
        "    T* Get(uint32 chunkId, uint32 slotId);\n\n",
        "    template<typename T>\n",
        "    T* Get(uint32 chunkId);\n\n",
        "    template<typename T>\n",
        "    Upgine::ECS::Entities::Entity Add();\n\n",
        "    template<typename T>\n",
        "    bool Remove(uint32 chunkId, uint32 slotId);\n\n",
        "    template<typename T>\n",
        "    uint32 UsedChunks();\n\n",
        "    template<typename T>\n",
        "    std::vector<Upgine::ECS::DTO::ComponentDTO> GetComponents();\n\n",
        "  private:\n",
        "    struct Data;\n",
        "    Data * data_;\n",
        "  };\n",
        "}\n",
        "#endif // INCLUDE_UPGINE_AUTO_GENERATE_CHUNK_SERVICE_H_\n"
    ])

    with open(HEADER_OUTPUT_PATH, "w") as header_file:
        header_file.writelines(header_data)

def generate_source_file(used_archetypes, used_chunks, archetypes_id, system_to_be_added):
    """
    Generate the content for chunk_service.cpp file.
    It includes logic to handle archetypes and components for the ChunkService class.
    """
    source_data = [
        "//This file is generated automatically by archetypes_generator.py\n\n",
        "#include \"upgine/auto_generate/chunk_service.h\"\n",
        "#include \"upgine/ecs/memory/memory_chunks.h\"\n",
        "#include \"upgine/ecs/dto/component_dto.h\"\n",
        "#include \"upgine/ecs/archetypes/archetypes_declaration.h\"\n\n",
        "using namespace Upgine::ECS;\n",
        "using namespace Upgine::ECS::Memory;\n\n",
        "struct Upgine::Core::Services::ChunkService::Data {\n"
    ]

    # Add chunk declarations
    source_data.extend([
        f"  {chunk} {chunk.split('::')[-1].split('>')[0]};\n"
        for chunk in used_chunks
    ])

    source_data.extend([
        "};\n\n",
        "Upgine::Core::Services::ChunkService::ChunkService() {\n",
        "  data_ = new Data();\n",
        "}\n\n",
        "Upgine::Core::Services::ChunkService::~ChunkService() {\n",
        "  delete data_;\n",
        "}\n\n",
        "void Upgine::Core::Services::ChunkService::Init() {\n",
        "}\n\n",
        "void Upgine::Core::Services::ChunkService::Update() {\n",
        "}\n\n",
        "void Upgine::Core::Services::ChunkService::Shutdown() {\n",
        "}\n\n"
    ])

    # Generate template specializations for Get<ArchetypeName>(chunkId, slotId)
    for chunk in used_chunks:
        archetype_name = chunk.split("::")[-1].split(">")[0]
        source_data.extend([
            f"template<> Archetypes::{archetype_name} *Upgine::Core::Services::ChunkService::Get<Archetypes::{archetype_name}>(uint32 chunkId, uint32 slotId) {{\n",
            f"  return data_->{archetype_name}.Get<Upgine::ECS::Archetypes::{archetype_name}>(chunkId, slotId);\n",
            "}\n\n"
        ])

    # Generate template specializations for Add<ArchetypeName>()
    for chunk in used_chunks:
        archetype_name = chunk.split("::")[-1].split(">")[0]
        source_data.extend([
            f"template<> Upgine::ECS::Entities::Entity Upgine::Core::Services::ChunkService::Add<Archetypes::{archetype_name}>() {{\n",
            f"  return data_->{archetype_name}.Add<Upgine::ECS::Archetypes::{archetype_name}>();\n",
            "}\n\n"
        ])

    # Generate template specializations for Remove<ArchetypeName>(chunkId, slotId)
    for chunk in used_chunks:
        archetype_name = chunk.split("::")[-1].split(">")[0]
        source_data.extend([
            f"template<> bool Upgine::Core::Services::ChunkService::Remove<Archetypes::{archetype_name}>(uint32 chunkId, uint32 slotId) {{\n",
            f"  return data_->{archetype_name}.Remove<Upgine::ECS::Archetypes::{archetype_name}>(chunkId, slotId);\n",
            "}\n\n"
        ])

    # Generate template specializations for Get<Chunk<ArchetypeName>>(chunkId)
    for chunk in used_chunks:
        archetype_name = chunk.split("::")[-1].split(">")[0]
        source_data.extend([
            f"template<> Chunk<Archetypes::{archetype_name}> *Upgine::Core::Services::ChunkService::Get<Chunk<Archetypes::{archetype_name}>>(uint32 chunkId) {{\n",
            f"  return data_->{archetype_name}.Get(chunkId);\n",
            "}\n\n"
        ])

    # Generate template specializations for UsedChunks<Chunk<ArchetypeName>>()
    for chunk in used_chunks:
        archetype_name = chunk.split("::")[-1].split(">")[0]
        source_data.extend([
            f"template<> uint32 Upgine::Core::Services::ChunkService::UsedChunks<Chunk<Archetypes::{archetype_name}>>() {{\n",
            f"  return data_->{archetype_name}.UsedChunks();\n",
            "}\n\n"
        ])

    # Generate GetComponents<Upgine::ECS::Components::X>()
    for system in system_to_be_added:
        component = system[:-6]
        source_data.extend([
            f"template<> std::vector<Upgine::ECS::DTO::ComponentDTO> Upgine::Core::Services::ChunkService::GetComponents<Upgine::ECS::Components::{component}>() {{\n",
            "    std::vector<Upgine::ECS::DTO::ComponentDTO> components;\n"
        ])

        for archetype in archetypes_id:
            if component in archetype[1]:
                archetype_name = archetype[0]
                source_data.extend([
                    f"    for (uint32 i = 0; i < data_->{archetype_name}.UsedChunks(); ++i) {{\n",
                    f"        auto chunk = data_->{archetype_name}.Get(i);\n",
                    "        for (uint32 j = 0; j < chunk->GetSize(); ++j) {\n",
                    f"          Archetypes::{archetype_name} * archetype = chunk->Get(j);\n",
                    "          Upgine::ECS::DTO::ComponentDTO componentDTO;\n",
                    f"          componentDTO.component = &archetype->{component.lower()};\n",
                    f"          componentDTO.archetypeId = Archetypes::{archetype_name}::GetId();\n",
                    "          componentDTO.entityId = j;\n",
                    "          components.push_back(componentDTO);\n",
                    "        }\n",
                    "    }\n\n"
                ])

        source_data.extend([
            "    return components;\n",
            "}\n\n"
        ])

    with open(SOURCE_OUTPUT_PATH, "w") as source_file:
        source_file.writelines(source_data)

if __name__ == "__main__":
    main()

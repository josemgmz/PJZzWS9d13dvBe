from doc_template import textHeader
from tools import find_in_folders

# Constants and file paths
INCLUDE_PATH = "../../../include/upgine"
OUTPUT_HEADER_PATH = "../../../include/upgine/auto_generate/system_service.h"
OUTPUT_SOURCE_PATH = "../../../src/upgine/auto_generate/system_service.cpp"
ISYSTEM_DERIVATION_PATTERN = " : public ISystem"

def find_system_classes(include_path, pattern):
     """
     Searches for all classes that inherit from ISystem within the given directory.
     Returns a list of class names.
     """
     lines_with_system = find_in_folders(include_path, pattern)
     return [
          line.split(pattern)[0].split("class ")[-1]
          for line in lines_with_system
     ]

def print_system_info(system_names):
     """
     Prints debugging information about the detected systems.
     """
     print("--------------------------------------")
     print("-- Checking System Dependencies --")
     print("--------------------------------------")
     print(f"-- Found a number of {len(system_names)} Archetypes")
     print(f"-- Found a number of {len(system_names)} Chunks")
     print(f"-- System's names: {system_names}")
     print("--------------------------------------\n")

def generate_header_file(system_names):
     """
     Generates the content for the system_service.h file.
     """
     header_data = textHeader[:]
     header_data.extend([
          "//This file is generated automatically by archetypes_generator.py\n\n",
          "#ifndef INCLUDE_UPGINE_AUTO_GENERATE_SYSTEM_SERVICE_H_\n",
          "#define INCLUDE_UPGINE_AUTO_GENERATE_SYSTEM_SERVICE_H_\n\n",
          "#include \"upgine/core/services/service_interface.h\"\n\n",
          "#include \"upgine/memory/smart_pointer/reference.h\"\n\n",
          "namespace Upgine::Core::Services{\n",
          "  class SystemService : public IService, public Upgine::Memory::SmartPointer::Reference {\n",
          "   public:\n",
          "    SystemService();\n",
          "    ~SystemService() override;\n\n",
          "    void Init() override;\n",
          "    void Update() override;\n",
          "    void Shutdown() override;\n\n",
          "  private:\n",
          "    struct Data;\n",
          "    Data * data_;\n",
          "  };\n",
          "}\n",
          "#endif // INCLUDE_UPGINE_AUTO_GENERATE_SYSTEM_SERVICE_H_\n"
     ])

     with open(OUTPUT_HEADER_PATH, "w") as header_file:
          header_file.writelines(header_data)

def generate_source_file(system_names):
     """
     Generates the content for the system_service.cpp file.
     It includes the detected systems and creates logic to initialize, update,
     and shut them down in the SystemService class.
     """
     source_data = [
          "//This file is generated automatically by system_service_generator.py\n\n",
          "#include \"upgine/core/services/service_interface.h\"\n"
     ]

     # Include components
     source_data.extend([
          f"#include \"upgine/ecs/components/{(system[:-6] + '_component').lower()}.h\"\n"
          for system in system_names
     ])

     source_data.append("\n")

     # Include systems
     source_data.extend([
          f"#include \"upgine/ecs/systems/{(system[:-6] + '_system').lower()}.h\"\n"
          for system in system_names
     ])

     # Include additional libraries
     source_data.extend([
          "#include <vector>\n",
          "#include <algorithm>\n",
          "#include \"upgine/auto_generate/system_service.h\"\n\n"
     ])

     # Internal Data structure definition
     source_data.append("struct Upgine::Core::Services::SystemService::Data {\n")
     source_data.extend([
          f"  Upgine::ECS::Systems::{system} {system[:-6].lower()};\n"
          for system in system_names
     ])
     source_data.append("  std::vector<Upgine::ECS::Systems::ISystem*> sortedSystems;\n")
     source_data.append("};\n\n")

     # Constructor
     source_data.extend([
          "Upgine::Core::Services::SystemService::SystemService() {\n",
          "  data_ = new Data();\n",
          "}\n\n"
     ])

     # Destructor
     source_data.extend([
          "Upgine::Core::Services::SystemService::~SystemService() {\n",
          "  delete data_;\n",
          "}\n\n"
     ])

     # Init
     source_data.append("void Upgine::Core::Services::SystemService::Init() {\n")
     source_data.extend([
          f"  data_->sortedSystems.push_back(&data_->{system[:-6].lower()});\n"
          for system in system_names
     ])
     source_data.extend([
          "  std::sort(data_->sortedSystems.begin(), data_->sortedSystems.end(), [](const ECS::Systems::ISystem* a, const ECS::Systems::ISystem* b) {\n",
          "    return a->GetPriority() > b->GetPriority();\n",
          "  });\n",
          "}\n\n"
     ])

     # Update
     source_data.extend([
          "void Upgine::Core::Services::SystemService::Update() {\n",
          "  for (auto system : data_->sortedSystems) {\n",
          "    system->Update();\n",
          "  }\n",
          "}\n\n"
     ])

     # Shutdown
     source_data.extend([
          "void Upgine::Core::Services::SystemService::Shutdown() {\n",
          "  data_->sortedSystems.clear();\n",
          "}\n\n"
     ])

     with open(OUTPUT_SOURCE_PATH, "w") as source_file:
          source_file.writelines(source_data)

def main():
     # 1. Find classes that inherit from ISystem
     system_names = find_system_classes(INCLUDE_PATH, ISYSTEM_DERIVATION_PATTERN)

     # 2. Print system info
     print_system_info(system_names)

     # 3. Generate files
     generate_header_file(system_names)
     generate_source_file(system_names)

     # 4. Completion messages
     print("System Generator finished")
     print("Step 2/2: System Generator finished\n")

if __name__ == "__main__":
     main()

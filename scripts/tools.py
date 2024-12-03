import os

def find_in_folders(path, reference):
    """
    Recursively search for lines containing a given reference string in all files under the specified path.
    Returns a set of all matching lines.
    """
    matched_lines = set()

    for item in os.listdir(path):
        item_path = os.path.join(path, item)

        if os.path.isfile(item_path):
            with open(item_path, "r", encoding='utf-8', errors='ignore') as file:
                for line in file:
                    if reference in line:
                        matched_lines.add(line)
        elif os.path.isdir(item_path):
            matched_lines.update(find_in_folders(item_path, reference))

    return matched_lines

def find_files_containing(path, word, not_contain=None):
    """
    Recursively searches for files under the given path that contain a specified word.
    Excludes files that contain any words in not_contain.
    Returns a list of file paths that match the criteria.
    """
    if not_contain is None:
        not_contain = []

    results = []
    for subdir, dirs, files in os.walk(path):
        for file_name in files:
            file_path = os.path.join(subdir, file_name)
            with open(file_path, 'r', encoding='utf-8', errors='ignore') as file:
                content = file.read()
                # Check if the file should be excluded
                if any(exclusion in content for exclusion in not_contain):
                    continue
                if word in content:
                    results.append(file_path.replace('\\', '/'))
    return results

def extract_get_id_from_component(path):
    """
    Extracts the component name and its ID from a component file.
    The ID is obtained from the line containing 'uint32 GetId()'.
    Returns [componentName, idValue].
    """
    component_name = ''
    with open(path, 'r', encoding='utf-8', errors='ignore') as file:
        for line in file:
            if 'struct ' in line:
                component_name = line.split(' ')[-1].strip()
            if 'uint32 GetId()' in line:
                # Extract ID, assuming it's before the semicolon and in hex or decimal format
                id_value = int(line.split(' ')[-2].replace(';', ''), 0)
                return [component_name, id_value]
    return None

def extract_component_from_archetype(path):
    """
    Extracts archetype components from a file containing 'CREATE_ARCHETYPE'.
    Returns a list of [archetypeName, processedComponents, idSum] for each archetype found.
    """
    archetypes_data = []
    with open(path, 'r', encoding='utf-8', errors='ignore') as file:
        for line in file:
            if 'CREATE_ARCHETYPE(' in line:
                archetype_name = line.split('(')[1].split(',')[0].strip()
                components_raw = line.split(',')[2:]  # Skip archetypeName and first param after comma
                # Process components: only take every even-indexed element after cleaning spaces
                processed_components = [comp.strip() for i, comp in enumerate(components_raw) if (i % 2) == 0]
                archetypes_data.append([archetype_name, processed_components, 0])
    return archetypes_data

def extract_archetype_id(path):
    """
    Extracts IDs from archetypes by:
    1. Finding component files referencing Upgine::ECS::Components.
    2. Finding archetype files containing CREATE_ARCHETYPE.
    3. Matching components to archetypes and summing their IDs.

    Returns a list of [archetypeName, components, idSum].
    """
    component_files = find_files_containing(
        path,
        'Upgine::ECS::Components',
        not_contain=['CREATE_ARCHETYPE', 'struct IComponent {};']
    )

    archetype_files = find_files_containing(
        path,
        'CREATE_ARCHETYPE',
        not_contain=['INCLUDE_UPGINE_MACROS_ARCHETYPE_GENERATOR_H_']
    )

    # Assume there's at least one archetype file
    archetypes = extract_component_from_archetype(archetype_files[0])

    # Process each component file and update archetype IDs
    for component_file in component_files:
        component_data = extract_get_id_from_component(component_file)
        if component_data:
            comp_name, comp_id = component_data
            for archetype in archetypes:
                if comp_name in archetype[1]:
                    archetype[2] += comp_id

    return archetypes

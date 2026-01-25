#ifndef GLOBAL_VARIABLES
#define GLOBAL_VARIABLES
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

namespace{

const fs::path INPUT_DIR{"Data/Input"};
const fs::path OUTPUT_DIR{"Data/Output"};
const fs::path INPUT_PATH{"Data/Input/input.txt"};
const fs::path OUTPUT_PATH{"Data/Output/target.bin"};


}

#endif // GLOBAL_VARIABLES

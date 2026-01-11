#include <iostream>
#include <string>
#include <fstream>
#include <bitset>
#include <vector>

std::string convert_to_binary(std::string line){
    std::string binary_version = "";
    for(auto i = 0; i < line.size(); i++){
        char letter = line.at(i);
        std::string bin_letter = std::bitset<8>(letter).to_string();

        binary_version = bin_letter + "_"+ binary_version;
    }
    binary_version += "00000000";
    return binary_version;
}


int main()
{


    std::ifstream file("./input.txt");
    std::string line;


    while(std::getline(file, line)){
        std::cout << line << '\n';
    }
    std::string new_line = "oran";
    std::vector<std::string> v;
    std::string binary_version = convert_to_binary(new_line);
    std::cout << binary_version << '\n';
    return 0;
}


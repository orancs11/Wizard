#include <iostream>
#include <string>
#include <fstream>
#include <bitset>
#include <vector>
#include <map>

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

void create_map(std::map<char, int>& initial_map, std::string_view line){
    std::cout << "Creating frequency map..." << '\n';
    for(int i = 0; i < line.length(); i++){
        char curr_letter = line.at(i);
        if(initial_map.count(curr_letter)) initial_map[curr_letter] += 1;
        else initial_map[curr_letter] = 1;
    }
    std::cout << "Frequency Map has created." << '\n';

}

std::ifstream encoded_file(std::string file_location){


return std::ifstream{};

}


int main()
{
    std::map<char, int> f_map;
    create_map(f_map, "Somethinnngg");
    std::cout << "Size of f_map: " << f_map.size() << '\n';
    for(auto i = f_map.begin(); i != f_map.end(); i++){
        std::cout << "Key: " << i->first << ',' << "Value: " << i->second << '\n';
    }
    return 0;
}


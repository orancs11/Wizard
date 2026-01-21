#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include<bitset>
#include "PriorityQueue.hpp";



//Get files
//Iterate over files one by one
// Huffman coding to create a dictionary
// Encode file
// Return encoded file
// Create a basic site where it can string only files into compressed versions and encode them
// return files as downloadable
// Run it in docker

//TODO
// 1 - Create Huffman Tree
// 1.1 - Create Frequency Map
// 1.2 - Create Pair Struct (letter, frequency) | Or rather directly create Binary Node
// 1.3 - Create Priority Q (min heap Q)

// 2 - Sucessfully Decode compressed file using huffman again


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

void print_file(const std::string& file_location){

    std::ifstream input_file;
    input_file.open(file_location);
    std::string line;
    int iterator{1};
    while(std::getline(input_file, line)){
        std::cout << iterator++ + "- " + line << '\n';
    }
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


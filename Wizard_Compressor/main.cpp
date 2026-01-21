#include <iostream>
#include "Huffman.hpp";



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



int main()
{
    std::map<char, int> f_map;
    Huffman::create_map(f_map, "Somethinnngg");
    std::cout << "Size of f_map: " << f_map.size() << '\n';
    for(auto i = f_map.begin(); i != f_map.end(); i++){
        std::cout << "Key: " << i->first << ',' << "Value: " << i->second << '\n';
    }
    return 0;
}


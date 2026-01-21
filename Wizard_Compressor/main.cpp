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
// 1.3 - Create Priority Q (min heap Q)

// 2 - Sucessfully Decode compressed file using huffman again



int main()
{
    std::map<char, int> f_map;
    Huffman::create_map(f_map, "Somethinnngg");
    std::cout << "---------------------------" << '\n';
    int map_size{f_map.size()};
    std::cout << "Size of f_map: " << map_size << '\n';
    Huffman::print_map(f_map);
    std::cout << "---------------------------" << '\n';
    Huffman::PriorityQueue minQ(map_size);
    std::cout << "Min Queue is created!" << '\n';

    for(auto i{f_map.begin()}; i != f_map.end(); i++){
        Huffman::TreeNode* new_node = new Huffman::TreeNode(i->first, i->second);
        minQ.offer(new_node); // Address of min queue
    }
    //Handle memory management
    minQ.display();
    std::cout << "Nodes are fed to min queue" << '\n';
    return 0;
}


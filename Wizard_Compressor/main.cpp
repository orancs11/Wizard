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
    Huffman::build_map(f_map, "Somethinnngg");
    std::cout << "---------------------------" << '\n';
    int map_size{f_map.size()};
    std::cout << "Size of f_map: " << map_size << '\n';
    Huffman::print_map(f_map);
    std::cout << "---------------------------" << '\n';
    Huffman::PriorityQueue minQ(map_size);
    Huffman::create_minQ(minQ, f_map);
    std::cout << "Min Queue is created!" << '\n';
    //Handle memory management
    //»

    //minQ.display();

    //Huffman Process
    int curr_size = minQ.size();

    for(int i = 0; i < curr_size - 1; i++){
        Huffman::TreeNode* first_node{minQ.poll()};
        Huffman::TreeNode* second_node{minQ.poll()};
        int composite_val = first_node->val + second_node->val;
        Huffman::TreeNode* composite_node = new Huffman::TreeNode(first_node->val + second_node->val);
        composite_node->left = first_node;
        composite_node->right = second_node;
        minQ.offer(composite_node);
    }

    minQ.display();



    std::cout << "Nodes are fed to min queue" << '\n';
    return 0;
}


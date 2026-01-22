#include <iostream>
#include "Huffman.hpp";

int main()
{
    std::map<char, int> f_map;

    std::string path{"./input.txt"};
    std::ifstream input_file;
    input_file.open(path);
    std::string line;

    while(std::getline(input_file, line)){
        Huffman::build_map(f_map, line);
    }

    std::cout << "---------------------------" << '\n';
    int map_size = f_map.size();

    Huffman::PriorityQueue minQ(map_size);
    Huffman::create_minQ(minQ, f_map);
    std::cout << "Min Queue is created!" << '\n';
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
    std::cout << "Nodes are fed to min queue" << '\n';

    Huffman::TreeNode* root{minQ.poll()};

    std::map<char, std::string> huffman_structure;
    Huffman::create_huffman_structure(root, "", huffman_structure);
    Huffman::print_map(huffman_structure);
    return 0;
}


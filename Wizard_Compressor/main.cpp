#include <iostream>
#include "Huffman.hpp";
#include "Utilities.hpp"
int main()
{
    std::map<char, int> f_map;

    std::string path{"./input.txt"};
    std::ifstream input_file;
    input_file.open(path);
    std::string line;

    while(std::getline(input_file, line)){
        Utilities::build_map(f_map, line);
    }

    std::cout << "---------------------------" << '\n';

    //Huffman Process
    int map_size = f_map.size();
    Huffman::PriorityQueue minQ(map_size);
    Utilities::create_minQ(minQ, f_map);
    std::cout << "Min Queue is created!" << '\n';


    std::cout << "Building Binary Huffman Tree..." << '\n';
    Huffman::TreeNode* root{Utilities::create_huffman_tree(minQ)};
    std::cout << "Huffman BT has built!" << '\n';

    // Huffman Encode Structure
    std::cout << "Map is initialized!" << '\n';
    std::map<char, std::string> huffman_structure;
    Utilities::create_huffman_structure(root, "", huffman_structure);
    std::cout << "Huffman Structure has built!" << '\n';

    Utilities::print_map(huffman_structure);

    return 0;
}


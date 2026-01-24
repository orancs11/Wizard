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

    input_file.close();

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


    std::fstream file;
    file.open(path);
    std::string new_line;
    std::vector<unsigned char> storage;

    std::ofstream target_file("target_file.bin", std::ios::out | std::ios::binary);

    unsigned char buffer{};

    long long total_bits_count{0};
    while(std::getline(file, new_line)){
        for(auto i{0}; i < new_line.size(); i++){
            std::string encoded_phrase{huffman_structure[new_line.at(i)]};

            for(auto j{0}; j < encoded_phrase.size(); j++){
                buffer = buffer << 1;
                if(encoded_phrase.at(j) == '1') buffer |= 1;
                else buffer |= 0;
                total_bits_count++;
                if(total_bits_count% 8 == 0){
                    storage.push_back(buffer);
                    buffer = 0;
                }
            }
        }

        for(auto k{0}; k < huffman_structure['\n'].size(); k++){
                buffer = buffer << 1;
                if(huffman_structure['\n'].at(k) == '1') buffer |= 1;
                else buffer |= 0;
                total_bits_count++;
                if(total_bits_count % 8 == 0){
                    storage.push_back(buffer);
                    buffer = 0;
                }
            }
    }

    int remaining = total_bits_count % 8;
    if (remaining > 0) {
        buffer = buffer << (8 - remaining); // Move bits to the left
        storage.push_back(buffer);
    }
    target_file.write(reinterpret_cast<const char*>(&total_bits_count), sizeof(total_bits_count));
    target_file.write(reinterpret_cast<const char*>(storage.data()), sizeof(storage.data()));

    file.close();
    target_file.close();

    return 0;
}






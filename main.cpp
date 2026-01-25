#include <iostream>
#include "Huffman.hpp";
#include "Utilities.hpp"
#include "Global_Variables.hpp"

int main()
{

    std::map<char, int> f_map;
    std::ifstream input_file(fs::absolute(INPUT_PATH));
    std::string line;

    while(std::getline(input_file, line)){
        Utilities::build_map(f_map, line);
    }

    input_file.close();

    //Huffman Process
    int map_size = f_map.size();
    Huffman::PriorityQueue minQ(map_size);
    Utilities::create_minQ(minQ, f_map);




    Huffman::TreeNode* root{Utilities::create_huffman_tree(minQ)};

    std::map<char, std::string> huffman_structure;
    Utilities::create_huffman_structure(root, "", huffman_structure);



    std::vector<unsigned char> storage;
    std::ofstream target_file(fs::absolute(OUTPUT_PATH), std::ios::out | std::ios::binary);
    unsigned char buffer{};
    input_file.open(fs::absolute(INPUT_PATH));
    long long total_bits_count{0};

    while(std::getline(input_file, line)){
        for(auto i{line.begin()}; i != line.end(); i++){
            std::string encoded_phrase{huffman_structure[*i]};

            for(auto j{encoded_phrase.begin()}; j < encoded_phrase.end(); j++){
                buffer = buffer << 1;
                if(*j == '1') buffer |= 1;
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
    input_file.close();

    int remaining = total_bits_count % 8;
    if (remaining > 0) {
        buffer = buffer << (8 - remaining);
        storage.push_back(buffer);
    }

    target_file.write(reinterpret_cast<const char*>(&total_bits_count), sizeof(total_bits_count));
    target_file.write(reinterpret_cast<const char*>(storage.data()), sizeof(storage.data()));

    target_file.close();

    return 0;
}






#ifndef Huffman_INCLUDED
#define Huffman_INCLUDED
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include<bitset>


// Min heap Q
// Q stores pairs by looking at their frequencies(second values)
// Binary TreeNode for building Huffman Tree


namespace Huffman{

    class TreeNode{
        public:
            int val;
            char letter;
            TreeNode* left{nullptr};
            TreeNode* right{nullptr};

            TreeNode(){}
            TreeNode(char input_letter, int input_val):
            val{input_val}, letter{input_letter}{}



};


    class PriorityQueue {
        public:
            std::vector<TreeNode*> minQ;

            PriorityQueue(int k){
                minQ.reserve(k);
            }

            void swim(){
                int curr_index{minQ.size() - 1};
                int parent_index{(curr_index - 1) / 2};

                while(curr_index > 0){
                    if(minQ.at(parent_index)->val > minQ.at(curr_index)->val)
                        std::swap(minQ.at(parent_index), minQ.at(curr_index));
                    else break;
                    curr_index = parent_index;
                    parent_index = (curr_index - 1) / 2;
                }


            }

            void sink(){

            }

            void offer(TreeNode& node){
                minQ.push_back(&node);
                swim();
            }

            TreeNode* peek(){
                return minQ.at(0);
            }

            TreeNode* poll(){
                TreeNode* tempAddress{minQ.at(0)};
                minQ.pop_back();
                sink();
                return tempAddress;
            }

    };



inline std::string convert_to_binary(std::string line){
    std::string binary_version = "";
    for(auto i = 0; i < line.size(); i++){
        char letter = line.at(i);
        std::string bin_letter = std::bitset<8>(letter).to_string();

        binary_version = bin_letter + "_"+ binary_version;
    }
    binary_version += "00000000";
    return binary_version;
}

inline void create_map(std::map<char, int>& initial_map, std::string_view line){
    std::cout << "Creating frequency map..." << '\n';
    for(int i = 0; i < line.length(); i++){
        char curr_letter = line.at(i);
        if(initial_map.count(curr_letter)) initial_map[curr_letter] += 1;
        else initial_map[curr_letter] = 1;
    }
    std::cout << "Frequency Map has created." << '\n';

}

inline std::ifstream encoded_file(std::string file_location){


return std::ifstream{};

}

inline void print_file(const std::string& file_location){

    std::ifstream input_file;
    input_file.open(file_location);
    std::string line;
    int iterator{1};
    while(std::getline(input_file, line)){
        std::cout << iterator++ + "- " + line << '\n';
    }
}


}




#endif

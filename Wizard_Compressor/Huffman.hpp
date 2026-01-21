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
            TreeNode(int input_val): val{input_val}{};

            ~TreeNode(){
                delete left;
                delete right;
            }

};


    class PriorityQueue {
        private:
            std::vector<TreeNode*> minQ;
            int parent(int i){ return (i - 1) / 2; }
            int left_child(int i){ return (2 * i + 1); }
            int right_child(int i){ return (2 * i + 2); }

            bool is_leaf(int i){
                if(left_child(i) >= minQ.size() || right_child(i) >= minQ.size()) return false;
                return true;
            }

        public:
            PriorityQueue(int k) {
                minQ.reserve(k);
            }

            void offer(TreeNode* element){
                minQ.push_back(element);
                int curr_index{minQ.size() - 1};

                while(curr_index > 0){
                    int parent_index{parent(curr_index)};
                    if(minQ.at(parent_index)->val > minQ.at(curr_index)->val){
                        std::swap(minQ.at(parent_index), minQ.at(curr_index));
                    }
                    curr_index = parent_index;
                }

            }

            void heapify(int i){
                if(is_leaf(i)) return;
                int child_index = minQ.at(left_child(i))->val > minQ.at(right_child(i))->val ?
                right_child(i) : left_child(i);

                if(minQ.at(i)->val > minQ.at(child_index)->val){
                    std::swap(minQ.at(child_index), minQ.at(i));
                    heapify(child_index);
                }

            }

            TreeNode* poll(){
                TreeNode * poppedNode{minQ.at(0)};
                //Swap last element with first element and pop last element
                std::swap(minQ.at(0), minQ.at(minQ.size() - 1));
                minQ.pop_back();
                heapify(0);
                return poppedNode;
            }


            void display(){
                for(auto i{0}; i < minQ.size(); i++){
                    TreeNode* curr_node{minQ.at(i)};
                    std::cout <<"Letter: " << curr_node->letter << " Value: " << curr_node->val << '\n';
                }
            }
    };

    // Utility functions

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

    inline void print_map(const std::map<char, int>& f_map){
        for(auto i = f_map.begin(); i != f_map.end(); i++){
            std::cout << "Key: " << i->first << ',' << "Value: " << i->second << '\n';
        }
    }

}


#endif

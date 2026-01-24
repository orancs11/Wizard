#ifndef UTILITIES_HPP
#define UTILITIES_HPP

using namespace Huffman;

namespace Utilities{

    // Utility functions



    inline TreeNode* create_huffman_tree(PriorityQueue& minQ){
        int currQ_size = minQ.size();

        for(int i = 0; i < currQ_size - 1; i++){
            Huffman::TreeNode* first_node{minQ.poll()};
            Huffman::TreeNode* second_node{minQ.poll()};

            int composite_val = first_node->val + second_node->val;
            Huffman::TreeNode* composite_node = new Huffman::TreeNode(first_node->val + second_node->val);

            composite_node->left = first_node;
            composite_node->right = second_node;

            minQ.offer(composite_node);
        }

        return minQ.poll();
    }

    inline void create_minQ(PriorityQueue& minQ, std::map<char, int>& f_map){
        for(auto i{f_map.begin()}; i != f_map.end(); i++){
        Huffman::TreeNode* new_node = new Huffman::TreeNode(i->first, i->second);
        minQ.offer(new_node); // Address of min queue
        }
    }

    inline void build_map(std::map<char, int>& initial_map, std::string_view line){
        for(int i = 0; i < line.length(); i++){
            char curr_letter = line.at(i);
            if(initial_map.count(curr_letter)) initial_map[curr_letter] += 1;
            else initial_map[curr_letter] = 1;
        }
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

    template <typename T, typename U>
    inline void print_map(const std::map<T, U>& f_map){
        std::cout << "*------------------------------------------------------------------------------*" << '\n';
        for(auto i = f_map.begin(); i != f_map.end(); i++){
            std::cout << "Key: " << i->first << ',' << "Value: " << i->second << '\n';
        }
        std::cout << "*------------------------------------------------------------------------------*" << '\n';
    }

    inline void create_huffman_structure(TreeNode* root, std::string encoded_letter, std::map<char, std::string>& huffman_map){
        // Recursive DFS function
        if(root == nullptr) return;
            create_huffman_structure(root->left, encoded_letter.append("0"), huffman_map);
            create_huffman_structure(root->right, encoded_letter.append("1"), huffman_map);

        if(root->letter != '\0') // Check sentinel value
            huffman_map.emplace(root->letter, encoded_letter);
    }
}


#endif // UTILITIES_HPP

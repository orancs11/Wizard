#ifndef PRIORITYQUEUE_HPP_INCLUDED
#define PRIORITYQUEUE_HPP_INCLUDED


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

}

#endif

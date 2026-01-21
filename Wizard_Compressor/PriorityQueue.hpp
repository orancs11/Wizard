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

            PriorityQueue(int k): minQ(k){
            }

            void swim(){

            }

            void sink(){

            }

            void offer(const TreeNode* node){

            }

            TreeNode& peek(){

            }

            TreeNode& poll(){

            }

    };

}

#endif

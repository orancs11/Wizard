#ifndef PRIORITYQUEUE_HPP_INCLUDED
#define PRIORITYQUEUE_HPP_INCLUDED


template <typename T, typename U>
struct Pair {
    T first;
    U second;

};

template <typename T, typename U>
class PriorityQueue {
    private:
        std::vector<Pair<T, U>> _q;

    public:
         PriorityQueue(){}
        ~PriorityQueue(){}

        void add(const Pair<T, U> &p)
        {
            this._q.push_back(p);
            swim();

        }
        Pair<T, U>& pop(){
            auto result = this._q.at(this._q.size() - 1);
            this._q.pop_back();
            return result;
        }

        void swim()
        {
            int last_index = _q.size() - 1;
            int curr_index{last_index};
            bool condition{true};


            while(condition){
                int parent = (curr_index - 1) / 2;
                if(this._q.at(parent).second < this._q.at(curr_index).second)
                {
                    std::swap(_q.at(parent), _q.at(curr_index));
                }
                else condition = false;
                curr_index = parent;
            }
        }

        void sink(){

        }
};








#endif

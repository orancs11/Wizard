#ifndef PRIORITYQUEUE_HPP_INCLUDED
#define PRIORITYQUEUE_HPP_INCLUDED


template <typename T, typename U>
struct Pair {
    T first;
    U second;
    Pair(T first, U second): first{first}, second{second}
    {}
};

template <typename T, typename U>
class PriorityQueue {
    private:
        std::vector<Pair<T, U>> q;

    public:
        void virtual swim();
        void virtual sink();
        void virtual add(const Pair<T, U>& freq_pair);
        void virtual vanish(int index);
};


#endif

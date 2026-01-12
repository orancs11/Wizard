#ifndef PRIORITYQUEUE_HPP_INCLUDED
#define PRIORITYQUEUE_HPP_INCLUDED


template <typename T, typename U>
struct Pair {
    T _first;
    U _second;
    Pair(T first, U second): first{_first}, second{_second}
    {}
};

template <typename T, typename U>
class PriorityQueue {
    private:
        std::vector<Pair<T, U>> q;

    public:
        virtual void swim(int i);
        virtual void sink(int i);
        virtual void add(const Pair<T, U>& freq_pair);
        virtual void vanish(int index);
};


#endif

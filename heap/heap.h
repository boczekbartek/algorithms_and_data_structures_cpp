//
// Created by Bartłomiej Boczek on 30/10/2019.
//

#ifndef ALGORITHMS_AND_DATA_STRUCTURES_CPP_HEAP_H
#define ALGORITHMS_AND_DATA_STRUCTURES_CPP_HEAP_H


#include <vector>

using std::vector;

template<typename T, typename cmp_class>
class heap {
/**
 * cmp_class have to implement static method bool is_first_better
 */
private:
    vector<T> data;

    void swap(int a, int b);

    void heap_up(int idx);

    void heap_down(int idx);

public:
    heap();

    void push(const T &);

    void pop();

    bool empty();

    int size();

    T &top();
};


#endif //ALGORITHMS_AND_DATA_STRUCTURES_CPP_HEAP_H

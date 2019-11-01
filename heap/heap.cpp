//
// Created by Bartłomiej Boczek on 30/10/2019.
//
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE vector

#include <boost/test/unit_test.hpp>
#include "heap.h"

template<typename T, typename cmp_class>
void heap<T, cmp_class>::swap(int a, int b) {
    T tmp = data[a];
    data[a] = data[b];
    data[b] = tmp;
}

template<typename T, typename cmp_class>
void heap<T, cmp_class>::heap_up(int idx) {
    int parent = idx / 2;
    if (idx == 1) return;
    if (cmp_class::is_first_better(data[idx], data[parent])) {
        swap(idx, parent);
        heap_up(parent);
    }
}

template<typename T, typename cmp_class>
void heap<T, cmp_class>::heap_down(int idx) {
    int best = idx;
    int left = idx * 2;
    int right = left + 1;
    if (left <= data.size()-1 && cmp_class::is_first_better(data[left], data[best]))
        best = left;
    if (right <= data.size()-1 && cmp_class::is_first_better(data[right], data[best]))
        best = right;
    if (best == idx) return;
    else {
        swap(best, idx);
        heap_down(best);
    }
}

template<typename T, typename cmp_class>
heap<T, cmp_class>::heap() {
    data.push_back(T());
}

template<typename T, typename cmp_class>
void heap<T, cmp_class>::push(const T &elem) {
    data.push_back(elem);
    heap_up(data.size() - 1);
}

template<typename T, typename cmp_class>
void heap<T, cmp_class>::pop() {
    data[1] = data.back();
    data.pop_back();
    heap_down(1);
}

template<typename T, typename cmp_class>
int heap<T, cmp_class>::size() {
    return data.size() - 1;
}

template<typename T, typename cmp_class>
bool heap<T, cmp_class>::empty() {
    return 0 == size();
}

template<typename T, typename cmp_class>
T &heap<T, cmp_class>::top() {
    return data[1];
}

struct cmp_int {
    static bool is_first_better(int a, int b) { return a < b; }
};

BOOST_AUTO_TEST_CASE(test_heap_size) {
    heap<int, cmp_int> pq;
    pq.push(2);
    pq.push(5);
    pq.push(7);
    pq.push(1);
    pq.push(0);
    BOOST_CHECK(pq.size() == 5);
}

BOOST_AUTO_TEST_CASE(test_heap_empty) {
    heap<int, cmp_int> pq;
    BOOST_CHECK(pq.empty());
    pq.push(2);
    BOOST_CHECK(!pq.empty());
}

BOOST_AUTO_TEST_CASE(test_heap_sort) {
    heap<int, cmp_int> pq;
    int ordered[] = {0,1,2,5,7};
    pq.push(2);
    pq.push(5);
    pq.push(7);
    pq.push(1);
    pq.push(0);
    for (int i=0; i<5; i++){
        BOOST_CHECK(ordered[i] == pq.top());
        pq.pop();
    }
}
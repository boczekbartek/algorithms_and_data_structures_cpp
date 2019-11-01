#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE vector

#include <boost/test/unit_test.hpp>
#include <cassert>
#include "vector.h"

template<typename T>
void vector<T>::push_back(const T &elem) {
    if (_size >= buf_size - 1) __grow();
    buf[_size++] = elem;
}

template<typename T>
T &vector<T>::operator[](int idx) {
    assert(idx < size() && "idx exceeds vector size");
    return buf[idx];
}

template<typename T>
void vector<T>::pop_back() { _size--; }

template<typename T>
T &vector<T>::back() {
    return buf[_size - 1];
}

template<typename T>
int vector<T>::size() { return _size; }

template<typename T>
bool vector<T>::empty() { return 0 == size(); }

template<typename T>
void vector<T>::__grow() {
    int new_size = buf_size * resize_factor;
    T *new_buf = new T[new_size];
    for (int i = 0; i < buf_size; i++)
        new_buf[i] = buf[i];
    delete[] buf;
    buf = new_buf;
    buf_size = new_size;
}

BOOST_AUTO_TEST_CASE(test_vector_push) {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    BOOST_CHECK(v[0] == 1);
    BOOST_CHECK(v[1] == 2);
    BOOST_CHECK(v[2] == 3);
}

BOOST_AUTO_TEST_CASE(test_vector_back) {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    BOOST_CHECK(v.back() == 3);
}

BOOST_AUTO_TEST_CASE(test_vector_pop_back) {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    BOOST_CHECK(v.size() == 3);
    BOOST_CHECK(v.back() == 3);
    v.pop_back();
    BOOST_CHECK(v.size() == 2);
    BOOST_CHECK(v.back() == 2);

}

BOOST_AUTO_TEST_CASE(test_vector_size) {
    vector<int> v;
    BOOST_CHECK(v.size() == 0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    BOOST_CHECK(v.size() == 3);
}

BOOST_AUTO_TEST_CASE(test_vector_empty) {
    vector<int> v;

    BOOST_CHECK(v.empty());
    v.push_back(1);
    BOOST_CHECK(!v.empty());
    v.pop_back();
    BOOST_CHECK(v.empty());
}
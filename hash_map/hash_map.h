//
// Created by Bartłomiej Boczek on 01/11/2019.
//

#ifndef ALGORITHMS_AND_DATA_STRUCTURES_CPP_HASH_MAP_H
#define ALGORITHMS_AND_DATA_STRUCTURES_CPP_HASH_MAP_H
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE vector

#include <boost/test/unit_test.hpp>
#include <vector>

using std::vector;

template<typename K, typename V>
struct pair {
    K k;
    V v;

    pair() = default;

    pair(K _k, V _v) : k(_k), v(_v) {}
};

template<typename K, typename V, typename cmp_class>
struct hash_node {
    typedef pair<K, V> kv_pair;

    vector<kv_pair> data;

    void put(K k, V v);

    V &get(K k);
};

const int HM_SIZE = 10001;

template<typename K, typename V, typename hash_class, typename cmp_class>
class hash_map {
private:
    hash_node<K, V, cmp_class> data[HM_SIZE];

    int hash(K key);

public:
    hash_map() = default;

    V &get(K key);

    void put(K key, V value);
};


#endif //ALGORITHMS_AND_DATA_STRUCTURES_CPP_HASH_MAP_H

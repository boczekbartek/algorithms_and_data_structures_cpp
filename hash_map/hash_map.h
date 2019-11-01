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

    void put(K k, V v) {
        bool found = false;
        for (int i = 0; i < data.size(); i++) {
            if (cmp_class::cmp(data[i].k, k)) {
                data[i].v = v;
                found = true;
                break;
            }
        }
        if (!found) data.push_back(kv_pair(k, v));
    }

    V &get(K k) {
        for (int i = 0; i < data.size(); i++) {
            if (cmp_class::cmp(data[i].k, k)) {
                return data[i].v;
            }
        }
    }
};

const int HM_SIZE = 10001;

template<typename K, typename V, typename hash_class, typename cmp_class>
class hash_map {
private:
    hash_node<K, V, cmp_class> data[HM_SIZE];

    int hash(K key) {
        return hash_class::hash(key);
    }

public:
    hash_map() = default;

    V &get(K key) {
        return data[hash(key)].get(key);
    }

    void put(K key, V value) {
        data[hash(key)].put(key, value);
    }

};


struct int_cmp {
    static bool cmp(int a, int b) { return a == b; }
};

struct hash_int {
    static int hash(int a) {
        int MOD = 1000000007;
        return (MOD + ((13 * a) % MOD)) % HM_SIZE;
    }
};

int str_len(const char *str) {
    int i = 0;
    while (str[i] != '\0') i++;
    return i;
}

struct hash_str {
    static int hash(const char *s) {
        int h = 0;
        int MOD = 1000000007;
        for (int i = 0; i < str_len(s); i++) {
            h *= 127;
            h += s[i];
        }
        return (MOD + h % MOD) % HM_SIZE;
    }
};

struct str_cmp {
    static bool cmp(const char *s1, const char *s2) {
        int i = 0;
        while (s1[i] != '\0' || s2[i] != '\0') {
            if (s1[i] != s2[i]) return false;
            i++;
        }
        return s1[i] == s2[i];
    }
};

BOOST_AUTO_TEST_CASE(test_strlen) {
    BOOST_CHECK(str_len("1234567") == 7);
    BOOST_CHECK(str_len("") == 0);
    BOOST_CHECK(str_len("1") == 1);
}

BOOST_AUTO_TEST_CASE(test_strcmp) {
    BOOST_CHECK(str_cmp::cmp("", ""));
    BOOST_CHECK(!str_cmp::cmp("1", ""));
    BOOST_CHECK(str_cmp::cmp("hello", "hello"));
    BOOST_CHECK(!str_cmp::cmp("hello", "hello1"));
}

BOOST_AUTO_TEST_CASE(test_int2int_hash_map) {
    hash_map<int, int, hash_int, int_cmp> hm;
    hm.put(1, 2);
    hm.put(2, 4);
    hm.put(3, 6);
    hm.put(4, 2);
    BOOST_CHECK(hm.get(4) == 2);
    BOOST_CHECK(hm.get(2) == 4);
    BOOST_CHECK(hm.get(4) == 2);
    BOOST_CHECK(hm.get(3) == 6);
    BOOST_CHECK(hm.get(1) == 2);
}

BOOST_AUTO_TEST_CASE(test_str2int_hash_map) {
    hash_map<const char *, int, hash_str, str_cmp> hm;
    hm.put("Mike", 1);
    hm.put("Tom", 2);
    hm.put("Gary", 3);
    hm.put("", 4);
    BOOST_CHECK(hm.get("Mike") == 1);
    BOOST_CHECK(hm.get("Gary") == 3);
    BOOST_CHECK(hm.get("Tom") == 2);
    BOOST_CHECK(hm.get("") == 4);
}

BOOST_AUTO_TEST_CASE(test_int2str_hash_map) {
    hash_map<int, const char *, hash_int, int_cmp> hm;
    hm.put(1, "Mike");
    hm.put(2, "Tom");
    hm.put(3, "Gary");
    hm.put(4, "");
    BOOST_CHECK(str_cmp::cmp(hm.get(1), "Mike"));
    BOOST_CHECK(str_cmp::cmp(hm.get(2), "Tom"));
    BOOST_CHECK(str_cmp::cmp(hm.get(3), "Gary"));
    BOOST_CHECK(!str_cmp::cmp(hm.get(4), "Gary"));
}


#endif //ALGORITHMS_AND_DATA_STRUCTURES_CPP_HASH_MAP_H

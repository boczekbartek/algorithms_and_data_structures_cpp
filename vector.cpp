#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Hello

#include <boost/test/unit_test.hpp>
#include <cassert>

template<typename T>
class vector {
private:
    T *buf;
    int buf_size;
    int _size;
    int resize_factor;
public:
    explicit vector(int ini_size = 4, int factor = 2) :
            _size(0),
            buf_size(ini_size),
            resize_factor(factor) {
        buf = new T[buf_size];
    }

    void push_back(const T &elem) {
        if (_size >= buf_size - 1) __grow();
        buf[_size++] = elem;
    }

    T &operator[](int idx) {
        assert(idx < size() && "idx exceeds vector size");
        return buf[idx];
    }

    void pop_back() { _size--; }

    T &back() {
        return buf[_size - 1];
    }

    int size() { return _size; }

    bool empty() { return 0 == size(); }

    void __grow() {
        int new_size = buf_size * resize_factor;
        T *new_buf = new T[new_size];
        for (int i = 0; i < buf_size; i++)
            new_buf[i] = buf[i];
        delete[] buf;
        buf = new_buf;
        buf_size = new_size;
    }
};

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

    BOOST_CHECK(v.empty() == true);
    v.push_back(1);
    BOOST_CHECK(v.empty() == false);
    v.pop_back();
    BOOST_CHECK(v.empty() == true);
}

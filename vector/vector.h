//
// Created by Bartłomiej Boczek on 30/10/2019.
//

#ifndef ALGORITHMS_AND_DATA_STRUCTURES_CPP_VECTOR_H
#define ALGORITHMS_AND_DATA_STRUCTURES_CPP_VECTOR_H

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
            resize_factor(factor){
        buf = new T[buf_size];
    }

    void push_back(const T &elem);

    T &operator[](int idx);

    void pop_back();

    T &back();

    int size();

    bool empty();

    void __grow();
};

#endif //ALGORITHMS_AND_DATA_STRUCTURES_CPP_VECTOR_H

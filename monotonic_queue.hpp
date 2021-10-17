#ifndef monotonic_queue_hpp
#define monotonic_queue_hpp
#include <bits/stdc++.h>
using namespace std;

template <class T>
class monotonic_queue{

public:

    void push(T);
    void pop();
    ///////////////////
    T min();
    T max();
    ///////////////////
    void front();
    size_t size();
    bool empty();

};

template <class T>
class monotonic_stack{

public: 

    void push(T);
    void pop();
    ///////////////////
    T min();
    T max();
    ///////////////////
    void top();
    size_t size();
    bool empty();

};

#endif
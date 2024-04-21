#ifndef LIBRARY_DOUBLENODE_H
#define LIBRARY_DOUBLENODE_H
#include <memory>
using namespace std;
template <typename T>
struct DoubleNode{
    T data;
    shared_ptr<DoubleNode> next;
    weak_ptr<DoubleNode> previous;

    DoubleNode(T obj) : data(obj) {}
};
#endif //LIBRARY_DOUBLENODE_H
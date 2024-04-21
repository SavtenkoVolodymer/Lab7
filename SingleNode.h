#ifndef LIBRARY_SINGLENODE_H
#define LIBRARY_SINGLENODE_H

#include <memory>
using namespace std;
template <typename T>
struct SingleNode {
    T data;
    unique_ptr <SingleNode> next;
    SingleNode(int value) : data{value}, next{nullptr} {};
};



#endif //LIBRARY_SINGLENODE_H
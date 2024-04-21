#ifndef LIBRARY_SINGLYLINKEDLIST_H
#define LIBRARY_SINGLYLINKEDLIST_H

#include "SingleNode.h"
#include <iostream>
using namespace std;
template <typename T>

class SinglyLinkedList {
    unique_ptr<SingleNode<T>>head;
    int size;
    void checkIndex(int index) const {
        if (index < 0 && index >= size) {
            throw std::out_of_range("Index out of range");
        }
    }

public:
    SinglyLinkedList(): head{nullptr},size{0}{};
    SinglyLinkedList(T obj): head{make_unique<SingleNode<T>>(obj)}, size{1}{};

    void InsertAtBeginning( T obj){
        unique_ptr<SingleNode<T>> newNode = make_unique<SingleNode<T>>(obj);
        newNode->next = std::move(head);
        head = std::move(newNode);
        size++;
    };

    void InsertAtEnd(T obj){
        unique_ptr<SingleNode<T>> newNode = make_unique<SingleNode<T>>(obj);
        SingleNode<T> *current = head.get();
        if (!current) {
            head = std::move(newNode);
            size++;
            return;
        }
        while (current->next != nullptr) {
            current = current->next.get();
        }
        current->next = std::move(newNode);
        size++;
    };

    int operator[](int index) const{
        checkIndex(index);
        SingleNode<T> *current = head.get();
        for (int i = 0; i < index; i++) {
            current = current->next.get();
        }
        return current->data;
    };

    void InsertAtIndex( int index, T obj){
        checkIndex(index);
        if (index == 0) {
            T insertAtBeginning(obj);
            return;
        } else if (index == size) {
            T insertAtEnd(obj);
            return;
        } else {
            unique_ptr<SingleNode<T>> newNode = make_unique<SingleNode<T>>(obj);
            SingleNode<T> *current = head.get();
            for (int i = 0; i < index - 1; i++) {
                current = current->next.get();
            }
            newNode->next = std::move(current->next);
            current->next = std::move(newNode);
            size++;
        }

    };

    void removeFromBeginning(){
        if (!head) {
            throw std::out_of_range("List is empty!");
        }
        head = std::move(head->next);
        --size;
    };

    void removeFromEnd(){
        if (!head) {
            throw std::out_of_range("List is empty!");
        }
        if (size == 1) {
            head.reset();
            --size;
            return;
        }else {
            SingleNode<T> *current = head.get();
            while (current->next->next) {
                current = current->next.get();
            }
            current->next.reset();
            --size;
        }
    };

    void removeAtIndex(int index){
        checkIndex(index);
        if (index == 0) {
            removeFromBeginning();
            return;
        } else if (index == size - 1) {
            removeFromEnd();
            return;
        }else {
            SingleNode<T> *current = head.get();
            for (int i = 0; i < index; i++) {
                current = current->next.get();
            }
            current->next = std::move(current->next->next);
            --size;
        }
    };

    bool search(T obj) const{
        SingleNode<T> *current = head.get();
        while (current) {
            if (current->data == obj) {
                return true;
            }
            current = current->next.get();
        }
        return false;
    };

    int getSize() const{
        return size;
    };

    bool isEmpty(){
        if(!head)
            return true;
        else
            return false;
    };

    friend ostream &operator<<(ostream &os, SinglyLinkedList <T> &obj){
        SingleNode<T> *current = obj.head.get();
        while (current != nullptr) {
            os << current->data << " ";
            current = current->next.get();
        }
        return os << endl;
    };

};


#endif //LIBRARY_SINGLYLINKEDLIST_H
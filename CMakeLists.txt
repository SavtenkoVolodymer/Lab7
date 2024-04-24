cmake_minimum_required(VERSION 3.27)
project(Lab7)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab7 main.cpp
        SinglyLinkedList.h
        DoubleLinkedList.h
        SingleNode.h
        DoubleNode.h
        Stack.h
        Queue.h
        QueueArray.h
        StackArray.h
        PriorityQueue.h
        Priornode.h)

#include <iostream>
#include "SinglyLinkedList.h"
#include "DoubleLinkedList.h"
using namespace std;


void Shtrix(){
    cout<<"------------------------\n";
}

void SingleList (){
    SinglyLinkedList <int> A;
    Shtrix();
    if(A.isEmpty())
        cout<<"List is empty"<<endl;
    Shtrix();
    A.InsertAtBeginning(3);
    A.InsertAtBeginning(2);
    A.InsertAtBeginning(1);


    if(!A.isEmpty())
        cout<<"List isn`t empty"<<endl;
    cout<<A;
    Shtrix();
    A.InsertAtEnd(6);
    A.InsertAtEnd(5);
    A.InsertAtEnd(4);

    cout<<A;
    Shtrix();

    A.removeFromEnd();
    A.removeFromBeginning();
    cout<<A;
    Shtrix();

    A.removeAtIndex(1);
    A.InsertAtIndex(1,5);
    cout<<A;
    Shtrix();


    if (A.search(2))
        cout<<"List has 2"<<endl;
    else cout<<"List don`t have 2"<<endl;
    cout<<"Size of list: "<<A.getSize()<<endl;
    cout<<A[3]-A[2]<<endl;
}

void DoubleList(){
    DoubleLinkedList <int> B;
    Shtrix();
    if(B.isEmpty())
        cout<<"List is empty"<<endl;
    Shtrix();
    B.insertAtBeginning(3);
    B.insertAtBeginning(2);
    B.insertAtBeginning(1);


    if(!B.isEmpty())
        cout<<"List isn`t empty"<<endl;
    cout<<B;
    Shtrix();
    B.insertAtEnd(6);
    B.insertAtEnd(5);
    B.insertAtEnd(7);

    cout<<B;
    Shtrix();

    B.removeFromEnd();
    B.removeFromBeginning();
    cout<<B;
    Shtrix();

    B.removeAtIndex(1);
    B.insertAtIndex(1,5);
    cout<<B;
    Shtrix();


    if (B.search(2))
        cout<<"List has 2"<<endl;
    else cout<<"List don`t have 2"<<endl;
    cout<<"Size of list: "<<B.getSize()<<endl;
    cout<<B[3]-B[2]<<endl;
}
#ifndef JOURNEYT_HW5_Q1_MYLIST_H
#define JOURNEYT_HW5_Q1_MYLIST_H

#include "listtoolshb.h"
#include <iostream>

template<class T>
        class Node;


template<class T>
class MyList {
public:
    MyList(); //Constructor
    ~MyList(); //Destructor
    void insertAtHead(const T& data);
    T deleteHead();
    bool search(const T& target);
    void display(Node<T> *pNode);

private:
    Node<T>* head; //Pointer to head node
};

template<class T>
MyList<T>::MyList() : head(nullptr) {}

template<class T>
MyList<T>::~MyList() {
    while (head != nullptr) {
        Node<T>* temp = head;
        head = head->link;
        delete temp;
    }
}

template<class T>
void MyList<T>::insertAtHead(const T& data) {
    headInsert(head, data);
}

template<class T>
T MyList<T>::deleteHead() {
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
    }
    T data = head->data;
    deleteFirstNode(head);
    return data;
}

template<class T>
bool MyList<T>::search(const T& target) {
    return search(head, target) != nullptr;
}

template<class T>
void MyList<T>::display(Node<T> *pNode) {
    display(head);
}

#endif //JOURNEYT_HW5_Q1_MYLIST_H

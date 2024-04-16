#ifndef LISTTOOLSHB_H
#define LISTTOOLSHB_H

template<class T>
class Mylist;

//Node class for list
template<class T>
class Node {
    friend class Mylist<T>;
public:
    Node(const T& initialData, Node<T>* initialLink) {
        data = initialData;
        link = initialLink;
    }
private:
    T data;
    Node<T>* link;
};

//Function declarations
template<class T>
void headInsert(Node<T>*& head, const T& theData);

template<class T>
void display(Node<T>* head);

template<class T>
void insert(Node<T>* afterMe, const T& theData);

template<class T>
void deleteNode(Node<T>* before);

template<class T>
void deleteFirstNode(Node<T>*& head);

template<class T>
Node<T>* search(Node<T>* head, const T& target);

#include "listtoolshb.cpp"

#endif // LISTTOOLSHB_H
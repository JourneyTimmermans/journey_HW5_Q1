#include <iostream>
#include "listtoolshb.h"
using namespace std;

//Inserts node at head
template<class T>
void headInsert(Node<T>*& head, const T& theData) {
    head = new Node<T>(theData, head);
}

//Displays nodes
template<class T>
void display(Node<T>*head) {
    Node<T>*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->getData()<<endl;
        temp = temp->getLink();
    }
}

//inserts node after specific node
template<class T>
void insert(Node<T>* afterMe, const T& theData) {
    afterMe->setLink(new Node<T>(theData, afterMe->getLink( )));
}

//Deletes node after specific node
template<class T>
void deleteNode(Node<T>* before) {
    Node<T> *discard;
    discard = before->getLink( );
    before->setLink(discard->getLink( ));
    delete discard;
}

//Function that deletes first node
template<class T>
void deleteFirstNode(Node<T>*& head) {
    Node<T> *discard;
    discard = head;
    head = head->getLink( );
    delete discard;
}

//Function to search for node
template<class T>
Node<T>* search(Node<T>* head, const T& target) {
    Node<T>* here = head;

    while (here != NULL && here->data !=target) {
        here = here->link;
    }

    return here;
}

template void headInsert(Node<int>*&, const int&);
template void display(Node<int>*);
template void insert(Node<int>*, const int&);
template void deleteNode(Node<int>*);
template void deleteFirstNode(Node<int>*&);
template Node<int>* search(Node<int>*, const int&);
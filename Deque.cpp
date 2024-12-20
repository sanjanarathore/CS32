#ifndef DEQUE_CPP
#define DEQUE_CPP

#include "Deque.h"
#include <string>
#include <sstream>

using namespace std;

namespace cs32 {

// done
template <typename Type>
Deque<Type>::Deque() // :      // TODO: CS 32 Students to complete code here
{
    // TODO: CS 32 Students to complete code here
    head = nullptr;
    tail = nullptr;
}

// done
template <typename Type>
Deque<Type>::Deque( const Deque& rhs ) {
    if (rhs.head == nullptr)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        head = new DequeNode<Type>( rhs.head->getElement() );
        tail = head;
        DequeNode<Type> *q = head;
        DequeNode<Type> *p = rhs.head->getNext();
        while (p != nullptr) {
            q->setNext( new DequeNode<Type>( p->getElement() ) );
            q->getNext()->setNext( nullptr );
            q->getNext()->setPrevious( q );
            tail = q->getNext();
            p = p->getNext();
            q = q->getNext();
        }
    }
}

// done
template <typename Type>
Deque<Type>::~Deque() {
	makeEmpty();
}

// done
template <typename Type>
bool Deque<Type>::isEmpty() const {
    // TODO: CS 32 Students to complete code here
    // return( false );
    return (head == nullptr && tail == nullptr);
}


template <typename Type>
void Deque<Type>::makeEmpty() {
    // TODO: CS 32 Students to complete code here
    while (!isEmpty()) {
        deleteItem( head->getElement( ) );
    }
}

// done
// did not connect it both ways
// forget to setPrevious so would not print correctly
template <typename Type>
void Deque<Type>::addToFront( const Type & data )
{
    // TODO: CS 32 Students to complete code here
    DequeNode<Type>* node = new DequeNode<Type>(data);
    if (isEmpty()) {
        head = node;
        tail = head;
    }
    else {
        node->setNext(head);
        head->setPrevious(node);
        head = node;
    }
}

// done
template <typename Type>
void Deque<Type>::addToRear( const Type & data )
{
    // TODO: CS 32 Students to complete code here
    DequeNode<Type>* node = new DequeNode<Type>(data);
    if (isEmpty()) {
        head = node;
        tail = head;
    }
    else {
        node->setPrevious(tail);
        tail->setNext(node);
        tail = node;
    }
}

template <typename Type>
void Deque<Type>::deleteFront( )
{
    // TODO: CS 32 Students to complete code here
    if (isEmpty()) {
        return;
    } else if (size() == 1){
        DequeNode<Type> * temp = head;
        delete temp;
        head = tail = nullptr;
    } else {
        DequeNode<Type> * temp = head;
        head = head->getNext();
        head->setPrevious(nullptr);
        delete temp;
    }
    
}

template <typename Type>
bool Deque<Type>::deleteItem( const Type & data )
{
    // TODO: CS 32 Students to complete code here
    if (isEmpty()) {
        return false;
    }
    else if (front() == data) {
        deleteFront();
        return true;
    } else if (rear() == data) {
        deleteRear();
        return true;
    } else {
        DequeNode<Type>* temp = head;
        while (temp != nullptr) {
            if (temp->getElement() == data) {
                break;
            }
            temp = temp->getNext();
        }
        if (temp == nullptr) {
            return false;
        }
        DequeNode<Type>* prev = temp->getPrevious();
        DequeNode<Type>* next = temp->getNext();
        prev->setNext(next);
        next->setPrevious(prev);
        delete temp;
        return true;

    }
    
}

// done
template <typename Type>
Type Deque<Type>::front( ) const
{
    Type result = Type();
    // TODO: CS 32 Students to complete code here
    if (head != nullptr) {
        result = head->getElement();
    }
    return( result );
}

// done
template <typename Type>
Type Deque<Type>::rear( ) const
{
    Type result = Type();
    // TODO: CS 32 Students to complete code here
    if (tail != nullptr) {
        result = tail->getElement();
    }
    return( result );
}

template <typename Type>
void Deque<Type>::deleteRear( )
{
    // TODO: CS 32 Students to complete code here
    if (isEmpty()) {
        return;
    } else if (size() == 1) {
        DequeNode<Type> * temp = tail;
        delete temp;
        tail = head = nullptr;
    } else {
        DequeNode<Type> * temp = tail;
        tail = tail->getPrevious();
        tail->setNext(nullptr);
        delete temp;
    }


}

// Howard is supplying code to convert a Type to a string using its operator <<
template <typename Type>
std::string Deque<Type>::to_string( const Type & value ) const
{
    stringstream s;
    // call the Type's operator <<
    s << value;
    return( s.str() );
}


template <typename Type>
std::string Deque<Type>::printItems( ) const
{
    // TODO: CS 32 Students to complete code here
    string s = "";
    DequeNode<Type>* node = head;
    s = s + "forwards:";
    while (node != nullptr) {
        s = s + " ";
        s = s + node->getElement();
        node = node->getNext();
    }
    s += "\n";
    
    node = tail;
    s = s + "backwards:";
    while (node != nullptr) {
        s = s + " ";
        s = s + node->getElement();
        node = node->getPrevious();
    }
    s += "\n";

    return( s );
}


// Deep copy of linked list
template <typename Type>
const Deque<Type> & Deque<Type>::operator =( const Deque<Type> & rhs ) {
    // TODO: CS 32 Students to complete code here
    
    if (this != rhs) {
        makeEmpty();
        
        DequeNode<Type>* node = rhs.head;
        while (node != nullptr) {
            addToRear(node->getElement());
            node = node->getNext();
        }
    }
    
	return( *this );
}

template <typename Type>
size_t Deque<Type>::size() const
{
    size_t result = 0;
    // TODO: CS 32 Students to complete code here
    // include if statement for empty?
    if (isEmpty()) {
        return result;
    }
    DequeNode<Type>* node = head;
    while (node != nullptr) {
        result++;
        node = node->getNext();
    }
    return( result );
}

// done
template <typename Type>
bool   Deque<Type>::get( int i, Type & data ) const
{
    // TODO: CS 32 Students to complete code here
    int index = 0;
    DequeNode<Type> * node = head;
    size_t s = size();
    while( i >= 0 && index < s && node != nullptr )
    {
        if (i == index)
        {
            data = node->getElement();
            return true;
        }
        node = node->getNext();
        index++;
    }
    return false;
}

}


#endif

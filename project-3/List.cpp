#include "List.h"

using namespace std;

namespace cs32 {

List::List() {
	head = nullptr;
}

List::List( const List& rhs ) {
    if (rhs.head == nullptr) head = nullptr;
    else {
        head = new ListNode( rhs.head->getElement() );
        ListNode *q = head;
        ListNode *p = rhs.head->getNext();
        while (p != nullptr) {
            q->setNext( new ListNode( p->getElement() ) );
            q->getNext()->setNext( nullptr );
            p = p->getNext( );
            q = q->getNext( );
        }
    }
}

List::~List() {
	makeEmpty();
}

bool List::isEmpty() const {
	return( head == nullptr );
}

void List::makeEmpty() {
	while (!isEmpty()) {
        deleteItem( head->getElement( ) );
	}
}

void List::addToFront( const std::string & data )
{
    ListNode * newnode = new ListNode( data );
    newnode->setNext( head );
    head = newnode;
}

void List::addToRear( const std::string & data )
{
    if (head == nullptr)
    {
        addToFront( data );
    }
    else
    {
        ListNode * node = head;
        while( node->getNext() != nullptr )
        {
            node = node->getNext();
        }
        ListNode * newnode = new ListNode( data );
        newnode->setNext( nullptr );
        node->setNext( newnode );
    }
}

void List::deleteItem( const std::string & data )
{
    ListNode * node = head;
    ListNode * priornode = nullptr;

        while( node != nullptr )
        {
            if (node->getElement() == data)
            {
                if (priornode != nullptr)
                    priornode->setNext( node->getNext( ) );
                else
                    head = node->getNext();
                delete( node );
                break;
            }
            priornode = node;
            node = node->getNext();
        }
}

bool List::findItem( const std::string & data )
{
    bool result = false;
    ListNode * node = head;
    while( node != nullptr )
    {
        if (node->getElement() == data)
        {
            result = true;
            break;
        }
        node = node->getNext();
    }
    return( result );
}

std::string List::printItems( )
{
    string s = "";
    if (isEmpty())
    {
        s += "---> empty list";
    }
    else
    {
        s += "head:";
        ListNode * node = head;
        while( node != nullptr )
        {
            s += " -> ";
            s += node->getElement();
            node = node->getNext();
        }
        s += " -> nullptr ";
    }
    return( s );
}

size_t List::size() const {
    size_t size = 0;
    if (isEmpty()) {
        return size;;
    } else {
        ListNode * node = head;
        while(node != nullptr) {
            size++;
            node = node->getNext();
        }
    }
    return size;
}

int List::position( const std::string& data ) const {
    int index = 0;
    ListNode * node = head;
    while( node != nullptr )
    {
        if (node->getElement() == data)
        {
            return index;
        }
        node = node->getNext();
        index++;
    }
    return -1;

}

bool List::before( const std::string& before, const std::string& after ) const {
    int indexBefore = position(before);
    int indexAfter = position(after);
    if (indexBefore == -1 || indexAfter == -1 || indexBefore >= indexAfter) {
        return false;
    }
    return true;
}

bool List::get( int i, std::string& data ) const {
    int index = 0;
    ListNode * node = head;
    size_t s = size();
    while( index < s && node != nullptr )
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

std::string List::min( ) const {
    if (isEmpty()) {
        return "";
    }
    ListNode * node = head;
    string min = node->getElement();
    while(node != nullptr )
    {
        if (node->getElement() < min) {
            min = node->getElement();
        }
        node = node->getNext();
    }
    return min;
}

// was terminating after removing one element that was greater
// had to rest node to head to start iteration from the beginning
// bc the next node might be shifted forward and you might accidentally skip over some nodes
// ensure you check all elements including the ones that may have shifted forward after deletion
void List::removeAllBiggerThan( const std::string& data ) {
    //cout << "remove bigger: " << endl;
    ListNode * node = head;
    while(node != nullptr )
    {
        if (node->getElement() > data) {
            //cout << "greater: " << node->getElement() << endl;
            deleteItem(node->getElement());
            node = head;
        }
        else
        {
            node = node->getNext();
        }
    }
}

// Deep copy of linked list
const List& List::operator =( const List& rhs ) {
	if (this != &rhs) {
		makeEmpty();

        ListNode * right = rhs.head;

		while( right != nullptr )
        {
            addToRear( right->getElement() );
            right = right->getNext();
		}
	}

	return( *this );
}

}



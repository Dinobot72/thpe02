#include "stringTracker.h"

// StringTracker::StringTracker()
// {
//     head = nullptr;
// }

// StringTracker::~StringTracker()
// {
//     cout << "Hello";
// }

// bool StringTracker::empty() const
// {
//     return head == nullptr;
// }


bool StringTracker::addString( const string& str )
{
    Node* current = head;
    Node* previous = nullptr;

    while ( current != nullptr && current->value < str )
    {
        previous = current;
        current = current->next;
    }

    while ( current != nullptr && current->value == str )
    {
        return true;
    }

    Node* newNode = new (nothrow) Node;
    if ( newNode == nullptr )
    {
        return false;
    }

    newNode->value = str;
    newNode->count = 1;
    newNode->next = current;

    if (previous == nullptr) {
        head = newNode;
    } else {
        previous->next = newNode;
    }
    return true;
}

void StringTracker::print( ostream& out ) const
{
    Node *temp;
    temp = this->head;
    while( temp != nullptr )
    {
        out << temp->value << " (" << temp->count << ")";
        temp = temp->next;
    }
}

bool StringTracker::removeString( const string& str )
{
    string i = str;
    return true;

}

bool StringTracker::findString( const string str ) const
{
    Node *temp;
    temp = this->head;
    while( temp != nullptr )
    {
        if( temp->value == str )
            return true;

        temp = temp->next;
    }

    return false;
}

bool StringTracker::incrementCount( const string str )
{
    Node* current = head;

    while ( current != nullptr )
    {
        if (current->value == str) {
            current->count++;
            return true;
        }
        current = current->next;
    }
    return false;
}

bool StringTracker::decrementCount( const string str )
{
    Node* current = head;

    while ( current != nullptr )
    {
        if (current->value == str) {
            current->count--;
            return true;
        }
        current = current->next;
    }
    return false;
}

int StringTracker::getCount( const string str ) const
{
    Node* current = head;
    int tempCount;

    while ( current != nullptr )
    {
        if (current->value == str) {
            tempCount = current->count;
            return tempCount;
        }
        current = current->next;
    }
    return 0;

}
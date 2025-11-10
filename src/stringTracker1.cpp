#include "stringTracker.h"

bool StringTracker::addString( const string& str )
{
    Node* current = head;
    Node* previous = nullptr;

    // traverse through the list until 
    while ( current != nullptr && current->value < str )
    {
        previous = current;
        current = current->next;
    }

    while ( current != nullptr && current->value == str )
    {
        if (current->value == str) {
            current->count++;
            return true;
        }
    }

    // Create a new node
    Node* newNode = new (nothrow) Node;
    
    // Check for new node creation failure
    if ( newNode == nullptr )
    {
        return false;
    }

    // assing new node variables
    newNode->value = str;
    newNode->count = 1;
    newNode->next = current;

    // if list is empty new node is head assign to head
    if (previous == nullptr) {
        head = newNode;
    } else { // if list is not empty then 
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
        if ( temp->next != nullptr )
        {
            out << ",";
        }
        temp = temp->next;
    }
}

bool StringTracker::removeString( const string& str )
{
    Node* current = head;
    Node* previous = nullptr;

    // Find the node to remove
    while (current != nullptr && current->value != str)
    {
        previous = current;
        current = current->next;
    }

    // If the string was not found
    if (current == nullptr)
    {
        return false;
    }

    // If the node to remove is the head
    if (previous == nullptr)
    {
        head = current->next;
    }
    else // If the node to remove is not the head
    {
        previous->next = current->next;
    }

    // Delete the node
    delete current;
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
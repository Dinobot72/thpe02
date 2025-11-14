#include "stringTracker.h"

bool StringTracker::addString( const string& str )
{
    Node* current = head;
    Node* previous = nullptr;

    // traverse through the list until value is greater than string and list is null
    while ( current != nullptr && current->value < str )
    {
        previous = current;
        current = current->next;
    }

    // if the string already exists, increment its count and return
    if ( current != nullptr && current->value == str )
    {
        return true;
    }

    // Create a new node
    Node* newNode = new ( nothrow ) Node;
    
    // Check for new node creation failure
    if ( newNode == nullptr )
    {
        return false;
    }

    // assing new node variables
    newNode->value = str;
    newNode->count = 1;
    newNode->next = current;

    // if list is empty or inserting at the beginning, new node is head
    if ( previous == nullptr )
    {
        head = newNode;
    } 
    else { // if list is not empty then 
        previous->next = newNode;
    }
    return true;
}

void StringTracker::print( ostream& out ) const
{
    // create temporary node to traverse array
    Node *temp;
    temp = this->head;

    // until the array is empty
    while( temp != nullptr )
    {
        // print node
        out << temp->value << " (" << temp->count << ")";

        // if node is not the end then add coma
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
    while ( current != nullptr && current->value != str )
    {
        previous = current;
        current = current->next;
    }

    // If the string was not found
    if ( current == nullptr )
    {
        return false;
    }

    // If the node to remove is the head
    if ( previous == nullptr )
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
    // create temporary node to traverse array
    Node *temp;
    temp = this->head;

    // traverse until the node is empty
    while( temp != nullptr )
    {
        // check if nodes value is the string we are looking for and retrun true
        if( temp->value == str )
            return true;

        temp = temp->next;
    }

    // if string is not found, return false
    return false;
}

bool StringTracker::incrementCount( const string str )
{
    Node* current = head;

    // traverse until the node is empty 
    while ( current != nullptr )
    {
        // check if nodes value is the string we are looking for
        // increment conut and retrun true
        if ( current->value == str )
        {
            current->count++;
            return true;
        }
        current = current->next;
    }
    // if string is not found, return false
    return false;
}

bool StringTracker::decrementCount( const string str )
{
    Node* current = head;

    // traverse until the node is empty
    while ( current != nullptr )
    {
        // check if nodes value is the string we are looking for
        // decrement conut and retrun true
        if ( current->value == str )
        {
            current->count--;
            return true;
        }
        current = current->next;
    }

    // if string is not found, return false
    return false;
}

int StringTracker::getCount( const string str ) const
{
    Node* current = head;
    int tempCount;

    // traverse until the node is empty
    while ( current != nullptr )
    {
        // check if nodes value is the string we are looking for
        // get the conut and retrun the count
        if ( current->value == str )
        {
            tempCount = current->count;
            return tempCount;
        }
        current = current->next;
    }

    // if no count is found return 0
    return 0;

}
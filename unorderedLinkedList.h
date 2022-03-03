#ifndef H_UnorderedLinkedList
#define H_UnorderedLinkedList

//***********************************************************
// Author: D.S. Malik
//
// This class specifies the members to implement the basic
// properties of an unordered linked list. This class is
// derived from the class linkedListType.
//***********************************************************

#include "linkedList.h"

using namespace std;

template <class Type>
class unorderedLinkedList : public linkedListType<Type>
{
public:
    bool search(const Type& searchItem) const;
    //Function to determine whether searchItem is in the list.
    //Postcondition: Returns true if searchItem is in the list,
    //    otherwise the value false is returned.

    void insertFirst(const Type& newItem);
    //Function to insert newItem at the beginning of the list.
    //Postcondition: first points to the new list, newItem is
    //    inserted at the beginning of the list, last points to
    //    the last node, and count is incremented by 1.
    //

    void insertLast(const Type& newItem);
    //Function to insert newItem at the end of the list.
    //Postcondition: first points to the new list, newItem is
    //    inserted at the end of the list, last points to the
    //    last node, and count is incremented by 1.

    void deleteNode(const Type& deleteItem);
    //Function to delete deleteItem from the list.
    //Postcondition: If found, the node containing deleteItem
    //    is deleted from the list. first points to the first
    //    node, last points to the last node of the updated
    //    list, and count is decremented by 1.


    
};


template <class Type>
bool unorderedLinkedList<Type>::search(const Type& searchItem) const
{
    nodeType<Type>* current; //pointer to traverse the list
    bool found = false;

    current = this->first; //set current to point to the first
                     //node in the list

    while (current != NULL && !found)    //search the list
        if (current->info == searchItem) //searchItem is found
            found = true;
        else
            current = current->link; //make current point to
                                     //the next node
    return found;
}//end search

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    nodeType<Type>* newNode; //pointer to create the new node

    newNode = new nodeType<Type>; //create the new node

    newNode->info = newItem;    //store the new item in the node
    newNode->link = this->first;      //insert newNode before first
    this->first = newNode;            //make first point to the
                                //actual first node
    this->count++;                    //increment count

    if (this->last == NULL)   //if the list was empty, newNode is also
                        //the last node in the list
        this->last = newNode;
}//end insertFirst

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem)
{
    nodeType<Type>* newNode; //pointer to create the new node

    newNode = new nodeType<Type>; //create the new node

    newNode->info = newItem;  //store the new item in the node
    newNode->link = NULL;     //set the link field of newNode
                              //to NULL

    if (this->first == NULL)  //if the list is empty, newNode is
                        //both the first and last node
    {
        this->first = newNode;
        this->last = newNode;
        this->count++;        //increment count
    }
    else    //the list is not empty, insert newNode after last
    {
        this->last->link = newNode; //insert newNode after last
        this->last = newNode; //make last point to the actual
                        //last node in the list
        this->count++;        //increment count
    }
}//end insertLast


template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type>* current; //pointer to traverse the list
    nodeType<Type>* trailCurrent; //pointer just before current
    bool found;

    if (this->first == NULL)    //Case 1; the list is empty.
        cout << "Cannot delete from an empty list."
        << endl;
    else
    {
        if (this->first->info == deleteItem) //Case 2
        {
            current = this->first;
            this->first = this->first->link;
            this->count--;
            if (this->first == NULL)    //the list has only one node
                this->last = NULL;
            delete current;
        }
        else //search the list for the node with the given info
        {
            found = false;
            trailCurrent = this->first;  //set trailCurrent to point
                                   //to the first node
            current = this->first->link; //set current to point to
                                   //the second node

            while (current != NULL && !found)
            {
                if (current->info != deleteItem)
                {
                    trailCurrent = current;
                    current = current->link;
                }
                else
                    found = true;
            }//end while

            if (found) //Case 3; if found, delete the node
            {
                trailCurrent->link = current->link;
                this->count--;

                if (this->last == current)   //node to be deleted
                                       //was the last node
                    this->last = trailCurrent; //update the value
                                         //of last
                delete current;  //delete the node from the list
            }
            else
                cout << "The item to be deleted is not in "
                << "the list." << endl;
        }//end else
    }//end else
}//end deleteNode

template <class Type>
Type linkedListType<Type>::FindHighest()
{
    nodeType<Type>* current;
    current = first;
    Type hold = current->info; //Will hold the highest value in the list as it continuously traverses the list
    current = current->link; //To proceed on the next element for comparison

    while (current != NULL)
    {
        if (hold <= current->info)
            hold = current->info; //continuously finds the highest value as it traverses the list
        current = current->link;
    }

    return hold;
}

template <class Type>
void linkedListType<Type>::DeleteSmallestInfo()
{
    nodeType<Type>* current; //pointer to traverse the list
    nodeType<Type>* nextCurrent = nullptr; //pointer after the current, for comparison
    nodeType<Type>* trailCurrent = 0; //pointer before the current
    int counter = 0;
    current = first;
    nextCurrent = current;
    nextCurrent = nextCurrent->link;
    if (this->first == NULL)
    {
        cout << "The smallest item cannot be deleted for the list is empty.";
    }
    else if (this->first->link == NULL)
    {
        this->first = NULL;
        delete this->last;
        this->last = NULL;
    }
    else
    {
        while (nextCurrent != NULL)
        {
            if (current->info >= nextCurrent->info)
            {
                counter++;
                for (int i = 0; i < counter; i++)
                {
                    trailCurrent = current;
                    current = current->link;
                }
                counter = 0;
            }
            else
                counter++;
            nextCurrent = nextCurrent->link;
        }

        if (this->first == current)       //Case 2
        {
            this->first = this->first->link;
        }
        else                         //Case 3
        {
            trailCurrent->link = current->link;

            if (current == this->last)
                this->last = trailCurrent;
        }
    }
    delete current;
    this->count--;
}

template <class Type>
int linkedListType<Type>::FrequencyChecker(Type element)
{
    nodeType<Type>* current;
    int frequency = 0;
    current = first;

    if (this->first == NULL)
        cout << "Cannot count the frequency from an empty list.";
    else
    while (current != NULL)
    {
        if (current->info == element)
            frequency++;
        current = current->link;
    }


    return frequency;
}

#endif
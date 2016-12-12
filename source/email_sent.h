/*
 Name: Joel Graham 
 Course: CS 163
 Programming Assignment #2

 File: email_sent.h

 Purpose: This file declares the class "email_sent". This class handles initialization of the flexible array / stack ADT (constructor), creating nodes
 (in-struct function), storing the data into an array component (push), removing elements (pop), displaying the data in a particular element (peek),
 destroying the linked list (deconstructor) and a function that checks to see if the stack is empty (empty_stack).

 This file also declares the struct "stack_node". This struct is used to build the flexible array and store the data provided in the
 "email_item" class into an array inside the node (see email_item.h). It uses an in-declaration function to allocate an array of email_item
 objects and has an email_item pointer to point to the new array memory location. A standard next pointer is used in order to point to additional
 nodes in the linked list as needed. There is one external pointer and an int named "index" to track the number of elements being added to the array. */

#ifndef EMAIL_SENT_H
#define EMAIL_SENT_H

#include "email_item.h"
#include <iostream>

using namespace std;

const int ARRAY_SIZE = 10; //Used to set the size of the array when a new node is created

class email_sent
{
public:
    //Constructor
	email_sent();

	//Destructor
    ~email_sent();

	bool empty_stack(); //Checks to see if the stack is empty
    void push(const email_item& a_email); //Adds an email to the stack
    void pop(); //Removes the most recent element from the stack
    bool peek(email_item& newest_sent); //Gets the most recent item added to the stack, providing the data back to main via the passed in object.
    void display(); //Displays all items currently on the stack.


private:

    struct stack_node
    {
        email_item * sent_data;
        stack_node * next;

        stack_node()
        {
            sent_data = new email_item[ARRAY_SIZE];
            next = NULL;
        }
    };

    int index;
    stack_node * head;
};
#endif

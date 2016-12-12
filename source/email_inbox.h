/*
 Name: Joel Graham 
 Course: CS 163
 Programming Assignment #2

 File: email_inbox.h

 Purpose: This file declares the class "email_inbox". This class handles initialization of the queue (constructor), storing the data
 into individual nodes (enqueue + in-struct function), deleting nodes (dequeue), displaying the data in a particular node (peek),
 destroying the linked list (deconstructor + dequeue) and a function that checks to see if the queue is empty (empty_queue).

 This file also declares the struct "queue_node". This struct is used to build the circular linked list and store the data provided in the
 "email_item" class into each node (see email_item.h). It uses an in-declaration function to grab the data out of the passed
 in object "a_email" and set it to the corresponding data object "inbox_data" for each new node. This allows the program to build
 a node based upon each incoming email from the user. Since it is a circular linked list, there is only one external pointer
 "queue_pointer" that is tracking the end of the queue. The next pointer in each node is set to the first node after every add so that
 queue_pointer->next will always point to the first item in the queue (see enqueue function).
 */

#ifndef EMAIL_INBOX_H
#define EMAIL_INBOX_H

#include "email_item.h"
#include <iostream>

using namespace std;


class email_inbox
{
public:
    //Constructor
	email_inbox();

	//Destructor
	~email_inbox();

	bool empty_queue(); //Checks to see if the queue is empty.
    void enqueue(const email_item& a_email); //Adds an email to the circular linked list.
    void dequeue(); //Removes first email in the queue
    bool peek(email_item& front); //Gets the first email in the queue, providing the data back to main via the passed in object.

private:

    struct queue_node
    {
        email_item inbox_data;
        queue_node * next;

        queue_node(const email_item& a_email)
        {
            char address[SMALL_CHAR];
            char name[SMALL_CHAR];
            char subject[SMALL_CHAR];
            char message[MAX_CHAR];

            a_email.get_address(address);
            a_email.get_name(name);
            a_email.get_subject(subject);
            a_email.get_message(message);

            inbox_data.set_address(address);
            inbox_data.set_name(name);
            inbox_data.set_subject(subject);
            inbox_data.set_message(message);
        }

    };

    queue_node * queue_ptr;
};
#endif

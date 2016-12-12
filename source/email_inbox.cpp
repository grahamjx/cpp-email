/*
 Name: Joel Graham 
 Course: CS 163
 Programming Assignment #2

 File: email_inbox.cpp

 Purpose: This file contains the function definitions for the class "email_inbox" found in "email_inbox.h".
 These functions are used to carry out proccess that deal with the circular linked list / queue ADT.
 Creating and destroying the list, creating nodes, deleting nodes, extracting data from the first node and
 checking to see if the queue is empty are some of the operations carried out by this file.

 Input:   This file utilizes input provided from main function as entered by the user as well as from the "email_item"
 class which supplies the data for each individual node.

 Output:  Displays a limited amount of information found in each node out to the user (main function).
 */

#include "email_inbox.h"
#include <iostream>

using namespace std;

//Sets the node pointer in the private section to null
email_inbox::email_inbox()
{
    queue_ptr = NULL;
}


/*Destroys the circular linked list by using a while loop. If the queue is not empty, it calls the dequeue function which deletes
the first node in the queue until the queue is empty.*/

email_inbox::~email_inbox()
{
	while (!empty_queue())
    {
        dequeue();
    }
}


//Checks to see if the queue is empty
bool email_inbox::empty_queue()
{
    return queue_ptr == NULL;
}


/* Takes in "a_email" which was passed by reference from the compose_email function in main(). A new pointer variable is
 created that will pass the object into the queue_node function depending on what value the private member variables
 are currently set to. If the queue is empty (queue_ptr == NULL), then the queue_ptr will point to a new node which is
 constructed with the a_email object that was passed in. The next pointer for that node is then set to queue_ptr
 so that the list becomes circular and that the first node can always be reached by using queue_ptr->next. If the queue is
 not empty,it will store the first node in temp, create a newnode at the beginning of the list, set the queue_ptr to the newnode
 and then set the next pointer back to the original first node stored in temp. This is done so that the first email that enters the queue
 is always in the first node position (First in, First out). */

void email_inbox::enqueue(const email_item& a_email)
{
    queue_node * new_node = new queue_node(a_email);
    queue_node * temp;

    if (empty_queue())
    {
        queue_ptr = new_node;
        queue_ptr->next = queue_ptr;
    }
    else
    {
        temp = queue_ptr->next;
        queue_ptr->next = new_node;
        queue_ptr = queue_ptr->next;
        queue_ptr->next = temp;
    }
}


/*If there is only one item in the queue, queue_ptr->next == queue_ptr, then it deletes the last remaining item. If there is more than
 one item in the queue, it stores the second node into temp before deleting the first node and setting temp as the new first node. The
 function does not check for an empty queue in this case becuase it is only called after that condition is check in both the main() function
 and in the deconstructor. */

void email_inbox::dequeue()
{
    queue_node * temp;

    if (queue_ptr->next == queue_ptr)
    {
        delete queue_ptr;
        queue_ptr = NULL;
    }
    else
    {
        temp = queue_ptr->next->next;
        delete queue_ptr->next;
        queue_ptr->next = temp;
    }
}


/*Function takes in a email_item object passed in from the display_inbox function in main. If the queue is empty, it returns a false value back
 to the display_inbox function. If the queue is not empty, it grabs the data out of the first node (queue_ptr->next) and sets that data to
 the passed in object and returns true. This is done so the user is able to see the first item in the queue.
 */
bool email_inbox::peek(email_item& first_email)
{
    char address[MAX_CHAR];
    char name[SMALL_CHAR];
    char subject[SMALL_CHAR];
    char message[MAX_CHAR];

    if (empty_queue())
    {
        return false;
    }
    else
    {
        queue_node * front = queue_ptr->next;

        front->inbox_data.get_address(address);
        front->inbox_data.get_name(name);
        front->inbox_data.get_subject(subject);
        front->inbox_data.get_message(message);

        first_email.set_address(address);
        first_email.set_name(name);
        first_email.set_subject(subject);
        first_email.set_message(message);

        return true;
    }
}

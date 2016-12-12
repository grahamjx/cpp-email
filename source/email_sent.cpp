/*
 Name: Joel Graham 
 Course: CS 163
 Programming Assignment #2

 File: email_sent.cpp

 Purpose: This file contains the function definitions for the class "email_sent" found in "email_sent.h".
 These functions are used to carry out proccess that deal with the flexible array / stack ADT. Creating and
 destroying the list, creating nodes, storing data in array elements, deleting array elements, deleting nodes,
 extracting data from array elements and checking to see if the stack is empty are some of the operations carried out by this file.

 Input:   This file utilizes input provided from main function as entered by the user as well as from the "email_item"
 class which supplies the data for each array component.

 Output:  Displays a limited amount of information found in each node out to the user (main function).
 */

#include "email_sent.h"
#include <iostream>

using namespace std;

//Sets the node pointer in the private section to null
email_sent::email_sent()
{
    head = NULL;
}


//Destroys the flexible array by setting current to head and then deleting each node until head is equal to null
email_sent::~email_sent()
{
	stack_node * current = head;
	while(current)
	{
		head = current->next;
		delete current;
		current = head;
	}
}


//Checks to see if the stack is empty
bool email_sent::empty_stack()
{
    return head == NULL;
}


/* Takes in "a_email" which was passed by reference from the compose_email function in main(). It first "gets" the data inside the passed
 in object and sets it to the corresponding local variables. For this implementation, it fills the arrays in reverse order starting from the last
 component [9] and working forward. The position it puts the data is determined by the index which is set to the (ARRAY_SIZE - 1) since array of 10
 elements would have a final position of 9 because arrays components are numbered starting from zero. If the stack is empty (head == NULL), then head
 will point to a new node and the information stored in the local variables will be stored to the [9] location within the array. If the stack is not empty,
 it will store the information in the next corresponding location , [8 ...] and so on since index is decremented everytime the function is called. Once the 10th element
 of the array is saved to position [0] then index will equal -1. On the next call for the function it will then create a new node, place it before the existing head node,
 set the index back to (ARRAY_SIZE -1) and repeat the process. This is done so that the most recent added items are always stored in the head node and that the first element of
 the array contains the most recent email (Last in, First out) */

void email_sent::push(const email_item &a_email)
{
    char address[SMALL_CHAR];
    char name[SMALL_CHAR];
    char subject[SMALL_CHAR];
    char message[MAX_CHAR];

    a_email.get_address(address);
    a_email.get_name(name);
    a_email.get_subject(subject);
    a_email.get_message(message);

    stack_node * new_node = new stack_node();

    if (empty_stack())
    {
        index = (ARRAY_SIZE - 1);
        head = new_node;

        head->sent_data[index].set_address(address);
        head->sent_data[index].set_name(name);
        head->sent_data[index].set_subject(subject);
        head->sent_data[index].set_message(message);

    }
    else
    {
        if (index < 0)
        {
            index = (ARRAY_SIZE - 1);
            new_node->next = head;
            head = new_node;

            head->sent_data[index].set_address(address);
            head->sent_data[index].set_name(name);
            head->sent_data[index].set_subject(subject);
            head->sent_data[index].set_message(message);

        }
        else
        {
            head->sent_data[index].set_address(address);
            head->sent_data[index].set_name(name);
            head->sent_data[index].set_subject(subject);
            head->sent_data[index].set_message(message);

        }
    }
    index--;
}


//This function is used for removing the most recent item added to the stack.
void email_sent::pop()
{
    index++;
}


/* Function takes in a email_item object passed in from the display_sent function in main. If the stack is empty or the index value is outside
 of the array boundary, it returns a false value back to the display_sent function. If the index is ever equal to the (ARRAY_SIZE - 1) when this
 function is called it checks to see if there is another node in the list. If not, then the list is empty and returns false. If there is another
 node then it resets the index to -1 (index+1 will be the first element in the new array) and changes the head pointer to point to the next node.
 That way when the pop function is used, it will be able to remove from the proper position in the new array. If neither of those conditions are met,
 then it gets the most recent data out of the array and sets it to the passed in object 'newest_sent' and returns true */

bool email_sent::peek(email_item& newest_sent)
{
    char address[MAX_CHAR];
    char name[SMALL_CHAR];
    char subject[SMALL_CHAR];
    char message[MAX_CHAR];
    stack_node * current = head;

    if (empty_stack() || index >= ARRAY_SIZE)
    {
        return false;
    }
    else if (index == (ARRAY_SIZE -1))
    {
        if (head->next == NULL)
            return false;
        index = -1;
        current = current->next;
        head = current;
    }
        current->sent_data[index+1].get_address(address);
        current->sent_data[index+1].get_name(name);
        current->sent_data[index+1].get_subject(subject);
        current->sent_data[index+1].get_message(message);

        newest_sent.set_address(address);
        newest_sent.set_name(name);
        newest_sent.set_subject(subject);
        newest_sent.set_message(message);

        return true;
}

/* This function displays all the elements on the stack. First it displays the elements in the head node starting with the most recent.
 Once a newnode has been added (current->next != NULL) then it will display the current elements in the head node in most recent order
 before displaying all the elements in the old node. This is all done by using for loops to get the data out of each component in the
 array, storing it locally and then displaying it out to the user. */

void email_sent::display()
{

    char address[MAX_CHAR];
    char name[SMALL_CHAR];
    char subject[SMALL_CHAR];
    char message[MAX_CHAR];
    stack_node * current = head;

    for(int i = (index+1); i < ARRAY_SIZE; i++)
    {
        head->sent_data[i].get_address(address);
        head->sent_data[i].get_name(name);
        head->sent_data[i].get_subject(subject);
        head->sent_data[i].get_message(message);

        cout <<"\nEmail Address: " << address
        << "\nName: " << name
        << "\nSubject: " << subject
        << "\nMessage: " << message << endl;

    }

    if (head->next != NULL)
    {
        current = current->next;

        for(int i = 0; i <= (ARRAY_SIZE -1) ; i++)
        {
            current->sent_data[i].get_address(address);
            current->sent_data[i].get_name(name);
            current->sent_data[i].get_subject(subject);
            current->sent_data[i].get_message(message);

            cout <<"\nEmail Address: " << address
            << "\nName: " << name
            << "\nSubject: " << subject
            << "\nMessage: " << message << endl;

        }
    }
}

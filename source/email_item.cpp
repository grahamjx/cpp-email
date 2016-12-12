/*
 Name: Joel Graham 
 Course: CS 163
 Programming Assignment #2

 File: email_item.cpp

 Purpose: This file contains the function definitions for the class "email_item" found in "email_item.h".
 These functions are used to carry out proccess that deal wth dynamically allocating memory for each
 member variable as well as functions to "get" and "set" the data which the member variables point to.

 Input: Since the member variables are private, "set" functions are used to set the data that the member variables
 are pointing to. This file utilizes input provided from the main() function compose_email. Functions from email_inbox
 including enqueue and get_front, utlize this class to set the data for storage in the queue as well as grab data out of
 objects in order to display the contents to the user. Functions from email_sent including push, pop, peek and display, utilize this class
 to set the data for storage on the stack and well as grab data out of objects in order to display the contents to the user.

 Output:  Member variables are private thus their access is limited to "getting" them out and setting them to some local variable
 where the "get" function is called from.
 */

#include "email_item.h"
#include <cstring> //Included to allow the use of strcpy, strlen in member functions. Also was required for Unix g++ compile.

//Points the member variables to a new memory location on construction of an object
email_item::email_item(void)
{
	address = new char[NULL];
    name = new char[NULL];
    subject = new char[NULL];
	message = new char[NULL];
}


//Deallocates memory for each member variable.
email_item::~email_item()
{
	if(address)
		delete [] address;
	if(name)
		delete [] name;
    if(subject)
        delete [] subject;
    if(message)
        delete [] message;
}


//The passed in reference argument out_address is assigned the value pointed to by the member variable "address"
void email_item::get_address(char out_address[]) const
{
	strcpy(out_address, address);
}


//The passed in reference argument out_name is assigned the value pointed to by the member variable "name"
void email_item::get_name(char out_name[]) const
{
	strcpy(out_name, name);
}


//The passed in reference argument out_subject is assigned the value pointed to by the member variable "subject"
void email_item::get_subject(char out_subject[]) const
{
	strcpy(out_subject, subject);
}


//The passed in reference argument out_message is assigned the value pointed to by the member variable "message"
void email_item::get_message(char out_message[]) const
{
	strcpy(out_message, message);
}


/* This function checks to see if member variable "address" is null, deallocating that memory if it is not.
 It then points "address" to a new char memory location with an array size exaclty as large as it need to be in
 order to hold the address. Using strlen, it measures the length of the character array in_address being passed
 in and sets the new memory location to that value + 1 to accomodate the null character. Then the in_address
 is copied in to the new memory location that "address" points to. */

void email_item::set_address(const char in_address[])
{
	if(address!=NULL)
		delete [] address;
	this->address = new char[strlen(in_address)+1];
	strcpy(address, in_address);
}


/* This function checks to see if member variable "name" is null, deallocating that memory if it is not.
 It then points "name" to a new char memory location with an array size exaclty as large as it need to be in
 order to hold the name. Using strlen, it measures the length of the character array in_name being passed
 in and sets the new memory location to that value + 1 to accomodate the null character. Then the in_name
 is copied in to the new memory location that "name" points to. */

void email_item::set_name(const char in_name[])
{
	if(name!=NULL)
		delete [] name;
	this->name = new char[strlen(in_name)+1];
	strcpy(name, in_name);
}


/* This function checks to see if member variable "subject" is null, deallocating that memory if it is not.
 It then points "subject" to a new char memory location with an array size exaclty as large as it need to be in
 order to hold the subject. Using strlen, it measures the length of the character array in_subject being passed
 in and sets the new memory location to that value + 1 to accomodate the null character. Then the in_subject
 is copied in to the new memory location that "subject" points to. */

void email_item::set_subject(const char in_subject[])
{
	if(subject!=NULL)
		delete [] subject;
	this->subject = new char[strlen(in_subject)+1];
	strcpy(subject, in_subject);
}


/* This function checks to see if member variable "message" is null, deallocating that memory if it is not.
 It then points "message" to a new char memory location with an array size exaclty as large as it need to be in
 order to hold the message. Using strlen, it measures the length of the character array in_message being passed
 in and sets the new memory location to that value + 1 to accomodate the null character. Then the in_message
 is copied in to the new memory location that "message" points to. */

void email_item::set_message(const char in_message[])
{
	if(message!=NULL)
		delete [] message;
	this->message = new char[strlen(in_message)+1];
	strcpy(message, in_message);
}

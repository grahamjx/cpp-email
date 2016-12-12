/*
 Name: Joel Graham 
 Course: CS 163
 Programming Assignment #2

 File: email_item.h

 Purpose: This file declares the class "email_item". This class handles the construction of the data that is used in both the email_inbox (queue) and
 email_sent (stack) classes. Since the data members are private, the public member functions of the class are made of up the constructor and destructor as
 well as four functions that "get" the data pointed to by the private member variables and four functions that "set" the data pointed to
 by the private member variables.
 */

#ifndef EMAIL_ITEM_H
#define EMAIL_ITEM_H

const int SMALL_CHAR = 41; //Used on local variables found in multiple functions. This is merely to hold information coming out of the email_item data class.
const int MAX_CHAR = 501; //Used on local variables found in multiple functions. This is merely to hold information coming out of the email_item data class.

class email_item
{
public:
	//Constructor
	email_item(void);

	//Destructor
    ~email_item(void);

	void get_address(char out_address[]) const; //Gets the 'address' pointed to by the private member variable "address" and assigns it to the passed in char array.
    void get_name(char out_name[]) const; //Gets the name pointed to by the private member variable "name" and assigns it to the passed in char array.
    void get_subject(char out_subject[]) const; //Gets the subject pointed to by the private member variable "subject" and assigns it to the passed in char array.
    void get_message(char out_message[]) const; //Gets the message pointed to by the private member variable "message" and assigns it to the passed in char array.

	void set_address(const char in_address[]); //Sets the private member variable "address" to the char array passed into the function.
	void set_name(const char in_name[]); //Sets the private member variable "name" to the char array passed into the function.
    void set_subject(const char in_subject[]); //Sets the private member variable "subject" to the char array passed into the function.
    void set_message(const char in_message[]); //Sets the private member variable "message" to the char array passed into the function.

private:
    char*  address;
	char*  name;
	char*  subject;
    char*  message;
};
#endif

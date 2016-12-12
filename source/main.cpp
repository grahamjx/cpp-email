/*
 Name: Joel Graham 
 Course: CS 163
 Programming Assignment #2

 File: main.cpp

 Purpose: This program creates a simulated email application with a Inbox and Sent Items folder. Each composed email will be passed into
 the corresponding ADT which handles storage and manipulation of the data. Each email will be sent to the email_inbox
 class which is setup as a queue, storing each email item in a circular linkedlist with the oldest composed email being represented
 first. Ever email will also be sent to the emai_sent class which is setup as a stack, storing each email item in a linkedlist
 where each node contains an array of emails. The user has the option to create an email, check and remove
 items in their inbox as well as view and remove sent items.

 Input: When executing this program, both a_queue (email_inbox) and a_stack (email_sent) object are created as well as an email_item object
 that passes the user information into each of the corresponding ADT's. Emails are stored differently in both classes. The data provided to
 the stack and queue is managed by the class "email_item" (See email_item.h). The overall structure of the inbox portion is handled by the "email_inbox"
 class (See email_inbox.h). The structure of the sent items portion is handled by the "email_sent" class (See email_sent.h).

 Output: The output of each email in the inbox is displayed by using the main() member function display_inbox and assisted by information
 from the queue provided by the email_inbox member functions peek and dequeue. The output of each email in the sent items is displayed by using the
 main() member function display_sent and is assisted by information from the stack provided by the email_sent member functions peek, pop and display.
 All additional output comes from this main.cpp file and relates to the user menu and various user prompts.
 */

#include "email_inbox.h"
#include "email_sent.h"
#include <iostream>

using namespace std;

void call_menu(void);
char read_input(const char prompt[]);
void run_input(char command, email_inbox& a_queue, email_sent& a_stack);
void compose_email(email_inbox& a_queue, email_sent& a_stack);
void display_inbox(email_inbox& a_queue);
void display_sent(email_sent& a_stack);
void read_string (const char prompt[],char input_string[], int max_char);

/* The function primarily handles how the client side of the program is structured. After declaring some class objects and other local variables, the function
 proceeds to displaying the menu screen. User input from the menu is processed through the function 'read_input' before passing 'input' and the objects 'a_queue'
 and 'a_stack' as arguments into the 'run_input' function to perform additional processes. When the user is ready to quit the program, the input of 'q' will cause
 the program to terminate. */

int main ()
{
    email_inbox a_queue;
    email_sent a_stack;
    char input;

    call_menu();
	input = read_input("Please enter an option from the list: ");
	while (input != 'q')
	{
		run_input(input, a_queue, a_stack);
		call_menu();
		input = read_input("Please enter an option from the list: ");
	}
    return 0;
}

//Displays the menu options to the user.
void call_menu(void)
{
	cout << "\nWelcome to Joel's Email Application!" << endl
    << "C. Compose an E-Mail" << endl
    << "I. Check your Inbox" << endl
    << "S. Recent Sent Item" << endl
    << "D. Display all Sent Items" << endl
    << "Q. Quit the program" << endl << endl;
}

/* Accepts a prompt from the main() function and displays it. Accepts user input, converts it to lower case
and passes it back to the main() function. */

char read_input(const char prompt[])
{
	char cmd;
	cout << prompt;
	cin >> cmd;

	cin.clear();
	cin.ignore(100, '\n');
	return tolower(cmd);
}

/* User input and objects 'a_queue' and 'a_stack' are passed into the function. A switch statement is used to process
 the command argument. The objects are passed to this function and then passed again to compose_email in order
 to start creating emails. The objects also get passed as references into both the inbox and sent items display functions
 in order to have access to the class member functions. Any command other than the ones outlined in the menu is considered
 invalid and it returns back to main() */

void run_input(char command,email_inbox& a_queue,email_sent& a_stack)
{
	switch (command)
        {
            case 'c': compose_email(a_queue,a_stack);
                break;
            case 'i': display_inbox(a_queue);
                break;
            case 's': display_sent(a_stack);
                break;
            case 'd': a_stack.display();
                break;
        default: cout << "\nInvalid option, please select again." << endl;
            break;
        }
}

/* Objects 'a_queue' and 'a_stack' are passed by reference to this function to handle the actual construction of the email
 data. The email_item object 'a_email' is used to store the data entered by the user and then the object is passed as a reference
 into both the email_inbox and email_sent classes. Since the email_inbox class is setup as a queue, the data item is passed into the
 class member function 'enqueue' in order to add the item to the queue. Since the sent_email class is setup as a stack, the item is passed into the
 class member function 'push' in order to add the item to the stack. This function uses the read_string function to handle the processing of user input
 before setting the input to the 'a_email' data object.*/

void compose_email(email_inbox& a_queue, email_sent& a_stack)
{
    email_item a_email;
    char address[SMALL_CHAR];
    char name[SMALL_CHAR];
    char subject[SMALL_CHAR];
    char message[MAX_CHAR];

    read_string("\nE-Mail Address (40 Character Maximum): ",address,SMALL_CHAR);
	read_string("\nName (40 Character Maximum): ",name,SMALL_CHAR);
    read_string("\nSubject (40 Character Maximum): ",subject,SMALL_CHAR);
    read_string("\nMessage (500 Character Maximum): ",message,MAX_CHAR);

    a_email.set_address(address);
    a_email.set_name(name);
    a_email.set_subject(subject);
    a_email.set_message(message);

    a_queue.enqueue(a_email);
    a_stack.push(a_email);

	cout << "\nEmail Summary:"
    <<"\nAddress: " << address
    << "\nName: " << name
    << "\nSubject: " << subject
    << "\nMessage: " << message << endl;
}

/*Object 'a_queue' is passed into this function to handle the displaying of items in the inbox. The function first establishes some local
 variables to work with including an email_item named 'first_email' in order to store the data coming out of the queue. A while loop is used
 to display the data and the bool variable 'working' is used as it's control variable. Working is assigned based upon a true or false return by the
 email_inbox member function 'peek' which grabs the first item in the queue and assigns it to our passed in object 'first_email' so the function
 can display it. A return of false would mean that the queue is empty and that there is nothing to display. If there is an email in the queue, the user
 is asked if they would like to remove that item and proceed to the next one. If they answer yes, it removes that item from the queue by calling the email_inbox
 function 'dequeue' which removes the first item in the queue. After removal, it recalls the display function and runs through criteria again.
 An answer of no will return the user back to the main menu and leave the displayed email at the front of the queue. */

void display_inbox(email_inbox& a_queue)
{
    char address[SMALL_CHAR];
    char name[SMALL_CHAR];
    char subject[SMALL_CHAR];
    char message[MAX_CHAR];
    char inbox_input;
    bool working = true;
    email_item first_email;

    working = a_queue.peek(first_email);
    if (working == false)
    {
        cout << "\nYour inbox is empty!" << endl;
    }
    else
    {
        while(working)
        {
            first_email.get_address(address);
            first_email.get_name(name);
            first_email.get_subject(subject);
            first_email.get_message(message);

            cout <<"\nAddress: " << address
            << "\nName: " << name
            << "\nSubject: " << subject
            << "\nMessage: " << message << endl;

            inbox_input = read_input("\nWould you like to remove this email and proceed to the next one (Y - Yes, N - No): ");

            if(inbox_input != 'y' && inbox_input != 'n')
            {
                cout << "\nInvalid input, please try again!" << endl;
            }
            else
            {
                if (inbox_input == 'y')
                {
                    a_queue.dequeue();
                    display_inbox(a_queue);
                }
                working = false;
            }
        }
    }
}

/*Object 'a_stack' is passed into this function to handle the displaying of sent items. The function first establishes some local
 variables to work with including an email_item named 'newest_sent' in order to store the data coming out of the stack. A while loop is used
 to display the data and the bool variable 'working' is used as it's control variable. Working is assigned based upon a true or false return by the
 email_sent member function 'get_front' which grabs the most recent item on the stack and assigns it to our passed in object 'newest_sent' so the function
 can display it. A return of false would mean that the stack is empty and that there is nothing to display. If there is an email on the stack, the user
 is asked if they would like to remove that item and proceed to the next one. If they answer yes, it removes that item from the stack by calling the email_sent
 function 'pop' which removes the top item on the stack. After removal, it recalls the display function and runs through criteria again.
 An answer of no will return the user back to the main menu and leave the displayed email on the stack. */

void display_sent(email_sent& a_stack)
{
    char address[SMALL_CHAR];
    char name[SMALL_CHAR];
    char subject[SMALL_CHAR];
    char message[MAX_CHAR];
    char sent_input;
    bool working = true;
    email_item newest_sent;

    working = a_stack.peek(newest_sent);
    if (working == false)
    {
        cout << "\nYour have no sent items!" << endl;
    }
    else
    {
        while(working)
        {
            newest_sent.get_address(address);
            newest_sent.get_name(name);
            newest_sent.get_subject(subject);
            newest_sent.get_message(message);

            cout <<"\nAddress: " << address
            << "\nName: " << name
            << "\nSubject: " << subject
            << "\nMessage: " << message << endl;

            sent_input = read_input("\nWould you like to remove this item and proceed to the next one (Y - Yes, N - No): ");

            if(sent_input != 'y' && sent_input != 'n')
            {
                cout << "\nInvalid input, please try again!";
            }
            else
            {
                if (sent_input == 'y')
                {
                    a_stack.pop();
                    display_sent(a_stack);
                }
                working = false;
            }
        }
    }
}

/* This function accepts a prompt, a string of characters and a max length in which to process user input. Essentially, before the data is stored into
 and object, it is cut down to it's approximate size since the user is only allowed a certain number of characters for each data field. */

void read_string (const char prompt[],char input_string[], int max_char)
{
	cout << prompt;
	cin.get(input_string, max_char, '\n');
	while(!cin)
	{
		cin.clear ();
		cin.ignore (100, '\n');
		cin.get(input_string, max_char, '\n');
	}

	cin.clear();
	cin.ignore (100, '\n');
}

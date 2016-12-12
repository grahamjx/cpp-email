##C++ - Email App

###Foreword
Repos like this one contain old work that I did during my time at Portland State University. Most of these projects were completed in the Data Structures or Computer Systems Programming courses. These projects demonstrate my solid understanding of programming basics as well as familiarity with fundamental system architectures. Each project is meticulously commented and the provided design write-up discusses some of the implementation choices I made when creating these projects.

###Getting Started

Simply run the compiled executable from any unix-based terminal

```bash
  $> cd /path/to/your-project-folder
  $> ./cs-email
  ```
Of course if you want to compile it from source a simple ```$> make run ``` from the source directory will do the trick.

###Purpose:
This program creates a simulated email application with a Inbox and Sent Items folder. Each composed email will be passed into the corresponding ADT which handles storage and manipulation of the data. Each email will be sent to the email_inbox class which is setup as a queue, storing each email item in a circular linkedlist with the oldest composed email being represented first. Ever email will also be sent to the emai_sent class which is setup as a stack, storing each email item in a linkedlist where each node contains an array of emails. The user has the option to create an email, check and remove items in their inbox as well as view and remove sent items.

###Input:
When executing this program, both a_queue (email_inbox) and a_stack (email_sent) object are created as well as an email_item object that passes the user information into each of the corresponding ADT's. Emails are stored differently in both classes. The data provided to the stack and queue is managed by the class "email_item" (See email_item.h). The overall structure of the inbox portion is handled by the "email_inbox" class (See email_inbox.h). The structure of the sent items portion is handled by the "email_sent" class (See email_sent.h).

###Output:
The output of each email in the inbox is displayed by using the main() member function display_inbox and assisted by information from the queue provided by the email_inbox member functions peek and dequeue. The output of each email in the sent items is displayed by using the main() member function display_sent and is assisted by information from the stack provided by the email_sent member functions peek, pop and display. All additional output comes from this main.cpp file and relates to the user menu and various user prompts.

###Algorithm:
_Duplicate Item Recursion_
  1. An item from a list containing some information (Item A).
  2. Compare Item A against the next item in the list (Item B).
    a. If the information is the same in both data items, than the items are duplicate.
  3. This process repeats itself, comparing Item A to subsequent items in the list (Item C, Item D, etc.).
  4. The process is complete once Item A is compared against every item in the list. 

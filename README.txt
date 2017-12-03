****************************
Contacts List App Interface
Author: Ibrahim Thai
****************************


*********************
Program Description
*********************
This program produces an interface that reads a binary file, displays it, and allow you to perform special actions.

This interface allows you to do the following:

- Listing all contacts alphabetically (in ascending order) by name (either last name or company name) - only displaying the name. ONLY 5 names are displayed at a time. But you have the ability to scroll down or up to look for more contacts.

- Adding contacts

- Display the full information of the selected contact.

- Delete the selected contact.

- Return to full contacts list

- Exit the program and save to binary file and written to disk.


************
Compilation
************
NOTE: This program is a Linux/Mac OS based program.

1. Open the Command Line (Terminal)

2. Go to the "ContactsListApp" directory

3. To compile this code:
run: make

After it's maked, an excecutable called "main" is created. You call out the excecutable:

run: bin/main

BUT if you already have a file called "myContactsList.db", simply include the file in your Command Line arguments after you "make":

run: bin/main myContactsList.db

4. Enjoy the program!

5. Once you end the program, a file called "myContactsList.db" is created and written to disk.


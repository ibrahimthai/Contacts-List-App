#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENT 300
#define MAX_CHAR 200
#define RECORD_TO_SHOW 5

int isNumber(char *inputStr);
int readFile();
int displayList(int recordCount, int start);
int displayContact(int start);
int deleteContact(int start);
int editContact(const void *a);
int saveContacts(int recordCount);

int compare_name_ascending (const void *a, const void *b);

/*Struct on disk*/
struct contact {
	unsigned long phone_number;
	/*Positions in the file*/
	long first_name_posn;
	long last_name_posn;
	long company_name_posn;
	long email_posn;
	long next;
};

/*Contact struct for use in memory*/
struct contactInfo {
	unsigned long phoneNumber;
    char firstName[MAX_CHAR];
    char lastName[MAX_CHAR];
    char company[MAX_CHAR];
    char email[MAX_CHAR];
};

/*Define our contact array in memory*/
struct contactInfo contactArray[MAX_ELEMENT];




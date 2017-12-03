#include "../include/contacts.h"

int saveContacts(int recordCount)
{
	FILE *file;
	long int location = 0;
	int i = 0;

	struct contact contactRecord;

	if (recordCount == 0)
		return 0;

	/*Open file for writing info*/
    file = fopen("myContactsList.db", "w");

    do
    {
		/*Find the location of data in a file*/
	    location = ftell(file) + (long) (6 * sizeof(long));

	    /*Calculate the position of the first name*/
	    if (strlen(contactArray[i].firstName) > 0) {
	        contactRecord.first_name_posn = location;
	        location = location + strlen(contactArray[i].firstName) + 1;
	    }
	    else
	        contactRecord.first_name_posn = 0;

	    /*Calculate the position of the last name, including the null*/
	    if (strlen(contactArray[i].lastName) > 0) {
	        contactRecord.last_name_posn = location;
	        location = location + strlen(contactArray[i].lastName) + 1;
	    }
	    else
	        contactRecord.last_name_posn = 0;

	    /*Calculate the position of the company name, including the null*/
	    if (strlen(contactArray[i].company) > 0) {
	        contactRecord.company_name_posn = location;
	        location = location + strlen(contactArray[i].company) + 1;
	    }
	    else
	        contactRecord.company_name_posn = 0;

	    /*Save phone number*/
	    contactRecord.phone_number = contactArray[i].phoneNumber;

	    /*Calculate the position of the email, including the null*/
	    if (strlen(contactArray[i].email) > 0) {
	        contactRecord.email_posn = location;
	        location = location + strlen(contactArray[i].email) + 1; 
	    }
	    else
	        contactRecord.email_posn = 0;

	    /*Set the next pointer to 0 in the current record*/
	    if (i < recordCount - 1)
	    	contactRecord.next = location;
	    else
	    	contactRecord.next = 0;

	    /*Write contact info header to file*/
	    fwrite(&contactRecord, 1, sizeof(contactRecord), file);

	    /*Write contact info data to file*/
	    if (strlen(contactArray[i].firstName) > 0)
	        fwrite(&contactArray[i].firstName, 1, strlen(contactArray[i].firstName) + 1, file);

	    if (strlen(contactArray[i].lastName) > 0)
	        fwrite(&contactArray[i].lastName, 1, strlen(contactArray[i].lastName) + 1, file);

	    if (strlen(contactArray[i].company) > 0)
	        fwrite(&contactArray[i].company, 1, strlen(contactArray[i].company) + 1, file);

	    if (strlen(contactArray[i].email) > 0)
	        fwrite(&contactArray[i].email, 1, strlen(contactArray[i].email) + 1, file);

	    /*Update our recordCounter with the new record we added*/
	    i++;

	} while (i < recordCount && i < MAX_ELEMENT);

	/*Update file on disk*/
	fclose(file);

	return 0;
}
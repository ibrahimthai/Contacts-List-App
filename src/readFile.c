#include "../include/contacts.h"

int readFile()
{
	FILE *file;
	struct contact lastRecord;
	int recordCount = 0;

	/*Open file for writing info*/
    file = fopen("myContactsList.db", "r");

    /*Check if there's no file*/
    if (file == NULL)
    {
        /*Create an empty file*/
        file = fopen("myContactsList.db", "w+");
        fclose(file);
        /*Set recordCount to 0*/
        return 0;
    }

    /*Rewind to the beginning for going through linked list*/
    rewind(file);

    lastRecord.next = 0;

    /*Go to the last record*/
    do {

        /*Read file data onto struct*/
        fread(&lastRecord, sizeof(lastRecord), 1, file);

        /*Check to see if file is empty*/
        if (ftell(file) == 0)
        {
        	/*If there's no record on the disk*/
        	recordCount = 0; 
        	break;
        }

        /*Copy phone number*/
        contactArray[recordCount].phoneNumber = lastRecord.phone_number;

        /*Read first name*/
        if (lastRecord.first_name_posn != 0)
        {
        	fseek(file, lastRecord.first_name_posn, SEEK_SET);
        	fgets(contactArray[recordCount].firstName, MAX_CHAR, file);
        }
        else
        	contactArray[recordCount].firstName[0] = '\0';
        
        /*Read last name*/
        if (lastRecord.last_name_posn != 0)
        {
	        fseek(file, lastRecord.last_name_posn, SEEK_SET);
	        fgets(contactArray[recordCount].lastName, MAX_CHAR, file);
    	}
    	else
        	contactArray[recordCount].lastName[0] = '\0';

        /*Read company*/
        if (lastRecord.company_name_posn != 0)
        {
	        fseek(file, lastRecord.company_name_posn, SEEK_SET);
	        fgets(contactArray[recordCount].company, MAX_CHAR, file);
    	}
    	else
        	contactArray[recordCount].company[0] = '\0';

        /*Read email*/
        fseek(file, lastRecord.email_posn, SEEK_SET);
        fgets(contactArray[recordCount].email, MAX_CHAR, file);

        /*Go to the end of all records*/
        if (lastRecord.next != 0)
        {
            fseek(file, lastRecord.next, SEEK_SET);
        }

        /*printf("%li, %s, %s, %s, %s\n", contactArray[recordCount].phoneNumber, contactArray[recordCount].firstName, contactArray[recordCount].lastName, contactArray[recordCount].company, contactArray[recordCount].email);*/

        recordCount++;

    } while (lastRecord.next != 0 );

    fclose(file);

	return recordCount;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR 200

int isNumber(char *inputStr);

struct contact {
	unsigned long phone_number;
	/*Positions in the file*/
	long first_name_posn;
	long last_name_posn;
	long company_name_posn;
	long email_posn;
	long next;
};

/*Check to see if the string is a number*/
int isNumber(char *inputStr) {
    int i = 0;

    if (strlen(inputStr) == 0)
        return 0;

    for (i = 0; i < strlen(inputStr); i++) {
        if (!isdigit(inputStr[i])) {
            return 0;
        }

    }

    return 1;

}

int main(int argc, char const *argv[]) {

    /*Initiate a file pointer*/
    FILE *file;
    char input[MAX_CHAR];
    char Q1[MAX_CHAR];
    char Q2[MAX_CHAR];
    int i = 0;
    int atLocation = 0;
    int dotLocation = 0;

    char *ptr;

    long int location;
    long int phoneNumber;
    long int recordCount = 0;
    long int last = 0;

    /*Making one struct*/
    struct contactInfo record;
    struct contact contactRecord;
    struct contact lastRecord;

    /*Open file for writing info*/
    file = fopen("myContactsList.db", "a+");
    /*Rewind to the beginning for going through linked list*/
    rewind(file);

    lastRecord.next = 0;

    /*Go to the last record*/
    do {

        /*Read file data onto struct*/
        fread(&lastRecord, sizeof(lastRecord), 1, file);

        /*Check to see if file is empty*/
        if (ftell(file) == 0)
        	recordCount = 0;
        /*Check to see if we only have one record*/
        else if (lastRecord.phone_number != 0)
            recordCount = 1;

        /*Go to the end of all records*/
        if (lastRecord.next != 0)
        {
            fseek(file, lastRecord.next, SEEK_SET);
            recordCount++;
        }

    } while (lastRecord.next != 0 );

    if (ftell(file) > 0)
    	last = ftell(file) - sizeof(lastRecord);

    fclose(file);

    do {

        printf("Do you wish to add a new contact (Yes or No)?: ");
        fgets(Q1, MAX_CHAR, stdin);

        /*Getting rid of carriage return*/
        Q1[strlen(Q1) - 1] = '\0';

        while (strcmp(Q1, "No") != 0) 
        {

            /*Open file for writing*/
            file = fopen("myContactsList.db", "r+");

            /*Go to end of file, after opening*/
            fseek(file, 0, SEEK_END);

            /*First name*/
            printf("First name: ");
            fgets(input, MAX_CHAR, stdin);

            /*Getting rid of carriage return*/
            input[strlen(input) - 1] = '\0';

            /*Copy input to record*/
            strcpy(record.firstName, input);

            do 
            {
            	/*Last name*/
	            printf("Last name: ");
	            fgets(input, MAX_CHAR, stdin);

	            /*Getting rid of carriage return*/
	            input[strlen(input) - 1] = '\0';

	            strcpy(record.lastName, input);

	            /*Company name*/
	            printf("Company Name: ");
	            fgets(input, MAX_CHAR, stdin);

	            /*Getting rid of carriage return*/
	            input[strlen(input) - 1] = '\0';

	            strcpy(record.company, input);

            } while (strlen(record.lastName) == 0 && strlen(record.company) == 0);
	            

            /*Phone number*/
            printf("Phone number: ");
            fgets(input, MAX_CHAR, stdin);

            /*Getting rid of carriage return*/
            input[strlen(input) - 1] = '\0';

            while (!( isNumber(input) != 0 && (strlen(input) == 7 || strlen(input) == 10)) ) 
            {
                printf("Error! Pshone number (enter only numbers): ");
                fgets(input, MAX_CHAR, stdin);

                input[strlen(input) - 1] = '\0';
            }

            contactRecord.phone_number = strtoul(input, &ptr, 10);

        	do 
        	{
	        	/*Email address*/
	            printf("Email: ");
	            fgets(input, MAX_CHAR, stdin);

	            /*Getting rid of carriage return*/
	            input[strlen(input) - 1] = '\0';

				atLocation = 0;
				dotLocation = 0;

	        	for (i = 0; i < strlen(input); i++)
	        	{
	        		if (input[i] == '@')
	        		{
	        			atLocation = i;
	        		}

	        		else if (input[i] == '.')
	        		{
	        			dotLocation = i;
	        		}
	        	}
	            
	        } while ( strlen(input) == 0 || !(atLocation > 0 && dotLocation > 0 && (dotLocation - atLocation) > 1 && (dotLocation < strlen(input) - 1)) );

	        strcpy(record.email, input);

            /*Find the current location in a file*/
            location = ftell(file) + (long) (6 * sizeof(long));

            /*Calculate the position of the first name*/
            if (strlen(record.firstName) > 0) {
                contactRecord.first_name_posn = location;
                location = location + strlen(record.firstName) + 1;
            }
            else
                contactRecord.first_name_posn = 0;

            /*Calculate the position of the last name, including the null*/
            if (strlen(record.lastName) > 0) {
                contactRecord.last_name_posn = location;
                location = location + strlen(record.lastName) + 1;
            }
            else
                contactRecord.last_name_posn = 0;

            /*Calculate the position of the company name, including the null*/
            if (strlen(record.company) > 0) {
                contactRecord.company_name_posn = location;
                location = location + strlen(record.company) + 1;
            }
            else
                contactRecord.company_name_posn = 0;

            /*Calculate the position of the email, including the null*/
            if (strlen(record.email) > 0) {
                contactRecord.email_posn = location;
                location = location + strlen(record.email) + 1;
            }
            else
                contactRecord.email_posn = 0;

            /*Set the next pointer to 0 in the current record*/
            contactRecord.next = 0;

            /*Set the next pointer*/
            lastRecord.next = ftell(file);

            /*Update last record with next pointer*/
            if (recordCount > 0) {
                fseek(file, last, SEEK_SET);
                fwrite(&lastRecord, 1, sizeof(lastRecord), file);
            }
            
            /*Update our last record to the latest input*/
            lastRecord = contactRecord;

            /*Go to the end of file for adding new record*/
            fseek(file, 0, SEEK_END);

            /*Set the next pointer*/
            last = ftell(file);

            /*Write contact info to file*/
            fwrite(&contactRecord, 1, sizeof(contactRecord), file);

            if (strlen(record.firstName) > 0)
                fwrite(&record.firstName, 1, strlen(record.firstName) + 1, file);

            if (strlen(record.lastName) > 0)
                fwrite(&record.lastName, 1, strlen(record.lastName) + 1, file);

            if (strlen(record.company) > 0)
                fwrite(&record.company, 1, strlen(record.company) + 1, file);

            if (strlen(record.email) > 0)
                fwrite(&record.email, 1, strlen(record.email) + 1, file);

            /*Update our recordCount with the new record we added*/
            recordCount++;

            /*Update file on disk*/
            fclose(file);

            printf("Do you wish to add a new contact (Yes or No)?: ");
            fgets(Q1, MAX_CHAR, stdin);

            /*Getting rid of carriage return*/
            Q1[strlen(Q1) - 1] = '\0';

        }
        
        /*Retrieving a contact*/
        printf("Do you wish to retrieve a contact (Yes or No)?: ");
        fgets(Q2, MAX_CHAR, stdin);

        /*Getting rid of carriage return*/
        Q2[strlen(Q2) - 1] = '\0';

        if (strcmp(Q2, "No") != 0) {
            /*Ask for phone number*/
            printf("Phone Number: ");
            fgets(input, MAX_CHAR, stdin);

            /*Getting rid of carriage return*/
            input[strlen(input) - 1] = '\0';

            phoneNumber = strtoul(input, &ptr, 10);

            file = fopen("myContactsList.db", "r");

            rewind(file);

            while(1) {
                /*Read file data onto struct*/
                fread(&contactRecord, sizeof(contactRecord), 1, file);

                /*Check if the file is empty from the beginning*/
                if (ftell(file) == 0) {
                    printf("No match found.\n");
                    break;
                }
                /*Check if the phone number is equal to user request*/
                else if (contactRecord.phone_number != phoneNumber) {
                    /*Check to see if it's the last record*/
                    if (contactRecord.next != 0) {
                        fseek(file, contactRecord.next, SEEK_SET);
                    }
                    
                    else {
                        printf("No match found.\n");
                        break;
                    }                        
                }
                /*When the number is found*/
                else {
                    /*Go to first name location and read into variable*/
                    fseek(file, contactRecord.first_name_posn, SEEK_SET);
                    fscanf(file, "%s", record.firstName);
                    /*Go to last name location and read into variable*/
                    fseek(file, contactRecord.last_name_posn, SEEK_SET);
                    fscanf(file, "%s",record.lastName);
                    /*Go to company name location and read into variable*/
                    fseek(file, contactRecord.company_name_posn, SEEK_SET);
                    fscanf(file, "%s", record.company);
                    /*Go to email location and read into variable*/
                    fseek(file, contactRecord.email_posn, SEEK_SET);
                    fscanf(file, "%s", record.email);

                    /*Print out results*/
                    printf("First Name: %s\n", record.firstName);
                    printf("Last Name: %s\n", record.lastName);
                    printf("Company Name: %s\n", record.company);
                    printf("Phone Number (enter only numbers): %lu\n", contactRecord.phone_number);
                    printf("Email: %s\n", record.email);
                    break;
                }

            }

        }

    } while (strcmp(Q2, "No") != 0);

	return 0;
}

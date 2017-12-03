#include "../include/contacts.h"

int main(int argc, char const *argv[])
{
	/* code */
	int start = 1;
	int recordCount = 0;
	int choice = 0;
	char input[MAX_CHAR];
	struct contactInfo record;
	int breakFlag = 0;

	recordCount = readFile();

	do
	{
		if (recordCount > 0)
			displayList(recordCount, start);

	    printf("Action: ");

	    printf("\n\n");
		printf("+ : Move down one name\n");
		printf("- : Move up one name\n");
		printf("Number : Select this contact and display its full information\n");
	    printf("A : Add a new contact\n");
	    printf("X : Exit the app\n\n");

	    fgets(input, MAX_CHAR, stdin);

	    /*Getting rid of carriage return*/
	    input[strlen(input) - 1] = '\0';

	    /*Shift contact down*/
		/*MAIN MENU: +*/
	    if (input[0] == '+' && start < recordCount)
	    	start += 1;

	    /*Shift contact up*/
		/*MAIN MENU: -*/
	    else if (input[0] == '-' && start > 1)
	    	start -= 1;

	    /*Choose contact Number*/
		/*MAIN MENU: Number*/
	    else if (atoi(input) >= start && atoi(input) < start + RECORD_TO_SHOW)
	    {
	    	choice = atoi(input);
	    	displayContact(choice);

	    	/*Set our flag to false*/
	    	breakFlag = 0;

	    	/*Submenu for DISPLAY contact: R, E, & D*/
	    	do
	    	{
	    		printf("Action: ");
	    		printf("\n\n");
	    		printf("R : Return to list\n");
	    		printf("E : Edit contact\n");
			    printf("D : Delete and return to list\n\n");

			    fgets(input, MAX_CHAR, stdin);

			    /*Getting rid of carriage return*/
			    input[strlen(input) - 1] = '\0';

			    /*Return to contact list*/
			    /*DISPLAY: R*/
			    if (input[0] == 'r' || input[0] == 'R')
			    {
			    	/*Clear our temporary record for next use*/
			    	record.firstName[0] = '\0';
		    		record.lastName[0] = '\0';
		    		record.company[0] = '\0';
		    		record.phoneNumber = 0;
		    		record.email[0] = '\0';
			    	
			    	/*Set our flag to true to exit to main menu*/
	    			breakFlag = 1;
			    }

			    /*Edit contact*/
			    /*DISPLAY: E*/
			    else if (input[0] == 'e' || input[0] == 'E')
			    {
			    	editContact(&record);

			    	/*Set our flag to false*/
	    			breakFlag = 0;

			    	/*Submenu for EDIT AND ADD: R, S, & D*/
			    	do
			    	{
			    		printf("Action: ");
			    		printf("\n\n");
			    		printf("R : Return to list\n");
			    		printf("S : Save contact\n");
					    printf("D : Delete and return to list\n\n");

					    fgets(input, MAX_CHAR, stdin);

					    /*Getting rid of carriage return*/
					    input[strlen(input) - 1] = '\0';

					    /*Return to contact list*/
					    /*EDIT AND ADD: R*/
					    if (input[0] == 'r' || input[0] == 'R')
					    {
					    	/*Clear our temporary record for next use*/
					    	record.firstName[0] = '\0';
				    		record.lastName[0] = '\0';
				    		record.company[0] = '\0';
				    		record.phoneNumber = 0;
				    		record.email[0] = '\0';

					    	/*Set our flag to true to exit to main menu*/
	    					breakFlag = 1;
					    }

					    /*Save contact*/
					    /*EDIT AND ADD: S*/
					    else if (input[0] == 's' || input[0] == 'S')
					    {
					    	strcpy(contactArray[choice - 1].firstName, record.firstName);
					    	strcpy(contactArray[choice - 1].lastName, record.lastName);
					    	strcpy(contactArray[choice - 1].company, record.company);
					    	contactArray[choice - 1].phoneNumber = record.phoneNumber;
					    	strcpy(contactArray[choice - 1].email, record.email);
					    	
					    	/*Set our flag to true to exit to main menu*/
	    					breakFlag = 1;
					    }

					    /*Delete contact*/
					    /*EDIT AND ADD: D*/
					    else if (input[0] == 'd' || input[0] == 'D')
					    {
					    	deleteContact(choice);
					    	recordCount--;

					    	/*Set our flag to true to exit to main menu*/
	    					breakFlag = 1;
					    }

			    	} while (breakFlag == 0);
			    }

			    /*Delete contact*/
			    /*DISPLAY: D*/
			    else if (input[0] == 'd' || input[0] == 'D')
			    {
			    	deleteContact(choice);
			    	recordCount--;

			    	/*Set our flag to true to exit to main menu*/
	    			breakFlag = 1;
			    }
	    	} while (breakFlag == 0);
	    }

	    /*Add contact*/
		/*MAIN MENU: A*/
	    else if (input[0] == 'a' || input[0] == 'A')
	    {
	    	editContact(&record);

	    	/*Submenu for ADD: R, S*/
	    	do
	    	{
	    		printf("Action: ");
	    		printf("\n\n");
	    		printf("R : Return to list\n");
			    printf("S : Save and return to list\n\n");
			    
			    fgets(input, MAX_CHAR, stdin);

			    /*Getting rid of carriage return*/
			    input[strlen(input) - 1] = '\0';

			    /*Return to contact list*/
			    /*ADD: R*/
			    if (input[0] == 'r' || input[0] == 'R')
			    {
			    	/*Clear our temporary record for next use*/
			    	record.firstName[0] = '\0';
		    		record.lastName[0] = '\0';
		    		record.company[0] = '\0';
		    		record.phoneNumber = 0;
		    		record.email[0] = '\0';

			    	/*Set our flag to true to exit to main menu*/
					breakFlag = 1;
			    }

			    /*Save contact*/
			    /*ADD: S*/
			    else if (input[0] == 's' || input[0] == 'S')
			    {

			    	if (recordCount < MAX_ELEMENT)
			    	{
			    		strcpy(contactArray[recordCount].firstName, record.firstName);
				    	strcpy(contactArray[recordCount].lastName, record.lastName);
				    	strcpy(contactArray[recordCount].company, record.company);
				    	contactArray[recordCount].phoneNumber = record.phoneNumber;
				    	strcpy(contactArray[recordCount].email, record.email);

				 		recordCount++;
			    	}
			    	
			    	/*Set our flag to true to exit to main menu*/
					breakFlag = 1;
			    }

	    	} while (breakFlag == 0);

	    }

	} while (input[0] != 'X' && input[0] != 'x');    

	saveContacts(recordCount);

	return 0;
}
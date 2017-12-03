#include "../include/contacts.h"

int editContact(const void *a) {
    
    /*Cast the function pointers to struct*/
    struct contactInfo *record = (struct contactInfo*)a;

	char input[MAX_CHAR];
	int atLocation = 0;
	int	dotLocation = 0;
    int i = 0;
    char *ptr;

    /*First name*/
    printf("First name: ");
    fgets(input, MAX_CHAR, stdin);

    /*Getting rid of carriage return*/
    input[strlen(input) - 1] = '\0';

    /*Copy input to record*/
    strcpy(record->firstName, input);

    do 
    {
    	/*Last name*/
        printf("Last name: ");
        fgets(input, MAX_CHAR, stdin);

        /*Getting rid of carriage return*/
        input[strlen(input) - 1] = '\0';

        strcpy(record->lastName, input);

        /*Company name*/
        printf("Company Name: ");
        fgets(input, MAX_CHAR, stdin);

        /*Getting rid of carriage return*/
        input[strlen(input) - 1] = '\0';

        strcpy(record->company, input);

    } while (strlen(record->lastName) == 0 && strlen(record->company) == 0);
    
    /*Phone number*/
    printf("Phone number: ");
    fgets(input, MAX_CHAR, stdin);

    /*Getting rid of carriage return*/
    input[strlen(input) - 1] = '\0';

    while (!( isNumber(input) != 0 && (strlen(input) == 7 || strlen(input) == 10)) ) 
    {
        printf("Error! Phone number (enter only numbers): ");
        fgets(input, MAX_CHAR, stdin);

        input[strlen(input) - 1] = '\0';
    }

    record->phoneNumber = strtoul(input, &ptr, 10);

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

    strcpy(record->email, input);

    return 0;

}
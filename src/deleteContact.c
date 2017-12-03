#include "../include/contacts.h"

int deleteContact(int start)
{
	int i = start - 1;

	do
	{
		/*Check if next contact is null or not*/
		if ( (contactArray[i + 1].phoneNumber != 0) && (i + 1 < MAX_ELEMENT) )
		{
			/*Shifts the contacts up, once it's deleted*/
			strcpy(contactArray[i].firstName, contactArray[i + 1].firstName);
	    	strcpy(contactArray[i].lastName, contactArray[i + 1].lastName);
	    	strcpy(contactArray[i].company, contactArray[i + 1].company);
	    	contactArray[i].phoneNumber = contactArray[i + 1].phoneNumber;
	    	strcpy(contactArray[i].email, contactArray[i + 1].email);
   	
	    	/*Increment to go to next record*/
	    	i++;
		}
		else
    	{
    		/*Delete the last element in the array after shifting up*/
    		contactArray[i].firstName[0] = '\0';
    		contactArray[i].lastName[0] = '\0';
    		contactArray[i].company[0] = '\0';
    		contactArray[i].phoneNumber = 0;
    		contactArray[i].email[0] = '\0';
    		break;
    	}
				
	} while (1);

	return 0;

}
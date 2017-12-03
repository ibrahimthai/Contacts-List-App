#include "../include/contacts.h"

int displayContact(int start)
{
	/*Print out results*/
	printf("\nContact #%d\n", start);
	printf("First Name: %s\n", contactArray[start - 1].firstName);
	printf("Last Name: %s\n", contactArray[start - 1].lastName);
	printf("Company Name: %s\n", contactArray[start - 1].company);
	printf("Phone Number: %lu\n", contactArray[start - 1].phoneNumber);
	printf("Email: %s\n\n", contactArray[start - 1].email);

	return 0;
}

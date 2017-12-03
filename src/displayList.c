#include "../include/contacts.h"

int displayList(int recordCount, int start)
{
	int i = 0;
	int (*compare_ptr)(const void *a, const void *b);
	char name[MAX_CHAR];
	char indexLetter = '\0';
	char fullName[MAX_CHAR];
	int end = 0;

	/*If our starting point is passed the record count, we set to last record*/
	if (start > recordCount)
		start = recordCount;

	/*Set the end record to display*/
	if (start + RECORD_TO_SHOW > recordCount)
		end = recordCount + 1;
	else
		end = start + RECORD_TO_SHOW;

	compare_ptr = &compare_name_ascending;

	qsort ( contactArray, recordCount, sizeof(struct contactInfo), compare_ptr);
	printf ("Number of Contacts = %d\n", recordCount);

	for ( i = start - 1; i < end - 1; i++ ) {

		/*Clear our name variables*/
		name[0] = '\0';
		fullName[0] = '\0';

		/*Take last name or company name*/
		if (strlen(contactArray[i].lastName) > 0)
		{
			strcpy(name, contactArray[i].lastName);
			strcpy(fullName, contactArray[i].firstName);
			strcat(fullName, " ");
			strcat(fullName, contactArray[i].lastName);
		}
		else
		{
			strcpy(name, contactArray[i].company);
			strcat(fullName, contactArray[i].company);
		}

		/*Output index letter*/
		if (toupper(name[0]) != indexLetter)
		{
			indexLetter = toupper(name[0]);
			printf("%c\n", indexLetter);
		}

		printf ( "   %d. %s\n", i + 1, fullName);
	}

	return 0;
}

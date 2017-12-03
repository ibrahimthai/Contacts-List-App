#include "../include/contacts.h"

int compare_name_ascending (const void *a, const void *b) {

	/*Cast the function pointers to struct*/
	struct contactInfo *one = (struct contactInfo*)a;
	struct contactInfo *two = (struct contactInfo*)b;
	
	char oneName[MAX_CHAR];
	char twoName[MAX_CHAR];

	/*Take last name or company name*/
	if (strlen(one->lastName) > 0)
		strcpy(oneName, one->lastName);
	else
		strcpy(oneName, one->company);

	/*Convert first letter to uppercase for sorting*/
	oneName[0] = toupper(oneName[0]);

	/*Take last name or company name*/
	if (strlen(two->lastName) > 0)
		strcpy(twoName, two->lastName);
	else
		strcpy(twoName, two->company);

	/*Convert first letter to uppercase for sorting*/
	twoName[0] = toupper(twoName[0]);

	/*Return compare string result*/
    return strcmp(oneName, twoName);
}



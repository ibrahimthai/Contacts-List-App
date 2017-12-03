#include "../include/contacts.h"

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
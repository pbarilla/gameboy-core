// gamebae_helpers.c
// helper methods and stuff to make life a little easier.
// aka less C like lol

#include "gamebae_helpers.h"

int stringMatches(char *str1, char *str2) {
    int check;
    check = strncmp(str1, str2, 0);
    // check is the number of characters that are wrong.
    // if there are 0 characters wrong, then the strings match.
    // kinda weird, right?
    if (check == 0) {
        return 1;
    } else {
        return 0;
    }
}

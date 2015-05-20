#include <stdio.h>
#include <string.h>

int stringMatches(char *str1, char *str2);

int main(int argc, char *argv[]) {
    /*
        Accepted Arguments:
        gamebae -rom romename.gb
        gamebae -help
        gamebae -test
        gamebae -dis romename.gb filename.txt
    */
    if (argc < 2) {
		printf("Nope! Usage is: %s -rom romname.gb\n", argv[0]);
	} else {
        // lets figure out what argument it is
        int check = stringMatches("-rom", argv[1]);
        if (check == 1) {
            printf("good\n");
        } else {
            printf("bad\n");
        }

	}

    return 0;
}

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

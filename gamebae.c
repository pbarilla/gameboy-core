#include "gamebae_helpers.h"

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

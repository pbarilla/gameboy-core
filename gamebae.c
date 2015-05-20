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
        int isRom = stringMatches("-rom", argv[1]);
        int isHelp = stringMatches("-help", argv[1]);
        int isTest = stringMatches("-test", argv[1]);
        int isDis = stringMatches("-dis", argv[1]);

        if (isRom == 1)  {
            printf("isRom\n");

        } else if (isHelp == 1) {
            printf("isHelp\n");

        } else if (isTest == 1) {
            printf("isTest\n");

        } else if (isDis == 1) {
            printf("isDis\n");
            
        } else {
            printf("Unknown Argument\n");
        }
	}
    return 0;
}

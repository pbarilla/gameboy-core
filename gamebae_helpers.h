#include <stdio.h>
#include <string.h>

// Helper Methods
int stringMatches(char *str1, char *str2);

// Typedefs
typedef unsigned char BYTE;
typedef char SIGNED_BYTE;
typedef unsigned short WORD;
typedef signed short SIGNED_WORD;

/*
    Flag Layout
    7  6  5  4  3  2  1  0
    Z  N  H  C  0  0  0  0
*/

#define  FLAG_Z 7 // zero flag
#define  FLAG_N 6 // subtract flag
#define  FLAG_H 5 // half carry flag
#define  FLAG_C 4 // carry flag

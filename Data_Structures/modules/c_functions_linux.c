#include <string.h>

#define MAXLENGTHSA 50

char reverse[MAXLENGTHSA],buffer[2];

char* strreverse(char *strings) {
    strcpy(reverse,"");
    for (int i=strlen(strings)-1; i>=0;i--) {
        //printf("\n [Debug] strings=%s and length=%d reverse=%s",strings, strlen(strings),reverse);
        if (strings[i]=='(') {
            buffer[0]=')';
        }
        else if (strings[i]==')') {
            buffer[0]='(';
        } else {
            buffer[0]=strings[i];
        }
        buffer[1]='\0';
        strcat(reverse,buffer);
    }
    return reverse;
}

int powers(int base, int exponent) {
    int result = 1.0;
    if (exponent > 0) {
        for (int i = 0; i < exponent; i++) {
            result *= base;
        }
    } else if (exponent < 0) {
        for (int i = 0; i > exponent; i--) {
            result /= base;
        }
    }
    return result;
}

char getch() {
    char value;
    scanf("%c",&value);
    scanf("%c",&value);
    return value;
}
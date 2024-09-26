// TODO: Research dynamic allocation for strIdent

#include "./lexer.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numValue;
char strIdent[80];

// Return the next token from the input
int getToken() {
    static int lastChar = ' ';
    static int i;

    // Ignore whitespaces and loop and getting input till its not a whitespace
    while (isspace(lastChar)) {
        lastChar = getchar();
    }

    // Handles string values
    if (isalpha(lastChar)) {
        strIdent[0] = lastChar;
        while (isalnum((lastChar = getchar())) && i < sizeof(strIdent)) {
            strIdent[i] = lastChar;
            i++;
        }

        i++;
        strIdent[i] = '\0';

        if (strcmp(strIdent, "fn")) {
            return tok_fn;
        }

        if (strcmp(strIdent, "int")) {
            return tok_int;
        }

        if (strcmp(strIdent, "yell")) {
            return tok_yell;
        }

        return tok_identifier;
    }

    // Handles numeric values
    if (isdigit(lastChar)) {
        char numStr[10];
        i = 0;

        do {
            numStr[i] = lastChar;
            lastChar = getchar();
            i++;
        } while (isdigit(lastChar) && i < sizeof(numStr));

        numStr[i] = '\0';

        numValue = atoi(numStr);
        return tok_number;
    }

    // Handles comments and skip to the end of the line
    if (lastChar == '#') {
        do {
            lastChar = getchar();
        } while (lastChar != EOF && lastChar != '\n' && lastChar != '\r');

        if (lastChar != EOF) {
            return getToken();
        }
    }

    if (lastChar == EOF) {
        return tok_eof;
    }

    // When no token is found just return ASCII value (probably a "+,- etc." sign)
    int currChar = lastChar;
    lastChar = getchar();
    return currChar;
}

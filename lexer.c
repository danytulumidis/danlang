// TODO: Research dynamic allocation for strIdent
// TODO: Research static keyword in c and use

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Token {
    tok_eof = -1,

    // commands
    tok_fn = -2,

    // data types
    tok_int = -3,

    // built-in functions
    tok_yell = -4,

    // primary
    tok_identifier = -5,
    tok_number = -6,
};

static char strIdent[20];
static int numValue;

// Return the next token from the input
static int getToken() {
    static int lastChar = ' ';
    static int i;

    // Ignore whitespaces and start to loop and getting input till its not a
    // whitespace anymore
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

        return tok_identifier;
    }

    // Handles numeric value
    if (isdigit(lastChar)) {
        char numStr[20];
        i = 0;

        do {
            numStr[i] = lastChar;
            lastChar = getchar();
            i++;
        } while (isdigit(lastChar));

        numStr[i] = '\n';

        numValue = atoi(numStr);
    }
}

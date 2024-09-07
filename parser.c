#include <_ctype.h>
#include <stdio.h>

// Current token and lexer function
static int curTok;
int gettok(void);
static int getNextToken() {
    return curTok = gettok();
}

// Binary operator precedence
#define MAX_BINOPS 256
static int binopPrecedence[MAX_BINOPS];

// Get precedence of the pending binary operator token
static int GetTokPrecedence() {
    if (!isascii(curTok))
        return -1;

    int tokPrec = binopPrecedence[curTok];
    if (tokPrec <= 0)
        return -1;
    return tokPrec;
}

// Error handling
void *logError(const char *err) {
    fprintf(stderr, "Error: %s\n", err);
    return NULL;
}

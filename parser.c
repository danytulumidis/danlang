#include "parser.h"
#include "ast.h"
#include "lexer.h"
#include <stdio.h>

// Current token and lexer function
static int curTok;

static int getNextToken() {
    return curTok = getToken();
}

ASTNode *parseNumber() {
    ASTNode *result = (ASTNode *)createNumberAST(numValue);
    getNextToken();
    return result;
}

int main() {
    // Initialize the lexer
    getNextToken();

    ASTNode *AST = parseNumber();
    if (AST) {
        printf("Parsed a number!");
    } else {
        printf("Error parsing");
    }
}

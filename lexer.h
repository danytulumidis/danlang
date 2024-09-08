#ifndef LEXER_H
#define LEXER_H

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

extern char strIdent[80];
extern int numValue;

int getToken(void);

#endif

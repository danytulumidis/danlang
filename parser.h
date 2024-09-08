#ifndef PARSER_H
#define PARSER_H

#include "ast.h"

ASTNode *parseNumber(void);
ASTNode *parseVariable(void);
ASTNode *parseBinary(void);
ASTNode *parseFunctionCall(void);
ASTNode *parsePrototype(void);
ASTNode *parseFunction(void);

#endif

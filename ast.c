#include <stdio.h>
#include <stdlib.h>

typedef enum {
    AST_NUMBER,
    AST_VARIABLE,
    AST_BINARY,
    AST_CALL_EXPR,
    AST_PROTOTYPE,
    AST_FUNCTION
} ASTNodeType;

/*
        Defining specific AST nodes for each type
*/
// The base AST node
typedef struct ASTNode {
    ASTNodeType type;
} ASTNode;

// Number AST node
typedef struct {
    ASTNode base;
    double value;
} NumberAST;

// Variable AST node
typedef struct {
    ASTNode base;
    double *name;
} VariableAST;

// Binary expression AST node
typedef struct {
    ASTNode base;
    char op;
    ASTNode *lhs;
    ASTNode *rhs;
} BinaryAST;

// Function call AST node
typedef struct {
    ASTNode base;
    char *callee;
    ASTNode **args;
    int num_args;
} FunctionCallAST;

// Prototype AST Node
typedef struct {
    ASTNode base;
    char *name;
    char **args;
    int num_args;
} PrototypeAST;

// Function AST Node
typedef struct {
    ASTNode base;
    PrototypeAST *proto;
    ASTNode *body;
} FunctionAST;

/*
        Functions to allocate nodes
        Allocate memory and initilize each type of node
*/
NumberAST *createNumberAST(double value) {
    NumberAST *node = (NumberAST *)malloc(sizeof(NumberAST));

    if (!node) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }

    node->base.type = AST_NUMBER;
    node->value = value;
    return node;
}

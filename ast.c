#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    AST_NUMBER,
    AST_VARIABLE,
    AST_BINARY,
    AST_FUNCTION_CALL,
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
    char *name;
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

VariableAST *createVariableAST(const char *name) {
    VariableAST *node = (VariableAST *)malloc(sizeof(VariableAST));

    if (!node) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }

    node->base.type = AST_VARIABLE;
    node->name = strdup(name);
    return node;
}

BinaryAST *createBinaryAST(char op, ASTNode *lhs, ASTNode *rhs) {
    BinaryAST *node = (BinaryAST *)malloc(sizeof(BinaryAST));

    if (!node) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }

    node->base.type = AST_BINARY;
    node->op = op;
    node->lhs = lhs;
    node->rhs = rhs;
    return node;
}

FunctionCallAST *createFunctionCallAST(const char *callee, ASTNode **args, int num_args) {
    FunctionCallAST *node = (FunctionCallAST *)malloc(sizeof(FunctionCallAST));

    if (!node) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }

    node->base.type = AST_FUNCTION_CALL;
    node->callee = strdup(callee);
    node->args = args;
    node->num_args = num_args;
    return node;
}

PrototypeAST *createPrototypeAST(const char *name, char **args, int num_args) {
    PrototypeAST *node = (PrototypeAST *)malloc(sizeof(PrototypeAST));

    if (!node) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }

    node->base.type = AST_PROTOTYPE;
    node->name = strdup(name);
    node->args = args;
    node->num_args = num_args;
    return node;
}

FunctionAST *createFunction(PrototypeAST *proto, ASTNode *body) {
    FunctionAST *node = (FunctionAST *)malloc(sizeof(FunctionAST));

    if (!node) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }

    node->base.type = AST_FUNCTION;
    node->proto = proto;
    node->body = body;
    return node;
}

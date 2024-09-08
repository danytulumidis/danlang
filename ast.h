#ifndef AST_H
#define AST_H

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

NumberAST *createNumberAST(double value);
VariableAST *createVariableAST(char *name);
BinaryAST *createBinaryAST(char op, ASTNode *lhs, ASTNode *rhs);
FunctionCallAST *createFunctionCallAST(const char *callee, ASTNode **args, int num_args);
PrototypeAST *createPrototypeAST(const char *name, char **args, int num_args);
FunctionAST *createFunctionAST(PrototypeAST *proto, ASTNode *body);

#endif

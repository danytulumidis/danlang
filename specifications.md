# Danlang Specification

## General

Danlang is a very simple, strong typed language and just exist for learning purpose.
It might evolve over time and get more features in the future. This specification file will always be up to date and reflect the current state of the language.

## Technical Insights

Danlangs compiler frontend is fully written in C. The Lexer, AST and Parser are implemented without any third-party plugin or framework as this project was created for learning purposes.

## Functionality

### Data Types

integer (64 bit)

### Control Flow

if, then ,else

### Operators

"+ - \* /"

### Functions

Defined via the fn keyword:

fn foo(int number): number {

    return number \* 2;

}

### Loops

For Loop

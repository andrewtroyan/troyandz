#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define SIZE 1000

void push(char stack[], char symbol);
int pop(char stack[]);
void add(char stack[]);
void deduct(char stack[]);
void multiply(char stack[]);
void divide(char stack[]);
void printResult(char stack[]);

#endif // STACK_H_INCLUDED

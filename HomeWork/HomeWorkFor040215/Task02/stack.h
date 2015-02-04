#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define SIZE 1000

void push(int stack[], int symbol);
int pop(int stack[]);
void add(int stack[]);
void deduct(int stack[]);
void multiply(int stack[]);
void divide(int stack[]);
void printResult(int stack[]);

#endif // STACK_H_INCLUDED

#ifndef STACK_H
#include <stdio.h>
#include <stdlib.h>


//STACK [10+1] = [HEAD, el1, el2, el3, el4, el5, el6, el7, el8, el9]

#define TEXTCOLOR_DEFAULT "\x1b[m"
#define TEXTCOLOR_RED "\x1b[31m"
#define TEXTCOLOR_GREEN "\x1b[32m"
#define TEXTCOLOR_BLUE "\x1b[34m"

#define MAX 10

#define STACK_H

//Header delle funzioni che operano su stack

//Ritorna 1 se lo stack è vuoto, 0 altrimenti
int isEmpty(int *top);
//Ritorna 1 se lo stack è pieno, 0 altrimenti
int isFull(int *top);
//Inserisce un elemento nello stack
void push(int *top, int n);
//Inserisce un elemento nello stack e stampa un messaggio di conferma
void pushCheck(int *top, int n);
//Rimuove un elemento dallo stack
int pop(int *top);
//Rimuove un elemento dallo stack e stampa un messaggio di conferma
int popCheck(int *top);
//Crea un nuovo stack
void newStack(int *top);

//Header delle funzioni di supporto

//Stampa lo stack
void printStack(int *top);
//Resetta lo stack
void reset(int *top);
//Stampa il menu
void printMenu();
//Inizializza il programma
void start();

#endif
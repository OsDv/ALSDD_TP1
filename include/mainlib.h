#ifndef MAINLIB_H_INCLUDED
#define MAINLIB_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

/*      Data structures definition      */
// type and expected vlues for operation code 
#define opcode unsigned char
#define transfer 1
#define deposite 2
#define withdrawal 3

// type for customer contains first name and last name
typedef struct{
    char lName[20];
    char fName[20]; 
} person;
// type for transaction contains all transation informations to create transactions linked list
typedef struct transactionRec{
    opcode code;
    char date[11];
    unsigned int balence;
    struct transactionRec *next,*prev;
} transaction;
// type for account contains all acount required informations and a pointer to transactions list
typedef struct accountRec{
    unsigned int number;
    unsigned short code;
    person customer;
    unsigned long balence;
    struct accountRec *next,*pre;
    transaction *history;
}account;










#endif // LIB_H_INCLUDED

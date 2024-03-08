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
#define OPCODE unsigned char
#define TRANSFER 1
#define DEPOSITE 2
#define WITHDRAWAL 3

// type for customer contains first name and last name // size=40
typedef struct { 
    char lName[20];
    char fName[20]; 
} person;

// type for transaction contains all transation informations // size=14
typedef struct { 
    OPCODE code;
    char date[9];
    unsigned int balence;
} transaction;

// transaction node to create a double linked list 
typedef struct tansactionNode{
    transaction data;
    struct tansactionNode *next,*prev;
} *transactionP;

// type for account contains all acount required informations 
typedef struct {
    unsigned int number; // 0000000001-9999999999
    unsigned short code;  // six-digit 000000-999999
    person customer; // lName & fName of client
    unsigned long balence;  // balence of the account in Belly 
    transactionP history;  // head of the account's transactions's list  
}account;

// account node used to create double linked list of accounts
typedef struct AccNode{
    account data;
    struct AccNode *next,*prev;
} *accountP;










#endif // LIB_H_INCLUDED

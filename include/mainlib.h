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

// type for customer contains first name and last name // 
typedef struct { 
    char lName[20];
    char fName[20]; 
} person;

// type for transaction contains all transation informations (data field for transaction node)// 
typedef struct { 
    OPCODE code;
    char date[9];
    unsigned int balence;
} transaction;

// transaction node to create a double linked list 
typedef struct tansactionNode{ // size=32
    transaction data;
    struct tansactionNode *next,*prev;
} *transactionP;

// type for account contains all acount required informations (data field for account node)
typedef struct {
    unsigned int number; // 0000000001-9999999999
    unsigned short code;  // five-digit 00000-99999
    person customer; // lName & fName of client
    unsigned long balence;  // balence of the account in Belly 
    transactionP history;  // head of the account's transactions's list  
}account;

// account node used to create double linked list of accounts
typedef struct AccNode{ // size=80
    account data;
    struct AccNode *next,*prev;
} *accountP;


/*    ABSTRACT MAHINE     */
void accAllocate(accountP *p);
unsigned int accNumber(accountP p);
unsigned short accCode(accountP p); // returns ushort the code of the account pointed by "p"
void accCFName(accountP p,char *arg_fName); // Copy the first name of client of account pointed by "p" in string arg_fName
void accCLName(accountP p,char *arg_lName); // Copy the last name of client of account pointed by "p" in string arg_lName
unsigned long accBalence(accountP p); // RETURNS THE BALENCE OF THE ACCOUNT ULONG
transactionP accHistory(accountP p);
accountP accNext(accountP p);   // returns the adress of the next element of p in the linked list
accountP accPrev(accountP p);  // returns the adress of the previus element of p in the linked list
void assfName(accountP p,char *arg_fName);// copy "arg_fname" to account copy client first name
void asslName(accountP p,char *arg_lName);

void historyClean(accountP p);





#endif // LIB_H_INCLUDED

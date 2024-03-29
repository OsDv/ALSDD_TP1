#ifndef MAINLIB_H_INCLUDED
#define MAINLIB_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
//colors // to be used to change color text when printing
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define CLEAR "\033[2J"
/*      Data structures definition      */
// type and expected vlues for operation code 
#define OPCODE unsigned char
#define TRANSFERIN 1
#define TRANSFEROUT 2
#define DEPOSITE 3
#define WITHDRAWAL 4

#define _OP1_ "Transfer received"
#define _OP2_ "Transfer sent"
#define _OP3_ "Deposit"
#define _OP4_ "Withdrawal"
#define _TRANSACTION_FORMAT_ "Operation type: %s\nBalence:%s %u \033[0m \nDate: %s\n"
#define _ACCOUNT_FORMAT_ "\tName: %s %s\n\tAccount number: %u\n\tAccount code: %u\n\tBalance: %lu\n"
// type for customer contains first name and last name // 
typedef struct { 
    char lName[20];
    char fName[20]; 
} person;

// type for transaction contains all transation informations (data field for transaction node)// 
typedef struct { 
    OPCODE code;
    char date[11];
    unsigned int balence;
} transaction;

// transaction node to create a double linked list 
typedef struct tansactionNode{ // size=32
    transaction data;
    struct tansactionNode *next,*prev;
} *transactionP;

// type for account contains all acount required informations (data field for account node)
typedef struct {
    unsigned int number; // 000000001-999999999
    unsigned int code;  // six-digit 000000-999999
    person customer; // lName & fName of client
    unsigned long balence;  // balence of the account  
    transactionP history;  // head of the account's transactions's list  
    unsigned int transNumber; // number of transactions of the account
}account;

// account node used to create double linked list of accounts
typedef struct AccNode{ // size=88
    account data;
    struct AccNode *next,*prev;
} *accountP;


/*    ABSTRACT MAHINE     */
void accAllocate(accountP *p);
unsigned int accNumber(accountP p);
unsigned int accCode(accountP p); // returns ushort the code of the account pointed by "p"
// returns pointer to account first name
char *accFname(accountP p);
// returns pointer to account last name
char *accLname(accountP p);
void accCPFName(accountP p,char *arg_fName); // Copy the first name of client of account pointed by "p" in string arg_fName
void accCPLName(accountP p,char *arg_lName); // Copy the last name of client of account pointed by "p" in string arg_lName
unsigned long accBalence(accountP p); // RETURNS THE BALENCE OF THE ACCOUNT ULONG
transactionP accHistory(accountP p);
accountP accNext(accountP p);   // returns the adress of the next element of p in the linked list
accountP accPrev(accountP p);  // returns the adress of the previus element of p in the linked list
void assfName(accountP p,char *arg_fName);// copy "arg_fname" to account copy client first name
void asslName(accountP p,char *arg_lName);
transactionP tranNext(transactionP p);
transactionP tranPrev(transactionP p);

//  GENERAL FUNCTIONS/PROCEDURES
void historyClean(accountP p);
void createNAccount(accountP *head,int n); // creat a linkedlist of n account and put the adress of head in (head)
void createNtransaction(transactionP* head,int n);//creat a linkedlist of n transaction and put the adress of head in (head)
bool accNumberExist(accountP head,unsigned int number);// check if account nummber exists
accountP accAccessNumber(accountP head,unsigned int number);// return a pointer to an account by its number if its exists or NULL if not
void addTrans(accountP acc,OPCODE code,unsigned int balence,char *date);
void printTransaction(transactionP p);
void readUINT(unsigned int *i);
// read a valid name 
void readNAME(char *name);
// check if name is valid (not empty && contain only alphabet)
bool validName(char *name);
// check if character c is an alphabet
bool alphabetCheck(char c);
#endif // LIB_H_INCLUDED

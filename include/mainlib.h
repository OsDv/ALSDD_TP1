#ifndef MAINLIB_H_INCLUDED
#define MAINLIB_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
//colors // to be used to change color text when printing
#define RESET   "\e[m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define CLEAR "\033[2J"
#define BOLD "\e[1m"
/*      Data structures definition      */
// type and expected vlues for operation code 
#define OPCODE unsigned char
#define TRANSFERIN 1
#define TRANSFEROUT 2
#define DEPOSITE 3
#define WITHDRAWAL 4

#define _OP1_ "\033[32mTransfer received\e[m"
#define _OP2_ "\033[31mTransfer sent\e[m"
#define _OP3_ "\033[32mDeposit\e[m"
#define _OP4_ "\033[31mWithdrawal\e[m"
#define _TRANSACTION_FORMAT_ "\e[1m\033[33mOperation type:\e[m %s\n\e[1m\033[33mBalence:\e[m%s %u \e[m \n\e[1m\033[33mDate:\e[m %s \n"
#define _ACCOUNT_FORMAT_ "\e[1m\033[33m Name:\e[m %s %s \n \e[1m\033[33mAccount number:\e[m %u \n\e[1m\033[33m Account code:\e[m %u \n\e[1m\033[33m Balance:\e[m %lu \n"
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
// Allocate enough memory for an account node
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
// returns the adress of the next element of p in the linked list
accountP accNext(accountP p);  
// returns the adress of the previus element of p in the linked list 
accountP accPrev(accountP p);  
// assigne q to "next" field of p
void accAssNext(accountP p,accountP q);
// assigne q to "next" field of p
void accAssNext(accountP p,accountP q);
// copy "arg_fname" to account client first name
void assfName(accountP p,char *arg_fName);
// copy "arg_lname" to account client last name
void asslName(accountP p,char *arg_lName);
// Allocate enough memory for an transaction node
void tranAllocate(transactionP *p);
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

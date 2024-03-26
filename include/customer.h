#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED
#include <mainlib.h>

void transfer(accountP sender,accountP receiver,unsigned int amount,char *date);
void deposit(accountP dest,unsigned int amount,char *date);
void withdrawal(accountP src,unsigned int amount,char *date);

void customerTransfer(accountP head,accountP _sender_);
void customerDeposit(accountP head);
void customerWithdrawal(accountP src);
void customerCheckBalence(accountP src);





#endif
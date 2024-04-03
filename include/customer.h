#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED
#include <mainlib.h>


/**
 * @brief Perform transfer operation from sender to receiver
 * 
 * @param sender Pointer to the sender account node
 * @param receiver  pointer to th receiver account node
 * @param amount the amount to transfer
 * @param date the date of the operation
 * @return no return
 */
void transfer(accountP sender,accountP receiver,unsigned int amount,char *date);

/**
 * @brief Perform deposit operation to  an account
 * 
 * @param dest Pointer to the targeted account 
 * @param amount the amount to deposit
 * @param date the date of the operation
 * @return no return
 */
void deposit(accountP dest,unsigned int amount,char *date);

/**
 * @brief Perform withdrawal operation from an account
 * 
 * @param src Pointer to the targeted account
 * @param amount the amount to withdrawal
 * @param date the date of the operation
 * @return no return
 */
void withdrawal(accountP src,unsigned int amount,char *date);


void customerTransfer(accountP head,accountP _sender_);
void customerDeposit(accountP head);
void customerWithdrawal(accountP src);
void customerCheckBalence(accountP src);
void customerHistoryDate(accountP p);
void customerDashboard(accountP head,accountP actAccount);
accountP customerSignin(accountP head);

int is_leap_year(int year) ;
void readDate(char *dest);
bool dateCheck(int d,int m,int y);

#endif
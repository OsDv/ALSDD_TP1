#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED
#include <mainlib.h>

void admintMenu();//disply the menu for admin 
 void adminCreatAccount(accountP *p,unsigned int num){ // 
    accAllocate(p);
    (*p)->data.number=num;
    printf(" Creating new account number %u",(*p)->data.number);
    printf("Administrator, please insert the following information:\n");
    // Read the first name
    printf("Customer's First Name: ");
    scanf("%s", (*p)->data.customer.fName);
    // Read the last name
    printf("Customer's Last Name: ");
    scanf("%s", (*p)->data.customer.lName);
    // Read the account code
    printf("Account Code: ");
    scanf("%hu", (*p)->data.code);
    (*p)->data.history=NULL;
 }
















#endif
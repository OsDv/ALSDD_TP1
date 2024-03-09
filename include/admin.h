#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED
#include <mainlib.h>
 void adminCreatAccount(accountP *p,unsigned int num){ // 
    accAllocate(p);
    (*p)->data.number=num;
    char firstName[20],lastName[20];
    unsigned short accountCode;
    printf(" Creating new account number %u",(*p)->data.number);
    printf("Administrator, please insert the following information:\n");
    // Read the first name
    printf("Customer's First Name: ");
    scanf("%s", firstName);

    // Read the last name
    printf("Customer's Last Name: ");
    scanf("%s", lastName);

    // Read the account code
    printf("Account Code: ");
    scanf("%hu", &accountCode);
 }















#endif
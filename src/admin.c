#include <mainlib.h>
#include <admin.h>
/*
void contolPanel(){
    char choice;
    do
    {
        adminMenu();
        
        switch (choice)
        {
        case '1':{
            addAccount();
            break;
            }
        case '2':{
            deleteAccount;
            break;
        }
        case '3':{
   //         editAccount;
            break;
        }
        
        default:
            break;
        }
    } while (choice!=0);
    
}

void admintMenu(){
    printf("=== CONTROL PANEL ===");
    printf("1) Create new account .");
    printf("2) Delete an accaount ");
    printf("3) Edit an acount .");
    printf("0) To back to main menu .");
}

void deleteAccount(accountP *head,accountP p){
    (p->next->prev)=(p->prev);
    (p->prev->next)=(p->next);
    hitoryClean(p);
    free(p);
}
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
    scanf("%u", (*p)->data.code);
    (*p)->data.history=NULL;
 }
*/
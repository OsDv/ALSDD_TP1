#include <mainlib.h>
#include <admin.h>

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
            editAccaount;
            break;
        }
        
        default:
            break;
        }
    } while (/* condition */);
    
}

void admintMenu(){
    printf("=== CONTROL PANEL ===");
    printf("1) Create new account .");
    printf("2) Delete an accaount ");
    printf("3) Edit an acount .");
    printf("0) To back to main menu .");
}

void accountDelete(accountP *head,accountP p){
    (p->next->prev)=(p->prev);
    (p->prev->next)=(p->next);
    free(p);
}


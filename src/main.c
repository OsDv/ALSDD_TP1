#include <mainlib.h>
#include <admin.h>
#include <textFileModules.h>
#include <customer.h>

void main(){
    unsigned int accountsN; // number of accounts
    accountP mainHead=NULL;// head for the linkedlist contains all accounts
    // READ INFORMATIONS FROM THE TEXT FILE
    FILE *fptr=fopen("accounts.txt","r");
        readFile(&mainHead,fptr,&accountsN);
    fclose(fptr);
   transactionP tr;
    accountP p=mainHead;
    customerHistoryDate(mainHead);

    customerCheckBalence(mainHead);
    customerCheckBalence(accNext(mainHead));
    customerWithdrawal(accNext(accNext(mainHead)));;
    customerDeposit(mainHead);
    customerTransfer(mainHead,mainHead);
     while(p) {
    printf("the number %u",p->data.number);
    printf("\nThe code %u",p->data.code);
    printf("\nhe name %s",p->data.customer.fName);
    printf("\nThe name %s",p->data.customer.lName);
    printf("\nThe Blanence %lu $\n",p->data.balence);
    tr=p->data.history;
    while (tr){
   // printf("transaction code %d date: %s balence : %u\n",tr->data.code,tr->data.date,tr->data.balence);
   printTransaction(tr);
    tr=tr->next;
    }
    p=accNext(p);
    }


}
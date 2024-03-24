#include <stdio.h>
#include <stdlib.h>
#include <textFileModules.h>

void accountFromFile(accountP p,FILE *fptr){ //  read an account from txt file
    char line[255];
    do fgets(line,255,fptr); while (strncmp("BEGIN",line,5)); //  looks for account begin in file 
    // read account informations from the file
    fgets(line,255,fptr);
    sscanf(line,"%u",&(p)->data.number); // read account number
    fgets(line,255,fptr);
    sscanf(line,"%u",&(p)->data.code);  // read account code
    fgets(line,255,fptr);
    sscanf(line,"%s",(p)->data.customer.fName); // read first name
    fgets(line,255,fptr);
    sscanf(line,"%s",(p)->data.customer.lName); // read last name
    fgets(line,255,fptr);
    sscanf(line,"%lu",&(p)->data.balence); // read balence
    fgets(line,255,fptr);
    sscanf(line,"%u",&(p)->data.transNumber); // read number of transactions
    createNtransaction(&(p->data.history),p->data.transNumber); 
    // creat a linked list to store account transactions history
    transactionP tr=p->data.history;
    fgets(line,255,fptr);
    while ((strncmp(line,"END",3))) // read all account transactions until the end flag
    {
        sscanf(line,"%u",&(tr->data.code)); // read transaction code
        strncpy(tr->data.date,&line[2],10); //read transaction date
        sscanf(&line[13],"%u",&(tr->data.balence)); // read transaction balence
        tr=tr->next;
        fgets(line,255,fptr);   // read next line
    }
    }

void readFile(accountP* head, FILE* fptr,int *num){ 
    // read a text file contains a list of accounts in a linkedlist pointed by head and contain "num" account
    char str[256]; // string to read file lines
    int i; 
    do fgets(str,255,fptr); while(strncmp("FILE_BEGIN",str,10));// looks for the file begin
    fgets(str,256,fptr);// read the number of accounts
    sscanf(str,"%u",num);
    createNAccount(head,(*num)); // create a linked to store accounts informations
    accountP actAcc=(*head);
    for (i=1;i<=(*num);i++){    //  read all the accounts
        accountFromFile(actAcc,fptr); 
        actAcc=accNext(actAcc);
    }
}

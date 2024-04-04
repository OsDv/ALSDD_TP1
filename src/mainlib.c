#include <mainlib.h>

                                    /*  Abstract machine    */
// allocate a memory for an account node and assigne its adress to "p" 
void accAllocate(accountP *p){ 
    *p= (accountP) malloc(88); // size of accountNode = 88
    (*p)->data.history=NULL; 
}
///////////////////////////////////////////////////////////////////////////////////////////////

//returns uint the number of the account pointed by "p"
unsigned int accNumber(accountP p){ 
    return (p->data.number);
}
///////////////////////////////////////////////////////////////////////////////////////////////
unsigned int accCode(accountP p){ // returns ushort the code of the account pointed by "p"
    return (p->data.code);
}
// returns pointer to account first name
char *accFname(accountP p){
    return (p->data.customer.fName);
}
// returns pointer to account last name
char *accLname(accountP p){
    return (p->data.customer.lName);
}

///////////////////////////////////////////////////////////////////////////////////////////////
void accCPFName(accountP p,char *arg_fName){ // Copy the first name of client of account pointed by "p" in string arg_fName
    int i=0;
     while((p->data.customer.fName[i])&&(i<20)){
        arg_fName[i]=p->data.customer.fName[i];
     }
     arg_fName[i]='\0';
     arg_fName[20]='\0';// last character always "\0" for protection

}
///////////////////////////////////////////////////////////////////////////////////////////////
void accCPLName(accountP p,char *arg_lName){ // Copy the last name of client of account pointed by "p" in string arg_lName
    int i=0;
     while((p->data.customer.lName[i])&&(i<20)){
        arg_lName[i]=p->data.customer.lName[i];
        i++;
     }
     arg_lName[i]='\0';
     arg_lName[20]='\0';// last character always "\0" for protection
}
///////////////////////////////////////////////////////////////////////////////////////////////

unsigned long accBalence(accountP p){ // RETURNS THE BALENCE OF THE ACCOUNT ULONG
  return (p->data.balence);
}
///////////////////////////////////////////////////////////////////////////////////////////////
transactionP accHistory(accountP p){
    return (p->data.history);
}
///////////////////////////////////////////////////////////////////////////////////////////////
accountP accNext(accountP p){   // returns the adress of the next element of p in the linked list
    return (p->next);
}
///////////////////////////////////////////////////////////////////////////////////////////////
accountP accPrev(accountP p){   // returns the adress of the previus element of p in the linked list
    return (p->prev);
}
///////////////////////////////////////////////////////////////////////////////////////////////

void assfName(accountP p,char *arg_fName){
    int i=0;
     while((arg_fName[i])&&(i<20)){
        p->data.customer.fName[i]=arg_fName[i];
        i++;
     }
     p->data.customer.fName[i]='\0';
     p->data.customer.fName[20]='\0';// last character always "\0" for protection
}
///////////////////////////////////////////////////////////////////////////////////////////////
void asslName(accountP p,char *arg_lName){
    int i=0;
     while((arg_lName[i])&&(i<20)){
        p->data.customer.lName[i]=arg_lName[i];
        i++;
     }
     p->data.customer.lName[i]='\0';
     p->data.customer.lName[20]='\0';// last character always "\0" for protection

}
// assigne q to "next" field of p
void accAssNext(accountP p,accountP q){ 
    p->next=q;
}
// assigne q to "prev" field of p
void accAssPrev(accountP p,accountP q){  
    p->prev=q;
}

void tranAllocate(transactionP *p){
    (*p)=(transactionP)malloc(32);
}

transactionP tranNext(transactionP p){
    return p->next;
}
transactionP tranPrev(transactionP p){
    return p->prev;
}
void tranAssCode(transactionP p,OPCODE code){
    p->data.code=code;
}
void tranAssBalence(transactionP p,unsigned int balence){
    p->data.balence=balence;
}
void tranAssDate(transactionP p,char *date){
    strncpy(p->data.date,date,11);
}

void tranAssNext(transactionP p,transactionP q){
    p->next=q;
}
void tranAssPrev(transactionP p,transactionP q){
    p->prev=q;
}

                                    /*  Abstract machine    */
void historyClean(accountP p){
    transactionP next,tran= p->data.history;
    while (tran){
        next=tran->next;
        free(tran);
        tran=next;
    }
}

// creat a linkedlist of n account and put the adress of head in (head)
void createNAccount(accountP *head,int n){ 
    if (n==0) return;
    int i;
    accountP curr=NULL,prev=NULL;
    accAllocate(&curr);
    (*head)=curr;
    for (i=1;i<n;i++){
        accAllocate(&curr);
        if (prev==NULL){
            accAssNext(*head,curr);
            accAssPrev(curr,*head);
        } else {
            accAssNext(prev,curr);
            accAssPrev(curr,prev);
        }
        prev=curr;
    }
    accAssNext(curr,NULL);
}
//creat a linkedlist of n transaction and put the adress of head in (head)
void createNtransaction(transactionP* head,int n){
    if (n==0) return;
    int i;
    transactionP curr=NULL,prev=NULL;
    tranAllocate(&curr);
    (*head)=curr;
    for (i=1;i<n;i++){
        tranAllocate(&curr);
        if (prev==NULL){
            tranAssNext(*head,curr);
            tranAssPrev(curr,*head);
        } else {
            tranAssNext(prev,curr);
            tranAssPrev(curr,prev);
        }
        prev=curr;
    }
    tranAssNext(curr,NULL);
}
// check if account nummber exists
bool accNumberExist(accountP head,unsigned int number){
    while (head)
    {
        if (accNumber(head)==number) return true; // account number exists
        head=accNext(head);
    }
    return false;
}
// return a pointer to an account by its number if its exists or NULL if not
accountP accAccessNumber(accountP head,unsigned int number){
    if (!accNumberExist(head,number)) return NULL;
    else {
        while (head)
        {
            if (accNumber(head)==number) return head;
            head=accNext(head);
        }
    }
}

void addTrans(accountP acc,OPCODE code,unsigned int balence,char *date){
    transactionP tr,prev;
    tranAllocate(&tr);
    tranAssCode(tr,code);
    tranAssBalence(tr,balence);
    tranAssDate(tr,date);
    if (accHistory(acc)==NULL){
        acc->data.history=tr;
        tranAssPrev(tr,NULL);
        tranAssNext(tr,NULL);
    } else {
        prev=accHistory(acc);
        while (prev->next)
        {
            prev=tranNext(prev);
        }
        tranAssNext(prev,tr);
        tranAssPrev(tr,prev);
    }
    tranAssNext(tr,NULL);
    acc->data.transNumber++;
}

void printTransaction(transactionP p){
    switch ((p->data.code))
    {
    case 1:
        printf(_TRANSACTION_FORMAT_,_OP1_,GREEN,p->data.balence,p->data.date);
        break;
    case 2:
        printf(_TRANSACTION_FORMAT_,_OP2_,RED,p->data.balence,p->data.date);
        break;
    case 3:
        printf(_TRANSACTION_FORMAT_,_OP3_,GREEN,p->data.balence,p->data.date);
        break;
    case 4:
        printf(_TRANSACTION_FORMAT_,_OP4_,RED,p->data.balence,p->data.date);
    }
}

// secured input function to read an ineger from user
void readUINT(unsigned int *i){
    char c;
    while(scanf("%u",i)!=1){
        while((c=fgetc(stdin))!=EOF && (c!='\n'));
        printf("%sEnter a valid number: %s",RED,RESET);
    }
}

// check if character c is an alphabet
bool alphabetCheck(char c){
    if ((c>64 && c<91)|| (c>96 && c<123 ) ) return 1;
    else return 0;
}

// check if name is valid (not empty && contain only alphabet)
bool validName(char *name){
    int i;
    for (i=0;i<19 && name[i];i++){
        if (!alphabetCheck(name[i])) return 0;
    }
    if ((i==19 && name[19]!='\0') || name[0]=='\0') return 0;
    else return 1;
}

// read a valid name 
void readNAME(char *name){
    int i=0;
    char c;
    bool test;
    do {
    c=fgetc(stdin);
    if (c!='\n') name[i++]=c;
    while ((c=fgetc(stdin))!=EOF && c!='\n' && i<19)
    {
        name[i++]=c;
    }
    name[i]='\0';
    test=validName(name);
    if(!test) {
        printf("%sEnter a valid name:%s ",RED,RESET); 
        i=0;
    }
    }while(!test);
}
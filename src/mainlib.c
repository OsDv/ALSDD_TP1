#include <mainlib.h>

                                    /*  Abstract machine    */

void accAllocate(accountP *p){ // allocate a memory for an account node and assigne its adress to "p" 
    *p= (accountP) malloc(80); // size of accountNode = 80
    (*p)->data.history=NULL; 
}
///////////////////////////////////////////////////////////////////////////////////////////////
unsigned int accNumber(accountP p){ //returns uint the number of the account pointed by "p"
    return (p->data.number);
}
///////////////////////////////////////////////////////////////////////////////////////////////
unsigned short accCode(accountP p){ // returns ushort the code of the account pointed by "p"
    return (p->data.code);
}
///////////////////////////////////////////////////////////////////////////////////////////////
void accCFName(accountP p,char *arg_fName){ // Copy the first name of client of account pointed by "p" in string arg_fName
    int i=0;
     while((p->data.customer.fName[i])&&(i<20)){
        arg_fName[i]=p->data.customer.fName[i];
     }
     arg_fName[i]='\0';
     arg_fName[20]='\0';// last character always "\0" for protection

}
///////////////////////////////////////////////////////////////////////////////////////////////
void accCLName(accountP p,char *arg_lName){ // Copy the last name of client of account pointed by "p" in string arg_lName
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
void accAssNext(accountP p,accountP q){ // assigne q to "next" field of p
    p->next=q;
}
void accAssPrev(accountP p,accountP q){  // assigne q to "prev" field of p
    p->prev=q;
}

void tranAllocate(transactionP *p){
    (*p)=(transactionP)malloc(32);
}
void historyClean(accountP p){
    transactionP next,tran= p->data.history;
    while (tran){
        next=tran->next;
        free(tran);
        tran=next;
    }
}



                                    /*  Abstract machine    */


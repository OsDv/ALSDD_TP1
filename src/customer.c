#include <customer.h>

//perform  transfer of "amount" from sender to receiver and save transaction in each one history
void transfer(accountP sender,accountP receiver,unsigned int amount,char *date){
    sender->data.balence-=amount;
    receiver->data.balence+=amount;
    addTrans(sender,TRANSFEROUT,amount,date);
    addTrans(receiver,TRANSFERIN,amount,date);
}
//perform  deposit of "amount" to dest and save transaction in account history
void deposit(accountP dest,unsigned int amount,char *date){
    dest->data.balence+=amount;
    addTrans(dest,DEPOSITE,amount,date);
}
void withdrawal(accountP src,unsigned int amount,char *date){
    src->data.balence-=amount;
    addTrans(src,WITHDRAWAL,amount,date);
}

void customerTransfer(accountP head,accountP _sender_){// procedure to do transfer operation
    int receiverNum,amount=0; // receiver account number & amount to transfer
    char date[11]="10/03/2024";// just for tests
    printf("===TRANSFER===\n");
    printf("your balence: %lu $ \n",accBalence(_sender_));
    printf("Enter the number of receiver's account: ");
    scanf("%u",&receiverNum); // 
    while (receiverNum!=0 && (!accNumberExist(head,receiverNum) || (receiverNum==(_sender_->data.number))))
    {
        if (receiverNum==_sender_->data.number) printf("You can transfer to your self!\n");
        printf("Please enter a valid number or '0' to exit: ");
        scanf("%u",&receiverNum);
    }
    if (receiverNum!=0){
    printf("Amount to transfer: ");
    scanf("%lu",&amount);
    while (amount!=0 && amount>accBalence(_sender_))
    {
        printf("You don't have enough money re enter amount or '0' to exit: ");
        scanf("%u",&amount);
    } 
    }
    if (amount!=0) {
        transfer(_sender_,accAccessNumber(head,receiverNum),amount,date);
        printf("Operation succeced\n");
    }
    else printf("Operation cancelled\n");
    printf("Press any key to continue..\n");
    getchar();getchar();

}

void customerDeposit(accountP head){
    unsigned int destNum,amount=0;
    char date[11]="10/03/2024";// just for test 
    printf("===DEPOSIT TO ACCOUNT===\n");
    printf("Enter the number of account: ");
    scanf("%u",&destNum); // 
    while (destNum!=0 && !accNumberExist(head,destNum) )
    {
        printf("Please enter a valid number or '0' to exit: ");
        scanf("%u",&destNum);
    }
    if (destNum!=0){
        printf("Amount to deposit: ");
        while (scanf("%u",&amount)!=1)
        {
            printf("Enter a valid amount or 0 to cancel: ");
        } 
    }
    if (amount!=0) {
        deposit(accAccessNumber(head,destNum),amount,date);
        printf("Operation succeced\n");
    }
    else printf("Operation cancelled\n");
    printf("Press any key to continue..\n");
    getchar();getchar();
}

void customerWithdrawal(accountP src){
    unsigned int amount=0;
    char date[11]="10/03/2024";// just for test 
    printf("===WITHDRAWAL of funds===\n");
    printf("Your balence: %u$\n",src->data.balence);
    printf("Amount to take: ");
    while (scanf("%u",&amount)!=1 || amount>accBalence(src))
        {
            if(amount>accBalence(src))printf("You dont have enough money!,your balence: %u$\n",accBalence(src));
            printf("Enter a valid amount or 0 to cancel: ");
        }
    if (amount!=0) {
        withdrawal(src,amount,date);
        printf("Operation succeced\n");
    }
    else printf("Operation cancelled\n");
    printf("Press any key to continue..\n");
    getchar();getchar();
     
}

void customerCheckBalence(accountP src){
    printf("===CHECK BALENCE===\n");
    printf("Hi,%s %s\n",src->data.customer.fName,src->data.customer.lName);
    printf("Your current balence is %u$\n",accBalence(src));
    printf("Press any key to continue..\n");
    getchar();

}

#include <customer.h>

//perform  transfer of "amount" from sender to receiver and save transaction in each one history
void transfer(accountP sender,accountP receiver,unsigned int amount,char *date){
    sender->data.balence-=amount;
    receiver->data.balence+=amount;
    addTrans(sender,TRANSFEROUT,amount,date);
    addTrans(receiver,TRANSFERIN,amount,date);
}

void customerTransfer(accountP head,accountP _sender_){// procedure to do transfer operation
    int receiverNum,amount=0; // receiver account number & amount to transfer
    accountP receiver; // pointer to receiver account
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
    receiver=accAccessNumber(head,receiverNum);
    printf("Amount to transfer: ");
    scanf("%lu",&amount);
    while (amount!=0 && amount>accBalence(_sender_))
    {
        printf("You don't have enough money re enter amount or '0' to exit: ");
        scanf("%u",&amount);
    } 
    }
    if (amount!=0) {
        transfer(_sender_,receiver,amount,date);
        printf("Operation succeced\n");
    }
    else printf("Operation cancelled\n");
    printf("Press any key to continue..\n");
    getchar();getchar();

}
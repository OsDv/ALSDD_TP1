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
    char date[11];
    printf("Enter the date:");
    readDate(date);// Just for test we made the date as user's input
    printf(CLEAR);

    printf("===TRANSFER===\n");
    printf("your balence: %lu $ \n",accBalence(_sender_));
    printf("Enter the number of receiver's account: ");
    readUINT(&receiverNum);
    while (receiverNum!=0 && (!accNumberExist(head,receiverNum) || (receiverNum==(_sender_->data.number))))
    {
        if (receiverNum==_sender_->data.number) printf("You can transfer to your self!\n");
        printf("Please enter a valid number or '0' to exit: ");
        readUINT(&receiverNum);
    }
    if (receiverNum!=0){
    printf("Amount to transfer: ");
    readUINT(&amount);
    while (amount!=0 && amount>accBalence(_sender_))
    {
        printf("You don't have enough money re enter amount or '0' to exit: ");
        readUINT(&amount);
    } 
    }
    if (amount!=0) {
        transfer(_sender_,accAccessNumber(head,receiverNum),amount,date);
        printf("Operation succeced\n");
    }
    else printf("Operation cancelled\n");
    printf("Press ENTER to continue..\n");
    getchar();getchar();

}

void customerDeposit(accountP head){
    unsigned int destNum,amount=0;
    char date[11];
    printf("Enter the date:");
    readDate(date);// Just for test we made the date as user's input

    printf("===DEPOSIT TO ACCOUNT===\n");
    printf("Enter the number of account: ");
    readUINT(&destNum); // 
    while (destNum!=0 && !accNumberExist(head,destNum) )
    {
        printf("Please enter a valid number or '0' to exit: ");
        readUINT(&destNum);
    }
    if (destNum!=0){
        printf("Amount to deposit: ");
        readUINT(&amount);
    }
    if (amount!=0) {
        deposit(accAccessNumber(head,destNum),amount,date);
        printf("Operation succeced\n");
    }
    else printf("Operation cancelled\n");
    printf("Press ENTER to continue..\n");
    getchar();getchar();
}

void customerWithdrawal(accountP src){
    unsigned int amount=0;
    char date[11];
    printf("Enter the date:");
    readDate(date);// Just for test we made the date as user's input

    printf("===WITHDRAWAL of funds===\n");
    printf("Your balence: %u$\n",src->data.balence);
    printf("Amount to take: ");
    readUINT(&amount);
    while ( amount>accBalence(src))
        {
            printf("You dont have enough money!,your balence: %u$\n",accBalence(src));
            printf("Enter a valid amount or 0 to cancel: ");
            readUINT(&amount);
        }
    if (amount!=0) {
        withdrawal(src,amount,date);
        printf("Operation succeced\n");
    }
    else printf("Operation cancelled\n");
    printf("Press ENTER to continue..\n");
    getchar();getchar();
     
}

void customerCheckBalence(accountP src){
    printf("===CHECK BALENCE===\n");
    printf("Hi,%s %s\n",src->data.customer.fName,src->data.customer.lName);
    printf("Your current balence is %u$\n",accBalence(src));
    printf("Press ENTER to continue..\n");
    getchar();

}

void customerHistoryDate(accountP p){
    char date[11];
    bool noTrans=true;
    printf("===TRANSACTIONS HISTORY===)\n");
    printf("Hi, %s %s\n",p->data.customer.fName,p->data.customer.lName);
    printf("%s Enter the date: \n %s",YELLOW,RESET);
    readDate(date);
    transactionP tr=p->data.history;
    while (tr)
    {
        if (!strncmp(date,tr->data.date,10)) {
            if (noTrans) printf("===Your tansactions on %s: ===\n",date);
            printTransaction(tr);
            noTrans=false;
        }
        tr=tranNext(tr);
    }
    if (noTrans) printf("You have no transaction on %s !\n",date);
        printf("Press ENTER to continue..\n");
    getchar();getchar();
    

}
// Function to check if a year is a leap year
int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void readDate(char *dest){
    unsigned int dd,mm,yy;
    char c;
    do {
    printf("\t%sDay :%s",BLUE,RESET);
    readUINT(&dd);
    printf("\t%sMounth: %s",BLUE,RESET);
    readUINT(&mm);
    printf("\t%sYear: %s",BLUE,RESET);
    
    readUINT(&yy);
    } while(!dateCheck(dd,mm,yy));
    sprintf(dest,"%.2u/%.2u/%.4u",dd,mm,yy);
}
bool dateCheck(int d,int m,int y){
    int max_d;
    int mm=m,dd=d,yy=y;
    if(dd<1 || dd>31||mm<1 || mm>12) return false;
    if (mm==2) max_d=28+is_leap_year(yy);
    else if ((mm<8)){
        if (mm%2==0)max_d=30;
        else max_d=31;
    }
    else{
        if (mm%2==0)max_d=31;
        else max_d=30;
    }
    if (dd>max_d)return false;
    else return true;
}

accountP customerSignin(accountP head){
    unsigned int num;
    char c;
    printf("=== Sign in ===\n");
    printf("Enter your account number: ");
    readUINT(&num);
    while (!accNumberExist(head,num)&&num!=0){
        printf("Not found!\nEnter a valid number or 0 to back: ");
        readUINT(&num);
        while((c=(char)fgetc(stdin))!=EOF && c!='\n');
    }
    if (num==0) return NULL;
    else {
        accountP p=accAccessNumber(head,num);
        printf("\nAccount code: ");
        readUINT(&num);
    while((c=(char)fgetc(stdin))!=EOF && c!='\n');
    while (num!=p->data.code&&num!=0){
        printf("Wrong code!!\nEnter the code again or 0 to back: ");
        readUINT(&num);
    }
    if (num==0) return NULL;
    else return p;

    }
}

void customerDashboard(accountP head,accountP actAccount){
    if (actAccount==NULL) return;
    int choice;
    char c;
    do {
        printf("\033[2J");
        printf("=== Account Dashboard ===\n");
        printf(_ACCOUNT_FORMAT_,accFname(actAccount),accLname(actAccount),accNumber(actAccount),accCode(actAccount),accBalence(actAccount));
        printf("==The Menu ==\n");
        printf("\t1) Make transfer\n");
        printf("\t2) Deposit to an account\n");
        printf("\t3) Make a withdrawal\n");
        printf("\t4) Check total amount\n");
        printf("\t5) Check your transactions hitory\n");
        printf("\t0) To exit...\n");
        printf("%sEnter your choice: %s",CYAN,RESET);
        readUINT(&choice);
        switch (choice)
        {
        case 1:
            customerTransfer(head,actAccount);
            break;
        case 2:
            customerDeposit(head);
            break;
        case 3:
            customerWithdrawal(actAccount);
            break;
        case 4:
            customerCheckBalence(actAccount);
            break;
        case 5:
            customerHistoryDate(actAccount);
            break;
        case 0: break;
        
        default:
            break;
        }



    } while(choice!=0);
}
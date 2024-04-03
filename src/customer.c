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

    printf("%s%s=========== TRANSFER ===========%s\n",CYAN,BOLD,RESET);
    printf("%s%sYour current balence is: %s %u%s$\n",BOLD,YELLOW,GREEN,accBalence(_sender_),RESET);
    printf("%s%sEnter the number of receiver's account:%s ",BOLD,YELLOW,RESET);
    readUINT(&receiverNum);
    while (receiverNum!=0 && (!accNumberExist(head,receiverNum) || (receiverNum==(_sender_->data.number))))
    {
        if (receiverNum==_sender_->data.number) printf("You can transfer to your self!\n");
        printf("%sPlease enter a valid number,%s or '0' to exit: ",RED,RESET);
        readUINT(&receiverNum);
    }
    if (receiverNum!=0){
    printf("%s%sAmount to transfer:%s ",BOLD,YELLOW,RESET);
    readUINT(&amount);
    while (amount!=0 && amount>accBalence(_sender_))
    {
        printf("%s%sYou don't have enough money re enter amount,%s or '0' to exit: ",BOLD,RED,RESET);
        readUINT(&amount);
    } 
    }
    if (amount!=0) {
        transfer(_sender_,accAccessNumber(head,receiverNum),amount,date);
        printf("%s%sOperation succeced%s\n",GREEN,BOLD,RESET);
    }
    else printf("%s%sOperation cancelled%s\n",RED,BOLD,RESET);
    printf("Press ENTER to continue..\n");
    getchar();getchar();

}

void customerDeposit(accountP head){
    unsigned int destNum,amount=0;
    char date[11];
    printf("Enter the date:");
    readDate(date);// Just for test we made the date as user's input
    printf(CLEAR);
    printf("%s%s=========== DEPOSIT TO ACCOUNT ===========%s\n",BOLD,CYAN,RESET);
    printf("%s%sEnter the number of account: %s",YELLOW,BOLD,RESET);
    readUINT(&destNum); // 
    while (destNum!=0 && !accNumberExist(head,destNum) )
    {
        printf("%sPlease enter a valid number,%s or '0' to exit: ",RED,RESET);
        readUINT(&destNum);
    }
    if (destNum!=0){
        printf("%s%sAmount to deposit:%s ",BOLD,YELLOW,RESET);
        readUINT(&amount);
    }
    if (amount!=0) {
        deposit(accAccessNumber(head,destNum),amount,date);
        printf("%s%sOperation succeced%s\n",GREEN,BOLD,RESET);
    }
    else printf("%s%sOperation cancelled%s\n",BOLD,RED,RESET);
    printf("Press ENTER to continue..\n");
    getchar();getchar();
}

void customerWithdrawal(accountP src){
    unsigned int amount=0;
    char date[11];
    printf("Enter the date:");
    readDate(date);// Just for test we made the date as user's input
    printf(CLEAR);
    printf("%s%s=========== WITHDRAWAL of funds ===========%s\n",CYAN,BOLD,RESET);
    printf("%s%sYour current balence is: %s %u%s$\n",BOLD,YELLOW,GREEN,accBalence(src),RESET);
    printf("%s%sAmount to take: %s",BOLD,YELLOW,RESET);
    readUINT(&amount);
    while ( amount>accBalence(src))
        {
            printf("You dont have enough money!,your balence: %u$\n",accBalence(src));
            printf("%sEnter a valid amount,%s or 0 to cancel: ",RED,RESET);
            readUINT(&amount);
        }
    if (amount!=0) {
        withdrawal(src,amount,date);
        printf("%s%sOperation succeced%s\n",GREEN,BOLD,RESET);
    }
    else printf("%s%sOperation cancelled%s\n",RED,BOLD,RESET);
    printf("Press ENTER to continue..\n");
    getchar();getchar();
     
}

void customerCheckBalence(accountP src){
    printf(CLEAR);
    printf("%s%s=========== CHECK BALENCE ===========%s\n",BOLD,CYAN,RESET);
    printf("Hi,%s %s\n",src->data.customer.fName,src->data.customer.lName);
    printf("%s%sYour current balence is: %s %u%s$\n",BOLD,YELLOW,GREEN,accBalence(src),RESET);
    printf("Press ENTER to continue..\n");
    getchar();getchar();

}

void customerHistoryDate(accountP p){
    char date[11];
    bool noTrans=true;
    printf(CLEAR);
    printf("%s%s=========== TRANSACTIONS HISTORY ===========%s\n",BOLD,CYAN,RESET);
    printf("Hi,%s %s %s %s\n",BOLD,p->data.customer.fName,p->data.customer.lName,RESET);
    printf("%s Enter the date: \n %s",YELLOW,RESET);
    readDate(date);
    transactionP tr=p->data.history;
    while (tr)
    {
        if (!strncmp(date,tr->data.date,10)) {
            if (noTrans) printf("%s%s=== Your tansactions on %s: ===\n%s-----------------------------------------\n",BOLD,CYAN,date,RESET);
            printTransaction(tr);
            printf("-----------------------------------------\n");
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
    dest[10]='\0';
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
    printf(CLEAR);// Clear terminal
    printf("%s\t ===== Sign in =====\n",CYAN);
    printf("%s Enter your account number: %s",YELLOW,RESET);
    readUINT(&num);
    while (!accNumberExist(head,num)&&num!=0){
        printf("%s Not found!\nEnter a valid number%s, or ""0"" to back: ",RED,RESET);
        readUINT(&num);
    }
    if (num==0) return NULL;
    else {
        accountP p=accAccessNumber(head,num);
        printf("%sAccount code: %s",YELLOW,RESET);
        readUINT(&num);
    while (num!=p->data.code&&num!=0){
        printf("%s Wrong code!!\nEnter the code again%s, or ""0"" to back: ",RED,RESET);
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
        printf("%s=========== Account Dashboard ===========%s\n",CYAN,RESET);
        printf(_ACCOUNT_FORMAT_,accFname(actAccount),accLname(actAccount),accNumber(actAccount),accCode(actAccount),accBalence(actAccount));
        printf("%s%s=========== The Menu ===========%s\n",BOLD,CYAN,RESET);
        printf("%s%s1) Make transfer\n",BOLD,BLUE);
        printf("2) Deposit to an account\n");
        printf("3) Make a withdrawal\n");
        printf("4) Check total amount\n");
        printf("5) Check your transactions hitory\n");
        printf("0) To exit...\n");
        printf("%s\e[4mEnter your choice: %s",CYAN,RESET);
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
#include <mainlib.h>
#include <admin.h>
#include <textFileModules.h>
#include <customer.h>

void main(){
    unsigned int accountsN=0,choice; // number of accounts
    int code=0;
    accountP mainHead=NULL;// head for the linkedlist contains all accounts
    // READ INFORMATIONS FROM THE TEXT FILE
    FILE *fptr=fopen("accounts.txt","r");
        if (fptr) { // check the file is accessible 
            readFile(&mainHead,fptr,&accountsN);
            fclose(fptr);
        }
    
    do
    {
        printf("\033[2J");// clear screen
        printf("%s%s=========== Welcome back ===========%s\n",BOLD,CYAN,RESET);
        printf("%s%sAre you: \n\t%s1)Customer \n\t2)Admin\n\t0) Exit...\n",BOLD,YELLOW,BLUE);
        printf("%sEnter your choice: %s",GREEN,RESET);
        readUINT(&choice);
        
        switch (choice)
        {
        case 1:
            customerDashboard(mainHead,customerSignin(mainHead));
            break;
        case 2:
            printf("%s%sEnter the security code (123):%s ",BOLD,GREEN,RESET);
            readUINT(&code);
            if (code==SECURITY_CODE) adminControlPanel(&mainHead,&accountsN); //  check a valid code entred; security code defined in admin.h
            else printf("%sWrong code!%s \n Press Enter to continue %s",RED,BLUE,RESET);
            getchar();getchar();
            break;
        case 0:
            break;
        
        default:
            printf("\nEnter a vlid choice: ");
            break;
        }

    } while (choice!=0);

    printf("\033[2J");
    printf("Do you want to save modifications to the file? 1)yes 2)no : ");
    readUINT(&choice);
    if (choice==1){
        fptr=fopen("accounts.txt","w");
        writeFile(mainHead,accountsN,fptr);//file just for test then will be only one file
        fclose(fptr);
    }

    

}
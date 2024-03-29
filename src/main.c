#include <mainlib.h>
#include <admin.h>
#include <textFileModules.h>
#include <customer.h>

void main(){
    unsigned int accountsN,choice; // number of accounts
    char c;
    accountP mainHead=NULL;// head for the linkedlist contains all accounts
    // READ INFORMATIONS FROM THE TEXT FILE
    FILE *fptr=fopen("accounts.txt","r");
        readFile(&mainHead,fptr,&accountsN);
    fclose(fptr);
    
    do
    {
        printf("=== Welcome back ===\n");
        printf("Are you: \n\t1)Customer \n\t2)Admin\n\t0) Exit...\n");
        printf("Enter your choice: ");
        scanf("%u",&choice);
        while((c=(char)fgetc(stdin))!=EOF && c!='\n');
        switch (choice)
        {
        case 1:
            customerDashboard(mainHead,customerSignin(mainHead));
            break;
        case 2:
            adminControlPanel(&mainHead,&accountsN);
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
        fptr=fopen("file2.txt","w");
        writeFile(mainHead,accountsN,fptr);//file just for test then will be only one file
        fclose(fptr);
    }

    

}
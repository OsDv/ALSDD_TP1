#include <stdio.h>
#include <admin.h>

void adminCreateAccount(accountP *head, unsigned int accnum) {
    // Check if the linked list of accounts is empty
    if (*head == NULL) {
        // Allocate memory for the first account node
        accAllocate(head);

        // Set the account number
        (*head)->data.number = accnum;
        // Initialize transaction number to 0
        (*head)->data.transNumber = 0;
        // Initialize account balance to 0
        (*head)->data.balence = 0;

        // Print message indicating the creation of a new account
        printf("%s%sCreating new account number:%s %u\n",BOLD,YELLOW,RESET ,(*head)->data.number);
        printf("Administrator, please insert the following information:\n");
        

        // Read the first name of the customer
        printf("%s%sCustomer's First Name: %s",BOLD,YELLOW,RESET);
        readNAME((*head)->data.customer.fName);
        // Read the last name of the customer
        printf("%s%sCustomer's Last Name: %s",BOLD,YELLOW,RESET);
        readNAME((*head)->data.customer.lName);
        // Read the account code
        printf("%s%sAccount Code:%s ",BOLD,YELLOW,RESET);
        readUINT(&((*head)->data.code));

        // Initialize transaction history as NULL for the new account
        (*head)->data.history = NULL;

        // Set next and previous pointers to NULL for the first node
        (*head)->next = NULL;
        (*head)->prev = NULL;
    } else {
        // If the linked list is not empty, traverse to the last node
        accountP p = *head;
        while (p->next != NULL) {
            p = p->next;
        }

        // Allocate memory for the next account node
        accAllocate(&(p->next));

        // Set the account number
        p->next->data.number = accnum;
        // Initialize transaction number to 0
        p->next->data.transNumber = 0;
        // Initialize account balance to 0
        p->next->data.balence = 0; // Spelling is incorrect, but left as it is
        // Set the previous pointer of the new node
        p->next->prev = p;

        // Print message indicating the creation of a new account
        printf("%s%sCreating new account number:%s %u\n",BOLD,YELLOW,RESET ,p->data.number);
        printf("Administrator, please insert the following information:\n");

        // Read the first name of the customer
        printf("%s%sCustomer's First Name: %s",BOLD,YELLOW,RESET);
        readNAME(p->next->data.customer.fName);
        // Read the last name of the customer
        printf("%s%sCustomer's Last Name: %s",BOLD,YELLOW,RESET);
        readNAME(p->next->data.customer.lName);
        // Read the account code
        printf("%s%sAccount Code:%s ",BOLD,YELLOW,RESET);
        readUINT(&(p->next->data.code));

        // Initialize transaction history as NULL for the new account
        p->next->data.history = NULL;

        // Set next pointer to NULL for the last node
        p->next->next = NULL;
    }
}



accountP accountSearch(accountP head, unsigned int accnum) {
    // Handle the case when the list is empty
    if (head == NULL) {
        return NULL;
    }

    // Initialize a pointer to traverse the linked list
    accountP p = head;

    // Traverse the linked list until the end is reached or the account is found
    while (p != NULL) {
        // Check if the current account number matches the target account number
        if (p->data.number == accnum) {
            return p;  // Account found, return the pointer to the node
        }
        // Move to the next node
        p = accNext(p);
    }

    // Account not found in the linked list
    return NULL;
}




void adminDeleteAccount(accountP *head, unsigned int accnum) {
    // Declare a pointer to hold the account node to be deleted
    accountP p;

    // Search for the account node with the given account number
    p = accountSearch(*head, accnum);

    // If the account node is not found
    if (p == NULL) {
        printf("%s%sAccount not found!%s",RED,BOLD,RESET);
    } 
    // If the account to be deleted is the head node
    else if (p == *head) {
        // Update the head pointer to skip the first node
        *head = p->next;

        // If the next node exists, update its previous pointer
        if (p->next != NULL) {
            p->next->prev = NULL;
        }

        // Free the memory allocated for the node to be deleted
        free(p);

        // Print a success message
        printf("%s%sAccount number %s%u \033[32mhas been deleted successfully%s",BOLD,GREEN,RED,accnum,RESET);
    } 
    // If the account to be deleted is not the head node
    else {
        // Adjust the next and previous pointers to bypass the node to be deleted
        p->prev->next = p->next;
        
        // If the next node exists, update its previous pointer
        if (p->next != NULL) {
            p->next->prev = p->prev;
        }
        // Destroy the history linked list related to the node to be deleted
        historyClean(p);
        // Free the memory allocated for the node to be deleted
        free(p);

        // Print a success message
        printf("%s%sAccount number %s%u \033[32mhas been deleted successfully%s",BOLD,GREEN,RED,accnum,RESET);
    }
    printf("\nPress Enter to continue...");
    getchar();getchar();
}


void accountEdit(accountP head, unsigned int accnum) {
    accountP p;

    // Search for the account node with the given account number
    p = accountSearch(head, accnum);

    // If the account node is not found
    if (p == NULL) {
        printf("%s%sAccount not found!%s",RED,BOLD,RESET);
    } else {
        printf("%s%sAccount found successfully%s\nWhat information do you want to edit?\n",GREEN,BOLD,GREEN);
        printf("%s1. Account Code\n",YELLOW);
        printf("2. Customer's First Name\n");
        printf("3. Customer's Last Name\n");
        printf("4. Exit\n");
        printf("%sEnter your choice: %s",GREEN,RESET);
        printf("-----------------------------------------\n");

        unsigned int choice;
        readUINT(&choice);

        switch (choice) {
            case 1:
                // Edit account code
                printf("%s%sEnter the new account code: ",BOLD,YELLOW);
                readUINT(&(p->data.code));
                printf("%sAccount code updated successfully%s\n",GREEN,RESET);
                break;
            case 2:
                // Edit customer's first name
                printf("%s%sEnter the new customer's first name: ",BOLD,YELLOW);
                readNAME(p->data.customer.fName);
                printf("%sCustomer's first name updated successfully%s\n",GREEN,RESET);
                break;
            case 3:
                // Edit customer's last name
                printf("%s%sEnter the new customer's last name: ",BOLD,YELLOW);
                readNAME(p->data.customer.lName);
                printf("%sCustomer's last name updated successfully%s\n",GREEN,RESET);
                break;
            case 4:
                printf("Exiting account editing...\n");
                break;
            default:
                printf("%s%sInvalid choice!%s\n",RED,BOLD,RESET);
                break;
        }
        printf("\nPress Enter to continue...");
        getchar();getchar();
    }
}


void adminControlPanel(accountP *head,unsigned int *accountsN) {
    unsigned int choice=1;
    bool exitMenu = false;

    while (!exitMenu) {
        printf(CLEAR);
        printf("\n%s%s=========== Admin Control Panel ===========\n",BOLD,CYAN);
        printf("%s1. Add Customer Accounts\n",YELLOW);
        printf("2. Delete Customer Accounts\n");
        printf("3. Edit Code/Customer\n");
        printf("4. Exit\n");
        if ((choice>4)||(choice<1))printf("\n%sInvalid choice! Please enter a valid option.\n",RED);//last choice was invalid
        printf("%sEnter your choice:%s ",GREEN,RESET);
        readUINT(&choice);

        switch (choice) {
            case 1:
                printf(CLEAR);
                printf("\n%s%s=========== Add Customer Accounts ===========%s\n",BOLD,CYAN,RESET);
                unsigned int accountNumber;
                do { 
                printf("%s%sEnter account number: %s",YELLOW,BOLD,RESET);
                readUINT(&accountNumber);
                if (accNumberExist(*head, accountNumber)){
                    printf("%s%sThis account number is already taken.%s Enter another number :\n",BOLD,RED,RESET);
                }
                } while ((accNumberExist(*head, accountNumber))&& (accAccessNumber!=0));
                adminCreateAccount(head, accountNumber);
                (*accountsN)++;
                break;
            case 2:
                printf(CLEAR);
                printf("\n%s%s=========== Delete Customer Accounts ===========%s\n",BOLD,CYAN,RESET);
                unsigned int deleteAccountNumber;
                printf("%s%sEnter account number to delete: %s",YELLOW,BOLD,RESET);
                readUINT(&deleteAccountNumber);
                adminDeleteAccount(head, deleteAccountNumber);
                (*accountsN)--;
                break;
            case 3:
                printf(CLEAR);
                printf("\n%s%s=========== Edit Code/Customer ===========\n",CYAN,BOLD);
                unsigned int editAccountNumber;
                printf("%sEnter account number to edit: %s",YELLOW,RESET);
                readUINT(&editAccountNumber);
                accountEdit(*head, editAccountNumber);
                break;
            case 4:
                printf("\nExiting Admin Control Panel...\n");
                printf("\nPress Enter to continue...");
                exitMenu = true;
                break;
            default:
                break;
        }
    }
} 













































































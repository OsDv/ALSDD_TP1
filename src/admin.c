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
        printf("Creating new account number %u\n", (*head)->data.number);
        printf("Administrator, please insert the following information:\n");

        // Read the first name of the customer
        printf("Customer's First Name: ");
        scanf("%s", (*head)->data.customer.fName);
        // Read the last name of the customer
        printf("Customer's Last Name: ");
        scanf("%s", (*head)->data.customer.lName);
        // Read the account code
        printf("Account Code: ");
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
        printf("Creating new account number %u\n", p->next->data.number);
        printf("Administrator, please insert the following information:\n");

        // Read the first name of the customer
        printf("Customer's First Name: ");
        scanf("%s", p->next->data.customer.fName);
        // Read the last name of the customer
        printf("Customer's Last Name: ");
        scanf("%s", p->next->data.customer.lName);
        // Read the account code
        printf("Account Code: ");
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
        printf("Account not found");
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
        printf("Account number %u has been deleted successfully", accnum);
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
        printf("Account number %u has been deleted successfully", accnum);
    }
}


void accountEdit(accountP head, unsigned int accnum) {
    accountP p;

    // Search for the account node with the given account number
    p = accountSearch(head, accnum);

    // If the account node is not found
    if (p == NULL) {
        printf("Account not found\n");
    } else {
        printf("Account found successfully\nWhat information do you want to edit?\n");
        printf("1. Account Code\n");
        printf("2. Customer's First Name\n");
        printf("3. Customer's Last Name\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        unsigned int choice;
        readUINT(&choice);

        switch (choice) {
            case 1:
                // Edit account code
                printf("Enter the new account code: ");
                readUINT(&(p->data.code));
                printf("Account code updated successfully\n");
                break;
            case 2:
                // Edit customer's first name
                printf("Enter the new customer's first name: ");
                scanf("%s", p->data.customer.fName);
                printf("Customer's first name updated successfully\n");
                break;
            case 3:
                // Edit customer's last name
                printf("Enter the new customer's last name: ");
                scanf("%s", p->data.customer.lName);
                printf("Customer's last name updated successfully\n");
                break;
            case 4:
                printf("Exiting account editing...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
}


void adminControlPanel(accountP *head,unsigned int *accountsN) {
    unsigned int choice;
    bool exitMenu = false;

    while (!exitMenu) {
        printf("\n===== Admin Control Panel =====\n");
        printf("1. Add Customer Accounts\n");
        printf("2. Delete Customer Accounts\n");
        printf("3. Edit Code/Customer\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        readUINT(&choice);

        switch (choice) {
            case 1:
                printf("\n-- Add Customer Accounts --\n");
                unsigned int accountNumber;
                do { 
                printf("Enter account number: ");
                readUINT(&accountNumber);
                if (accNumberExist(*head, accountNumber)){
                    printf("This account number is already taken. Enter another number.\n");
                }
                } while (accNumberExist(*head, accountNumber));
                adminCreateAccount(head, accountNumber);
                (*accountsN)++;
                break;
            case 2:
                printf("\n-- Delete Customer Accounts --\n");
                unsigned int deleteAccountNumber;
                printf("Enter account number to delete: ");
                readUINT(&deleteAccountNumber);
                adminDeleteAccount(head, deleteAccountNumber);
                (*accountsN)--;
                break;
            case 3:
                printf("\n-- Edit Code/Customer --\n");
                unsigned int editAccountNumber;
                printf("Enter account number to edit: ");
                readUINT(&editAccountNumber);
                accountEdit(*head, editAccountNumber);
                break;
            case 4:
                printf("\nExiting Admin Control Panel...\n");
                exitMenu = true;
                break;
            default:
                printf("\nInvalid choice! Please enter a valid option.\n");
                break;
        }
    }
} 

















/*int main() {
    // Initialize the head pointer to NULL
    accountP head = NULL;

    // Call the admin control panel function to perform actions
    adminControlPanel(&head);

    // Display the list of accounts after exiting the admin control panel
    printf("\n===== Account List =====\n");
    if (head == NULL) {
        printf("No accounts found.\n");
    } else {
        accountP current = head;
        while (current != NULL) {
            printf("Account Number: %u\n", current->data.number);
            printf("Customer Name: %s %s\n", current->data.customer.fName, current->data.customer.lName);
            printf("Account Code: %u\n", current->data.code);
            printf("Balance: %lu\n", current->data.balence);
            printf("Transaction History: %p\n", (void *)current->data.history); // Just printing the address for simplicity
            printf("Transaction Count: %u\n\n", current->data.transNumber);
            current = current->next;
        }
    }

    // Free any remaining memory allocated for accounts
    accountP temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}*/











































































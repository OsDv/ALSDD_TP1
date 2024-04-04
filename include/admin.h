#ifndef ADMIN_H
#define ADMIN_H

#include "mainlib.h"
// Function prototypes
#define SECURITY_CODE 123

/**
 * @brief Displays the admin control panel and performs account management actions.
 * 
 * @param head Pointer to the head of the account list.
 */
void adminControlPanel(accountP *head,unsigned int *accountsN);

/**
 * @brief Creates a new account and adds it to the account list.
 * 
 * @param head Pointer to the head of the account list.
 * @param accnum Account number to assign to the new account.
 */
void adminCreateAccount(accountP *head, unsigned int accnum);

/**
 * @brief Searches for an account by its account number.
 * 
 * @param head Pointer to the head of the account list.
 * @param accnum Account number to search for.
 * @return Pointer to the account node if found, NULL otherwise.
 */
accountP accountSearch(accountP head, unsigned int accnum);

/**
 * @brief Deletes an account from the account list by its account number.
 * 
 * @param head Pointer to the pointer to the head of the account list.
 * @param accnum Account number to delete.
 */
void adminDeleteAccount(accountP *head, unsigned int accnum);

/**
 * @brief Edits account information such as code or customer's name.
 * 
 * @param head Pointer to the head of the account list.
 * @param accnum Account number to edit.
 */
void accountEdit(accountP head, unsigned int accnum);

#endif /* ADMIN_H */

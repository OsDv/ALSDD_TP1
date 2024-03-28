#ifndef TEXT_FILE_MODULES_H_INCLUDED
#define TEXT_FILE_MODULES_H_INCLUDED
#include <mainlib.h>

//READING MADULES
void accountFromFile(accountP p,FILE *fptr);
void readFile(accountP* head, FILE* fptr, unsigned int *num);
void accountToFile(accountP p,FILE *fptr);
void writeFile(accountP head,unsigned int accNUM,FILE* fptr);











#endif
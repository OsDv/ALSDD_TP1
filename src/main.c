#include <mainlib.h>

void main(){
    
    accountP p;
    accAllocate(&p);
    p->data.balence=98988;
    asslName(p,"Dib");
   // strncpy_s((p->data.customer.fName),20,"ahmed",6);
   assfName(p,"ahmed");
    p->data.code=123;
    p->data.number=4294967295;
    char f[20],l[20];
    accCLName(p,l);
    printf("fname: %s || lname:%s \n code %i || number %x:",p->data.customer.fName,l,accCode(p),accNumber(p));
}
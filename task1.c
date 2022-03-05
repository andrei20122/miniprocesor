#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{
    
    unsigned int inst;
    scanf("%u", &inst);
    unsigned int  m=7<<29;
    unsigned int N=inst & m;
    N=N>>29;
    N++;
    inst=inst<<3;
    
    printf("%u ",N);
    int k=0;
    for(;k<N;k++)
    {   unsigned int operand;
        m=3<<30;
        operand=inst&m;
        operand=operand>>30;
        if(operand == 0) printf("+ ");
        else if(operand == 1) printf("- ");
        else if(operand == 2) printf("* ");
        else if(operand ==3)  printf("/ ");
        inst=inst<<2; 

    } 
   unsigned int dim;
    m=15<<28;
    dim=inst&m;
    dim=dim>>28;
    dim++;
    printf("%u\n",dim);


    return 0;
}
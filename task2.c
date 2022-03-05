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
    
    
    int k=0;
    unsigned char vec_operator[20];
    unsigned int vec_operand[20];
    for(;k<N;k++)
    {   unsigned int operand;
        m=3<<30;
        operand=inst&m;
        operand=operand>>30;
        if(operand == 0) vec_operator[k]='+';
        else if(operand == 1) vec_operator[k]='-';
        else if(operand == 2) vec_operator[k]='*';
        else if(operand == 3)  vec_operator[k]='/';
        inst=inst<<2; 

    } 
   unsigned int dim;
    m=15<<28;
    dim=inst&m;
    dim=dim>>28;
    dim++;
   
    unsigned short int var;
    var =((N+1)*dim)/16 + (((N+1)*dim)%16);
    int d=0;
    unsigned  int aux;
    int index=0;
    for(;d<var;d++)
    {  
        scanf("%u",&aux);
        int j=0;

        for(;j<16/dim;j++)
        { unsigned short a= 1<<dim;
            m=(a-1)<<(16-dim);
            if(index<=15)
                vec_operand[index++]=(aux&m)>>(16-dim);
            aux=aux<<dim;
        }
    }
    
    unsigned  int sum=vec_operand[0];
    int x=0;
    for(;x<N;x++)
    {
        if(vec_operator[x] == '+') sum += vec_operand[x+1];
        if(vec_operator[x] == '-') sum =sum - vec_operand[x+1];
        if(vec_operator[x] == '*') sum *= vec_operand[x+1];
        if(vec_operator[x] == '/') sum =sum / vec_operand[x+1];


    }

    printf("%u\n",sum);



    return 0;
}
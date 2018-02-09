#include <stdio.h>

char DATA[16];
 
int trentecinq (void)
{
  int address = DATA;
   // __asm ("mov $35,%eax\n");
  //__asm ("mov $0x123456789abcdef0,%r14\n");
  //__asm ("movq %r14,%xmm0\n");
  __asm("mov $0x123456789abcdef0,%rax\n");
  __asm("movq %rax,%xmm0\n");
  __asm("mov $0x123456789abcdef0,%rax\n");
  __asm("movq %rax,%xmm1\n");
  __asm("movlhps %xmm1,%xmm0\n");
  //__asm("movntdq %xmm0,%xmm0\n");
  __asm("mov %0,%%eax\n"
    :
    :"r"(address)
    :"%eax");
  __asm("movntdq %xmm0,%[eax]\n");

}
 
int main (void)
{  
    printf ("%d\n",trentecinq());
    //printf("Adresse : %x\n",address);
    //printf("Adresse : %x\n",&DATA);
    return 0;
}

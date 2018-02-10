#include <stdio.h>

char DATA[16];

int mov_data(void)
{
  __asm("mov $0x123456789abcdef0,%rax\n");
  __asm("movq %rax,%xmm0\n");
  __asm("mov $0x123456789abcdef0,%rax\n");
  __asm("movq %rax,%xmm1\n");
  __asm("movlhps %xmm1,%xmm0\n");
  __asm("movntdq %%xmm0,%0\n" : "=m"(DATA));
}

int main (void)
{
  while(1){
    mov_data();
  }

  return 0;
}

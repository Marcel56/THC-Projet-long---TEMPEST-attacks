#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

char DATA[16];

int * allocate_buffer(int buffer_size){

  int * ptr = malloc(buffer_size);
  int * temp_ptr = ptr;
  int temp_size = buffer_size;
  int rand_value;
  while(temp_size > 0){
    rand_value = rand()%INT_MAX;
    //printf("Random value : %d\n", rand_value);
    *temp_ptr = rand_value;
    //printf("Value in buffer : %d\n", *ptr);
    temp_size -= 4;
    temp_ptr ++;
  }

  return ptr;
}

void mov_data(int * ptr)
{
  //__asm("mov $0x123456789abcdef0,%rax\n");
  __asm("movq %0,%%xmm0\n"
         :
         :"m" (*ptr)
         :"%xmm0");
  //__asm("movq %rax,%xmm0\n");
  //__asm("mov $0x123456789abcdef0,%rax\n");
  //__asm("movq %rax,%xmm1\n");
  __asm("movq %0,%%xmm1\n"
         :
         :"m" (*(ptr+8))
         :"%xmm1");
  __asm("movlhps %xmm1,%xmm0\n");
  __asm("movntdq %%xmm0,%0\n" : "=m"(DATA));
}

int main (void)
{
  int * buffer = allocate_buffer(4096);
  printf("Address : %p\n", buffer);
  int i;
  while(1){
    time_t start=time(NULL);
    //printf("%d\n", start);
    while(time(NULL)-start<1){
      for(i=0;i<4096;i+=4){
        mov_data(buffer+i);
      }
      //printf("loop!");
    }
    sleep(1);
    printf("loop!\n");
  }
  return 0;
}

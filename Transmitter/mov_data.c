#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

//char DATA[16];
float TX_TIME = 0.5;

int * allocate_data(int buffer_size){

  int * ptr = malloc(buffer_size);
  int * temp_ptr = ptr;
  int temp_size = buffer_size;
  int rand_value;
  while(temp_size > 0){
    rand_value = rand()%(INT_MAX-268435456)+268435456;
    //printf("Random value : %d\n", rand_value);
    *temp_ptr = rand_value;
    //printf("Value in buffer : %d\n", *ptr);
    temp_size -= 1;
    temp_ptr ++;
  }

  return ptr;
}

void mov_data(int * data_ptr,char * buffer_ptr )
{
  //__asm("mov $0x123456789abcdef0,%rax\n");
  __asm("movq %0,%%xmm0\n"
         :
         :"m" (*data_ptr)
         :"%xmm0");
  //__asm("movq %rax,%xmm0\n");
  //__asm("mov $0x123456789abcdef0,%rax\n");
  //__asm("movq %rax,%xmm1\n");
  __asm("movq %0,%%xmm1\n"
         :
         :"m" (*(data_ptr+8))
         :"%xmm1");
  __asm("movlhps %xmm1,%xmm0\n");
  __asm("movntdq %%xmm0,%0\n" : "=m"(*buffer_ptr));
}

int main (void)
{
  int * data = allocate_data(4096);
  char * memory_buffer = malloc(16);
  //char * memory_buffer = DATA;
  printf("Memory buffer address : %p\n", memory_buffer);
  int i;
  //for(i=0; i<4; i++){
  //  *(memory_buffer+i)=0x00000000;
  //}
  //for(i=0; i<4096; i++){
   // printf("Address : %p - Value : %x - Int : %d\n", buffer+i, *(buffer+i), *(buffer+i));
    //sleep(1);
  //}
  while(1){
    time_t start=time(NULL);
    //printf("%d\n", start);
    //clock_t t = clock();
    printf("ON! \n");
    int k = 0;
    while(time(NULL)-start<TX_TIME){
      for(i=0;i<4096;i+=4){
        mov_data(data+i, memory_buffer);
        //int j;
	//for(j=0; j<16; j++){
	//  printf("%x",*(memory_buffer+j));
	//}
        //printf("\n");
        //k++;
        //sleep(1);
      }
    }
    //printf("k = %d\n", k);
    printf("OFF! \n");
    usleep(500000);
  }
  return 0;
}

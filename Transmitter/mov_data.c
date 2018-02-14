#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

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
  __asm("movq %0,%%xmm0\n"
         :
         :"m" (*data_ptr)
         :"%xmm0");
  __asm("movq %0,%%xmm1\n"
         :
         :"m" (*(data_ptr+8))
         :"%xmm1");
  __asm("movlhps %xmm1,%xmm0\n");
  __asm("movntdq %%xmm0,%0\n" : "=m"(*buffer_ptr));
}

int main (void)
{
  int i;
  int * data = allocate_data(4096);
  char * memory_buffer = malloc(16);
  //printf("Memory buffer address : %p\n", memory_buffer);

  int * tx_data = allocate_data(sizeof(int));
  printf("Data : %d\n", *tx_data);
  unsigned bit = 0 ;
  unsigned mask = 1 ;
  for(i=0; i<sizeof(int)*8; i++){
    bit = (*tx_data & mask) >> i ;
    printf("%d", bit) ;
    mask <<= 1 ;
  }
  printf("\n");

  while(1){
    time_t start=time(NULL);
    printf("ON! \n");
    while(time(NULL)-start<TX_TIME){
      for(i=0;i<4096;i+=4){
        mov_data(data+i, memory_buffer);
      }
    }
    printf("OFF! \n");
    usleep(TX_TIME*pow(10,6));
  }
  return 0;
}

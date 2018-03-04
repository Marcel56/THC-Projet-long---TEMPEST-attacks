#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <string.h>

float TX_TIME = 1; //Temps de transmission d'un bit
int DATA_SIZE = 128; //Taille maximale en octet des données à transmettre


int * allocate_data(int buffer_size){

  int * ptr = malloc(buffer_size);
  int * temp_ptr = ptr;
  int temp_size = buffer_size;
  int rand_value;
  while(temp_size > 0){
    rand_value = rand()%(INT_MAX-268435456)+268435456;
    *temp_ptr = rand_value;
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


int main (int argc, char ** argv)
{
  int * data_to_move = allocate_data(4096); //Création d'un buffer de données à écrire
  char * memory_buffer = malloc(16); //Création d'un buffer dans lequel les données seront écrites
  int k;

  while (1) {
    //Emission pendant TX_TIME
    time_t start=time(NULL);
    while(time(NULL)-start<TX_TIME){
      for(k=0;k<4096;k+=4){
        mov_data(data_to_move+k, memory_buffer);
      }
    }
    //Non-émission pendant TX_TIME
    usleep(TX_TIME*pow(10,6));
  }

  return 0;
}

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <string.h>

float TX_TIME = 0.5; //Temps de transmission d'un bit
int DATA_SIZE = 128; //Taille maximale en octet des données à transmettre


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


int main (int argc, char ** argv)
{
  //Lecture du pass dans le fichier passé en argument
  int i=1;
  FILE * fd;
  int c;
  int true_data_size;
  char tx_data[DATA_SIZE];

  if(argc == 2){
    fd = fopen(argv[1], "r");

    if (fd != NULL) {
      tx_data[0] = 0xcc; //Création d'un header
      while((c = fgetc(fd)) != EOF){
        tx_data[i] = (char) c;
        i++;
      }
      true_data_size = i;
    } else {
      printf("%s : No such file\n", argv[1]);
      return -1;
    }
    fclose(fd);
  } else {
    printf("No file specified\n");
    return -1;
  }


  //Envoie des données binaires
  int * data_to_move = allocate_data(4096); //Création d'un buffer de données à écrire
  char * memory_buffer = malloc(16); //Création d'un buffer dans lequel les données seront écrites
  int j;

  for(i=0;i<true_data_size; i++){
    for(j = 7; j >= 0; --j){
      if(((tx_data[i] & (1 << j)) ? 1 : 0) == 1){
        //Emission pendant TX_TIME
        time_t start=time(NULL);
        while(time(NULL)-start<TX_TIME){
          for(i=0;i<4096;i+=4){
            mov_data(data_to_move+i, memory_buffer);
          }
        }
        putchar('1');
      } else {
        //Non-émission pendant TX_TIME
        usleep(TX_TIME*pow(10,6));
        putchar('0');
      }
    }
    putchar(' ');
  }
  putchar('\n');

  return 0;
}

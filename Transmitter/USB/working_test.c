#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int BUFFER_SIZE = 6144;
float TX_TIME = 0.002;

int int_to_bin(int k) {
    return (k == 0 || k == 1 ? k : ((k % 2) + 10 * int_to_bin(k / 2)));
}

void fill_buffer_freq(int *buf, int size, double freq) {
 int i = 0;
 int x = 0;
 double t = freq / 4800 * 2;
 for (i = 0, x = 0x00000000; i<size*8; i++)
 {
  x = x<<1;
  if ((int)(i*t)%2==0)
    x++;
  if((i%32)==31)
  {
    *(buf++) = x;
    x=0x00000000;
  }
 }
}


int main(){
  int * buffer_0 = malloc(BUFFER_SIZE);
  int * buffer_1 = malloc(BUFFER_SIZE);

  fill_buffer_freq(buffer_0, BUFFER_SIZE, 200);
  fill_buffer_freq(buffer_1, BUFFER_SIZE, 400);
  
  int i;
  for(i=0;i<100;i++){
    //time_t start=time(NULL);
    if(i%2 == 0){
      printf("1");
      //while(time(NULL)-start<TX_TIME){
        FILE * fd=fopen("/run/media/florian/2890-8E11/test", "w");
        fwrite(buffer_1, BUFFER_SIZE,1,fd);
        fclose(fd);
      //}
    } else {
      printf("0");
      //while(time(NULL)-start<TX_TIME){
        FILE * fd=fopen("/run/media/florian/2890-8E11/test", "w");
        fwrite(buffer_0, BUFFER_SIZE,1,fd);
        fclose(fd);
      //}
    }
  }
  printf("\n"); 
  return 0;

}

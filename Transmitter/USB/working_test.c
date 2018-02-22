#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int BUFFER_SIZE = 614400;

int set_bit(int number, int pos, int bit){
  number ^= (-bit ^ number) & (1 << pos);
  return number;
}

void fill_buffer_freq_2(int *buf, int size, double freq) {
  int i;
  int x = 0x00000000;
  int n = 2400/freq; //nombre de bits dans une demi-période

  //printf("n = %d\n", n);

  int flag = 1;
  for(i=0; i<size*8; i++){
    
    if(flag == 1){
      x = set_bit(x, (7-(i%8))+((i%32)/8)*8, 1);
      //x = set_bit(x, (i%32), 1);
    }

    if(i%n == n-1)
    {
      flag = flag ^ 1;
    }

    if((i%32)==31)
    {
      *buf = x;
      buf++;
      x=0x00000000;
    }
  }
}

int main(int argc, char ** argv){
  int * buffer_0 = malloc(BUFFER_SIZE);
  int * buffer_1 = malloc(BUFFER_SIZE);
  fill_buffer_freq_2(buffer_0, BUFFER_SIZE, 10);
  fill_buffer_freq_2(buffer_1, BUFFER_SIZE, 1000);

  FILE * fd;
  int i;

  fd = fopen("/run/media/florian/2890-8E11/test", "w");
  for(i=0;i<5;i++){
    //fwrite(buffer_1, BUFFER_SIZE,1,fd);
      fwrite(buffer_1, 1, BUFFER_SIZE,fd);
  }
  fclose(fd);
  sleep(15);
  fd = fopen("/run/media/florian/2890-8E11/test2", "w");
  for(i=0;i<5;i++){
    //fwrite(buffer_0, BUFFER_SIZE,1,fd);  
    fwrite(buffer_0, 1, BUFFER_SIZE,fd);  
  }
  fclose(fd);

  return 0;
}

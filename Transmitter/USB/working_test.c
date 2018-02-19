#include <stdio.h>
#include <stdlib.h>

int BUFFER_SIZE = 6144;

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
  int * buffer = malloc(BUFFER_SIZE);
  fill_buffer_freq(buffer, BUFFER_SIZE, 200);
  while(1){
    FILE * fd=fopen("/path/to/USB_key/test", "w");
    fwrite(buffer, BUFFER_SIZE,1,fd);
    fclose(fd);
  } 

  return 0;

}

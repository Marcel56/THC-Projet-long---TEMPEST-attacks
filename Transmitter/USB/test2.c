#include <stdio.h>
#include <stdint.h>
#include <sys/ioctl.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

int BUFFER_SIZE = 6144;

//uint32_t buffer[6000];

uint32_t int_to_bin(uint32_t k) {
    return (k == 0 || k == 1 ? k : ((k % 2) + 10 * int_to_bin(k / 2)));
}

inline static void fill_buffer_freq(uint32_t *buf, int size, double freq) {

 int i = 0;
 uint32_t x = 0;
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
//  printf("%u\n", int_to_bin(buffer));
//  write(fd,buffer,1);
 }
}

int main(){
  //FILE * fd=fopen("/run/media/florian/2890-8E11/test", "w");
  //int fd = open("/media/tsl-sec/cle/test", O_RDWR);
  uint32_t * buffer = malloc(BUFFER_SIZE);
 

 fill_buffer_freq(buffer, BUFFER_SIZE, 200);
  //int i=0;
  while(1){
    FILE * fd=fopen("/path/to/USB_key/test", "w");
    fwrite(buffer, BUFFER_SIZE,1,fd);
    fclose(fd);
    //printf("Loop : %d\n", i);
    //i++;
    //rewind(fd);
  } 
  //fclose(fd);
  
  return 0;
}

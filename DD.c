#include <stdio.h>
#include <stdint.h>
#include <sys/ioctl.h>
#include <string.h>
#include <fcntl.h>


//uint32_t buffer[6000];

uint32_t int_to_bin(uint32_t k) {
    return (k == 0 || k == 1 ? k : ((k % 2) + 10 * int_to_bin(k / 2)));
}

inline static void fill_buffer_freq
(FILE *buf, int size, double freq) {

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
//   *(buf++) = x;
   fwrite(&x,sizeof(uint32_t),1,buf);
   x=0x00000000;
  }
//  printf("%u\n", int_to_bin(buffer));
//  write(fd,buffer,1);
 }
}

int main()
{
 FILE * fd=fopen("/media/tls-sec/cle/test", "w");
 //int fd = open("/media/tls-sec/cle/test", O_RDWR);
 fill_buffer_freq(fd, 6000, 200);
 fclose(fd);
 return 0;
}

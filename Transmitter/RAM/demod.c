#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BYTE_MAX 100

int main(int argc, char *argv[])
{
    FILE* fichier = NULL;
    unsigned char byte;
    unsigned char tab_hex[BYTE_MAX];
    unsigned char tab_bits[BYTE_MAX*8];
    int i, nb_bytes =0;
    int c, k;


    fichier = fopen("test", "rb");

    if (fichier == NULL)
    {
	exit(1);
    }

//on lit le fichier
    while((fread(&byte,sizeof(byte), 1,fichier))!=0){
	printf("%02x ",byte);
//on crée un tableau avec les octets
	tab_hex[i] = byte;
	i++;
    }
    nb_bytes = i;
    printf("\n");

//Pour chaque octet
    for (i=0;i<nb_bytes;i++){

//on les convertit en binaire
        int j=0;
	for (c=7;c>=0; c--){
	    k = tab_hex[i] >> c;
	    if (k & 1){
		tab_bits[i*8+j] = '\x01';
		
	    }
	    else {
		tab_bits[i*8+j] ='\x00';

	    }
	    j++;

	}
	
    } 
    for (i=0;i<nb_bytes*8;i++){
        printf("%d", tab_bits[i]);
    }
    return 0;
	fclose(fichier);

}

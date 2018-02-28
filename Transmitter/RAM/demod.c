#include <stdlib.h>
#include <stdio.h>

#define BYTE_MAX 100

int main(int argc, char *argv[])
{
    FILE* fichier = NULL;
    unsigned char byte;
    unsigned char tab_hex[BYTE_MAX];
    unsigned char octet_bin[8];
//    unsigned char tab_bin[8*BYTE_MAX];
    int i, nb_bytes =0;
    int j, c, k;


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
        j = 7;
	for (c=0;c<=7; c++){
	    k = tab_hex[i] >> c;
	    if (k & 1){
		octet_bin[j]='1';
		//printf("1");
	    }
	    else {
		octet_bin[j]='0';
		//printf("0");
	    }
    	    j--;
	}
	
	    printf("%s ", octet_bin);

    } 

    return 0;
	fclose(fichier);
}

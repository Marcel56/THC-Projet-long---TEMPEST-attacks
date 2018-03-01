#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#define TAILLE_MAX 1000

char * rem_space(char *chaine)
// Enlève les espaces d'un string
{
  int i;
  int j = -1;
  for (i = 0; chaine[i]; i++)
    if (chaine[i] != ' ')
        chaine[++j] = chaine[i];
  chaine[++j] = '\0';
  return(chaine);
}

int bin_to_dec(char * bin)
// Convertit un binaire en décimal
{
  int i, b, dec=0;
  char c;
  for(i=7; i>=0; i--)
  {
    c = *(bin+i);
    b = c - 48;
    dec += b * pow(2, 7-i);
  }
  return(dec);
}

void bin_to_ascii(char * bin, char * ascii)
// Convertit un binaire en ascii
{
  int i, dec;
  char tmp[TAILLE_MAX]="", c;
  for(i=0; i<strlen(bin); i+=8)
  {
    strncpy(tmp, bin+i, 8);
    //printf("%c\n", *(tmp+1));
    dec = bin_to_dec(tmp);
    c = dec;
    ascii[i/8] = c;
  }
  ascii[strlen(bin)/8] = '\0';
}

int main(int argc, char ** argv)
{
    char chaine[TAILLE_MAX],
         commande[30] = "xxd -b ",
         tmp1[TAILLE_MAX],
         tmp2[TAILLE_MAX],
         *tmp3, *tmp4,
         tmp5[TAILLE_MAX]="",
         bin[TAILLE_MAX]="",
         res[TAILLE_MAX]="",
         *pattern="11111111",
         ascii[TAILLE_MAX]="";
    FILE *sortie;

    strcat(commande, argv[1]);
    sortie = popen(commande, "r");
    if(sortie == NULL)
    {
        perror("Erreur popen ");
        exit(EXIT_FAILURE);

    }

    while (fgets(chaine, TAILLE_MAX, sortie) != NULL)
    {
      memset (tmp1, 0, sizeof (tmp1));
      strncpy(tmp1, chaine+10, 55);
      strcpy(tmp2, rem_space(tmp1));
      strcat(bin, tmp2);
    }
    tmp3 = strstr(bin, pattern);
    printf("bin = %s\n", bin);;
    strcpy(tmp5, tmp3+strlen(pattern));
    tmp4 = strstr(tmp5, pattern);
    strncpy(res, tmp5, tmp4-tmp5);
    printf("res = %s\n", res);
    bin_to_ascii(res, ascii); //remplacer bin par res
    printf("ascii = %s\n", ascii);
    pclose(sortie);
    fclose(fic);

    return 0;
}

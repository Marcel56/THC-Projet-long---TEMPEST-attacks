#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#define TAILLE_MAX 1000

void rem_space(char *chaine)
// Enlève les espaces d'un string
{
  int i;
  int j = -1;
  for (i = 0; chaine[i]; i++)
    if (chaine[i] != ' ')
        chaine[++j] = chaine[i];
  chaine[++j] = '\0';
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
  for(i=0; i<(int)strlen(bin); i+=8)
  {
    strncpy(tmp, bin+i, 8);
    //printf("%c\n", *(tmp+1));
    dec = bin_to_dec(tmp);
    c = dec;
    ascii[i/8] = c;
  }
  ascii[strlen(bin)/8] = '\0';
}

void extract_msg(FILE * fic, char * msg, char * pattern)
{
  // Extrait la charge utile du fichier obtenu à la réception du signal
  // Met le résultat en binaire dans la chaine "msg"
  char chaine[TAILLE_MAX],
       tmp1[TAILLE_MAX],
       *tmp2,
       tmp3[TAILLE_MAX]="",
       *tmp4,
       bin[TAILLE_MAX]="";

  while (fgets(chaine, TAILLE_MAX, fic) != NULL)
  {
    memset (tmp1, 0, sizeof (tmp1));
    strncpy(tmp1, chaine+10, 55);
    rem_space(tmp1);
    strcat(bin, tmp1);
  }
  tmp2 = strstr(bin, pattern);
  strcpy(tmp3, tmp2+strlen(pattern));
  tmp4 = strstr(tmp3, pattern);
  strncpy(msg, tmp3, tmp4-tmp3);
}

int main(int argc, char ** argv)
{
  // Déclaration des variables
  char commande[30] = "xxd -b ",
       msg[TAILLE_MAX]="",
       *pattern="11111111",
       ascii[TAILLE_MAX]="";
  FILE *sortie;

  // Teste du nombre d'argument
  if(argc!=2)
  {
    printf("%s\n", "Il faut un argument");
    exit(1);
  }

  // Ouverture du fichier
  strcat(commande, argv[1]);
  sortie = popen(commande, "r");
  if(sortie == NULL)
  {
    perror("Erreur popen ");
    exit(EXIT_FAILURE);

  }

  extract_msg(sortie, msg, pattern);

  bin_to_ascii(msg, ascii);
  printf("ascii = %s\n", ascii);
  pclose(sortie);

  return 0;
}

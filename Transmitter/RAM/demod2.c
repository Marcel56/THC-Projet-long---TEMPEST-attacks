#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define TAILLE_MAX 200

char * rem_space(char *chaine)
{
  int i;
  int j = -1;
  for (i = 0; chaine[i]; i++)
    if (chaine[i] != ' ')
        chaine[++j] = chaine[i];
  chaine[++j] = '\0';
  return(chaine);
}

int main(void)
{
    int c;
    char chaine[TAILLE_MAX], tmp1[TAILLE_MAX], tmp2[TAILLE_MAX];
    FILE *sortie = popen("xxd -b test", "r");
    FILE *fic = fopen("sortie", "w");
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
      fwrite(tmp2, strlen(tmp2), 1, fic);
    }
    pclose(sortie);
    fclose(fic);

    return 0;
}

# THC-Projet-long---TEMPEST-attacks

Ceci est le dépôt du projet long "Wanna TEMPEST your computer?". Dans ce challenge guidé, vous allez découvrir une vulnérabilité permettant d'extraire des données d'un réseau Air-Gapped, c'est-à-dire un réseau coupé du monde extérieur (Internet). Dans ce type d'infrastructure, seules les attaques locales sont possibles.

Nous allons ici mettre en place une attaque dite TEMPEST. L'objectif est d'utiliser les fuites électromagnétiques du matériel afin d'extraire des données utiles. Le composant corrompu sera ici la RAM.

Nous allons présenter la vulnérabilité en utilisant du matériel grand public, facile d'accès et peu cher. La distance entre la source et l'antenne réceptrice sera donc relativement faible mais des traitements plus approfondis et l'utilisation de matériels plus sophistiqués permettraient de réaliser une attaque à plus grande distance.

Ce challenge se déroulera en plusieurs étapes :

- Étude du rayonnement électromagnétique de l'ordinateur avec utilisation d'un analyseur de spectre;
- Écriture d'un programme permettant de contrôler le rayonnement électromagnétique de la RAM;
- Récupération et démodulation du signal émis par la RAM;
- Écriture du malware permettant de transmettre l'information souhaitée.

Vous trouverez dans ce dépôt les différents documents réalisés dans le cadre de ce projet long.

## Comment utiliser ce dépôt?

Le dossier docs contient les pages web permettant de résoudre le challenge. Il est possible d'accéder directement à la page du challenge [ici](https://marcel56.github.io/THC-Projet-long---TEMPEST-attacks/).

Le dossier Transmitter contient les fichiers devant être présents et compilé sur la machine attaquée. Le fichier flag ne devra être lisible que par root et le binaire compilé du fichier malware.c devra être en suid root pour être le seul à pouvoir lire le flag.

Le dossier Receiver contient les fichiers devant être présents sur la machine de la personne résolvant le challenge. Les logiciels GNURadio et URH ainsi que les pilotes RTL-SDR et USRP devront également être installés sur cette machine.

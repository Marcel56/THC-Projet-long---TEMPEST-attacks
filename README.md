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

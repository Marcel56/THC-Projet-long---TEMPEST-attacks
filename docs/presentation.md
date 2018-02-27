# Présentation

À travers ce challenge guidé, vous allez découvrir une vulnérabilité permettant d'extraire des données d'un réseau dit **Air-Gap**, c'est-à-dire un réseau coupé du monde extérieur (internet). Seul les attaques physiques sont donc possibles.
Ici, nous allons mettre en place une attaque dites de **TEMPEST**. L'objectif est d'utiliser les fuites électromagnétiques du matériel pour extraire des données utiles. Le composant corrompu ici est la RAM.

Le matériel idéal à l'exploitation de la fuite n'étant pas à disposition, nous allons uniquement présenter la vulnérabilité. La distance entre la source et l'antenne réceptrice est donc relativement faible ici.

N'étant pas le sujet ici, nous supposerons que l'étape d'ingénierie sociale est réalisé par quelqu'un d'autre pour exécuter notre malware sur la machine victime. 

Ce challenge ce déroulera en plusieurs étapes :
1. Étudier des émanations électromagnétiques de l'ordinateur (avec un analyseur de spectre);
2. Écrire un programme provoquant une émanation électromatique de la RAM;
3. Récupérer et démoduler le signal émis par la RAM;
4. (Écrire le malware permettant de transmettre l'information souhaitée.)
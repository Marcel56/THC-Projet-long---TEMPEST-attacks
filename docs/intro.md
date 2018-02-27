# Introduction

TEMPEST est un nom de code de la NSA faisant référence aux mesures et aux standards liés aux émissions compromettantes des machines traitant de l'information.
Toutes les machines ont des émissions compromettantes (nous allons le voir à l'étape 1). Elles peuvent être de nature électrique, électromagnétique, mécanique ou acoustique, bien que le terme TEMPEST soit généralement utilisé pour parler des émanations électromagnétiques.

Dans ce challenge, nous n'allons pas utiliser les émanations naturelles d'un composant, mais forcer une émanation afin de créer un canal caché, ou canal auxiliaire, pour transmettre de l'information.

Les outils et logiciels nécessaires sont les suivants :
- Un analyseur de spectre;
- Un SDR (Software-defined radio) : USRP/RTL-SDR;
- URH/GNURadio;
- Une antenne.
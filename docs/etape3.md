# Etape 3

À présent, vous savez à quelle fréquence est émis le signal exploitable.
Changer alors de mode dans URH pour réceptionner le signal à la fréquence trouvée précedemment.
Qu'observez vous ?

Vous devrier voir un différence d'amplitude entre le moment ou le programme s'exécute, et celui ou il ne s'exécute pas. Cela veut dire que nous pouvons faire une modulation ASK (Amplitude-shift keying). L'objectif est donc de transmettre un binaire en utilisant l'émanation de la RAM : une forte amplitude correspond à un 1, tandis qu'une faible correspond à un 0.

Modifiez alors le fichier C pour transmettre une altérnance de 0 et 1 0101010101...

Vérifiez alors que votre signal ressemble à un créneau.

À ce stade, un être humain est alors capable de reconstitué le binaire en regardant le signal. Cependant, l'objectif est d'automatiser la recontruction du binaire. Cela s'appelle la **démodulation** du signal.

_La il faudrait mettre les blocs nécessaire à la démodulation du signal, expliquer leur fonctionnement et dire au gars de les mettre dans l'ordre dans GNU Radio._
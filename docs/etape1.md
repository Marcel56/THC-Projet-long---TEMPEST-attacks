# Etape 1

Dans cette étape, nous allons nous assurer qu'un ordinateur émet bien des ondes électromagnétiques.
Pour cela, nous allons utilser un analyseur de spectre. Cet instrument de mesure est destiné à afficher les différentes fréquences contenues dans un signal ainsi que leurs amplitudes respectives.
Pour une plus grande précision, les analyseurs de spectre utilisés en laboratoire sont de ce type :
		_PHOTO_

Ici, nous utiliserons un RTL-SDR ainsi que le logiciel URH. Le RTL-SDR, couplé à son antenne, sert à réceptionner le signal. URH sert quant à lui à l'afficher et le traiter.

**À vous !** Avec URH en mode analyseur de spectre et le RTL-SDR, constatez qu'une activité sur l'ordinateur (un défilement d'une fenêtre par exemple), provoque une augmentation du signal.

À présent, vous devriez être convaincu de l'existance d'émanation électromatique de l'ordinateur.

Dans l'étape 2, vous allez voir qu'il est possible de contrôler les émanations de la RAM avec un petit programme en C. 
#!/bin/bash

while true; do
./AdaAndSpiecesGenerador > gen.txt
./AdaAndSpiecesCuadratico < gen.txt > esperado.txt
./AdaAndSpieces < gen.txt > res.txt


if diff res.txt esperado.txt
then
	echo "Anda"
else
	echo "Fallo"
	break
fi
done

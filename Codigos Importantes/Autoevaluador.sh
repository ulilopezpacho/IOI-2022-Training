#!/bin/bash

while true; do
./$1 > gen.txt
./$2 < gen.txt > res.txt
./$3 < gen.txt > esperado.txt


if diff res.txt esperado.txt
then
	echo "Anda"
else
	echo "Fallo"
	break
fi
done

#!/bin/bash

# Ejemplo realizado para comprender: ps -s root 
# Hacer un script que tiene que guardar el número de procesos de root más del usuario en un fichero con formtato date -Iseconds .txt

ROOT=$(ps -u root | wc -l)
ACTUAL=$(ps -u $USER | wc -l)
FECHA=$(date -Iseconds)

echo $(($ROOT + $ACTUAL)) > $FECHA.txt

# Se ha realizado el script con variables porque veía que era más sencillo de esta manera
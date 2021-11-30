#!/bin/bash

# Contar los directorios y los soflinks que hay en el directorio actual que tengan activado el permiso de ejecución de usuario y de otros

ls -l | grep ^d | cut -d' ' -f1 | grep -e "^......x" | wc -l 
# El comando anterior lo que se pretendía era contar los distintos de que el la posición determinada por la expresión regualar, con eso se determina que no tengan el permiso de ejecución en el campo grupo
# A partir de ahí se tiene la lista reducida
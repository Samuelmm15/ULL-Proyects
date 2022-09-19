!/bin/bash

# Generar en un fichero el listado de archivos y directorios que comiencen por mayúsculas
ls [[:upper:]]* > mayusculas.txt


# Mostrar los 10 primeros archivos que terminen en número ordenados alfabéticamente
ls *[:digit:] | sort -d | head -n10

# Copiar los archivos que comiencen en número y terminen en .txt a un directorio
cp [:digit:]*.txt directorio

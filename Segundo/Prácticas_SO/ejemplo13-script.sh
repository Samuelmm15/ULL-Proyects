#!/bin/bash

# sysinfo - Menú de opciones con la opción -t N que debe de mostrar aquellos procesos con tiempo mayor al establecido como parámetro

# Declaración de variables
tiempo=
BOLD=$(tput bold)
GREEN=$(tput setaf 2)
RESET=$(tput sgr0)

# Declaración de funciones
process_fuction() {
    ps aux --sort=lstart    # Esto no está de manera correcta, ARREGLAR 
}

# Programa principal
if [ "$1" != "" ]; then
    case $1 in
        -h | --help ) 
            clear
            echo "$BOLD usage: [-t] N $RESET"
            echo
            ;;
        -t ) 
            clear
            if [ "$2" = "" ]; then
                echo "No se ha introducido nigún tiempo sobre el que buscar."
                echo "Se establece la búsqueda sobre un segundo."
                tiempo=1
                process_fuction     # accedemos a la función sobre la cual se realiza la operación
            else
                echo "El tiempo establecido establecido por teclado para la búsqueda es $2"
                tiempo=$2
                process_fuction     # accedemos a la función sobre la cual se realiza la operación
            fi
            ;;
        * ) 
            clear
            echo "$GREEN << Opción no disponible >> $RESET"
            echo "$BOLD Para entender el funcionamiento del programa, haga uso de la opción -h o --help $RESET"
            echo
    esac
fi

if [ "$1" = "" ]; then
    echo "$BOLD No se ha añadido ninguna opción la cual usar. $RESET"
    echo
    echo "$GREEN << FINALIZACIÓN DEL PROGRAMA >> $RESET"
    echo
    exit 0
else
    
    echo "Programa ejecutado de manera correcta."
    echo "$GREEN << FINALIZACIÓN DEL PROGRAMA >> $RESET"

fi
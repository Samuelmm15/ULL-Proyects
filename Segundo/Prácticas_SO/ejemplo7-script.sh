#!/bin/bash

# sysinfo - Este ejemplo se trata de un ejemplo de uso del comando case

# Declaración de variables
title="Información general del sistema"
BOLD=$(tput bold)
GREEN=$(tput setaf 2)
RESET=$(tput sgr0)


# Declaración de funciones
case_comand() {
    echo -n "Escribe un número a través de teclado > "
 
}

# Función principal del programa

cat << _EOF_
=== $title ===

$BOLD Uso de las distintas funcionalidades del programa $RESET

$(case_comand)

_EOF_

# Escribo el código en este punto y no en la función, debido a que dentro de la función no realiza la operación y si es colocado en este punto si
read numero
    
    case $numero in
        1 ) echo "El número introducido ha sido 1"
            ;;
        2 ) echo "El número introducido ha sido 2"
            ;;
        * ) echo "El número introducido no ha sido ni uno ni dos"
            ;;
    esac  


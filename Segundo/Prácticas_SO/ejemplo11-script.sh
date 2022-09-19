#!/bin/bash

# sysinfo - Creación de un menú ejemplo

# Declaración de variables
selection=
# Declaración de funciones
press_enter() {
    echo -en "\nPulsa ENTER para continuar"
    read
    clear
}
# Programa principal
until [ "$selection" = "0" ]; do
    echo "
    MENÚ DEL PROGRAMA
    0 - Salir del programa
    1 - Mostrar el espacio libre en disco
    2 - Mostrar la memoria disponible
    "
    echo -n "Introduzca una opción > "
    read -t 20 selection
    echo ""
    case $selection in
        0 ) exit ;;
        1 ) df ;;
        2 ) df ;;
        * ) echo "Introduzca uno de los valores correspondientes."
    esac
    press_enter
done

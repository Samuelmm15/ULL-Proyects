#!/bin/bash

# sysinfo - Plantilla de desarrollo de cualquier programa escrito en bash, de manera general

# Declaración de variables
option=
t_value=
N_value=
u_value=
BOLD=$(tput bold)
GREEN=$(tput setaf 2)
RESET=$(tput sgr0)

# Declaración de funciones
error_exit_u() {
    echo "Se ha producido un error con la opción -u."   # Se ejecuta esta función en el caso de que el comando -u no tenga ningún valor numérico 
    echo "$GREEN SALIDA INMINENTE DEL PROGRAMA $RESET"
    exit 0
}

option_t() {   # función que hace uso de la opción -t
    echo "El valor numérico introducido por teclado es del valor: $t_value"
}

option_u() {
    if [ "$u_value" = "" ]; then
        error_exit_u
    else
        echo "El valor introducido para esta opción por teclado es: $u_value"
    fi
}

# Programa principal

echo "Introduzca una opción por teclado > "
read option N_value

until [ "$option" = "exit" ]; do
    case $option in
        --help | -h ) echo "usage: [-opción]"  # se pueden añadir que compruebe dos opciones o más por caso, haciendo uso de |
                      echo
                      echo "$BOLD Funcionamiento de la opción -t $RESET"
                      echo "usage: -t N"
                      echo
                      echo "$BOLD Funcionamiento de la opción -u $RESET"
                      echo "usage: -u N"
                 exit 0
            ;;
        -t ) clear
             echo "$GREEN INTRODUZCA EL COMANDO DE MANERA CORRECTA > $RESET"
             read option t_value
             option_t    # De esta manera es como se llaman a las funciones dentro de cualquier lugar
            ;;
        -u ) clear  # Otra manera de poder hacer uso de la opción es como lo realizado anteriormente
             echo "La opción -u puede realizar una acción declarada en otra función ejemplo."
             u_value=$N_value   # De esta manera es como se igualan las variables en bash
             option_u   # se llama a la función de la opción
            ;;
        * ) clear
            echo "Para poder entender el funcionamiento del programa hacer uso de la opción -h o --help"
            echo "$GREEN Si se quiere salir del programa, introduza exit como opción por teclado. $RESET"
    esac

echo "Introduzca una opción por teclado > "
read option N_value

done

if [ "$option" != "exit" ]; then  # sirve para el control de errores
    echo "No se ha introducido ninguna opción la cual realizar."
    exit 0
else 
    echo "$BOLD El programa ha finalizado. $RESET"
fi

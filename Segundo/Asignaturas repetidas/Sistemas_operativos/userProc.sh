#!/bin/bash

# Nombre: Samuel
# Apellidos: Martín Morales
# Correo: alu0101359526@ull.edu.es

# sysinfo - Práctica de entrega final de bash "Procesos de Usuarios"

# Declaración de variables

time=

# Estilo de texto

TEXT_BOLD=$(tput bold)
TEXT_GREEN=$(tput setaf 2)
TEXT_UNLINE=$(tput sgr 0 1)
TEXT_RESET=$(tput sgr0)

# Funciones

usage() # Función que muestra la correcta ejecución del script
{
    echo "$TEXT_BOLD<< FUNCIONAMIENTO GENERAL DEL SCRIPT >> $TEXT_RESET"
    echo "usage: ./userProc.sh [-t N] [-h | --help]"
    echo "$TEXT_GREEN N (número entero especificado) $TEXT_RESET"
}

error_exit() # CORREGIR ESTA FUNCIÓN Y PONER COMO SE PIDE
{
    echo "$TEXT_BOLD Se ha producido un <<ERROR>> $TEXT_RESET"
    if [ "$time" = "" ]; then
        echo "script:$TEXT_UNLINE La opción de ejecución -t se ha introducida de manera incorrecta, falta la especificación del entero N. $TEXT_RESET"
    fi
    exit 1
}

user_process()  # Función que muestra por pantalla un listado de todos los usuarios que tiene procesos con tiempo de CPU mayor que un valor N
{
    echo "$TEXT_GREEN El valor del número entero sobre el cual se quieren listar los procesos de usuarios es: $time $TEXT_RESET"
    # El comando para ordenar la lista de procesos según el %CPU    ps aux --sort=+pcpu
    # Página web usada para esto anterior: https://eltallerdelbit.com/como-saber-que-procesos-consumen-mas-cpu-en-linux/#comando_ps
}

# Programa principal

while [ "$1" != "" ]; do # Cuando se ejecuta el script con alguna opción
    case $1 in
        -h | --help )
            usage
            exit 0
        ;;
        -t )
            shift
            time=$1

            if [ "$time" = "" ]; then # En el caso de que el entero N no haya sido introducido junto con la opción -t
                error_exit
            fi
            
            user_process
            exit 0
        ;;
        * )
            echo "<< Opción introducida no soportada >>"
            echo
            usage
            exit 1
    esac
done

if [ "$1" = "" ]; then  # Cuando se ejecuta el script sin ninguna opción
    time=1
    user_process
fi
#!/bin/bash

# Nombre: Samuel
# Apellidos: Martín Morales
# Correo: alu0101359526@ull.edu.es

# sysinfo - Práctica de entrega final de bash "Procesos de Usuarios"

# Declaración de variables

time=
user_list=
user_who=

# Estilo de texto

TEXT_BOLD=$(tput bold)
TEXT_GREEN=$(tput setaf 2)
TEXT_UNLINE=$(tput sgr 0 1)
TEXT_RESET=$(tput sgr0)

# Funciones

usage() # Función que muestra la correcta ejecución del script
{
    echo "$TEXT_BOLD<< FUNCIONAMIENTO GENERAL DEL SCRIPT >> $TEXT_RESET"
    echo "usage: ./userProc.sh [-t N] [-usr] [-u {Lista_Usuarios}] [-count] [-inv] [-pid] [-c] [-h | --help]"
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
    # ps aux | sort -k 1 -r   con k se especifica la columna la cual se quiere ordenar, en este caso la número 10 que corresponde con el tiempo
    # Página usada para entender esto: https://francisconi.org/linux/comandos/sort
    
    if [  ]; then

    fi
}

user_process_usr()   # Función que muestra únicamente los procesos de los usuarios conectados actualmente en el sistema
{
    # ESTO ESTÁ MAL, PERO PENSADO NO ESTÁ TAN MAL
    user_who= who | awk '{ print $2 }'
    ps ux -t $user_who   # En este punto se debe de poner una variable que muestre por pantalla los procesos que se están ejecutando por los usuarios que devuelve el comando who
    exit 0
}

user_process_u()    # Función que muestra los procesos lanzados por usuarios especificos
{
    exit 1
}

user_process_count()    # Función que en vez de sacar la lista de procesos, saca el número de procesos por usuario
{
    exit 1
}

user_process_inv()  # Función que muestra el listado de procesos de manera inversa
{
    exit 1
}

user_process_pid()  # Función que muestra el listado de procesos ordenados por el pid
{
    exit 1
}

user_process_c()    # Función que realiza la ordenación de la lista de procesos según el número de procesos de usuario
{
    exit 1
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
        -usr )
            user_process_usr
        ;;
        -u )
            shift
            user_list=$1    # ESTO EN EL CASO DE QUE SOLO SE INTRODUZCA UN USUARIO, COMPROBAR PARA CUANDO SE INTRODUCE MÁS DE UN USUARIO
            user_process_u
        ;;
        -count )
            user_process_count
        ;;
        -inv )
            user_process_inv
        ;;
        -pid )
            user_process_pid
        ;;
        -c )
            user_process_c
        ;;
        * )
            echo "<< Opción introducida no soportada >>"
            echo
            usage
            exit 1
    esac
done

if [ "$1" = "" ]; then  # Cuando se ejecuta el script sin ninguna opción
    time=0:10
    user_process
fi
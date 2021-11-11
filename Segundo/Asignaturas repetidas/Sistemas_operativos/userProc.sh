#!/bin/bash

# Nombre: Samuel
# Apellidos: Martín Morales
# Correo: alu0101359526@ull.edu.es

# sysinfo - Práctica de entrega final de bash "Procesos de Usuarios"

# Declaración de variables

time=
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
    echo "$TEXT_GREEN {Lista_Usuarios} (Lista de usuarios a los que se quiere aplicar la lista de procesos de estos) $TEXT_RESET"
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
    
    for i in $(ps -A --no-headers --sort=+user | awk '{print $1}'); do      # Con la setencia $(comando), se puede hacer uso de comando dentro del bucle for
        for j in $(ps --pid $i --no-headers -o etimes); do       # Con la opción etimes muestra el tiempo en segundos
            if [ "$j" -ge "$time" ]; then   
                ps --pid $i -u --no-headers 
            fi
        done
    done        
}

user_process_usr()   # Función que muestra únicamente los procesos de los usuarios conectados actualmente en el sistema
{
    for i in $(who | awk '{print $1}'); do  # En este punto se obtiene cada usuario conectado
        echo
        echo "$TEXT_BOLD El usuario al que se le van a listar los procesos es: $i $TEXT_RESET"
        echo
        for j in $(ps -u $i --no-headers | awk '{print $1}'); do    # En este punto se obtiene el pid de cada proceso
            for k in $(ps --pid $j --no-headers -o etimes); do # En este punto se obtiene el tiempo a comparar
                if [ "$k" -ge "$time" ]; then
                    ps --pid $j -u --no-headers
                fi
            done
        done
    done
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
            if [ "$time" = "" ]; then
                time=1
            fi
            user_process_usr
            exit 0
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
    time=1
    user_process
fi
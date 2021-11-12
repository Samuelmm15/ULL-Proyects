#!/bin/bash

# Nombre: Samuel
# Apellidos: Martín Morales
# Correo: alu0101359526@ull.edu.es

# sysinfo - Práctica de entrega final de bash "Procesos de Usuarios"

# Declaración de variables

time=
count=
add=
result=
inv=
pid=
user_list=


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
    
    if [ "$inv" != 1 ]; then
        for i in $(ps -A --no-headers --sort=+user | awk '{print $1}'); do      # Con la setencia $(comando), se puede hacer uso de comando dentro del bucle for
            for j in $(ps --pid $i --no-headers -o etimes); do       # Con la opción etimes muestra el tiempo en segundos
                if [ "$j" -ge "$time" ]; then   
                    ps --pid $i -u --no-headers 
                fi
            done
        done 
    elif [ "$inv" = 1 ]; then
        for i in $(ps -A --no-headers --sort=-user | awk '{print $1}'); do      # Con la setencia $(comando), se puede hacer uso de comando dentro del bucle for
            for j in $(ps --pid $i --no-headers -o etimes); do       # Con la opción etimes muestra el tiempo en segundos
                if [ "$j" -ge "$time" ]; then   
                    ps --pid $i -u --no-headers 
                fi
            done
        done 
    fi       
}

user_process_usr()   # Función que muestra únicamente los procesos de los usuarios conectados actualmente en el sistema
{
    if [ "$count" != 1 ] && [ "$pid" != 1 ]; then
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
    elif [ "$count" = 1 ]; then
        for i in $(who | awk '{print $1}'); do  # En este punto se obtiene cada usuario conectado
            echo
            echo "$TEXT_BOLD El usuario al que se va a mostrar el número total de procesos es: $i $TEXT_RESET"
            echo
            for j in $(ps -u $i --no-headers | awk '{print $1}'); do    # En este punto se obtiene el pid de cada proceso
                for k in $(ps --pid $j --no-headers -o etimes); do # En este punto se obtiene el tiempo a comparar
                    if [ "$k" -ge "$time" ]; then
                        add=$(ps --pid $j -u --no-headers | wc -l)
                        let result=$result+$add
                    fi
                done
            done
            echo " El número total de procesos es: $result"
        done
    elif [ "$pid" = 1 ]; then   # En este caso se ha ordenado de manera inversa en cuanto al pid del proceso
        for i in $(who | awk '{print $1}'); do  # En este punto se obtiene cada usuario conectado
            echo
            echo "$TEXT_BOLD El usuario al que se le van a listar los procesos es: $i $TEXT_RESET"
            echo
            for j in $(ps -u $i --no-headers --sort=-pid | awk '{print $1}'); do    # En este punto se obtiene el pid de cada proceso
                for k in $(ps --pid $j --no-headers -o etimes); do # En este punto se obtiene el tiempo a comparar
                    if [ "$k" -ge "$time" ]; then
                        ps --pid $j -u --no-headers
                    fi
                done
            done
        done
    fi
    
}

user_process_u()    # Función que muestra los procesos lanzados por usuarios especificos
{
    # AÑADIR UNA SALIDA CON ERROR CUANDO SE PRODUCE QUE EL USUARIO NO ES ENCUENTRA EN /ect/passwd 

    if [ "$count" != 1 ] && [ "$pid" != 1 ]; then
        echo
        echo "$TEXT_BOLD La lista de procesos para el usuario: $user_list $TEXT_RESET"
        echo
        for i in $(ps -u $user_list --no-headers | awk '{print $1}'); do
            for j in $(ps --pid $i --no-headers -o etimes); do
                if [ "$j" -ge "$time" ]; then
                    ps --pid $i -u --no-headers
                fi
            done
        done
    elif [ "$count" = 1 ]; then
        echo
        echo "$TEXT_BOLD El número de procesos de la lista del usuario $user_list es: $TEXT_RESET"
        for i in $(ps -u $user_list --no-headers | awk '{print $1}'); do
            for j in $(ps --pid $i --no-headers -o etimes); do
                if [ "$j" -ge "$time" ]; then
                    add=$(ps --pid $i -u --no-headers | wc -l)
                    let result=$result+$add     # El comando let permite realizar operaciones aritméticas en los scripts de bash
                fi
            done
        done
        echo " $result"
    elif [ "$pid" = 1 ]; then   # Impreso de manera inversa teniendo en cuenta el pid
        echo
        echo "$TEXT_BOLD La lista de procesos de manera inversa para el usuario: $user_list $TEXT_RESET"
        echo
        for i in $(ps -u $user_list --no-headers --sort=-pid | awk '{print $1}'); do
            for j in $(ps --pid $i --no-headers -o etimes); do
                if [ "$j" -ge "$time" ]; then
                    ps --pid $i -u --no-headers
                fi
            done
        done
    fi

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

if [ "$1" = "" ]; then  # Cuando se ejecuta el script sin ninguna opción
    time=1
    user_process
fi  # El condicional se pone antes debido a que si se ponen distintas opciones de ejecución por línea de comando tras lanzarlas todas también entra en este condional

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
            
            for i in $*; do     # La variable $*, se trata de un parámetro posicional especial que contiene un string que contiene todos los argumentos separados por un separador
                if [ "$i" = "-inv" ]; then
                    inv=1
                fi
            done

            user_process
        ;;
        -usr )
            if [ "$time" = "" ]; then
                time=1
            fi

            for i in $*; do     # La variable $*, se trata de un parámetro posicional especial que contiene un string que contiene todos los argumentos separados por un separador
                if [ "$i" = "-count" ]; then
                    count=1
                fi
            done

            for i in $*; do     # La variable $*, se trata de un parámetro posicional especial que contiene un string que contiene todos los argumentos separados por un separador
                if [ "$i" = "-pid" ]; then
                    pid=1
                fi
            done

            user_process_usr
        ;;
        -u )
            if [ "$time" = "" ]; then
                time=1
            fi

            for i in $*; do     # La variable $*, se trata de un parámetro posicional especial que contiene un string que contiene todos los argumentos separados por un separador
                if [ "$i" = "-count" ]; then
                    count=1
                fi
            done

            for i in $*; do     # La variable $*, se trata de un parámetro posicional especial que contiene un string que contiene todos los argumentos separados por un separador
                if [ "$i" = "-pid" ]; then
                    pid=1
                fi
            done

            while [ "$2" != "-t" ] && [ "$2" != "-usr" ] && [ "$2" != "-count" ] && [ "$2" != "-inv" ] && [ "$2" != "-pid" ] && [ "$2" != "-c" ] && [ "$2" != "" ]; do
                shift 
                user_list=$1
                user_process_u
            done
        ;;
        -count )    # COMPROBAR COMO EJECUTAR TODO SIN NECESIDAD DE QUE SE TENGAN QUE PONER COMO CASOS ESTAS OPCIONES
            exit 1
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
            echo
            echo "<< Opción introducida no soportada >>"
            echo
            usage
            exit 1
    esac
    shift   # Con este shift se pueden usar varias opciones
done
exit 0  # Salida de manera correcta del programa
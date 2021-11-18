#!/bin/bash

# Nombre: Samuel
# Apellidos: Martín Morales
# Correo: alu0101359526@ull.edu.es

# sysinfo - Práctica de entrega final de bash "Procesos de Usuarios"

# Declaración de variables

time=
option_count=
add=
result=0
usu_uid=
usu_gid=
usu_max_time=
usu_max_pid=
option_inv=
option_pid=
option_c=
process_value=
comparation_c=0
before_user=a
actual_user=
user_list=

# Estilo de texto

TEXT_BOLD=$(tput bold)
TEXT_GREEN=$(tput setaf 2)
TEXT_UNLINE=$(tput sgr 0 1)
TEXT_RESET=$(tput sgr0)

# Funciones

usage()
{
    echo "$TEXT_BOLD<< FUNCIONAMIENTO GENERAL DEL SCRIPT >> $TEXT_RESET"
    echo "usage: ./userProc.sh [-t N] [-usr] [-u {Lista_Usuarios}] [-count] [-inv] [-pid] [-c] [-h | --help]"
    echo "$TEXT_GREEN N (número entero especificado) $TEXT_RESET"
    echo "$TEXT_GREEN {Lista_Usuarios} (Lista de usuarios a los que se quiere aplicar la lista de procesos de estos) $TEXT_RESET"
}

error_exit()
{
    echo "$TEXT_BOLD Se ha producido un <<ERROR>> $TEXT_RESET"
    if [ "$time" = "" ]; then
        echo "script:$TEXT_UNLINE La opción de ejecución -t se ha introducida de manera incorrecta, falta la especificación del entero N. $TEXT_RESET"
    fi
    exit 1
}

user_process()
{
    echo "$TEXT_GREEN El valor del número entero sobre el cual se quieren listar los usuarios es: $time $TEXT_RESET"

    if [ "$option_inv" != 1 ]; then
        for i in $(ps -A --no-headers -o user --sort=+user | awk '{print $1}'); do      # Con la setencia $(comando), se puede hacer uso de comando dentro del bucle for
            actual_user=$i
            for j in $(ps -u $i --no-headers -o etimes); do       # Con la opción etimes muestra el tiempo en segundos
                if [ "$j" -ge "$time" ]; then   
                    let result=$result+1
                fi
            done
            if [ "$before_user" != "$actual_user" ]; then
                usu_uid=$(id -u $i)
                usu_gid=$(id -g $i)
                usu_max_time=$(ps -u $i --no-headers --sort=time | tail -n 1 | awk '{print $3}')
                usu_max_pid=$(ps -u $i --no-headers --sort=time | tail -n 1 | awk '{print $1}'
)
                echo
                echo "$TEXT_BOLD Usuario: $i $TEXT_RESET"
                echo "UID del usuario: $usu_uid"
                echo "GID del usuario: $usu_gid"
                echo "Número total del procesos mayores que el tiempo $time: $result"
                echo "Pid del proceso con mayor tiempo consumido: $usu_max_pid"
                echo "Tiempo del proceso con mayor tiempo consumido: $usu_max_time"
                echo
                before_user=$actual_user
                result=0
            elif [ "$before_user" = "$actual_user" ]; then
                before_user=$actual_user
                result=0
            fi
        done 
    fi
}

user_process_usr()
{
    if [ "$option_count" != 1 ] && [ "$option_pid" != 1 ] && [ "$option_c" != 1 ]; then
        for i in $(who | uniq | awk '{print $1}'); do  # En este punto se obtiene cada usuario conectado
            echo
            echo "$TEXT_BOLD El usuario al que se le van a listar los procesos es: $i $TEXT_RESET"
            echo
            actual_user=$i
        for j in $(ps -u $i --no-headers -o etimes); do       # Con la opción etimes muestra el tiempo en segundos
            if [ "$j" -ge "$time" ]; then   
                let result=$result+1
            fi
        done
        if [ "$before_user" != "$actual_user" ]; then
            usu_uid=$(id -u $i)
            usu_gid=$(id -g $i)
            usu_max_time=$(ps -u $i --no-headers --sort=time | tail -n 1 | awk '{print $3}')
            usu_max_pid=$(ps -u $i --no-headers --sort=time | tail -n 1 | awk '{print $1}')
            echo
            echo "$TEXT_BOLD Usuario: $i $TEXT_RESET"
            echo "UID del usuario: $usu_uid"
            echo "GID del usuario: $usu_gid"
            echo "Número total del procesos mayores que el tiempo $time: $result"
            echo "Pid del proceso con mayor tiempo consumido: $usu_max_pid"
            echo "Tiempo del proceso con mayor tiempo consumido: $usu_max_time"
            echo
            before_user=$actual_user
            result=0
        elif [ "$before_user" = "$actual_user" ]; then
            before_user=$actual_user
            result=0
        fi
        done
    fi
}

user_process_u()
{
     if [ "$option_count" != 1 ] && [ "$option_pid" != 1 ] && [ "$option_c" != 1 ]; then
        echo
        echo "$TEXT_BOLD La lista de procesos para el usuario: $user_list $TEXT_RESET"
        echo        
        actual_user=$user_list
        for i in $(ps -u $user_list --no-headers -o etimes); do       # Con la opción etimes muestra el tiempo en segundos
            if [ "$i" -ge "$time" ]; then   
                let result=$result+1
            fi
        done
        if [ "$before_user" != "$actual_user" ]; then
            usu_uid=$(id -u $actual_user)
            usu_gid=$(id -g $actual_user)
            usu_max_time=$(ps -u $actual_user --no-headers --sort=time | tail -n 1 | awk '{print $3}')
            usu_max_pid=$(ps -u $actual_user --no-headers --sort=time | tail -n 1 | awk '{print $1}')
            echo
            echo "$TEXT_BOLD Usuario: $actual_user $TEXT_RESET"
            echo "UID del usuario: $usu_uid"
            echo "GID del usuario: $usu_gid"
            echo "Número total del procesos mayores que el tiempo $time: $result"
            echo "Pid del proceso con mayor tiempo consumido: $usu_max_pid"
            echo "Tiempo del proceso con mayor tiempo consumido: $usu_max_time"
            echo
            before_user=$actual_user
        elif [ "$before_user" = "$actual_user" ]; then
            before_user=$actual_user
        fi
     fi
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
                    option_inv=1
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
                    option_count=1
                fi
            done

            for i in $*; do     # La variable $*, se trata de un parámetro posicional especial que contiene un string que contiene todos los argumentos separados por un separador
                if [ "$i" = "-pid" ]; then
                    option_pid=1
                fi
            done

            for i in $*; do     # La variable $*, se trata de un parámetro posicional especial que contiene un string que contiene todos los argumentos separados por un separador
                if [ "$i" = "-c" ]; then
                    option_c=1
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
                    option_count=1
                fi
            done

            for i in $*; do     # La variable $*, se trata de un parámetro posicional especial que contiene un string que contiene todos los argumentos separados por un separador
                if [ "$i" = "-pid" ]; then
                    option_pid=1
                fi
            done

            for i in $*; do     # La variable $*, se trata de un parámetro posicional especial que contiene un string que contiene todos los argumentos separados por un separador
                if [ "$i" = "-c" ]; then
                    option_c=1
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
            exit 1
        ;;
        -pid )
            exit 1
        ;;
        -c )
            exit 1
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
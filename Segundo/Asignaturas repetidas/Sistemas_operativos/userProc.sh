#!/bin/bash

# Nombre: Samuel
# Apellidos: Martín Morales
# Correo: alu0101359526@ull.edu.es

# sysinfo - Práctica de entrega final de bash "Procesos de Usuarios"

# Declaración de variables

time=
result=0
user_name=
usu_uid=
usu_gid=
usu_max_time=
usu_max_pid=
option_count=
option_inv=
option_pid=
option_c=
process_value=
comparation_c=0
before_user=a
actual_user=
user_list=()
user_list_sorted=()
total_process_list=()
total_process_list_sorted=()
usr_list=()
usr_list_sorted=()
max_proccess_pid=()    # Declaración de un array
max_proccess_pid_sorted=()
counter=0
auxiliary=0
actual_number=
before_number=0

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

    if [ "$option_count" != 1 ] && [ "$option_inv" != 1 ] && [ "$option_pid" != 1 ] && [ "$option_c" != 1 ]; then     # Caso estándar de la opción -t
        for i in $(ps -A --no-headers -o user --sort=+user | awk '{print $1}'); do      # Con la setencia $(comando), se puede hacer uso de comando dentro del bucle for
            actual_user=$i
            result=$(ps -u $i --no-headers | wc -l)
            if [ "$before_user" != "$actual_user" ]; then
                usu_uid=$(id -u $i)
                usu_gid=$(id -g $i)
                usu_max_time=$(ps -u $i --no-headers --sort=time | tail -n 1 | awk '{print $3}')
                usu_max_pid=$(ps -u $i --no-headers --sort=time | tail -n 1 | awk '{print $1}')
                echo
                echo "$TEXT_BOLD Usuario: $i $TEXT_RESET"
                echo "UID del usuario: $usu_uid"
                echo "GID del usuario: $usu_gid"
                echo "Número total de procesos del usuario: $result"
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
    elif [ "$option_count" = 1 ]; then  # Caso de la opción -t con la opción -count
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
                usu_max_pid=$(ps -u $i --no-headers --sort=time | tail -n 1 | awk '{print $1}')
                echo
                echo "$TEXT_BOLD Usuario: $i $TEXT_RESET"
                echo "UID del usuario: $usu_uid"
                echo "GID del usuario: $usu_gid"
                echo "Número total del procesos mayores que $time segundo[s]: $result"
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
    elif [ "$option_inv" = 1 ]; then    # Caso de la opción -t con la opción -inv
        for i in $(ps -A --no-headers -o user --sort=-user | awk '{print $1}'); do      # Con la setencia $(comando), se puede hacer uso de comando dentro del bucle for
            actual_user=$i
            result=$(ps -u $i --no-headers | wc -l)
            if [ "$before_user" != "$actual_user" ]; then
                usu_uid=$(id -u $i)
                usu_gid=$(id -g $i)
                usu_max_time=$(ps -u $i --no-headers --sort=time | tail -n 1 | awk '{print $3}')
                usu_max_pid=$(ps -u $i --no-headers --sort=time | tail -n 1 | awk '{print $1}')
                echo
                echo "$TEXT_BOLD Usuario: $i $TEXT_RESET"
                echo "UID del usuario: $usu_uid"
                echo "GID del usuario: $usu_gid"
                echo "Número total de procesos del usuario: $result"
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
    elif [ "$option_pid" = 1 ]; then    # Caso de la opción -t con la opción -pid
        # Entiendo que la lista de usuarios se ordena por el pid del proceso con más tiempo consumido
        for i in $(ps -A --no-headers -o user --sort=+user | uniq | awk '{print $1}'); do
            for j in $(ps -u $i --no-headers --sort=time | tail -n 1 | awk '{print $1}'); do
                max_proccess_pid[counter]=$j
            done
            let counter=$counter+1
        done
        
        max_proccess_pid_sorted=($(for i in "${max_proccess_pid[@]}"; do echo $i; done | sort -h))  # ordenación del vector de los pid de menor a mayor
        
        for i in "${max_proccess_pid_sorted[@]}"; do    # Lista de usuarios ordenada por el pid del proceso con más tiempo consumido
                user_name=$(ps --pid $i --no-headers -u | awk '{print $1}')
                usu_uid=$(id -u $user_name)
                usu_gid=$(id -g $user_name)
                result=$(ps -u $user_name --no-headers | wc -l)
                usu_max_time=$(ps -u $user_name --no-headers --sort=time | tail -n 1 | awk '{print $3}')
                usu_max_pid=$(ps -u $user_name --no-headers --sort=time | tail -n 1 | awk '{print $1}')
                echo
                echo "$TEXT_BOLD Usuario: $user_name $TEXT_RESET"
                echo "UID del usuario: $usu_uid"
                echo "GID del usuario: $usu_gid"
                echo "Número total de procesos del usuario: $result"
                echo "Pid del proceso con mayor tiempo consumido: $usu_max_pid"
                echo "Tiempo del proceso con mayor tiempo consumido: $usu_max_time"
                echo
        done

        # Paǵina de ordenando un array: https://licodeli.blogspot.com/2017/08/ordenando-un-array.html
        
    elif [ "$option_c" = 1 ]; then
        for i in $(ps -A --no-headers -o user --sort=+user | uniq | awk '{print $1}'); do
            for j in $(ps -u $i --no-headers | wc -l); do
                total_process_list[counter]=$j
            done
            user_list[counter]=$i
            let counter=$counter+1 
        done

        total_process_list_sorted=($(for i in "${total_process_list[@]}"; do echo $i; done | sort -h))  # ordenación del vector de los procesos totales de menor a mayor
        
        for i in "${total_process_list_sorted[@]}"; do
            actual_number=$i
            for j in "${user_list[@]}"; do
                auxiliary=$(ps -u $j --no-headers | wc -l)
                if [ "$i" = "$auxiliary" ] && [ "$actual_number" != "$before_number" ]; then
                    usu_uid=$(id -u $j)
                    usu_gid=$(id -g $j)
                    usu_max_time=$(ps -u $j --no-headers --sort=time | tail -n 1 | awk '{print $3}')
                    usu_max_pid=$(ps -u $j --no-headers --sort=time | tail -n 1 | awk '{print $1}')
                    echo
                    echo "$TEXT_BOLD Usuario: $j $TEXT_RESET"
                    echo "UID del usuario: $usu_uid"
                    echo "GID del usuario: $usu_gid"
                    echo "Número total de procesos del usuario: $auxiliary"
                    echo "Pid del proceso con mayor tiempo consumido: $usu_max_pid"
                    echo "Tiempo del proceso con mayor tiempo consumido: $usu_max_time"
                    echo
                elif [ "$actual_number" = "$before_number" ]; then
                    before_number=$actual_number
                fi
            done
            before_number=$actual_number
        done
    fi
}

user_process_usr()
{
    if [ "$option_count" != 1 ] && [ "$option_inv" != 1 ] && [ "$option_pid" != 1 ] && [ "$option_c" != 1 ]; then     # Caso en el que se pide de manera estándar la opción usr
        for i in $(who | awk '{print $1}'); do  # En este punto se obtiene cada usuario conectado
            usr_list[counter]=$i
            let counter=$counter+1
        done

        usr_list_sorted=($(for i in "${usr_list[@]}"; do echo $i; done | sort -d))  # ordenación del vector en orden alfabético

        for i in "${usr_list_sorted[@]}"; do
            actual_user=$i
            if [ "$before_user" != "$actual_user" ]; then
                echo
                echo "$TEXT_BOLD El usuario al que se le van a listar los procesos es: $i $TEXT_RESET"
            fi
            result=$(ps -u $i --no-headers | wc -l)
            if [ "$before_user" != "$actual_user" ]; then
                usu_uid=$(id -u $i)
                usu_gid=$(id -g $i)
                usu_max_time=$(ps -u $i --no-headers --sort=time | tail -n 1 | awk '{print $3}')
                usu_max_pid=$(ps -u $i --no-headers --sort=time | tail -n 1 | awk '{print $1}')
                echo
                echo "$TEXT_BOLD Usuario: $i $TEXT_RESET"
                echo "UID del usuario: $usu_uid"
                echo "GID del usuario: $usu_gid"
                echo "Número total del procesos del usuario: $result"
                echo "Pid del proceso con mayor tiempo consumido: $usu_max_pid"
                echo "Tiempo del proceso con mayor tiempo consumido: $usu_max_time"
                echo
                before_user=$actual_user
                result=0
            elif [ "$before_user" = "$actual_user" ]; then  # 
                before_user=$actual_user
                result=0
            fi
        done

        # for j in ${usr_list[@]}; do # Impresión del vector
            # echo "$j"
        # done
    elif [ "$option_count" = 1 ]; then  # Caso en el que se pide usr con la opción -count
        for i in $(who | awk '{print $1}'); do  # En este punto se obtiene cada usuario conectado
            usr_list[counter]=$i
            let counter=$counter+1
        done

        usr_list_sorted=($(for i in "${usr_list[@]}"; do echo $i; done | sort -d))  # ordenación del vector en orden alfabético

        for i in "${usr_list_sorted[@]}"; do
            actual_user=$i
             if [ "$before_user" != "$actual_user" ]; then
                echo
                echo "$TEXT_BOLD El usuario al que se le van a listar los procesos es: $i $TEXT_RESET"
            fi
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
                echo "Número total del procesos mayores que $time segundo[s]: $result"
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
    elif [ "$option_inv" = 1 ]; then    # caso en el que se pide usr con la opción -inv
        for i in $(who | awk '{print $1}'); do  # En este punto se obtiene cada usuario conectado
            usr_list[counter]=$i
            let counter=$counter+1
        done
        
        usr_list_sorted=($(for i in "${usr_list[@]}"; do echo $i; done | sort -d -r))  # ordenación del vector en orden alfabético de manera inversa

        for i in "${usr_list_sorted[@]}"; do
            actual_user=$i
            if [ "$before_user" != "$actual_user" ]; then
                echo
                echo "$TEXT_BOLD El usuario al que se le van a listar los procesos es: $i $TEXT_RESET"
            fi
            result=$(ps -u $i --no-headers | wc -l)
            if [ "$before_user" != "$actual_user" ]; then
                usu_uid=$(id -u $i)
                usu_gid=$(id -g $i)
                usu_max_time=$(ps -u $i --no-headers --sort=time | tail -n 1 | awk '{print $3}')
                usu_max_pid=$(ps -u $i --no-headers --sort=time | tail -n 1 | awk '{print $1}')
                echo
                echo "$TEXT_BOLD Usuario: $i $TEXT_RESET"
                echo "UID del usuario: $usu_uid"
                echo "GID del usuario: $usu_gid"
                echo "Número total del procesos del usuario: $result"
                echo "Pid del proceso con mayor tiempo consumido: $usu_max_pid"
                echo "Tiempo del proceso con mayor tiempo consumido: $usu_max_time"
                echo
                before_user=$actual_user
                result=0
            elif [ "$before_user" = "$actual_user" ]; then  # 
                before_user=$actual_user
                result=0
            fi
        done
    elif [ "$option_pid" = 1 ]; then    # caso en el que se pide usr con la opción -pid
        for i in $(who | awk '{print $1}'); do  # En este punto se obtiene cada usuario conectado
            actual_user=$i
            if [ "$actual_user" != "$before_user" ]; then
                usr_list[counter]=$i
                let counter=$counter+1
                before_user=$actual_user
            elif [ "$actual_user" = "$before_user" ]; then
                before_user=$actual_user
            fi
        done
        
        counter=0

        for i in "${usr_list[@]}"; do
            for j in $(ps -u $i --no-headers --sort=time | tail -n 1 | awk '{print $1}'); do
                max_proccess_pid[counter]=$j
            done
            let counter=$counter+1
        done

        max_proccess_pid_sorted=($(for i in "${max_proccess_pid[@]}"; do echo $i; done | sort -h))  # ordenación del vector de los pid de menor a mayor

        for i in "${max_proccess_pid_sorted[@]}"; do    # Lista de usuarios ordenada por el pid del proceso con más tiempo consumido
                user_name=$(ps --pid $i --no-headers -u | awk '{print $1}')
                usu_uid=$(id -u $user_name)
                usu_gid=$(id -g $user_name)
                result=$(ps -u $user_name --no-headers | wc -l)
                usu_max_time=$(ps -u $user_name --no-headers --sort=time | tail -n 1 | awk '{print $3}')
                usu_max_pid=$(ps -u $user_name --no-headers --sort=time | tail -n 1 | awk '{print $1}')
                echo
                echo "$TEXT_BOLD Usuario: $user_name $TEXT_RESET"
                echo "UID del usuario: $usu_uid"
                echo "GID del usuario: $usu_gid"
                echo "Número total de procesos del usuario: $result"
                echo "Pid del proceso con mayor tiempo consumido: $usu_max_pid"
                echo "Tiempo del proceso con mayor tiempo consumido: $usu_max_time"
                echo
        done
    elif [ "$option_c" = 1 ]; then  # caso en el que se hace uso de la opción -usr con -c
        for i in $(who | awk '{print $1}'); do  # En este punto se obtiene cada usuario conectado
            for j in $(ps -u $i --no-headers | wc -l); do
                total_process_list[counter]=$j
            done
            usr_list[counter]=$i
            let counter=$counter+1
        done

        total_process_list_sorted=($(for i in "${total_process_list[@]}"; do echo $i; done | sort -h))  # ordenación del vector de los procesos totales de menor a mayor

        for i in "${total_process_list_sorted[@]}"; do
            actual_number=$i
            for j in "${usr_list[@]}"; do
                actual_user=$j
                auxiliary=$(ps -u $j --no-headers | wc -l)
                if [ "$i" = "$auxiliary" ] && [ "$actual_number" != "$before_number" ] && [ "$actual_user" != "$before_user" ]; then
                    usu_uid=$(id -u $j)
                    usu_gid=$(id -g $j)
                    usu_max_time=$(ps -u $j --no-headers --sort=time | tail -n 1 | awk '{print $3}')
                    usu_max_pid=$(ps -u $j --no-headers --sort=time | tail -n 1 | awk '{print $1}')
                    echo
                    echo "$TEXT_BOLD Usuario: $j $TEXT_RESET"
                    echo "UID del usuario: $usu_uid"
                    echo "GID del usuario: $usu_gid"
                    echo "Número total de procesos del usuario: $auxiliary"
                    echo "Pid del proceso con mayor tiempo consumido: $usu_max_pid"
                    echo "Tiempo del proceso con mayor tiempo consumido: $usu_max_time"
                    echo
                    before_user=$actual_user
                elif [ "$actual_number" = "$before_number" ]; then
                    before_number=$actual_number
                fi
                if [ "$actual_user" = "$before_user" ]; then
                    before_user=$actual_user
                fi
            done
            before_number=$actual_number
        done
    fi
}

user_process_u()
{
    if [ "$option_count" != 1 ] && [ "$option_inv" != 1 ] && [ "$option_pid" != 1 ] && [ "$option_c" != 1 ]; then     # Caso estándar de la opción -u
        user_list_sorted=($(for i in "${user_list[@]}"; do echo $i; done | sort -d))  # ordenación del vector en orden alfabético
        
        for i in "${user_list_sorted[@]}"; do
            echo
            echo "$TEXT_BOLD La lista de procesos para el usuario: $i $TEXT_RESET"
            echo        
            result=$(ps -u $i --no-headers | wc -l)
            usu_uid=$(id -u $i)
            usu_gid=$(id -g $i)
            usu_max_time=$(ps -u $i --no-headers --sort=time | tail -n 1 | awk '{print $3}')
            usu_max_pid=$(ps -u $i --no-headers --sort=time | tail -n 1 | awk '{print $1}')
            echo
            echo "$TEXT_BOLD Usuario: $i $TEXT_RESET"
            echo "UID del usuario: $usu_uid"
            echo "GID del usuario: $usu_gid"
            echo "Número total del procesos del usuario: $result"
            echo "Pid del proceso con mayor tiempo consumido: $usu_max_pid"
            echo "Tiempo del proceso con mayor tiempo consumido: $usu_max_time"
            echo
            result=0
        done
    elif [ "$option_count" = 1 ]; then  # caso en el que se pide -u con la opción -count
        user_list_sorted=($(for i in "${user_list[@]}"; do echo $i; done | sort -d))  # ordenación del vector en orden alfabético

        for i in "${user_list_sorted[@]}"; do
            echo
            echo "$TEXT_BOLD La lista de procesos para el usuario: $i $TEXT_RESET"
            echo        
            for j in $(ps -u $i --no-headers -o etimes); do       # Con la opción etimes muestra el tiempo en segundos
                if [ "$j" -ge "$time" ]; then   
                    let result=$result+1
                fi
            done

            usu_uid=$(id -u $i)
            usu_gid=$(id -g $i)
            usu_max_time=$(ps -u $i --no-headers --sort=time | tail -n 1 | awk '{print $3}')
            usu_max_pid=$(ps -u $i --no-headers --sort=time | tail -n 1 | awk '{print $1}')
            echo
            echo "$TEXT_BOLD Usuario: $i $TEXT_RESET"
            echo "UID del usuario: $usu_uid"
            echo "GID del usuario: $usu_gid"
            echo "Número total del procesos mayores que $time segundo[s]: $result"
            echo "Pid del proceso con mayor tiempo consumido: $usu_max_pid"
            echo "Tiempo del proceso con mayor tiempo consumido: $usu_max_time"
            echo
            result=0
        done
    elif [ "$option_inv" = 1 ]; then    # caso en el que se pide -u con la opción -inv
        user_list_sorted=($(for i in "${user_list[@]}"; do echo $i; done | sort -d -r))  # ordenación del vector en orden alfabético
        
        for i in "${user_list_sorted[@]}"; do
            echo
            echo "$TEXT_BOLD La lista de procesos para el usuario: $i $TEXT_RESET"
            echo        
            result=$(ps -u $i --no-headers | wc -l)
            usu_uid=$(id -u $i)
            usu_gid=$(id -g $i)
            usu_max_time=$(ps -u $i --no-headers --sort=time | tail -n 1 | awk '{print $3}')
            usu_max_pid=$(ps -u $i --no-headers --sort=time | tail -n 1 | awk '{print $1}')
            echo
            echo "$TEXT_BOLD Usuario: $i $TEXT_RESET"
            echo "UID del usuario: $usu_uid"
            echo "GID del usuario: $usu_gid"
            echo "Número total del procesos del usuario: $result"
            echo "Pid del proceso con mayor tiempo consumido: $usu_max_pid"
            echo "Tiempo del proceso con mayor tiempo consumido: $usu_max_time"
            echo
            result=0
        done
    elif [ "$option_pid" = 1 ]; then    # caso en el que se pide -u con la opción -pid
        for i in "${user_list[@]}"; do
            for j in $(ps -u $i --no-headers --sort=time | tail -n 1 | awk '{print $1}'); do
                max_proccess_pid[counter]=$j
            done
            let counter=$counter+1
        done

        max_proccess_pid_sorted=($(for i in "${max_proccess_pid[@]}"; do echo $i; done | sort -h))  # ordenación del vector de los pid de menor a mayor

        for i in "${max_proccess_pid_sorted[@]}"; do    # Lista de usuarios ordenada por el pid del proceso con más tiempo consumido
                user_name=$(ps --pid $i --no-headers -u | awk '{print $1}')
                usu_uid=$(id -u $user_name)
                usu_gid=$(id -g $user_name)
                result=$(ps -u $user_name --no-headers | wc -l)
                usu_max_time=$(ps -u $user_name --no-headers --sort=time | tail -n 1 | awk '{print $3}')
                usu_max_pid=$(ps -u $user_name --no-headers --sort=time | tail -n 1 | awk '{print $1}')
                echo
                echo "$TEXT_BOLD Usuario: $user_name $TEXT_RESET"
                echo "UID del usuario: $usu_uid"
                echo "GID del usuario: $usu_gid"
                echo "Número total de procesos del usuario: $result"
                echo "Pid del proceso con mayor tiempo consumido: $usu_max_pid"
                echo "Tiempo del proceso con mayor tiempo consumido: $usu_max_time"
                echo
        done
    elif [ "$option_c" = 1 ]; then
        for i in "${user_list[@]}"; do
            for j in $(ps -u $i --no-headers | wc -l); do
                total_process_list[counter]=$j
            done
            let counter=$counter+1
        done

        total_process_list_sorted=($(for i in "${total_process_list[@]}"; do echo $i; done | sort -h))  # ordenación del vector de los procesos totales de menor a mayor

        for i in "${total_process_list_sorted[@]}"; do
            actual_number=$i
            for j in "${user_list[@]}"; do
                auxiliary=$(ps -u $j --no-headers | wc -l)
                if [ "$i" = "$auxiliary" ] && [ "$actual_number" != "$before_number" ]; then
                    usu_uid=$(id -u $j)
                    usu_gid=$(id -g $j)
                    usu_max_time=$(ps -u $j --no-headers --sort=time | tail -n 1 | awk '{print $3}')
                    usu_max_pid=$(ps -u $j --no-headers --sort=time | tail -n 1 | awk '{print $1}')
                    echo
                    echo "$TEXT_BOLD Usuario: $j $TEXT_RESET"
                    echo "UID del usuario: $usu_uid"
                    echo "GID del usuario: $usu_gid"
                    echo "Número total de procesos del usuario: $auxiliary"
                    echo "Pid del proceso con mayor tiempo consumido: $usu_max_pid"
                    echo "Tiempo del proceso con mayor tiempo consumido: $usu_max_time"
                    echo
                elif [ "$actual_number" = "$before_number" ]; then
                    before_number=$actual_number
                fi
            done
            before_number=$actual_number
        done
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
                if [ "$i" = "-count" ]; then
                    option_count=1
                fi
            done
            
            for i in $*; do     # La variable $*, se trata de un parámetro posicional especial que contiene un string que contiene todos los argumentos separados por un separador
                if [ "$i" = "-inv" ]; then
                    option_inv=1
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
                if [ "$i" = "-inv" ]; then
                    option_inv=1
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
                if [ "$i" = "-inv" ]; then
                    option_inv=1
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
                user_list[counter]=$1
                let counter=$counter+1
            done
            user_process_u
        ;;
        -count )    # COMPROBAR COMO EJECUTAR TODO SIN NECESIDAD DE QUE SE TENGAN QUE PONER COMO CASOS ESTAS OPCIONES
            exit 0
        ;;
        -inv )
            exit 0
        ;;
        -pid )
            exit 0
        ;;
        -c )
            exit 0
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
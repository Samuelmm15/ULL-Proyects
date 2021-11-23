#!/bin/bash

# Name: Samuel
# Surnames: Martín Morales
# E-mail: alu0101359526@ull.edu.es

# sysinfo - Bash Final Exercise Practice "User Processes"

# Declaration of variables

PROGNAME=$(basename $0) # Variable that specifies the name of the program
time=
transformation=
is_a_number='^[0-9]+$'  # Regular expression that determines positive integers
result=0
user_name=
usu_uid=
usu_gid=
usu_max_time=
usu_max_pid=
option_t=0
option_usr=0
option_u=0
option_count=0
option_inv=0
option_pid=0
option_c=0
process_value=
comparation_c=0
before_user=a
actual_user=
user_list=()    # Array declaration
user_list_sorted=()
option_list=()
total_process_list=()
total_process_list_sorted=()
usr_list=()
usr_list_sorted=()
max_proccess_pid=() 
max_proccess_pid_sorted=()
iterator=0
counter=0
auxiliary=0
actual_number=
before_number=0
snitch=0

# Text style

TEXT_BOLD=$(tput bold)
TEXT_GREEN=$(tput setaf 2)
TEXT_UNLINE=$(tput sgr 0 1)
TEXT_RESET=$(tput sgr0)

# Functions

usage() # Fuction that print the correct usage of the script
{
    echo "$TEXT_BOLD<< FUNCIONAMIENTO GENERAL DEL SCRIPT >> $TEXT_RESET"
    echo "usage: ./userProc.sh [-t N] [-usr] [-u {Lista_Usuarios}] [-count] [-inv] [-pid] [-c] [-h | --help]"
    echo "$TEXT_GREEN N (número entero especificado) $TEXT_RESET"
    echo "$TEXT_GREEN {Lista_Usuarios} (Lista de usuarios a los que se quiere aplicar la lista de procesos de estos) $TEXT_RESET"
}

error_exit() # Fuction that print a error during the execution of the script
{
    echo "$TEXT_BOLD Se ha producido un <<ERROR>> $TEXT_RESET"
    if [ "$time" = "" ]; then
        echo "${PROGNAME}:$TEXT_UNLINE La opción de ejecución -t se ha introducidO de manera incorrecta; falta especificación del entero N. $TEXT_RESET" 1>&2
    elif [ "$time" = -1 ]; then
        echo "${PROGNAME}:$TEXT_UNLINE La opción de ejecución -t se ha introducidO de manera incorrecta; falta especificación del entero N. $TEXT_RESET" 1>&2
    fi
    exit 1
}

user_information()
{
    if [ "$snitch" != 1 ]; then
        printf "%-s NAME\t"
        printf "%-s UID\t"
        printf "%-s GID\t"
        printf "%-s NUM_TOTAL\t"
        printf "%-s PID_MAX\t"
        printf "%-s PID_MAX_TIME"
        printf "\n"
        snitch=1
    fi
    usu_uid=$(id -u $1)
    usu_gid=$(id -g $1)
    usu_max_time=$(ps -u $1 --no-headers --sort=time | tail -n 1 | awk '{print $3}')
    usu_max_pid=$(ps -u $1 --no-headers --sort=time | tail -n 1 | awk '{print $1}')
    printf "%-s \t" $1
    printf "%-d \t" $usu_uid
    printf "%-d \t" $usu_gid
    printf "%-d \t" $2
    printf "%-d \t" $usu_max_pid
    printf "%-s \t" $usu_max_time
    printf "\n"
}

option_count_fuction()
{
    actual_user=$1
    for i in $(ps -u $1 --no-headers -o time); do # With the etimes option it shows the time in seconds
        transformation=$(echo "$i" | awk -F: '{ print ($1 * 3600) + ($2 * 60) + $3 }')  # Transformation of the time in format 00:00:00 to seconds
        if [ "$transformation" -ge "$time" ]; then   
            let result=$result+1
        fi
    done
    if [ "$before_user" != "$actual_user" ]; then
        user_information $1 $result
        before_user=$actual_user
        result=0
    elif [ "$before_user" = "$actual_user" ]; then
        before_user=$actual_user
        result=0
    fi
}

option_inv_fuction()
{
    actual_user=$1
    result=$(ps -u $1 --no-headers | wc -l)
    if [ "$before_user" != "$actual_user" ]; then
        user_information $1 $result
        before_user=$actual_user
        result=0
    elif [ "$before_user" = "$actual_user" ]; then
        before_user=$actual_user
        result=0
    fi
}

option_pid_fuction()
{               
    max_proccess_pid_sorted=($(for i in "${max_proccess_pid[@]}"; do echo $i; done | sort -h)) # Vector ordering form smallest to largest
    for i in "${max_proccess_pid_sorted[@]}"; do 
        user_name=$(ps --pid $i --no-headers -u | awk '{print $1}')
        result=$(ps -u $user_name --no-headers | wc -l)
        user_information $user_name $result
    done  
}

option_c_fuction()
{
    total_process_list_sorted=($(for i in "${total_process_list[@]}"; do echo $i; done | sort -h)) 
    for i in "${total_process_list_sorted[@]}"; do
        actual_number=$i
        for j in "${user_list[@]}"; do
            auxiliary=$(ps -u $j --no-headers | wc -l)
            if [ "$i" = "$auxiliary" ] && [ "$actual_number" != "$before_number" ]; then
                user_information $j $auxiliary
            elif [ "$actual_number" = "$before_number" ]; then
                before_number=$actual_number
            fi
        done
        before_number=$actual_number
    done
}

user_process() # Fuction that contents the option -t functioning
{
    if [ "${option_list[@]}" = 0 ]; then # Standar option without any paramether
        echo "$TEXT_GREEN El valor del número entero sobre el cual se quieren listar los usuarios es: $time $TEXT_RESET"
        echo
        echo "$TEXT_BOLD Opción estándar sin ningún parámetro $TEXT_RESET"
        echo
        for i in $(ps -A --no-headers -o user --sort=+user | awk '{print $1}'); do # With the $ (command) statement, you can use command within a for loop
            actual_user=$i
            result=$(ps -u $i --no-headers | wc -l)
            if [ "$before_user" != "$actual_user" ]; then
                user_information $i $result # Function call with parameters
                before_user=$actual_user
                result=0
            elif [ "$before_user" = "$actual_user" ]; then
                before_user=$actual_user
                result=0
            fi
        done 
    fi

    for k in "${option_list[@]}"; do
        if [ "$option_count" != 1 ] && [ "$option_inv" != 1 ] && [ "$option_pid" != 1 ] && [ "$option_c" != 1 ] && [ "$k" = "-t" ]; then # Standar option of -t
            echo
            echo "$TEXT_BOLD Opción estándar -t $TEXT_RESET"
            echo
            for i in $(ps -A --no-headers -o user --sort=+user | awk '{print $1}'); do # With the $ (command) statement, you can use command within a for loop
                actual_user=$i
                result=$(ps -u $i --no-headers | wc -l)
                if [ "$before_user" != "$actual_user" ]; then
                    user_information $i $result # Function call with parameters
                    before_user=$actual_user
                    result=0
                elif [ "$before_user" = "$actual_user" ]; then
                    before_user=$actual_user
                    result=0
                fi
            done 
        elif [ "$option_count" = 1 ] && [ "$k" = "-count" ]; then  # Case -t with -count
            echo 
            echo "$TEXT_BOLD Opción -t con -count $TEXT_RESET"
            echo
            for i in $(ps -A --no-headers -o user --sort=+user | uniq | awk '{print $1}'); do 
                option_count_fuction $i
            done
        elif [ "$option_inv" = 1 ] && [ "$k" = "-inv" ]; then # Case -t with -inv
            echo
            echo "$TEXT_BOLD Opción -t con -inv $TEXT_RESET"
            echo
            for i in $(ps -A --no-headers -o user --sort=-user | awk '{print $1}'); do 
                option_inv_fuction $i
            done
        elif [ "$option_pid" = 1 ] && [ "$k" = "-pid" ]; then # Case -t with -pid   # TENER CUIDADO CON ESTA OPCIÓN QUE PONE QUE ALGUNOS USUARIOS NO EXISTEN Y LANZA MENSAJE DE ERROR
            echo
            echo "$TEXT_BOLD Opción -t con -pid $TEXT_RESET"
            echo
            for i in $(ps -A --no-headers -o user --sort=+user | uniq); do
                for j in $(ps -u $i --no-headers --sort=time | tail -n 1 | awk '{print $1}'); do
                    max_proccess_pid[counter]=$j
                    let counter=$counter+1
                done
            done
            option_pid_fuction   
        elif [ "$option_c" = 1 ] && [ "$k" = "-c" ]; then # Case -t with -c
            echo
            echo "$TEXT_BOLD Opción -t con -c $TEXT_RESET"
            echo
            for i in $(ps -A --no-headers -o user --sort=+user | uniq | awk '{print $1}'); do
                for j in $(ps -u $i --no-headers | wc -l); do
                    total_process_list[counter]=$j
                done
                user_list[counter]=$i
                let counter=$counter+1 
            done
            option_c_fuction
        fi
    done
}

user_process_usr() # Fuction that contents the option -usr functioning
{
    for k in "${option_list[@]}"; do
        if [ "$option_count" != 1 ] && [ "$option_inv" != 1 ] && [ "$option_pid" != 1 ] && [ "$option_c" != 1 ]; then # Standar option of -usr
            echo 
            echo "$TEXT_BOLD Opción -usr estándar $TEXT_RESET"
            echo
            for i in $(who | awk '{print $1}'); do 
                usr_list[counter]=$i
                let counter=$counter+1
            done

            usr_list_sorted=($(for i in "${usr_list[@]}"; do echo $i; done | sort -d)) # User ordering

            for i in "${usr_list_sorted[@]}"; do
                actual_user=$i
                if [ "$before_user" != "$actual_user" ]; then
                    echo
                    echo "$TEXT_BOLD El usuario al que se le van a listar los procesos es: $i $TEXT_RESET"
                fi
                result=$(ps -u $i --no-headers | wc -l)
                if [ "$before_user" != "$actual_user" ]; then
                    user_information $i $result
                    before_user=$actual_user
                    result=0
                elif [ "$before_user" = "$actual_user" ]; then  # 
                    before_user=$actual_user
                    result=0
                fi
            done

        elif [ "$option_count" = 1 ] && [ "$k" = "-count" ]; then  # Case -usr with -count
            echo 
            echo "$TEXT_BOLD Opción -usr con -count $TEXT_RESET"
            echo
            for i in $(who | awk '{print $1}'); do
                usr_list[counter]=$i
                let counter=$counter+1
            done

            usr_list_sorted=($(for i in "${usr_list[@]}"; do echo $i; done | sort -d))

            for i in "${usr_list_sorted[@]}"; do
                option_count_fuction $i
            done
        elif [ "$option_inv" = 1 ] && [ "$k" = "-inv" ]; then # Case -usr with -inv
            echo 
            echo "$TEXT_BOLD Opción -usr con -inv $TEXT_RESET"
            echo
            for i in $(who | awk '{print $1}'); do
                usr_list[counter]=$i
                let counter=$counter+1
            done
        
            usr_list_sorted=($(for i in "${usr_list[@]}"; do echo $i; done | sort -d -r)) # Ordering the vectoc in reverse mode

            for i in "${usr_list_sorted[@]}"; do
                option_inv_fuction $i
            done
        elif [ "$option_pid" = 1 ] && [ "$k" = "-pid" ]; then # Case -usr with -pid
            echo 
            echo "$TEXT_BOLD Opción -usr con -pid $TEXT_RESET"
            echo
            for i in $(who | awk '{print $1}'); do 
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
            option_pid_fuction
        elif [ "$option_c" = 1 ] && [ "$k" = "-c" ]; then  # Case -usr with -c
            echo 
            echo "$TEXT_BOLD Opción -usr con -c $TEXT_RESET"
            echo
            for i in $(who | awk '{print $1}'); do 
                for j in $(ps -u $i --no-headers | wc -l); do
                    total_process_list[counter]=$j
                done
                usr_list[counter]=$i
                let counter=$counter+1
            done
            option_c_fuction
        fi
    done
}

user_process_u() # Fuction that contents the option -u functioning
{
    for k in "${option_list[@]}"; do
        if [ "$option_count" != 1 ] && [ "$option_inv" != 1 ] && [ "$option_pid" != 1 ] && [ "$option_c" != 1 ] && [ "$k" = "-u" ]; then # Standar option of -u
            echo 
            echo "$TEXT_BOLD Opción -u estándar $TEXT_RESET"
            echo
            user_list_sorted=($(for i in "${user_list[@]}"; do echo $i; done | sort -d))  
        
            for i in "${user_list_sorted[@]}"; do
                echo
                echo "$TEXT_BOLD La lista de procesos para el usuario: $i $TEXT_RESET"
                echo        
                result=$(ps -u $i --no-headers | wc -l)
                user_information $i $result
                result=0
            done
        elif [ "$option_count" = 1 ] && [ "$k" = "-count" ]; then  # Case -u with -count
            echo 
            echo "$TEXT_BOLD Opción -u con -count $TEXT_RESET"
            echo

            user_list_sorted=($(for i in "${user_list[@]}"; do echo $i; done | sort -d))

            for i in "${user_list_sorted[@]}"; do
                option_count_fuction $i
            done
        elif [ "$option_inv" = 1 ] && [ "$k" = "-inv" ]; then # Case -u with -inv
            echo 
            echo "$TEXT_BOLD Opción -u con -inv $TEXT_RESET"
            echo
            
            user_list_sorted=($(for i in "${user_list[@]}"; do echo $i; done | sort -d -r))
        
            for i in "${user_list_sorted[@]}"; do
                option_inv_fuction $i
            done
        elif [ "$option_pid" = 1 ] && [ "$k" = "-pid" ]; then # Case -u with -pid
            echo 
            echo "$TEXT_BOLD Opción -u con -pid $TEXT_RESET"
            echo
            for i in "${user_list[@]}"; do
                for j in $(ps -u $i --no-headers --sort=time | tail -n 1 | awk '{print $1}'); do
                    max_proccess_pid[counter]=$j
                done
                let counter=$counter+1
            done
            option_pid_fuction
        elif [ "$option_c" = 1 ] && [ "$k" = "-c" ]; then # Case -u with -c
            echo 
            echo "$TEXT_BOLD Opción -u con -c $TEXT_RESET"
            echo
            for i in "${user_list[@]}"; do
                for j in $(ps -u $i --no-headers | wc -l); do
                    total_process_list[counter]=$j
                done
                let counter=$counter+1
            done
            option_c_fuction
        fi
    done
}

# Principal program

if [ "$1" = "" ]; then  # Script execution without any option
    time=1
    option_list[0]=0
    user_process
fi 

while [ "$1" != "" ]; do # Script execution with options
    case $1 in
        -h | --help )
            usage
            exit 0
        ;;
        -t ) # Option -t
            for i in $*; do # The variable $ *, it is a special positional parameter that contains a string that contains all the arguments separated by a separator   
                if [ "$i" = "-t" ]; then
                    option_t=1
                    option_list[iterator]=$i
                    let iterator=$iterator+1
                fi
            done

            for i in $*; do     
                if [ "$i" = "-usr" ]; then
                    option_usr=1
                    option_list[iterator]=$i
                    let iterator=$iterator+1
                fi
            done

            for i in $*; do    
                if [ "$i" = "-u" ]; then
                    option_u=1
                    option_list[iterator]=$i
                    let iterator=$iterator+1
                fi
            done

            for i in $*; do  
                if [ "$i" = "-count" ]; then
                    option_count=1
                    option_list[iterator]=$i
                    let iterator=$iterator+1
                fi
            done
            
            for i in $*; do   
                if [ "$i" = "-inv" ]; then
                    option_inv=1
                    option_list[iterator]=$i
                    let iterator=$iterator+1
                fi
            done

            for i in $*; do     
                if [ "$i" = "-pid" ]; then
                    option_pid=1
                    option_list[iterator]=$i
                    let iterator=$iterator+1
                fi
            done

            for i in $*; do     
                if [ "$i" = "-c" ]; then
                    option_c=1
                    option_list[iterator]=$i
                    let iterator=$iterator+1
                fi
            done

            shift
            time=$1
            
            if [ "$time" = "" ]; then # Error_exit
                error_exit
            fi

            if [ "$option_usr" != 1 ] && [ "$option_u" != 1 ]; then
                user_process
            elif [ "$option_usr" = 1 ]; then
                user_process_usr
            elif [ "$option_u" = 1 ]; then
                user_process_u
            fi
            exit 0
        ;;
        -usr ) # Option -usr
            if [ "$time" = "" ]; then
                time=1
            fi

            for i in $*; do    
                if [ "$i" = "-t" ]; then
                    option_t=1
                    option_list[iterator]=$i
                    let iterator=$iterator+1
                fi
            done

            for i in $*; do     
                if [ "$i" = "-usr" ]; then
                    option_usr=1
                    option_list[iterator]=$i
                    let iterator=$iterator+1
                fi
            done

            for i in $*; do     
                if [ "$i" = "-count" ]; then
                    option_count=1
                    option_list[iterator]=$i
                    let iterator=$iterator+1
                fi
            done

            for i in $*; do     
                if [ "$i" = "-inv" ]; then
                    option_inv=1
                    option_list[iterator]=$i
                    let iterator=$iterator+1
                fi
            done

            for i in $*; do     
                if [ "$i" = "-pid" ]; then
                    option_pid=1
                    option_list[iterator]=$i
                    let iterator=$iterator+1
                fi
            done

            for i in $*; do    
                if [ "$i" = "-c" ]; then
                    option_c=1
                    option_list[iterator]=$i
                    let iterator=$iterator+1
                fi
            done

            for i in $*; do     
                if [ "$i" = "-t" ]; then
                    option_t=1
                    time=-1
                    option_list[iterator]=$i
                    let iterator=$iterator+1
                fi
                if [[ $i =~ $is_a_number ]]; then
                    time=$i
                fi
            done

            if [ "$time" = -1 ]; then
                error_exit
            fi

            user_process_usr
            exit 0
        ;;
        -u ) # Option -u
            if [ "$time" = "" ]; then
                time=1
            fi

            for i in $*; do    
                if [ "$i" = "-u" ]; then
                    option_u=1
                    option_list[iterator]=$i
                    let iterator=$iterator+1
                fi
            done

            for i in $*; do     
                if [ "$i" = "-count" ]; then
                    option_count=1
                    option_list[iterator]=$i
                    let iterator=$iterator+1
                fi
            done

             for i in $*; do     
                if [ "$i" = "-inv" ]; then
                    option_inv=1
                    option_list[iterator]=$i
                    let iterator=$iterator+1
                fi
            done

            for i in $*; do     
                if [ "$i" = "-pid" ]; then
                    option_pid=1
                    option_list[iterator]=$i
                    let iterator=$iterator+1
                fi
            done

            for i in $*; do   
                if [ "$i" = "-c" ]; then
                    option_c=1
                    option_list[iterator]=$i
                    let iterator=$iterator+1
                fi
            done

            while [ "$2" != "-t" ] && [ "$2" != "-usr" ] && [ "$2" != "-count" ] && [ "$2" != "-inv" ] && [ "$2" != "-pid" ] && [ "$2" != "-c" ] && [ "$2" != "" ]; do
                shift 
                user_list[counter]=$1
                let counter=$counter+1
            done

            for i in $*; do 
                if [ "$i" = "-t" ]; then
                    option_t=1
                    time=-1
                fi
                if [[ $i =~ $is_a_number ]]; then
                    time=$i
                fi
            done

            if [ "$time" = -1 ]; then
                error_exit
            fi

            user_process_u
            exit 0
        ;;
        * )
            echo
            echo "<< Opción introducida no soportada >>"
            echo
            usage
            exit 1
    esac
done
exit 0  # Correct exit of the script
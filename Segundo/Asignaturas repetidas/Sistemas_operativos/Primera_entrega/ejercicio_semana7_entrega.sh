#!/bin/bash

# sysinfo - Entrega semana 6
# Nombre: Samuel
# Apellidos: Martín Morales

# Declaración de variables

TITLE="Información del sistema para $HOSTNAME"
RIGHT_NOW=$(date +"%x %r%Z")
TIME_STAMP="Actualizada el $RIGHT_NOW por $USER"
interactive=
answer=
overwritten=
filename=~/sysinfo.txt

# Estilos

TEXT_BOLD=$(tput bold)
TEXT_GREEN=$(tput setaf 2)
TEXT_UNLINE=$(tput sgr 0 1)
TEXT_RESET=$(tput sgr0)

# Funciones

system_info()
{
    echo "$TEXT_UNLINE Versión del sistema $TEXT_RESET"
    echo
    uname -a
    echo
}

show_uptime()
{
    echo "$TEXT_UNLINE Tiempo de encendido del sistema $TEXT_RESET"
    echo
    uptime
    echo
}

drive_space()
{
    echo "$TEXT_UNLINE Espacio ocupado en las particiones del sistema $TEXT_RESET"
    echo
    df -h   # Usado con la opción h para determinar de que se muestren las particiones por tamaños descritos en mb
    echo
}

home_space()
{   
    echo "$TEXT_UNLINE Espacio ocupado del directorio de trabajo del usuario $TEXT_RESET"
    echo
    if [ $USER = root ]; then
        echo "$TEXT_GREEN *El usuario que lanza el script se trata de root* $TEXT_RESET"
        echo
        cd /home 
        du | sort -n -r     # con la opción -r se puede invertir el orden de ordenación, en vez de menor a mayor, de mayor a menor
        echo
    else
        echo "$TEXT_GREEN *El usuario que ha lanzado el script se trata de un usuario distinto de root* $TEXT_RESET"    
        echo
        cd /home/$USER
        echo "$TEXT_BOLD El espacio total ocupado en el directorio personal de $USER es: $TEXT_RESET"
        du -c | tail -n 1
        echo
    fi
}

daemon_process()
{  
    echo "LISTA DE USUARIOS DE /etc/passwd QUE NO ESTÁN EJECUTANDO NINGÚN PROCESO:"
    for i in $(cat /etc/passwd | tr ':' ' ' | awk '{print $1}'); do     # No recorta de manera correcta los usuarios del fichero, pero el bucle se realiza de esta maneraq
        for j in $(ps -u $i --no-headers | wc -l); do
            if [ "$j" = "0" ]; then
                echo "$i"
            fi
        done
    done
}

usage()
{
    echo "usage: sysinfo [-f filename] [-i] [-h] [-d]"
}

write_page()    # Función que se encarga de incluir el script-here 
{
    cat << _EOF_
    $TEXT_BOLD$TITLE$TEXT_RESET
    
    $(system_info)
    $(show_uptime)
    $(drive_space)
    $(home_space)
    
    $TEXT_GREEN$TIME_STAMP$TEXT_RESET

_EOF_
}

# Programa principal

while [ "$1" != "" ]; do
    case $1 in
        -f | --file )
            shift
            filename=$1
            ;;
        -i | --interactive )
            interactive=1
            ;;
        -h | --help )
            usage
            exit
            ;;
        -d )    # Opción necesaria para comprobar que usuarios no están ejecutando ningún proceso en el sistema
            daemon_process
            exit
            ;;
        * )     # opción por defecto
            usage   
            exit 1  # indicación de salida del programa con error
    esac
    shift

    if [ "$interactive" = "1" ]; then
        echo -n "Mostrar el informe del sistema en pantalla (S/N): "
        read answer
        if [ "$answer" = "N" ]; then
            echo -n "Introduzca el nombre del archivo [~/sysinfo.txt]: "
            read filename
            if [ "$filename" = "" ]; then
                filename=~/sysinfo.txt
            fi
        fi
        if [ "$answer" = "N" ]; then
            if [ -f $filename ]; then   # Condicional necesario para comprobar si un fichero existe, para ello, se hace uso de la opción -f y si se quiere comprobar si existe un directorio, se hace uso de la opción -d
                echo -n "El archivo de destino existe. ¿Sobreescribir? (S/N): "
                read overwritten
                if [ "$overwritten" = "N" ]; then
                    exit 0
                fi
            fi
        fi
    fi

done

if [ "$answer" = "S" ]; then
    write_page
    exit 0
fi

# Guardado de todo el informe en un fichero de texto a parte
echo "$TEXT_BOLD El informe del sistema se ha almacenado en el fichero con ruta $filename $TEXT_RESET"
write_page > $filename

# Modificación propuesta para la semana 7
# Mirar cuales de los usuarios y demonios del /etc/passwd no tiene procesos ejecutando
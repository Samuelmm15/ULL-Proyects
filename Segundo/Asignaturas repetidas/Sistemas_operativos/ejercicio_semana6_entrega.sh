#!/bin/bash

# sysinfo - Entrega semana 6
# Nombre: Samuel
# Apellidos: Martín Morales

# Declaración de variables

TITLE="Información del sistema para $HOSTNAME"
RIGHT_NOW=$(date +"%x %r%Z")
TIME_STAMP="Actualizada el $RIGHT_NOW por $USER"

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

# Programa principal

cat << _EOF_

    $TEXT_BOLD$TITLE$TEXT_RESET
    $TEXT_GREEN$TIME_STAMP$TEXT_RESET

_EOF_

system_info
show_uptime
drive_space
home_space

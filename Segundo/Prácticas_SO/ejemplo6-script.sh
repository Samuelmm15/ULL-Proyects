#!/bin/bash

# sysinfo - Ejemplo del uso de comando uptime y de la declaración y funcionalidades de las funciones

# Declaración de variables
title="Información general del sistema"
BOLD=$(tput bold)
GREEN=$(tput setaf 2)
RESET=$(tput sgr0)

# Declaración de funciones
system_info() {
    echo "Función de $GREEN system_info $RESET"
    echo "Versión del sistema:"
    echo
    uname -a # Como se puede observar en esta línea, se pueden declarar comandos que se pueden hacer uso en la línea de comandos de la terminal y que se pueden ejecutar en un script
    # El comando uname sirve para mostrar información del sistema, con la opción -a muestra toda la información del sistema
}

show_uptime() {
    echo "Función de $GREEN show_uptime $RESET"
    echo "Tiempo de encendido del sistema:"
    echo
    uptime # Este comando sirve para determinar cierta información sobre el propio sistema operativo
}

# Función principal del programa

cat << _EOF_
=== $title ===

$BOLD Uso de las distintas funcionalidades del programa $RESET
$(system_info)

$(show_uptime)

_EOF_
#!/bin/bash

# sysinfo - Ejemplo de uso de funciones en bash

# Declaración de variables
title="Información general del sistema"
BOLD=$(tput bold)
GREEN=$(tput setaf 2)
RESET=$(tput sgr0)

# Declaración de funciones
system_info() {
    echo "Función de $GREEN system_info $RESET"
}

show_uptime() {
    echo "Función de $GREEN show_uptime $RESET"
}

# Función principal del programa

cat << _EOF_
=== $title ===

$BOLD Uso de las distintas funcionalidades del programa $RESET
$(system_info)

$(show_uptime)

_EOF_
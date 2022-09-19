#!/bin/bash

# sysinfo - Ejemplo con la declaración de variables para el uso de distintas características para los textos en bash

# Declaración de variables
title="Información general del sistema"
BOLD=$(tput bold)
GREEN=$(tput setaf 2)
RESET=$(tput sgr0)

cat << _EOF_
=== $title ===

$BOLD Información sobre los procesos: $RESET
    Datos del proceso 1
    Datos del proceso 2

$GREEN Información de red: $RESET
    Datos de la interfaz de red 1
    Datos de la interfaz de red 2

_EOF_
#!/bin/bash

# sysinfo - Segundo script para entender lo básico que posee la introducción a las variables en bash

# En este punto se produce la declaración de las variables, antes de la utilización de estas
title="INFORMACIÓN DEL SISTEMA"

cat << _EOF_
=== $title ===

Información sobre los procesos:
    Datos del proceso 1
    Datos del proceso 2

Información de red:
    Datos de la interfaz de red 1
    Datos de la interfaz de red 2

_EOF_
#!/bin/bash
# De manera general se hace uso de lo anterior para marcar el comienzo del script

# sysinfo - Se trata de un script de prueba para entender los elementos básicos de estos

# Se va a hacer uso del método script-here para poder crear muchas líneas de salida por pantalla sin necesidad de escribir muchas veces el comando echo

cat << _EOF_
=== INFORMACIÓN DEL SISTEMA ===

Información sobre los procesos:
    Datos del proceso 1
    Datos del proceso 2

Información de red:
    Datos de la interfaz de red 1
    Datos de la interfaz de red 2

_EOF_
#!/bin/bash

# sysinfo - Ejemplo del uso de las variables de entorno declaradas en una lista que puede ser visualizada mediante el comando printenv

# Declaración de variables
title="Información general del sistema..."

# Para este caso, la variable de entorno es la variable HOSTNAME que se puede visualizar dentro de la lista y no necesita ser declarada anteriormente porque se trata de una variable de entorno
cat << _EOF_
=== $title $HOSTNAME ===

Información sobre los procesos:
    Datos del proceso 1
    Datos del proceso 2

Información de red:
    Datos de la interfaz de red 1
    Datos de la interfaz de red 2

_EOF_
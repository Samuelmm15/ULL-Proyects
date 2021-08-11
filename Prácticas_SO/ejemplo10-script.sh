#!/bin/bash

# sysinfo - Ejemplo de uso del comando read con distintos casos de uso

# Declaración de variables

# Declaración de funciones

# Uso del comando read sin opciones
    echo -n "Escriba su nombre > "
    read nombre
    echo
    echo "¿ Usted se llama $nombre ?"

    echo
# Uso del comando read con la opción -t

    echo -n "Escriba su nombre > "
    read -t 5 usuario
    echo
    echo "¿ Usted se llama $usuario ?"

    echo
# Uso del comando read con la opción -s

    echo -n "Escriba la contraseña de su usuario > "
    read -s contrasena
    echo
    echo "La contraseña introducida es: $contrasena"

    echo
# Programa principal

# El script se debe de ejecutar así porque si se ejecuta mediante el uso de funciones no deja ejecutar las funciones
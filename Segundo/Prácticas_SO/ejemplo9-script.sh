#!/bin/bash

# sysinfo - Ejemplo de códigos útiles para comprobar si las variables especiales contienen algo

# Declaración de variables

# Declaración de funciones
code_1() {
if [ "$1" != "" ]; then
    echo "El parámetro contiene algo"
else
    echo "El parámetro no contiene nada"
fi
}

code_2() {    
if [ $# -gt 0 ]; then
    echo "La línea de comandos contiene $# argumentos"
else
    echo "La línea de comandos no contiene argumentos"
fi
}
# Programa princiapl
cat << _EOF_
=== CÓDIGOS DE EJEMPLO ===
$(code_1)

$(code_2)
_EOF_
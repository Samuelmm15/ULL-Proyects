#!/bin/bash

# sysinfo - Ejemplo de uso de los comando while y until

# Declaración de variables

# Declaración de funciones
while_comand() {
    number=0
    while [ "$number" -lt 10 ]; do
        echo "Number = $number"
        number=$( (number + 1) )
    done
}

until_comand() {
    number=0
    until [ "$number" -ge 10 ]; do
        echo "Number = $number"
        number=$( (number + 1) )
    done
}
# Programa principal
cat << _EOF_
 === EJEMPLO DE USO DEL COMANDO WHILE Y UNTIL ===

 $(while_comand)

 $(until_comand)
_EOF_

# Este script da error, comprobar por qué da error, pero los coódigos ejemplo están correctos
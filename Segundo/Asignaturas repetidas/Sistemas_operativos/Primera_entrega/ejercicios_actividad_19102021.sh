#!/bin/bash

# El fichero de ejercicios se encuentra en: https://drive.google.com/file/d/1cz1BAW8I3ZfdDjXHXdRypx77lfwyNcvx/view?usp=sharing

# 1. Hacer uso de un comando para poder crear un árbol de directorios concreto

mkdir -p ~/temp/temp{1,2}/temp{1,2}

# La segunda parte del apartado consiste en hacer uso del comando touch para crear archivos vacíos en las
# subcarpetas que acaben en 1, el nombre de dichos archivos debe de ser la concatenación de $USER con .dat

touch $USER.dat

# Este comando anterior, la expansión que realiza se basa principalmente en que crear el fichero con extensión .dat
# pero, realiza una expansión de la variable del sistema $USER y crea el fichero con el nombre del usuario que está lanzando el comando

# 2. Haciendo uso del comando find descrito y hacer uso de grep con una tubería para que muestre solo los directorios que terminan en 1
# junto con otra tubería que haga uso del comando xargs y chamod para retirar el permiso de lectura del grupo otros de los archivos que se encuentren dentro de estos directorios

find ~ -name 'temp*' -type d | grep "1$" | xargs chmod o-r

# El entrecomillado que se encuentra a continuación de name, delimitando de que se trama de los directorios que poseen el nombre de temp,
# se debe o se hace uso de este, para determinar de que se trata de una expansión de una expresión regular que indica que se busquen todos aquellos directorios
# que tengan las especificación de que primero posean el nombre de temp y que a continuación venga todo lo que sea

# 3. Escribir una línea de comando que permita automatizar la creación del archivo

find ~ -name 'temp*' -type d | grep "1$" | touch $USER.dat
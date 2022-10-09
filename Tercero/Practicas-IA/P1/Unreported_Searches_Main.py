"""
 @file Unreported_Searches_Main.py
 @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 @brief
 @version 0.1
 @date 2022-10-09
  
 @copyright Copyright (c) 2022
"""

import os
import colorama # Librería necesaria para ejecutar los colores de los mensajes por la terminal
from colorama import Fore
from colorama import init

init(autoreset=True) # Esto hace que el color de las cadenas vuelva a su color original cada vez que se use por defecto

if __name__ == '__main__': # This is the main program
    print()
    print(Fore.MAGENTA + '<< BIENVENIDO A LA BÚSQUEDA EN AMPLITUD DEL CAMINO QUE CONECTE DOS VÉRTICES DE UN GRAFO >>')
    print()
    
    # Se pregunta el nombre del fichero el cual se va a hacer uso
    inputFileName = input(Fore.GREEN + 'Introduzca el nombre del fichero del cual se van a obtener los datos del grafo: ')
    if os.path.exists(inputFileName) == False: # Esta sentencia sirve para comprobar si un fichero introducido por teclado existe
        print()
        print(Fore.RED + 'ERROR >> El nombre del fichero que ha sido introducido, no existe, introduzca un nombre válido.')
        exit(1) # Finaliza el programa con un código de error de tipo 1
    
    # Se realiza la lectura del fichero que ha sido indicado
    inputFile = open(inputFileName)

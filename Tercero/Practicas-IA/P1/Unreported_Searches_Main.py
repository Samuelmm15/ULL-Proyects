"""
 @file Unreported_Searches_Main.py
 @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 @brief
 @version 0.1
 @date 2022-10-09
  
 @copyright Copyright (c) 2022
"""

from itertools import count
import os
import colorama # Librería necesaria para ejecutar los colores de los mensajes por la terminal
from colorama import Fore
from colorama import init

from Unreported_Search import Unreported_Search

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
    
    # Para el grafo se van a tener dos vectores, uno que almacene los costes y otro que contenga la representación de las aristas.
    verticesNumber = 0
    edgeCosts = [] # Vector de costes
    edgeVector = [] # Vector de aristas
    
    for line in inputFile:
        edgeCosts.append(line)

    verticesNumber = edgeCosts[0] # Obtenemos el número de vértices
    edgeCosts.remove(verticesNumber) # De esta manera se elimina el número de vértices del vector de costes
    verticesNumber = int(verticesNumber) # Se convierte a entero para poder operar con este
    
    # Obtenemos el vector de aristas
    i = 1
    j = 2
    counter = 0
    auxiliary = []
    while counter < len(edgeCosts):
        while j <= verticesNumber:
            auxiliary.append(i)
            auxiliary.append(j)
            edgeVector.append(auxiliary)
            auxiliary = [] # No se hace uso de .clear() ya que genera errores de que elimina dónde apunta la memoria
            j += 1
        j = i + 2
        i += 1
        counter += 1
        
    # Impresión del vector de aristas
    print(edgeVector)

    # Solicitud del nodo inicial y del nodo final
    initialNode = input('Introduzca el número del nodo el cual quiere que sea el nodo inicial del camino: ')
    finalNode = input('Introduzca el número del nodo el cual quiere que sea el nodo final del camino: ')
    
    Unreported_Search(initialNode, finalNode, edgeVector, edgeCosts)


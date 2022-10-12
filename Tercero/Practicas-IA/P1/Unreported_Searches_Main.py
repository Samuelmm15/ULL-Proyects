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

from BFSSearch import BFSSearch

init(autoreset=True) # Esto hace que el color de las cadenas vuelva a su color original cada vez que se use por defecto

if __name__ == '__main__': # This is the main program
    print()
    print(Fore.MAGENTA + '<< BIENVENIDO A LA BÚSQUEDA EN AMPLITUD DEL CAMINO QUE CONECTE DOS VÉRTICES DE UN GRAFO >>')
    print()
    
    inputFileName = input(Fore.GREEN + 'Introduzca el nombre del fichero del cual se van a obtener los datos del grafo: ')
    if os.path.exists(inputFileName) == False: # Comprobación de si el fichero existe
        print()
        print(Fore.RED + 'ERROR >> El nombre del fichero que ha sido introducido, no existe, introduzca un nombre válido.')
        exit(1)
    
    inputFile = open(inputFileName)
    

    verticesNumber = 0
    edgeCosts = [] # Vector de costes
    edgeVector = [] # Vector de aristas
    
    for line in inputFile:
        edgeCosts.append(float(line))

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
            auxiliary = []
            j += 1
        j = i + 2
        i += 1
        counter += 1
        
    # Solicitud del nodo inicial y del nodo final
    print()
    initialNode = input('Introduzca el número del nodo el cual quiere que sea el nodo inicial del camino: ')
    finalNode = input('Introduzca el número del nodo el cual quiere que sea el nodo final del camino: ')
    
    if (int(finalNode) == int(initialNode)):
        print()
        print(Fore.RED + 'ERROR >>> Introduzca de manera correcta el nodo inicial y el nodo final.')
        exit(1)
    
    BFSSearch(initialNode, finalNode, edgeVector, edgeCosts, verticesNumber)


"""
 @file Unreported_Searches_Main.py
 @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 @brief This file implements the main function of the program.
 @version 0.1
 @date 2022-10-09
  
 @copyright Copyright (c) 2022
"""

import os # This library brings the file operations functions.
import colorama # This library prints the colour of the different screen messages.
from colorama import Fore
from colorama import init

from BFSSearch import BFSSearch

init(autoreset=True) # This permits to reset the colours of the printed screen messages.

"""This is the main function of the program.    
"""
if __name__ == '__main__':
    print()
    print(Fore.MAGENTA + '<< BIENVENIDO A LA BÚSQUEDA EN AMPLITUD DEL CAMINO QUE CONECTE DOS VÉRTICES DE UN GRAFO >>')
    print()
    
    inputFileName = input(Fore.GREEN + 'Introduzca el nombre del fichero del cual se van a obtener los datos del grafo: ')
    if os.path.exists(inputFileName) == False: # Comprobes if the introduced file exists.
        print()
        print(Fore.RED + 'ERROR >> El nombre del fichero que ha sido introducido, no existe, introduzca un nombre válido.')
        exit(1)
    
    inputFile = open(inputFileName)
    

    verticesNumber = 0
    edgeCosts = [] # Costs array.
    edgeVector = [] # Edge array.
    
    for line in inputFile:
        edgeCosts.append(float(line))

    verticesNumber = edgeCosts[0] # This is the number of edges.
    edgeCosts.remove(verticesNumber)
    verticesNumber = int(verticesNumber)
    
    # Gets the edge array.
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
        
    print()
    initialNode = input('Introduzca el número del nodo el cual quiere que sea el nodo inicial del camino: ')
    finalNode = input('Introduzca el número del nodo el cual quiere que sea el nodo final del camino: ')
    
    if (int(finalNode) == int(initialNode)):
        print()
        print(Fore.RED + 'ERROR >>> Introduzca de manera correcta el nodo inicial y el nodo final.')
        exit(1)
    
    BFSSearch(initialNode, finalNode, edgeVector, edgeCosts, verticesNumber)
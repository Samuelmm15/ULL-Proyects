"""
 @file Unreported_Search.py
 @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 @brief
 @version 0.1
 @date 2022-10-09
  
 @copyright Copyright (c) 2022
"""

from typing import final
from colorama import Fore
from colorama import init
from collections import defaultdict

# Función necesaria para generar el deccionario de nodos y aristas
def generateDictionary(edges):
    dictionaryList = defaultdict(list)
    for u, v in edges:
        dictionaryList[u].append(v)
        dictionaryList[v].append(u)
    return dictionaryList

def bfs(edgeGraph, initialnode, finalNode):
    finalRoute = []
    visited = [] # Lista de nodos visitado
    queue = [] # Cola de nodos a visitar
    node = int(initialnode)
    
    # Comienzo del algoritmo BFS    
    visited.append(node) # Inicializacion de los vectores
    queue.append(node)
    
    while queue:
        auxiliary = queue.pop(0)
        print(auxiliary, end = " ") # Para imprimir los nodos visitados
    
        for neighbour in edgeGraph[auxiliary]:
            if (neighbour not in visited):
                visited.append(neighbour)
                queue.append(neighbour)
            if (neighbour in visited) and (neighbour == int(finalNode)): # De esta manera se puede encontrar el camino desde el nodo inicial hasta el final
                finalRoute = visited
                return finalRoute

# Se implementará una búsqueda en amplitud que es lo mismo que en anchura
def BFSSearch(initialNode, finalNode, edgeVector, edgeCosts, verticesNumber):
    # Para comenzar eliminación de aquellos nodos que son de coste -1
    i = 0
    while i < len(edgeVector):
        auxiliaryCost = edgeCosts[i]
        if float(auxiliaryCost) == float(-1.00):
            edgeVector.pop(i)
            edgeCosts.pop(i)
            i = 0
        i += 1
    
    # De esta manera sólo se dejan los nodos que realmente son necesarios para el árbol y el grafo
    
    # Comprobación
    print()
    print(edgeVector)
    print(edgeCosts)
    
    edgeGraph = generateDictionary(edgeVector)
    print()
    print(edgeGraph)
    print()
    
    finalRoute = bfs(edgeGraph, int(initialNode), int(finalNode))
    
    print()
    print('Encontrado el camino entre los nodos introducidos por teclado >>>')
    i = 0
    while i < len(finalRoute):
        if (i != len(finalRoute) - 1):
            print(f'{finalRoute[i]} --> ', end=' ')
        else:
            print(f'{finalRoute[i]}')
        i += 1
    print()
    
    # Obtener los costes totales de las aristas
    auxiliaryEdges = []
    finalRouteEdges = []
    i = 0
    j = 1
    while i < len(finalRoute) - 1:
        if (finalRoute[i] < finalRoute[j]):
            auxiliaryEdges.append(finalRoute[i])
            auxiliaryEdges.append(finalRoute[j])
            finalRouteEdges.append(auxiliaryEdges)
            auxiliaryEdges = []
        else:
            auxiliaryEdges.append(finalRoute[j])
            auxiliaryEdges.append(finalRoute[i])
            finalRouteEdges.append(auxiliaryEdges)
            auxiliaryEdges = []
        j += 1
        i += 1
    
    print()
    print('Aristas del camino final:')
    print(finalRouteEdges)
    print()
    
    # Una vez con las aristas del camino final se obtiene el coste total asociado
    i = 0
    j = 0
    repetitionFlag = False
    costPosition = 0
    costsVector = []
    while i < len(edgeCosts):
        auxiliaryEdges = finalRouteEdges[j]
        auxiliaryEdgesOriginal = edgeVector[i]
        if (auxiliaryEdges == auxiliaryEdgesOriginal):
            costPosition = i
            costsVector.append(costPosition)
            repetitionFlag =True
            j += 1
        if (repetitionFlag == False):
            i += 1
        else:
            i = 0
            repetitionFlag = False
        
    finalCosts = []
    for position in costsVector:
        auxiliaryCosts = edgeCosts[position]
        finalCosts.append(auxiliaryCosts)
    
    print()
    print('Vector de costes:')
    print(finalCosts)
    print()
    
    
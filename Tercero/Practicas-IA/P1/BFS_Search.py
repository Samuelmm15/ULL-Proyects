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

def bfsPrint(finalResult, initialNode, finalNode, edgeCosts, edgeVector):
    partialRotue = []
    print()
    print(finalResult)
    print()
    print(f'El camino de nodos para poder ir desde el nodo {initialNode} hasta el nodo {finalNode} es: ')
    beforeNode = 0
    size = 0
    for i in finalResult:
        if (beforeNode == 0):
            beforeNode = i[0]
            print(f'{i[0]} --> ', end=' ')
            partialRotue.append(i[0])
        if (beforeNode != i[0]):
            beforeNode = i[0]
            print(f'{i[0]} --> ', end=' ')
            partialRotue.append(i[0])
        if (size == len(finalResult) - 1):
            print(f'{i[1]}')
            partialRotue.append(i[1])
        size += 1
    
    printRoute = []
    introducedFlag = False
    repeatedFlag = False
    i = 0
    j = 1
    while i < (len(partialRotue) - 1):
        auxiliary = []
        auxiliary.append(partialRotue[i])
        auxiliary.append(partialRotue[j])
        for k in finalResult:
            if (auxiliary == k):
                printRoute.append(auxiliary)
                print(printRoute)
                if (repeatedFlag == False):
                    i += 1
                    if (j == len(partialRotue) - 1):
                        i = len(partialRotue)
                    j += 1
                    repeatedFlag = False
                    introducedFlag = True
                else:
                    i += 1
                    if (j == len(partialRotue) - 1):
                        i = len(partialRotue)
                    j += 1
                    repeatedFlag = False
                    introducedFlag = True
        if (introducedFlag == False) or (repeatedFlag == True):
            i -= 1
            repeatedFlag = True
        introducedFlag = False
        
    print()
    print(printRoute)
    print()
    
    # Búsqueda final del camino
    i = len(printRoute) - 1
    j = i - 1
    # (v, u)
    v = 0
    u = 0
    finalRoute = []
    finalRoute.append(printRoute[i])
    flag = False
    while i >= 0:
        v = printRoute[i]
        u = printRoute[j]
        if (v[0] == u[1]):
            finalRoute.append(u)
            if (flag == False):
                i -= 1
            else:
                i -= 2
            flag = False
        else:
            flag = True
        if (j >= 0):
            j -= 1
        else:
            i = -1
    
    i = len(finalRoute) - 1
    auxiliaryResult = []
    while i >= 0:
        auxiliaryResult.append(finalRoute[i])
        i -= 1

    print()
    print(auxiliaryResult)
    
    print()
    print('El camino final es:')
    i = 0
    while i < len(auxiliaryResult):
        if (i < len(auxiliaryResult) - 1):
            print(f'{auxiliaryResult[i][0]} --> ', end=' ')
        else:
            print(f'{auxiliaryResult[i][0]} -->', end=' ')
            print(f'{auxiliaryResult[i][1]}')
        i += 1

    # Calculo del coste final del camino entre ambos nodos
    i = 0
    j = 0
    indexVectorAuxiliary = []
    while i < len(auxiliaryResult):
        auxiliary = auxiliaryResult[i]
        if (auxiliary[0] > auxiliary[1]):
            auxiliaryVector = []
            auxiliaryVector.append(auxiliary[1])
            auxiliaryVector.append(auxiliary[0])
            while j < len(edgeVector):
                if (edgeVector[j] == auxiliaryVector):
                    indexVectorAuxiliary.append(j)
                j += 1
            j = 0
        else:
            while j < len(edgeVector):
                if (edgeVector[j] == auxiliary):
                    indexVectorAuxiliary.append(j)
                j += 1
            j = 0
        i += 1
    
    costsVectorResult = []
    for i in indexVectorAuxiliary:
        costsVectorResult.append(edgeCosts[i])
        
    print('El vector de costes de las aristas resultantes es: ')
    print(costsVectorResult)
    
    distanceResult = 0
    for i in costsVectorResult:
        distanceResult = float(distanceResult) + float(i)
        
        
    print()
    print('La distancia total del camino es:')
    print(distanceResult)

# Función necesaria para generar el deccionario de nodos y aristas
def generateDictionary(edges):
    dictionaryList = defaultdict(list)
    for u, v in edges:
        dictionaryList[u].append(v)
        dictionaryList[v].append(u)
    return dictionaryList

def bfs(edgeGraph, initialnode, finalNode, edgeCosts, edgeVector):
    finalResult = []
    visited = [] # Lista de nodos visitado
    queue = [] # Cola de nodos a visitar
    node = int(initialnode)
    
    # Comienzo del algoritmo BFS    
    # Inicializacion de los vectores
    visited.append(node)
    queue.append(node)
    
    while queue:
        auxiliary = queue.pop(0)
        print(auxiliary, end = " ") # Para imprimir los nodos visitados
    
        # Se comprueba para cada arista del tipo (auxiliary, neighbour), es similar a la arista (i, j)
        for neighbour in edgeGraph[auxiliary]:
            if (neighbour not in visited):
                visited.append(neighbour)
                queue.append(neighbour)
                # Mediante esta operación se va añadiendo hasta que se encuentre el nodo final del camino
                auxiliaryEdge = []
                auxiliaryEdge.append(auxiliary)
                auxiliaryEdge.append(neighbour)
                finalResult.append(auxiliaryEdge)
            if (neighbour in visited) and (neighbour == int(finalNode)): # De esta manera se puede encontrar el camino desde el nodo inicial hasta el final
                bfsPrint(finalResult, initialnode, finalNode, edgeCosts, edgeVector)

# Se implementará una búsqueda en amplitud que es lo mismo que en anchura
def BFSSearch(initialNode, finalNode, edgeVector, edgeCosts):
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
    
    bfs(edgeGraph, int(initialNode), int(finalNode), edgeCosts, edgeVector)
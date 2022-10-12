"""
 @file Unreported_Search.py
 @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 @brief
 @version 0.1
 @date 2022-10-09
  
 @copyright Copyright (c) 2022
"""

from bfsDivition import BfsDivition

# Implementación de la búsqueda en amplitud
def bfs(edgeGraph, initialnode, finalNode, edgeCosts, edgeVector, verticesNumber, edgesNumber):
    finalFlag = False
    vectorResult = []
    visited = [] # Lista de nodos visitado
    queue = [] # Cola de nodos a visitar
    node = int(initialnode)

    # Inicializacion de los vectores
    visited.append(node)
    queue.append(node)
    
    while queue:
        auxiliary = queue.pop(0)
    
        # Se comprueba para cada arista del tipo (auxiliary, neighbour), es similar a la arista (i, j)
        for neighbour in edgeGraph[auxiliary]:
            if (neighbour not in visited):
                visited.append(neighbour)
                queue.append(neighbour)
                # Mediante esta operación se va añadiendo hasta que se encuentre el nodo final del camino
                auxiliaryEdge = []
                auxiliaryEdge.append(auxiliary)
                auxiliaryEdge.append(neighbour)
                vectorResult.append(auxiliaryEdge)
            if (neighbour in visited) and (neighbour == int(finalNode)): # De esta manera se puede encontrar el camino desde el nodo inicial hasta el final
                if (finalFlag == False):
                    BfsDivition(vectorResult, visited, initialnode, finalNode, edgeCosts, edgeVector, verticesNumber, edgesNumber)
                finalFlag = True # Esto se hace debido a que se sigue recorriendo el árbol hasta el último nodo
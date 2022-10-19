"""
 @file Unreported_Search.py
 @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 @brief This file contains the inplementation of the bfs algorithm.
 @version 0.1
 @date 2022-10-09
  
 @copyright Copyright (c) 2022
"""

from PrintFile import PrintFile
from bfsDivition import BfsDivition
from Probability import Probability

"""This function implements the bfs algorithm.
    """
def bfs(edgeGraph, initialnode, finalNode, edgeCosts, edgeVector, verticesNumber, edgesNumber):
    finalFlag = False
    comprobation = False
    vectorResultAuxiliary = []
    vectorResult = []
    visited = [] # Visited nodes.
    queue = [] # Queue of nodes to visit.
    probabilityComparationFlag = 0
    probabilityComprobation = []
    node = int(initialnode)

    visited.append(node)
    queue.append(node)
    probabilityComparationFlag = node
      
    while queue:
        auxiliary = queue.pop(0)
    
        # Comprobation of (i, j) edges.
        for neighbour in edgeGraph[auxiliary]:
            if (neighbour not in visited):
                # Final route array insertion.
                auxiliaryEdge = []
                auxiliaryEdge.append(auxiliary) # i
                auxiliaryEdge.append(neighbour) # j
                vectorResultAuxiliary.append(auxiliaryEdge)
                if (probabilityComparationFlag != auxiliary):
                    auxiliaryProbability = Probability(vectorResultAuxiliary, edgeCosts, edgeVector)
                    vectorResult.append(auxiliary)
                    vectorResult.append(auxiliaryProbability)
                    probabilityComparationFlag = auxiliary
                    queue.append(auxiliaryProbability)
                else:
                    # En este punto vemos que se introduce para cambiar el rumbo del algoritmo
                    visited.append(neighbour)
                    queue.append(neighbour)
            if (neighbour in visited) and (neighbour == int(finalNode)):
                if (finalFlag == False):
                    BfsDivition(vectorResult, visited, initialnode, finalNode, edgeCosts, edgeVector, verticesNumber, edgesNumber)
                    comprobation = True
                finalFlag = True
                
    if (comprobation == False):
        print()
        print('Camino no encontrado')
        print('El camino generado ha sido: ')
        print(vectorResult)
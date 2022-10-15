"""
 @file Unreported_Search.py
 @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 @brief This file contains the inplementation of the bfs algorithm.
 @version 0.1
 @date 2022-10-09
  
 @copyright Copyright (c) 2022
"""

from bfsDivition import BfsDivition

"""This function implements the bfs algorithm.
    """
def bfs(edgeGraph, initialnode, finalNode, edgeCosts, edgeVector, verticesNumber, edgesNumber):
    finalFlag = False
    vectorResult = []
    visited = [] # Visited nodes.
    queue = [] # Queue of nodes to visit.
    node = int(initialnode)

    visited.append(node)
    queue.append(node)
    
    while queue:
        auxiliary = queue.pop(0)
    
        # Comprobation of (i, j) edges.
        for neighbour in edgeGraph[auxiliary]:
            if (neighbour not in visited):
                visited.append(neighbour)
                queue.append(neighbour)
                # Final route array insertion.
                auxiliaryEdge = []
                auxiliaryEdge.append(auxiliary)
                auxiliaryEdge.append(neighbour)
                vectorResult.append(auxiliaryEdge)
            if (neighbour in visited) and (neighbour == int(finalNode)):
                if (finalFlag == False):
                    BfsDivition(vectorResult, visited, initialnode, finalNode, edgeCosts, edgeVector, verticesNumber, edgesNumber)
                finalFlag = True
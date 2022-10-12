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

from bfs import bfs

# Función necesaria para generar el deccionario de nodos y aristas
def generateDictionary(edges):
    dictionaryList = defaultdict(list)
    for u, v in edges:
        dictionaryList[u].append(v)
        dictionaryList[v].append(u)
    return dictionaryList

def BFSSearch(initialNode, finalNode, edgeVector, edgeCosts, verticesNumber):
    # Eliminación de los costes y de los nodos de coste -1 o que son inalcanzables
    i = 0
    while i < len(edgeVector):
        auxiliaryCost = edgeCosts[i]
        if float(auxiliaryCost) == float(-1.00):
            edgeVector.pop(i)
            edgeCosts.pop(i)
            i = 0
        i += 1
    
    edgesNumber = len(edgeCosts)
    
    # Creación del diccionario
    edgeGraph = generateDictionary(edgeVector)
    
    bfs(edgeGraph, int(initialNode), int(finalNode), edgeCosts, edgeVector, verticesNumber, edgesNumber)
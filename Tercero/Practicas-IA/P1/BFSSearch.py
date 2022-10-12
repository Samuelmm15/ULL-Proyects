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
    
    # # Comprobación
    # print()
    # print(edgeVector)
    # print(edgeCosts)
    
    # Creación del diccionario
    edgeGraph = generateDictionary(edgeVector)
    # print()
    # print(edgeGraph)
    # print()
    
    bfs(edgeGraph, int(initialNode), int(finalNode), edgeCosts, edgeVector)
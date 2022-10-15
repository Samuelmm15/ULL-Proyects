"""
 @file Unreported_Search.py
 @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 @brief This file implements the node and edges dictionary.
 @version 0.1
 @date 2022-10-09
  
 @copyright Copyright (c) 2022
"""

from colorama import Fore
from colorama import init
from collections import defaultdict

from bfs import bfs

"""This function generates the node dictionary.
    """
def generateDictionary(edges):
    dictionaryList = defaultdict(list)
    for u, v in edges:
        dictionaryList[u].append(v)
        dictionaryList[v].append(u)
    return dictionaryList

"""This function deletes the unreacheable edges and their associated costs.
    """
def BFSSearch(initialNode, finalNode, edgeVector, edgeCosts, verticesNumber):
    # Deleting the unreacheable edges and the costs.
    i = 0
    while i < len(edgeVector):
        auxiliaryCost = edgeCosts[i]
        if float(auxiliaryCost) == float(-1.00):
            edgeVector.pop(i)
            edgeCosts.pop(i)
            i = 0
        i += 1
    
    edgesNumber = len(edgeCosts)
    
    # Creating the dicctionry.
    edgeGraph = generateDictionary(edgeVector)
    
    bfs(edgeGraph, int(initialNode), int(finalNode), edgeCosts, edgeVector, verticesNumber, edgesNumber)
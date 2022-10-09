"""
 @file Unreported_Search_InDepth_Search.py
 @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 @brief
 @version 0.1
 @date 2022-10-09
  
 @copyright Copyright (c) 2022
"""

def NextNode(edgeVector, position):
    i = 0
    resultPosition = 0
    comprobationFlag = False
    while i < len(edgeVector):
        auxiliary = edgeVector[i]
        if int(position) == int(auxiliary[0]): # Hay que tener cuidado con las comparaciones de números enteros
            if comprobationFlag == False:
                resultPosition = i
                comprobationFlag = True
        i += 1
    return resultPosition

def InDepthSearch(initialNode, finalNode, edgeVector, edgeCosts, depth):
    # Primero comprobación de cual es el nodo inicial del vector según lo especificado
    i = 0
    initialPosition = 0
    comprobationFlag = False
    while i < len(edgeVector):
        auxiliary = edgeVector[i]
        if int(initialNode) == int(auxiliary[0]): # Hay que tener cuidado con las comparaciones de números enteros
            if comprobationFlag == False:
                initialPosition = i
                comprobationFlag = True
        i += 1
        
    # Inicialización de la búsqueda del camino teniendo en cuenta la profundidad limite
    i = 0
    auxiliaryResult = [] # Para poder ir metiendo los nodos del camino parcial
    while i <= int(depth):
        # Primero comprobar si se trata del nodo final
        auxiliaryEdge = edgeVector[initialPosition]
        if int(auxiliaryEdge[1]) != int(finalNode):
            auxiliaryCosts = edgeCosts[initialPosition]
            if auxiliaryCosts != -1:
                auxiliaryResult.append(auxiliaryEdge)
                initialPosition = initialPosition + 1
        else:
            auxiliaryCosts = edgeCosts[initialPosition]
            if auxiliaryCosts != -1:
                auxiliaryResult.append(auxiliaryEdge)
                initialPosition = initialPosition + 1
        i += 1
        
    print(auxiliaryResult)
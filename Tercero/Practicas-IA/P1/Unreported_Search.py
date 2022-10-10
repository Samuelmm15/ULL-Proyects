"""
 @file Unreported_Search.py
 @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 @brief
 @version 0.1
 @date 2022-10-09
  
 @copyright Copyright (c) 2022
"""

# Se implementará una búsqueda en amplitud que es lo mismo que en anchura
def UnreportedSearch(initialNode, finalNode, edgeVector, edgeCosts):
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
    
    # Una vez se tiene esto, se debe de encontrar el nodo ráiz del árbol
    # Cuando se tiene el nodo raiz, se expanden todos los sucesores de este nodo raíz.
    
    # Primero búsqueda del nodo raíz y expansión de los nodos sucesores de dicho nodo raíz, además de los costes
    i = 0
    comprobationFlag = False
    sucessorsEdges = [] # Este es el vector de sucesores a partir del nodo raiz
    while i < len(edgeVector):
        auxiliaryEdge = edgeVector[i]
        if int(auxiliaryEdge[0]) == int(initialNode):
            comprobationFlag = True
        if comprobationFlag == False: # Se realiza la eliminación de los costes asociados hasta que se encuentre el nodo raiz
            edgeCosts.pop(i)
        if comprobationFlag == True:
            sucessorsEdges.append(auxiliaryEdge) # De esta manera se obtiene el vector de sucesores a partir del nodo raíz
        i += 1
    
    # Comprobación
    print()   
    print(sucessorsEdges)
    print(edgeCosts)
    print(len(sucessorsEdges))
    print(len(edgeCosts))
    
    # Búsqueda del camino haciendo uso del vector de sucesores y costes asociado
    i = 0
    j = int(initialNode)
    finalFlag = False
    partialCosts = -1
    partialCostsPosition = 0
    partialRoute = [] # Este es el vector de soluciones parcial
    while i < len(sucessorsEdges):
        auxiliaryEdge = sucessorsEdges[i] # De esta manera se obtiene la arista
        auxiliaryCost = edgeCosts[i] # De esta manera se obtiene el coste asociado
        if auxiliaryEdge[0] == j:
            if int(auxiliaryEdge[1]) == int(finalNode): # En el caso de que el siguiente nodo de alguna de las aristas sea el nodo final
                finalFlag = True
                partialCostsPosition = i
                partialRoute.append(int(partialCostsPosition))
            if finalFlag != True:
                if partialCosts == -1:
                    partialCosts = float(auxiliaryCost)
                    partialCostsPosition = i
                else:
                    if float(auxiliaryCost) <= partialCosts:
                        partialCosts = float(auxiliaryCost)
                        partialCostsPosition = i
        else:
            if finalFlag != True:
                partialRoute.append(int(partialCostsPosition))
                partialCosts = -1
                partialCostsPosition = 0
                j += 1 # De esta manera se está yendo al siguiente nivel del árbol, es decir se pasa al siguiente nivel
        i += 1
    
    finalRoute = []
    finalCosts = []
    for i in partialRoute:
        auxiliaryEdge = sucessorsEdges[i]
        auxiliaryCost = edgeCosts[i]
        finalRoute.append(auxiliaryEdge)
        finalCosts.append(float(auxiliaryCost))
    
    print()
    print(finalRoute)
    print(finalCosts)
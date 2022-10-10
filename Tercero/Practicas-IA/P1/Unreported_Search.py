"""
 @file Unreported_Search.py
 @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 @brief
 @version 0.1
 @date 2022-10-09
  
 @copyright Copyright (c) 2022
"""

from colorama import Fore
from colorama import init

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
            edgeCosts.pop(0) # Siempre se elimina la posición 0 porque vamos recorriendo el vector de manera ordenada hasta el punto en el que se inicializa el árbol
        if comprobationFlag == True:
            sucessorsEdges.append(auxiliaryEdge) # De esta manera se obtiene el vector de sucesores a partir del nodo raíz
        i += 1
        
    if comprobationFlag == False:
        print()
        print(Fore.RED + 'ERROR >> El nodo inicial no posee ningún sucesor.')
        exit(1)
    
    # Comprobación
    print()   
    print(sucessorsEdges)
    print(edgeCosts)
    print(len(sucessorsEdges))
    print(len(edgeCosts))
    
    # Última prueba de todo esto anterior
    # ESTO ES LA BÚSQUEDA POR APLITUD DEL CAMINO ENTRE EL NODO INICIAL Y EL NODO FINAL, UNA VEZ SE TIENE ESTO, SE REALIZA LA BÚSQUEDA CONCRETA DEL CAMINO Y LISTO
    i = 0
    j = int(initialNode)
    finalFlag = False
    partialPosition = 0
    partialRoute = [] # Este es el vector de soluciones parcial
    while i < len(sucessorsEdges):
        auxiliaryEdge = sucessorsEdges[i] # De esta manera se obtiene la arista
        if (int(auxiliaryEdge[1]) == int(finalNode)) or (int(auxiliaryEdge[0]) == int(finalNode)): # COMPROBAR POR QUÉ DA ERRORES
            partialPosition = i
            partialRoute.append(partialPosition);
            i = len(sucessorsEdges)
            finalFlag = True
        if finalFlag == False:
            if int(auxiliaryEdge[0]) == int(j):
                partialPosition = i
                partialRoute.append(partialPosition)
            else:
                j += 1
                partialPosition = 0
                if int(auxiliaryEdge[0]) == int(j): # Para cuando se cambia de j y se aumenta
                    partialPosition = i
                    partialRoute.append(partialPosition)
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
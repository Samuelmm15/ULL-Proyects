from typing import final
from colorama import Fore
from colorama import init

from PrintFile import PrintFile

def BfsPrint(vectorResult, visited, initialNode, finalNode, edgeCosts, edgeVector, verticesNumber, edgesNumber):
    partialRoute = []
    print()
    print(Fore.MAGENTA + f'Los nodos genrerados para poder encontrar el camino entre los nodos {int(initialNode)} y {int(finalNode)} han sido: ')
    beforeNode = 0
    size = 0
    for i in vectorResult:
        if (beforeNode == 0):
            beforeNode = i[0]
            print(Fore.CYAN + f'{i[0]} --> ', end=' ')
            partialRoute.append(i[0])
        if (beforeNode != i[0]):
            beforeNode = i[0]
            print(Fore.CYAN + f'{i[0]} --> ', end=' ')
            partialRoute.append(i[0])
        if (size == len(vectorResult) - 1):
            print(Fore.CYAN + f'{i[1]}')
            partialRoute.append(i[1])
        size += 1
    
    print()
    print(Fore.CYAN + f'La cantidad de nodos que han sido generados son: {len(partialRoute)}')
    
    print()
    print(Fore.CYAN + f'La cantidad de nodos que han sido ispeccionados han sido: {len(visited)}')
    
    printRoute = []
    introducedFlag = False
    repeatedFlag = False
    i = 0
    j = 1
    while i < (len(partialRoute)):
        auxiliary = []
        if (i < len(partialRoute)) and (j < len(partialRoute)):
            auxiliary.append(partialRoute[i])
            auxiliary.append(partialRoute[j])
            for k in vectorResult:
                if (auxiliary == k):
                    printRoute.append(auxiliary)
                    if (repeatedFlag == False):
                        i += 1
                        if (j >= len(partialRoute)):
                            i = len(partialRoute)
                        j += 1
                        repeatedFlag = False
                        introducedFlag = True
                    else:
                        i += 1
                        if (j >= len(partialRoute)):
                            i = len(partialRoute)
                        j += 1
                        repeatedFlag = False
                        introducedFlag = True
            if (introducedFlag == False) or (repeatedFlag == True):
                if (i > 0):
                    i -= 1
                else:
                    i = j
                repeatedFlag = True
            introducedFlag = False
        else:
            i = len(partialRoute)
        
    # Búsqueda final del camino
    i = len(printRoute) - 1
    j = i - 1
    # (v, u)
    v = 0
    u = 0
    finalRoute = []
    finalRoute.append(printRoute[i])
    while i >= 0:
        v = printRoute[i]
        u = printRoute[j]
        if (v[0] == u[1]):
            finalRoute.append(u)
            i = j
            j -= 1
        else:
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
    print(Fore.MAGENTA + f'El camino de nodos para poder ir desde el nodo {initialNode} hasta el nodo {finalNode} es: ')
    i = 0
    while i < len(auxiliaryResult):
        if (i < len(auxiliaryResult) - 1):
            print(Fore.CYAN + f'{auxiliaryResult[i][0]} --> ', end=' ')
        else:
            print(Fore.CYAN + f'{auxiliaryResult[i][0]} -->', end=' ')
            print(Fore.CYAN + f'{auxiliaryResult[i][1]}')
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
        
    
    distanceResult = 0
    for i in costsVectorResult:
        distanceResult = float(distanceResult) + float(i)
        
        
    print()
    print(Fore.MAGENTA + 'La distancia total del camino es:')
    print(Fore.CYAN + f'{distanceResult}')
    
    PrintFile(auxiliaryResult, initialNode, finalNode, distanceResult, partialRoute, visited, verticesNumber, edgesNumber)
"""
 @file Probability.py
 @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 @brief
 @version 0.1
 @date 2022-10-09
  
 @copyright Copyright (c) 2022
"""

import random

def Probability(probabilityComprobation, edgeCosts, edgeVector):
    finalResult = []
    auxiliaryPosition = []
    i = 0
    j = 0
    while i < len(probabilityComprobation): # Obtenemos las posisiones de los costes de las aristas
        auxiliary = probabilityComprobation[i]
        while j < len(edgeVector):
            auxiliaryEdge = edgeVector[j]
            if ((int(auxiliary[0]) == int(auxiliaryEdge[0])) and (int(auxiliary[1]) == int(auxiliaryEdge[1]))):
                auxiliaryPosition.append(j)
            j += 1
        j = 0
        i += 1
        
    auxiliaryCosts = []
    i = 0
    while i < len(auxiliaryPosition):
        auxiliary = auxiliaryPosition[i]
        auxiliaryCosts.append(edgeCosts[auxiliary])
        i += 1
        
    # Realizamos las operaciones con los costes
    finalCostsVector = []
    i = 0
    while i < len(auxiliaryCosts): # Realización de la inversa
        auxiliary = auxiliaryCosts[i]
        auxiliary = 1 / auxiliary
        finalCostsVector.append(auxiliary)
        i += 1
        
    i = 0
    finalAdd = 0
    while i < len(finalCostsVector): # obtención de las probabilidades
        finalAdd = finalAdd + finalCostsVector[i]
        i += 1
        
    resultCostsVector = []
    i = 0
    while i < len(finalCostsVector):
        auxiliaryResult = finalCostsVector[i] / finalAdd
        resultCostsVector.append(auxiliaryResult)
        i += 1
        
    # Elección de manera aleatoria
    # Dependiendo de la posición de la elección ese será el neighbour
    randomProbability = random.choice(resultCostsVector)
    
    # Encontrar cual es la arista asociada a la probabilidad
    i = 0
    position = 0
    while i < len(resultCostsVector):
        if (resultCostsVector[i] == randomProbability):
            position = i
        i += 1
        
    return probabilityComprobation[position][1] # Devuelve j
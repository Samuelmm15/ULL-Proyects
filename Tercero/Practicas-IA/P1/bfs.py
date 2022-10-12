from bfsPrint import bfsPrint

def bfs(edgeGraph, initialnode, finalNode, edgeCosts, edgeVector):
    finalFlag = False
    finalResult = []
    visited = [] # Lista de nodos visitado
    queue = [] # Cola de nodos a visitar
    node = int(initialnode)
    
    # Comienzo del algoritmo BFS    
    # Inicializacion de los vectores
    visited.append(node)
    queue.append(node)
    
    while queue:
        auxiliary = queue.pop(0)
        # print(auxiliary, end = " ") # Para imprimir los nodos visitados
    
        # Se comprueba para cada arista del tipo (auxiliary, neighbour), es similar a la arista (i, j)
        for neighbour in edgeGraph[auxiliary]:
            if (neighbour not in visited):
                visited.append(neighbour)
                queue.append(neighbour)
                # Mediante esta operación se va añadiendo hasta que se encuentre el nodo final del camino
                auxiliaryEdge = []
                auxiliaryEdge.append(auxiliary)
                auxiliaryEdge.append(neighbour)
                finalResult.append(auxiliaryEdge)
            if (neighbour in visited) and (neighbour == int(finalNode)): # De esta manera se puede encontrar el camino desde el nodo inicial hasta el final
                if (finalFlag == False):
                    bfsPrint(finalResult, initialnode, finalNode, edgeCosts, edgeVector)
                finalFlag = True # Esto se hace debido a que se sigue recorriendo el árbol hasta el último nodo
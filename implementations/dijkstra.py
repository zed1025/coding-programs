# implementaion of dijkstra's algorithm
# https://www.youtube.com/watch?v=OrJ004Wid4o

from collections import defaultdict
from platform import node
import sys
# useful in finding the min. cost neighbour, greedy approach
from heapq import heapify, heappush, heappop

def dijkstra(graph, src, dest):
    inf = sys.maxsize
    # i created one more dict of dict to set the cost of each node to infinity and set its predecessors as empty array
    # the pred array will store the path from source to destination
    node_data = {
        'A': {'cost': inf, 'pred': []},
        'B': {'cost': inf, 'pred': []},
        'C': {'cost': inf, 'pred': []},
        'D': {'cost': inf, 'pred': []},
        'E': {'cost': inf, 'pred': []},
        'F': {'cost': inf, 'pred': []},
    }
    # assigning cost of starting node as 0
    node_data[src]['cost'] = 0
    # creating an array of visited elements
    visited = []
    # initially temp = src, and it will be updated with the minimum cost neighbour
    temp = src
    # we run it for 5 iterations because the graph has 6 vertices, so the algorithm will end in 5 steps
    for i in range(5):
        if temp not in visited:
            visited.append(temp)
            min_heap = []
            for j in graph[temp]: # traversing the neighbours of temp
                if j not in visited: # if neighbour in visited array do not calculate cost for it
                    cost =  node_data[temp]['cost'] + graph[temp][j]
                    if cost < node_data[j]['cost']:
                        node_data[j]['cost'] = cost
                        node_data[j]['pred'] = node_data[temp]['pred'] + list(temp)
                    heappush(min_heap, (node_data[j]['cost'], j))
        heapify(min_heap) # by default it will create min heap
        temp = min_heap[0][1]
    print('Shortest Distance: ' + str(node_data[dest]['cost']))
    print('Path: ' + str(node_data[dest]['pred'] + list(dest)))
        

if __name__ == "__main__":
    # representing graph as a dictionary of dictionary
    # similar to the adjacency list implementatation, and weigh of each edge is 1
    # weight represents the hop count as described in the question
    graph = {
        'A':{'B':1, 'C': 1},
        'B':{'A':1, 'C':1, 'D':1},
        'C':{'A':1, 'B':1, 'E':1, 'D':1},
        'D':{'B':1, 'C':1, 'E':1, 'F':1},
        'E':{'C':1, 'D':1, 'F':1},
        'F':{'D':1, 'E':1},
    }

    source = 'A'
    destination = 'F'
    dijkstra(graph, source, destination)


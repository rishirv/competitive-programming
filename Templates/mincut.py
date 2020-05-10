from random import randint
from copy import deepcopy

def contract(graph, a, b):
	if b in graph.keys():
		graph[a].extend(graph[b])
		del graph[b]
	graph[a][:] = [val for val in graph[a] if val != a and val != b]
	for i in graph:
		graph[i][:] = [val if val != b else a for val in graph[i]]

def mincut(graph, n):
	for x in range(n-2):
		m = 0
		for i in graph:
			m += len(graph[i])
		ran = randint(0, m-1)
		for i in graph:
			if(ran >= len(graph[i])):
				ran -= len(graph[i])
			else:
				contract(graph, i, graph[i][ran])
				break
	return min([len(x) for x in graph.values()])

graph = {}

with open('mincut.txt', 'r') as data:
	lines = data.read().strip().split("\n")

for line in lines:
	line_list = list(map(int, line.strip().split("\t")))
	graph[line_list[0]] = line_list[1:]

m = 19900

for i in range(200):
	k = mincut(deepcopy(graph), 200)
	if(k < m):
		m = k

print(m)
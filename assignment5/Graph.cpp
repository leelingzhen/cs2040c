#include "Graph.h"
//uncomment this to include your own "heap.h"
//we will assume that you use the same code in your previous assignment
#include "heap.h"

std::ostream& operator<<(std::ostream& os, nodeWeightPair const& n) {
	return os << " (idx:" << n._node << " w:" << n._weight << ")";
}


Graph::Graph(int n)
{
	_al = new List<nodeWeightPair> [n];
	_nv = n;
}

int Graph::shortestDistance(int s, int d)
{
	// implement your code here
	Heap<nodeWeightPair> min_heap;
	int visited[100] = {}; // too lazy to use std::vector or idk if im allowed to use it

	List<nodeWeightPair>* neighbour_list;

	// push soure node to minheap first
	min_heap.insert(nodeWeightPair(s, 0));


	// searching base on min_heap
	// "bfs" with PQ
	while (!min_heap.empty()){

		auto node = min_heap.extractMax();	
		int i = node.nodeIndex();
		int w = node.weight();

		if (visited[i]){
			cout << "visited" << endl;
			continue;
		}

		if (node.nodeIndex() == d) {
			return - node.weight();
		}

		visited[i] = 1;

		neighbour_list = &_al[node.nodeIndex()];

		for (neighbour_list->start(); !neighbour_list->end(); neighbour_list->next()) {
			auto neighbour = neighbour_list->current();
			nodeWeightPair insert_node = nodeWeightPair(neighbour.nodeIndex(), node.weight() - neighbour.weight());
			min_heap.insert(insert_node);
		}
		min_heap.printHeapArray();

	}


	return -1;
}


void Graph::addEdge(int s, int d, int w)
{
	_al[s].insertHead(nodeWeightPair(d, w));
}

void Graph::printGraph()
{
	for (int i=0; i < _nv; i++)
	{
		cout << "Node " << i << ": ";
		for (_al[i].start(); !_al[i].end(); _al[i].next())
			cout << " (" << _al[i].current().nodeIndex() << "," << _al[i].current().weight() << ")";
		cout << endl;

	}

}
Graph::~Graph()
{

	delete[] _al;

}

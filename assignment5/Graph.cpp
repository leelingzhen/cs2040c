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
	int* dist = new int [_nv]();

	for (int i = 0; i <_nv; i++) {
		dist[i] = -2147483647;
	}
	dist[s] = 0;

	int* parents = new int[_nv]();
	parents[s] = s;
	
	int shortest_distance = -1;

	List<nodeWeightPair>* neighbour_list;

	// push soure node to minheap first
	min_heap.insert(nodeWeightPair(s, 0));

	// searching based on min_heap
	// searching with PQ
	while (!min_heap.empty()){

		auto node = min_heap.extractMax();	
		int u = node.nodeIndex();
		int w = node.weight();

		if (w < dist[u]){
			continue;
		}

		if (u == d) {

			shortest_distance = - w;
			break;
		}

		neighbour_list = &_al[u];

		for (neighbour_list->start(); !neighbour_list->end(); neighbour_list->next()) {
			auto neighbour = neighbour_list->current();
			int v = neighbour.nodeIndex();
			int v_weight = w - neighbour.weight();
			if (dist[v] > v_weight) {
				continue;
			}
			dist[v] = v_weight;
			parents[v] = u;
			nodeWeightPair insert_node = nodeWeightPair(v, v_weight);
			min_heap.insert(insert_node);
		}


	}


	// for (int i = 0; i < _nv; i++) {
	// 	cout << i << " ";
	// }
	// cout << endl;
	//
	// for (int i = 0; i < _nv; i++) {
	// 	cout << parents[i] << " ";
	// }
	// cout << endl;
	// for (int i = 0; i < _nv; i++) {
	// 	cout << dist[i] << " ";
	// }
	// cout << endl;



	if (shortest_distance != - 1){
		int path_size = 0;
		for (int p = d; p != parents[p]; p = parents[p]){
			path_size ++;
		}
		path_size++;
		// cout << endl;
		// cout << "path size: " << path_size<< endl;

		int* path = new int[path_size] {s};
		for (int p = d, i = path_size - 1; p != parents[p]; p = parents[p], i--) {
			path[i] = p;
		}

		cout << "Path:";
		for (int i = 0; i < path_size; i++) {
			cout <<" "<< path[i];
		}
		cout << endl;

		delete [] path;
	}


	// printing shortest path
	delete [] dist;
	delete [] parents;
	return shortest_distance;
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

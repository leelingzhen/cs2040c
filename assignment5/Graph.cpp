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
	int* visited = new int[_nv]();
	int shortest_distance = -1;
	int shortest_path;

	List<nodeWeightPair>* neighbour_list;

	// push soure node to minheap first
	min_heap.insert(nodeWeightPair(s, 0));

	// searching based on min_heap
	// "bfs" with PQ
	/* 
	 * to print path, can store the entire path of the node in the int nodeindex
	 * the current node will be obtained from the last digit in node index
	 * for eg nodeIndex = 14568
	 * path traversed so far 1 -> 4 -> 5 -> 6 -> 8 
	 * current node = 8
	 *
	* */
	while (!min_heap.empty()){

		auto node = min_heap.extractMax();	
		int path = node.nodeIndex();
		int i = path % 10;
		int w = node.weight();

		if (visited[i]){
			// cout << "visited" << endl;
			continue;
		}

		if (i == d) {

			shortest_path = path;
			shortest_distance = - w;
			break;
		}

		visited[i] = 1;

		neighbour_list = &_al[i];

		for (neighbour_list->start(); !neighbour_list->end(); neighbour_list->next()) {
			auto neighbour = neighbour_list->current();
			int new_path = path * 10 + neighbour.nodeIndex();
			nodeWeightPair insert_node = nodeWeightPair(new_path, w - neighbour.weight());
			min_heap.insert(insert_node);
		}
	}


	// printing shortest path
	if (shortest_distance != -1) {
		int temp = shortest_path;
		int size_path = 0;
		while (temp) {
			size_path++;
			temp /= 10;
		}
		int *r_path = new int[size_path];
		for (int i = 0; i < size_path; i++) {
			r_path[i] = shortest_path % 10;
			shortest_path /= 10;
		}
		cout << "Path:";
		if (s == 0) {
			cout << " " << 0;
		}
		for (int i = size_path - 1; i >= 0; i--){
			cout << " " << r_path[i];
		}
		cout << endl;
		delete [] r_path;
	}
	delete [] visited;
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

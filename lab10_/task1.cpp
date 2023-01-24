#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph
{
    // No. of vertices
	int n_vertices; 

	// Pointer to an array containing adjacency lists
	vector<list<int> > adj;
public:
//constructor
Graph(int V)
{
	this->n_vertices = V;
	adj.resize(V);
}

void addEdge(int a, int b)
{
    // Add a to b’s list.
	adj[a].push_back(b); 
}

void BFS(int x)
{
	// Mark all the vertices as not visited
	vector<bool> visited;
	visited.resize(n_vertices,false);

	// Creating a queue for BFS
	list<int> queue;

	// Mark the current node as visited and enqueue it
	visited[x] = true;
	queue.push_back(x);

	while(!queue.empty())
	{
		// Dequeue a vertex from queue and print it
		x = queue.front();
		cout << x << " ";
		queue.pop_front();

		// Get all adjacent vertices of the dequeued
		// vertex s. If a adjacent has not been visited,
		// then mark it visited and enqueue it
		for (auto adjecent: adj[x])
		{
			if (!visited[adjecent])
			{
				visited[adjecent] = true;
				queue.push_back(adjecent);
			}
		}
	}
}
~Graph(){
    adj.clear();
}
};

int main()
{
     // Reg 2021468
    // Name: M. Talha Imtiaz

    // KHOOBSOORAT CODE
    
    int st_vertex=3;
	// Creating graph
	Graph graph(4);
	graph.addEdge(0, 1);
	graph.addEdge(0, 2);
	graph.addEdge(1, 2);
	graph.addEdge(2, 0);
	graph.addEdge(2, 3);
	graph.addEdge(3, 3);
	graph.addEdge(3, 2);
	graph.addEdge(3, 3);

	cout << "Breadth First Traversal "
		<< "(starting from vertex "<<st_vertex<<" ) \n";
	graph.BFS(st_vertex);

	return 0;
}


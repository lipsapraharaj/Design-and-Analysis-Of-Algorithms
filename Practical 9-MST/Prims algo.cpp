#include<bits/stdc++.h>
using namespace std;
# define INF 999

// iPair ==> Integer Pair
typedef pair<int, int> iPair;

class Graph
{
	int V;

	// In a weighted graph, we need to store vertex
	// and weight pair for every edge
	list< pair<int, int> > *adj;

public:
	Graph(int V); // Constructor
	void addEdge(int u, int v, int w);
	void primMST();// Print MST using Prim's algorithm

};

// Allocates memory for adjacency list
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<iPair> [V];
}

void Graph::addEdge(int u, int v, int w)
{
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}

// Prints shortest paths from src to all other vertices
void Graph::primMST()
{
	priority_queue< iPair, vector <iPair> , greater<iPair> > pq;

	int src =0; // Taking vertex 0 as source
	int cost=0;
	vector<int> key(V, INF); // Create a vector for keys and initialize all
	                         // keys as infinite (INF)
	vector<int> parent(V, -1);// To store parent array which in turn store MST
	vector<bool> inMST(V, false);   // To keep track of vertices included in MST
	pq.push(make_pair(0, src));// Insert source itself in priority queue and initialize
	                           // its key as 0.
    key[src] = 0;

	/* Looping till priority queue becomes empty */
	while (!pq.empty())
	{
		// The first vertex in pair is the minimum key
		// vertex, extract it from priority queue.
		// vertex label is stored in second of pair (it
		// has to be done this way to keep the vertices
		// sorted key (key must be first item
		// in pair)
		int u = pq.top().second;
		pq.pop();

		inMST[u] = true; // Include vertex in MST
		list< pair<int, int> >::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			int v = (*i).first;         // Get vertex label and weight of current adjacent
		                             	// of u.
			int weight = (*i).second;

			// If v is not in MST and weight of (u,v) is smaller
			// than current key of v
			if (inMST[v] == false && key[v] > weight)
			{
				// Updating key of v
				key[v] = weight;
				pq.push(make_pair(key[v], v));
				parent[v] = u;
			}
		}
	}


	// Print edges of MST using parent array
	for (int i = 1; i < V; ++i)
    {
        cout<<"\nEdge("<<parent[i]<<","<<i<<")"<<"\t"<<parent[i]<<"\t\t"<<i<<"\t\t"<<key[i]<<endl;

		cost=cost+key[i];

    }


cout<<"\nTOTAL WEIGHT (OR COST) OF THIS MINIMUM SPANNING TREE = "<<cost;
}


int main()
{
	int vertices,u,v,w;
	char ans;
	cout<<"Enter the number of vertices: ";
	cin>>vertices;
	Graph g(vertices);

do
{
    cout<<"\nEnter the source vertex and destination vertex for the edge  : ";
	cin>>u>>v;

	cout<<"Enter weight of this edge : ";
	cin>>w;

	g.addEdge(u,v,w);
	cout<<"Want to add more edges('Y'=yes / 'N'=no)? : ";
	cin>>ans;
}while(ans=='y'|| ans=='Y');

    cout<<"\nMIMIMUM SPANNING TREE USING PRIM's ALGORITHM:";
	cout<<"\n-----------------------------------------------------";
    cout<<"\nEdges    Source vertex   Destination vertex  Weight";
    cout<<"\n-----------------------------------------------------";
	g.primMST();

	return 0;
}

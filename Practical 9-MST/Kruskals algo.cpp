#include<stdio.h>
#include<iostream>
#define MAX 30
using namespace std;

typedef struct edge
{
	int u,v,w;
}edge;

typedef struct edgelist
{
	edge data[MAX];
	int n;
}edgelist;

edgelist elist;

int G[MAX][MAX],n;
edgelist spanlist;

void kruskal();
int find_set(int rank[],int vertexno);
void union_set(int rank[],int c1,int c2);
void sort();
void print();

int main()
{
	int i,j,total_cost;

	cout<<"\nEnter the number of vertices:";
	cin>>n;

	cout<<"\nEnter the cost adjacency matrix:\n";

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>G[i][j];

	kruskal();
	print();
	return 0;
}

void kruskal()
{
	int rank[MAX],i,j,cno1,cno2;
	elist.n=0;

	for(i=1;i<n;i++)
		for(j=0;j<i;j++)
		{
			if(G[i][j]!=0)
			{
				elist.data[elist.n].u=i;
				elist.data[elist.n].v=j;
				elist.data[elist.n].w=G[i][j];
				elist.n++;
			}
		}

	sort();

	for(i=0;i<n;i++)
		rank[i]=i;

	spanlist.n=0;

	for(i=0;i<elist.n;i++)
	{
		cno1=find_set(rank,elist.data[i].u);
		cno2=find_set(rank,elist.data[i].v);

		if(cno1!=cno2)
		{
			spanlist.data[spanlist.n]=elist.data[i];
			spanlist.n=spanlist.n+1;
			union_set(rank,cno1,cno2);
		}
	}
}

int find_set(int rank[],int vertexno)
{
	return(rank[vertexno]);
}

void union_set(int rank[],int c1,int c2)
{
	int i;

	for(i=0;i<n;i++)
		if(rank[i]==c2)
			rank[i]=c1;
}

void sort()
{
	int i,j;
	edge temp;

	for(i=1;i<elist.n;i++)
		for(j=0;j<elist.n-1;j++)
			if(elist.data[j].w>elist.data[j+1].w)
			{
				temp=elist.data[j];
				elist.data[j]=elist.data[j+1];
				elist.data[j+1]=temp;
			}
}

void print()
{
	int i,cost=0;
	cout<<"\nMIMIMUM SPANNING TREE USING KRUSKAL's ALGORITHM:";
	cout<<"\n-----------------------------------------------------";
    cout<<"\nEdges    Source vertex   Destination vertex  Weight";
    cout<<"\n-----------------------------------------------------";
	for(i=0;i<spanlist.n;i++)
	{
		cout<<"\nEdge"<<"("<<spanlist.data[i].u<<","<<spanlist.data[i].v<<")"<<"\t"<<spanlist.data[i].u<<"\t\t"<<spanlist.data[i].v<<"\t\t"<<spanlist.data[i].w;
		cost=cost+spanlist.data[i].w;
	}

	cout<<"\n\nTOTAL WEIGHT (OR COST) OF THIS MINIMUM SPANNING TREE = "<<cost;
}

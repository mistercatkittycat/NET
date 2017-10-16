#include<bits/stdc++.h>
#include <stdio.h>
#include <limits.h>
  

#define V 9
using namespace std;  
int node2;

int minDistance(int dist[], bool sptSet[])
{

   int min = INT_MAX, min_index;
  
   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
  
   return min_index;
}
  

int printSolution(int dist[], int n)
{

   printf("Vertex   Distance from Source\n");
   for (int i = 0; i < V ; i++){
		if(i==node2)
      printf("%d \t\t %d\n", i, dist[i]);
	}
}
  


void dijkstra(int graph[V][V], int src)
{
     int dist[V];

  
     bool sptSet[V];
                    
  
     
     for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
  
     
     dist[src] = 0;
  
     
     for (int count = 0; count < V-1; count++)
     {
     
     
       int u = minDistance(dist, sptSet);
  
     
       sptSet[u] = true;
  
     
       for (int v = 0; v < V; v++)
  
     
     
     
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }
  
     
     printSolution(dist, V);
}
  

int main()
{

   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
    int node1;

	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			cout<<graph[i][j]<<"\t";
	}
cout<<endl;
}
	
cout<<"Enter the nodes between whom the distance is to be found"<<endl;

cin>>node1>>node2;

    dijkstra(graph, node1);
  
    return 0;
}

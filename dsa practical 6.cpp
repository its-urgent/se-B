#include <iostream>
#include <stdlib.h>
using namespace std;

int cost[10][10], i, j, k, n, qu[10], front, rear, v, visit[10], visited[10];
int stk[10], top, visit1[10], visited1[10];

int main()
{
    int m;
    cout << "Enter number of vertices : ";
    cin >> n;
    cout << "Enter number of edges : ";
    cin >> m;
    cout << "\nEDGES :\n";
    for (k = 1; k <= m; k++)
    {
        cin >> i >> j;
        cost[i][j] = 1;
        cost[j][i] = 1;
    }
    
    //display function
    cout << "The adjacency matrix of the graph is : " << endl;
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            cout << " " << cost[i][j];
        }
        cout << endl;
    }
    
   cout << "Enter initial vertex : ";
   cin >> v;
   cout << "The BFS of the Graph is\n";
   cout << v << " ";
   visited[v] = 1;
   qu[rear++] = v;
   while (front < rear) 
   {
   	    v = qu[front++];
        for (j = 0; j <= n; j++)
        {
            if (cost[v][j] != 0 && visited[j] != 1)
            {
                cout << j << " "; 
                visited[j] = 1;
                qu[rear++] = j;
            }
        }
    }  
    cout <<endl<<"Enter initial vertex : ";
    cin >> v;
    cout << "The DFS of the Graph is\n";
    cout << v<<" ";
    visited[v] = 1;
    stk[top]=v;
    top++;
    int k = 1;

     while (k < n && top > 0) {
        v = stk[--top]; 
        for (int j = n; j >=1; j--) {
            if (cost[v][j] != 0 && visited1[j] != 1) {
                visited1[j] = 1;
                stk[top] = j; 
                top++; 
                cout << j << " "; 
                k++;
                break; 
            }
        }
    }

    return 0;
}

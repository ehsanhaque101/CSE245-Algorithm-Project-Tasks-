#include <bits/stdc++.h>
using namespace std;

vector<int>adj[100]; ///2D link list
int n,e,t=0,cy=0;///t=time
int color[100],prev[100],d[100],f[100];///d=discover time & f=finish time
int inf=4.0/0.0;///setting infinity

/// 111= color white , 222= color gray & 333= color white

void DFS_visit(int u)
{
    int i,v;///v is adjacency of u
    color[u]=222;
    t=t+1;
    d[u]=t;
    for(i=0;i<adj[u].size();i++){ /// the adj[u] head array is running up to its size
        v=adj[u][i];
        if(color[v]==111){
            prev[v]=u;
            DFS_visit(v); /// recursion
        }
        if(color[v]==222){
            cy++;
            cout << "Cycle\n";
        }
    }
    color[u]=333;
    t=t+1;
    f[u]=t;
}

void DFS(int n, int s)
{
    int u; /// main nodes
    for (u=0;u<n;u++){
        color[u]=111;
        prev[u]=u;
        d[u]=inf;
        f[u]=inf;
    }
    t=0;
    for (u=0;u<n;u++){
        if(color[u]==111){
            DFS_visit(u);
        }
    }
}


int main()
{
    /*int inf=4.0/0.0;
    cout << inf << endl;*/
    int u,v,i,j,s,des;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;
    for (i=0;i<e;i++){
        cout << "Enter the connectable node" << i << ": ";
        cin >> u;
        cout << "Enter the connected node: ";
        cin >> v;
       adj[u].push_back(v);
       ///adj[v].push_back(u); /// creating header by adj[u] and v is connecting to it as a link list
       ///undirected graph
    }
    cout << "---------Adjacency List of the Graph------------\n";
    ///traverse and print algorithm
    for(i=0;i<n;i++){
            cout << i << "-> ";
        for(j=0;j<adj[i].size();j++){ /// the adj[i] head array is running up to its size
            cout << adj[i][j] << " ";  ///printing the connected nodes
        }
        cout << endl;
    }
    cout << "Enter source node:";
    cin >> s;
    DFS(n,s);
    cout << "Enter the reaching node: ";
    cin >> des;
    cout << "The discovering time from " << s << " to " << des << " is :" << d[des] << endl;
    cout << "The finish time from " << s << " to " << des << " is :" << f[des] << endl;
}

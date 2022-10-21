///adj list max degree
#include <bits/stdc++.h>
using namespace std;

///vector<int>gra[100];
vector<int>adj[100]; ///2D link list
int n,e;

void ndegree(int v, int e)
{
    int maxi=0,pos=0,c=0;
    for(int i=0;i<v;i++){
        c=adj[i].size();
        if(maxi<c){
            maxi=c; ///maximum degree
            pos=i;
        }
    }
    cout << pos << " " << maxi;
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
       adj[u].push_back(v); /// creating header by adj[u] and v is connecting to it as a link list
       adj[v].push_back(u);
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
    ndegree(n,e);
    return 0;
}

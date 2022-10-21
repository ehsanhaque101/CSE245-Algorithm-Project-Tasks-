///weighted graph and its maximum weight
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int v,w;
}temp;

///vector<int>gra[100];
vector<node>adj[100]; ///2D link list

int main()
{
    /*int inf=4.0/0.0;
    cout << inf << endl;*/
    int n,e,a,b,i,j,weight,c=0,maxw=0,maxv=0,pos=0;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;
    for (i=0;i<e;i++){
        cin >> a;
        cin >> b;
        cin >> weight;
        temp.v=a;
        temp.w=weight;
        adj[b].push_back(temp);
        temp.v=b;
        adj[a].push_back(temp);
    }
    cout << "---------Adjacency List of the Graph------------\n";
    ///traverse and print algorithm
    for(i=0;i<n;i++){
            cout << i << "-> ";
        for(j=0;j<adj[i].size();j++){ /// the adj[i] head array is running up to its size
            cout << adj[i][j].v << "(" << adj[i][j].w << ") ";  ///printing the connected nodes
        }
        cout << endl;
    }
    for(i=0;i<n;i++){
        for(j=0;j<adj[i].size();j++){
            c=adj[i][j].w;
            if(maxw<c){
                maxw=c;
                maxv=adj[i][j].v;
                pos=i;
            }
        }
    }
    cout << pos << " " << maxv << "(" << maxw << ")" << endl;
}

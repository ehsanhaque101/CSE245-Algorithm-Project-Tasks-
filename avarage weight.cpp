#include <bits/stdc++.h>
using namespace std;

struct node
{
    int v,aw;
}temp;

vector<node>adj[100]; ///2D link list

int main()
{
    int weight[100],a[100],b[100];
    /*int inf=4.0/0.0;
    cout << inf << endl;*/
    int n,e,aa,bb,i,j,avg,k,sum=0;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;
    for (i=0;i<e;i++){
        cin >> a[i];
        cin >> b[i];
        cin >> weight[i];}
    for(k=0;k<e;k++){
        sum=sum+weight[k];
    }
    avg=sum/e;
    for (i=0;i<e;i++){
        aa=a[i];
        bb=b[i];
        temp.v=aa;
        temp.aw=avg;
        adj[bb].push_back(temp);
        temp.v=bb;
        adj[aa].push_back(temp);
    }

    cout << "---------Adjacency List of the Graph------------\n";
    ///traverse and print algorithm
    for(i=0;i<n;i++){
            cout << i << "-> ";
        for(j=0;j<adj[i].size();j++){ /// the adj[i] head array is running up to its size
            cout << adj[i][j].v << "(" << adj[i][j].aw << ") ";  ///printing the connected nodes
        }
        cout << endl;
    }

}

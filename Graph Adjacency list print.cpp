#include <bits/stdc++.h>
using namespace std;

vector<int>gra[100];
vector<int>adj[100]; ///2D link list
queue<int>Q;
int n,e;
int color[100],prev[100],d[100];
int inf=4.0/0.0;


void ndegree(int v, int e)
{
    for(int i=0;i<v;i++){
        cout << i << "'s degree = ";
        cout << adj[i].size() << endl; ///printing the size of every head array or nodes
    }
}

int BFS(int n, int s)
{
    int u,i,v,cy=0;
    for (u=0;u<n;u++){
        color[u]=111;
        prev[u]=u;
        d[u]=inf;
    }
    color[s]=222;
	d[s]=0;
	prev[s]=s;
    Q.push(s);
    while(!Q.empty()){
        u=Q.front();
        Q.pop();
        for(i=0;i<adj[u].size();i++){ /// the adj[i] head array is running up to its size
            v=adj[u][i];
            if(color[v]==111){
                color[v]==222;
                prev[v]=u;
                d[v]=d[u]+1;
                Q.push(v);
            }
            else if(color[v]==222){
                cy++;
            }
        }
        color[u]=333;
    }
    return cy;
}

void print_path(int s, int v)
{
    if(s==v){
        cout << s << " ";
    }
    else if(prev[v]==v){
        cout << "No path\n";
    }
    else{
        print_path(s,prev[v]);
        cout << v << " ";

    }
}
void connectedness()
{
    for(int i=0;i<n;i++){
    if(color[i]==0){
        flag=2;
        break;

    }
    else{
        flag=1;


    }
}
if(flag==1){
    cout << "connected\n";
}
else if ( flag==2){
    cout << "disconnected\n";
}
}

int main()
{
    /*int inf=4.0/0.0;
    cout << inf << endl;*/
    int u,v,i,j,s,des,cy;
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
    cout << "Enter source node:";
    cin >> s;
    cy=BFS(n,s);
    cout << "Enter the reaching node: ";
    cin >> des;
    print_path(s,des);
    cout << "\nThe distance from " << s << "to " << des << "is :" << d[des] << endl;
    cout << "There are " << cy << " cycles\n";
    connectedness();
    return 0;
}

///this is a code for graph adjacent matrix
#include<bits/stdc++.h>
using namespace std;

int a[10000][10000];

void adjacency_mat(int v,int e)
{
    int x,y;
    cout << "Initial matrix: \n";
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            a[i][j]=0;
        }
    }
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    for(int i=0;i<e;i++){
        cout << "Enter the connectable node" << i << ": ";
        cin >> x;
        cout << "Enter the connected node: ";
        cin >> y;
        a[x][y]=1;
        a[y][x]=1;
    }
    cout << "-------Adjacency Matrix of the graph-----\n";
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-------Adjacency List of the graph-----\n";
    for(int i=0;i<v;i++){
            cout << i << "->";
        for(int j=0;j<v;j++){
            if(a[i][j]==1){
                cout << j <<" ";
            }
        }
        cout << endl;
    }

}

void complete(int v, int e)
{
    int c=(v*(v-1))/2;
    if(e==c)
        cout << "Complete Graph\n";
    else
        cout << "Connected Graph\n";
}

void ndegree(int v, int e)
{
    for(int i=0;i<v;i++){
        int c=0;
        cout << i << "'s degree = ";
        for(int j=0;j<v;j++){
            if(a[i][j]==1){
                c++;
            }
        }
        cout << c << endl;
    }
}

int main()
{
    int m,n,e;
    cout << "Enter the nodes no: ";
    cin >> n;
    cout << "Enter edges no: ";
    cin >> e;
    adjacency_mat(n,e);
    complete(n,e);
    cout << "The degree of every node: ";
    ndegree(n,e);

    return 0;
}

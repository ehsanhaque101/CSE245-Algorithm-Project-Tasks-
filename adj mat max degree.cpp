///adj matrix max degree find
#include<bits/stdc++.h>

using namespace std;

int a[10000][10000];

int main()
{
    int n,e,i,j,x,y,maxi=0,c=0,pos=0;
    cout << "Enter the nodes no: ";
    cin >> n;
    cout << "Enter edges no: ";
    cin >> e;
    cout << "Initial matrix: \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
     for(int i=0;i<e;i++){
        cout << "Enter the connectable node " << i << ": ";
        cin >> x;
        cout << "Enter the connected node: ";
        cin >> y;
        a[x][y]=1;
        a[y][x]=1;
    }
    cout << "-------Adjacency Matrix of the graph-----\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    for(int i=0;i<n;i++){
        c=0;
        for(int j=0;j<n;j++){
            if(a[i][j]==1){
                c++;
            }
        }
        if(maxi<c){ ///maximum degree
            maxi=c;
            pos=i;
        }
    }
    cout << pos << " "<< maxi<< endl;
}

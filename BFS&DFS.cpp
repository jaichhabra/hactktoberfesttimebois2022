#include<bits/stdc++.h>

using namespace std;

int e, x, f(0), r(-1), t(-1);
const int v = 5;

void init(int visited[]){
    for(int i = 0; i < v; i++){
        visited[i] = 0;
    }
}

void BFS(int graph[v][v], int visited[], int x){
    init(visited);
    cout<<"\nBFS : \n";
    int q[10];
    q[r++] = x;
    cout<<x<<" ";
    int j = 1;
    while(j < v){
        for(int i = 0; i < v; i++){
            if(graph[x][i] == 1 && visited[i] == 0){
                visited[i] = 1;
                q[r++] = i;
            }
        }
        x = q[f++];
        cout<<x<<" ";
        j++;
    }
}

void DFS(int graph[v][v], int visited[], int x){
    init(visited);
    cout<<"\nDFS : \n";
    int s[10];
    s[t++] = x;
    cout<<x<<" ";
    visited[x] = 1;
    int j = 1;
    while(j < v){
        for(int i = v; i >= 0; i--){
            if(graph[x][i] == 1 && visited[i] == 0){
                visited[i] = 1;
                s[t++] = i;
            }
        }
        x = s[--t];
        cout<<x<<" ";
        j++;
    }
}

int main(){
    cout<<"Enter number of edges : ";
    cin>>e;
    int graph[v][v];
    int visited[v];
    cout<<"\nNow, enter the edges :\n";
    for(int i = 0; i < e; i++){
        int s, d;
        cout<<"S:"; cin>>s;
        cout<<"D:"; cin>>d;
        graph[s][d] = 1;
    }
    cout<<"\nEnter edge to traverse from : ";
    cin>>x;
    BFS(graph, visited, x);
    DFS(graph, visited, x);

    return 0;
}

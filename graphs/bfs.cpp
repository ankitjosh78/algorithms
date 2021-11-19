#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int> >adj(n);
vector<bool>visited(n);


void bfs(int node){
    queue<int>q;
    q.push(node);
    visited[node]=true;

    while(!q.empty()){
        int x=q.front();
        q.pop();

        for(int y:adj[x]){
            if(!visited[y]){
                q.push(y);
                visited[y]=true;
            }
        }
    }
    return;
}

int main(){
    for(int i=1;i<=n;i++){
        if(!visited[i])
            bfs(i);
    }
}

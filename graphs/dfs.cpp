#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int> >adj(n);
vector<bool>visited(n);

void dfs(int node){
    visited[node]=true;
    for(int x:adj[node]){
        if(!visited[x])
            dfs(x);
    }
    return;
}

int main(){
    for(int i=1;i<=n;i++){
        if(!visited[i])
            dfs(i);
    }
    return 0;
}

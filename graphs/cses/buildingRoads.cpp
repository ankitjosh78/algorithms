#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>adj;
vector<int>comp;
vector<vector<int>>comps;
vector<int>vis;

void dfs(int v){
  vis[v]=1;
  for(int u:adj[v]){
    if(vis[u]==0){
      dfs(u);
    }
  }
  comp.push_back(v);
}
int main(){
  int n,m;
  cin>>n>>m;
  adj.resize(n+1);
  vis.assign(n+1,0);
  int ans=0;
  for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for(int i=1;i<=n;i++){
    if(!vis[i]){
      dfs(i);
      comps.push_back(comp);
      comp.clear();
      ans++;
    }
  }
  ans=ans-1;
  cout<<ans<<endl;
  for(int i=0;i<ans;i++){
    cout<<comps[i][0]<<" "<<comps[i+1][0]<<endl;
  }
}

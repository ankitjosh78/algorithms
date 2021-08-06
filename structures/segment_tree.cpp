// Segment Tree for Sum Queries ( can be easily modified for various other range queries like min/max/gcd)

#include <bits/stdc++.h>
using namespace std;
 
vector<long long>tree;  
vector<int>arr; 
 
// building the segment tree
void build(int node,int left,int right){
    if(right==left){
        tree[node]=arr[left];
        return;
    }
    int mid=(left+right)/2;
    build(2*node,left,mid);
    build(2*node+1,mid+1,right);
    tree[node]=tree[2*node] + tree[2*node +1]; // change line as per question
}
 
// calculating sum for a given range
long long sum(int node,int left_query,int right_query,int left_bound,int right_bound){
    if(right_query < left_bound || left_query > right_bound)
        return 0;  // change line as per question
    if(left_bound >= left_query && right_query >= right_bound)
        return tree[node];
    int mid=(right_bound + left_bound)/2;
    
    return sum(2*node,left_query,right_query,left_bound,mid)+sum(2*node+1,left_query,right_query,mid+1,right_bound) ;// change line as per question
}
 
// updating value at a given position and the segment tree
void update(int index,int value,int n){
    tree[n+index]=value;
    for(int i=n+index;i>=1;i/=2){
        if(i & 1)
            tree[i/2]=tree[i] + tree[i-1];
        else 
            tree[i/2]=tree[i] + tree[i+1];
    }
}

int main(){
    // Sample Question: https://cses.fi/problemset/task/1648/
    int n;cin>>n;
    int q;cin>>q;
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    while(__builtin_popcount(n)!=1){ // adding 0 to the array until length of array becomes a power of 2
        arr.push_back(0);
        n++;
    }
    tree.resize(2*n);
    build(1,0,n-1);
    while(q--){
        int type;cin>>type;
        if(type==1){
            int k;int u;
            cin>>k>>u;
            k--;
            update(k,u,n);
        }
        else{
            int l;int r;
            cin>>l>>r;
            l--;r--;
            cout<<sum(1,l,r,0,n-1)<<'\n';
        }
    }
    return 0;
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;

class DisjointSet{
    unordered_map<ll,ll> parent,sz;
    public:
        void makeSet(vector<ll> &Nodes){
            for(ll i:Nodes){
                parent[i] = i;
                sz[i] = 1;
            }
        }    
        ll findParent(ll node){
            if(parent[node] ==  node)
                return node;
            return parent[node] = findParent(parent[node]);
        }
        void unionSet(ll a,ll b){
            a = findParent(a);
            b = findParent(b);
            if(a!=b){
                if(sz[a]<sz[b])
                    swap(a,b);
                parent[b]  = a;
                sz[a]+=sz[b];
            }
        }
};



void solve(){
    
    ll n;cin>>n;
    vector<ll> Nodes(n);
    for(ll i=1;i<=n;i++)    Nodes[i-1] = i; // Comment this line if array is given
    //for(auto &i:Nodes)  cin>>Nodes[i];    // Uncomment this line if array is given


    DisjointSet djs;
    djs.makeSet(Nodes);


    ll no_of_edges;cin>>no_of_edges;
    for(ll i = 1;i<=no_of_edges;i++){
        ll x,y;cin>>x>>y;
        djs.unionSet(x,y);
    }

}
int main(){
    ll tt;cin>>tt;
    while(tt--)
    solve();
    return 0;
}
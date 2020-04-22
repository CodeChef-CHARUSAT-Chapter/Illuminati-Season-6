/// ILLUMINATI SEASON 6
/// Queries with Bags

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll MAX = 1e5+1;
vector<ll> parent(MAX);
vector<ll> unionBySize(MAX,1);

ll find_set(ll v){
    if(parent[v]==v)return v;
    return parent[v] = find_set(parent[v]);
}

void union_set(ll a, ll b){
    if(unionBySize[a] < unionBySize[b])swap(a,b);
    parent[b] = a;
    unionBySize[a] += unionBySize[b];
}

int main(){
    FAST_IO
    ofstream fout,fin;
    fin.open("Input_1.txt");
    fout.open("Output_1.txt");
    ll n,q;
    cin>>n>>q;
    for(ll i=1;i<=n;i++)parent[i]=i;
    ll a, b;
    ll no_of_bags = n;
    while(q--){
        ll query_type;
        cin>>query_type;
        if(query_type==1){
            cin>>a>>b;
            a = find_set(a);
            b = find_set(b);
            if(a!=b){
                no_of_bags--;
                union_set(a,b);
            }
        }
        else if(query_type==2){
            cin>>a>>b;
            a = find_set(a);
            b = find_set(b);
            if(a==b) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else{
            cout<<no_of_bags<<endl;
        }
    }
}


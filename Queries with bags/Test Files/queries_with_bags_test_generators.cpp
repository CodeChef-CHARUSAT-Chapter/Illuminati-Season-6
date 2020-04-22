/// ILLUMINATI SEASON 6
/// Queries with Bags

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll MAX = 1e5+1;
vector<ll> parent(MAX);
vector<ll> unionBySize(MAX,1);


ll randomRange(ll lower,ll upper){
    ll num = (rand() %(upper - lower + 1)) + lower;
    return num;
}

char randomChoice(){
    double r = ((double) rand() / (RAND_MAX));
    if(r<=0.9){
        return 2;
    }
    else{
        ll x = randomRange(1,3);
        while(x==2)x = randomRange(1,3);
        return x;
    }

    /*return randomRange(2,3);*/
}

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
    fin.open("Input_File_19.txt");
    fout.open("Output_File_19.txt");
    ll n=100000,q=100000;
    fin<<n<<" "<<q<<endl;
    for(ll i=1;i<=n;i++)parent[i]=i;
    ll a, b;
    ll no_of_bags = n;
    while(q--){
        ll query_type = randomChoice();
        //cout<<query_type<<endl;
        fin<<query_type;
        if(query_type==1){
            a = randomRange(1,n);
            b = randomRange(1,n);
            while(a==b){
                b = randomRange(1,n);
            }
            fin<<" "<<a<<" "<<b<<endl;
            a = find_set(a);
            b = find_set(b);
            if(a!=b){
                no_of_bags--;
                union_set(a,b);
            }
        }
        else if(query_type==2){
            a = randomRange(1,n);
            b = randomRange(1,n);
            while(a==b){
                b = randomRange(1,n);
            }
            fin<<" "<<a<<" "<<b<<endl;
            a = find_set(a);
            b = find_set(b);
            if(a==b) fout<<"YES"<<endl;
            else fout<<"NO"<<endl;
        }
        else{
            fin<<endl;
            fout<<no_of_bags<<endl;
        }
    }
    fin.close();
    fout.close();
}


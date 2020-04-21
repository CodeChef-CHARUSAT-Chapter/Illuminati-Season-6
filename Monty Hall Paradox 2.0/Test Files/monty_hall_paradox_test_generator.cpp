/// ILLUMINATI SEASON 6
/// Monty Hall Paradox 2.0

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

ll randRange(ll lower,ll upper){
    ll num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int main(){
    ofstream fout,fin;
    fin.open("Input_File_1.txt");
    fout.open("Output_File_1.txt");
    ll t;
    t = (ll)1e5;
    fin<<t<<endl;
    while(t--){
        ll n = randRange(3,((ll)(1e18)));
        fin<<n<<endl;
        fout<<1<<" "<<n<<" "<<n-1<<" "<<n<<endl;
    }
    fout.close();
    fin.close();
}

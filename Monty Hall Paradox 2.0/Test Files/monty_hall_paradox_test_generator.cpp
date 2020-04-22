/// ILLUMINATI SEASON 6
/// Monty Hall Paradox 2.0 (Test Files Generator)

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
    fin<<100000<<endl;
    t = 10000;
    while(t--){
        ll n = randRange(3,100);
        fin<<n<<endl;
        fout<<1<<" "<<n<<" "<<n-1<<" "<<n<<endl;
    }
    t = 10000;
    while(t--){
        ll n = randRange(100,1000);
        fin<<n<<endl;
        fout<<1<<" "<<n<<" "<<n-1<<" "<<n<<endl;
    }
    t = 10000;
    while(t--){
        ll n = randRange(1000,10000);
        fin<<n<<endl;
        fout<<1<<" "<<n<<" "<<n-1<<" "<<n<<endl;
    }
    t = 10000;
    while(t--){
        ll n = randRange(10000,100000);
        fin<<n<<endl;
        fout<<1<<" "<<n<<" "<<n-1<<" "<<n<<endl;
    }
    t = 10000;
    while(t--){
        ll n = randRange(100000,1000000);
        fin<<n<<endl;
        fout<<1<<" "<<n<<" "<<n-1<<" "<<n<<endl;
    }
    t = 10000;
    while(t--){
        ll n = randRange(1000000,10000000);
        fin<<n<<endl;
        fout<<1<<" "<<n<<" "<<n-1<<" "<<n<<endl;
    }
    t = 10000;
    while(t--){
        ll n = randRange(10000000,100000000);
        fin<<n<<endl;
        fout<<1<<" "<<n<<" "<<n-1<<" "<<n<<endl;
    }
    t = 10000;
    while(t--){
        ll n = randRange(100000000,1000000000);
        fin<<n<<endl;
        fout<<1<<" "<<n<<" "<<n-1<<" "<<n<<endl;
    }
    t = 10000;
    while(t--){
        ll n = randRange((1000000000-10000),1000000000);
        fin<<n<<endl;
        fout<<1<<" "<<n<<" "<<n-1<<" "<<n<<endl;
    }
    t = 10000-2;
    while(t--){
        ll n = randRange(3,1000000000);
        fin<<n<<endl;
        fout<<1<<" "<<n<<" "<<n-1<<" "<<n<<endl;
    }

    /// Boundary Test Cases
    ll n = 3;
    fin<<n<<endl;
    fout<<1<<" "<<n<<" "<<n-1<<" "<<n<<endl;
    n = 1000000000;
    fin<<n<<endl;
    fout<<1<<" "<<n<<" "<<n-1<<" "<<n<<endl;
    fout.close();
    fin.close();
}

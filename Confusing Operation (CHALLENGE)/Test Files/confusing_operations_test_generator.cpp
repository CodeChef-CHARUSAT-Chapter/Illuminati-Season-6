/// @author mann2108
/// confusion_operations (One approach to reduce the score and maximize the points)

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back

ll randomRange(ll lower,ll upper){
    ll num = (rand() %(upper - lower + 1)) + lower;
    return num;
}

ll randomChoice(){
    double r = ((double) rand() / (RAND_MAX));
    ll choice;
    if(r<=0.61803398875){
        ll iterations = randomRange(randomRange(3,29),randomRange(37,47));
        for(ll k=0;k<iterations;k++)choice = randomRange(0,3);
    }
    else{
        ll iterations = randomRange(randomRange(7,11),randomRange(13,17));
        for(ll k=0;k<iterations;k++)choice = randomRange(0,3);
    }
    return choice;
}

int main(){
    ofstream fin;
    fin.open("input_file_6.txt");
    ll n=500;
    fin<<n<<endl;

    vector<vector<ll> > MAT1,MAT2;
    ll inputs;

    for(ll i=0;i<n;i++){
        vector<ll> row;
        for(ll j=0;j<n;j++){
            inputs = randomRange(1,100);
            if(j!=n-1)
                fin<<inputs<<" ";
            else
                fin<<inputs;
            row.pb(inputs);
        }
        fin<<endl;
        MAT1.pb(row);
        MAT2.pb(row);
    }

    for(ll k=0;k<(n*n*n);k++){
        ll i1 = randomRange(0,n-1);
        ll j1 = randomRange(0,n-1);
        ll i2 = randomRange(0,n-1);
        ll j2 = randomRange(0,n-1);
        ll x = MAT1[i1][j1];
        ll y = MAT2[i2][j2];
        MAT2[i1][j1]=y;
        MAT2[i2][j2]=x;
    }

    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(j!=n-1)
                fin<<MAT2[i][j]<<" ";
            else
                fin<<MAT2[i][j];
        }
        fin<<endl;
    }
    fin.close();
}

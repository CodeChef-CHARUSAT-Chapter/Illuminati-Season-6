/// @author mann2108
/// Problem : Rotating Planes

#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll randomRange(ll lower,ll upper){
    ll num = (rand() %(upper - lower + 1)) + lower;
    return num;
}

int main(){

    ll n;
    cin>>n;

    ll plane_stack[n+1][n+1][n+1];

    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            for(ll k=1;k<=n;k++){
                cin>>plane_stack[i][j][k];
            }
        }
    }

    ll rotation_direction[n+1];
    ll rotation_count[n+1];

    for(ll i=1;i<=n;i++){
        ll sum = 0;
        for(ll j=1;j<=n;j++){
            for(ll k=1;k<=n;k++){
                sum+=plane_stack[i][j][k];
            }
        }
        rotation_direction[i] = (sum%2);
        rotation_count[i] = randRange(0,3);
    }
}

/// @author mann2108
/// Problem : Rotating Planes (Challenge)

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
        rotation_direction[i] = sum;
        rotation_count[i] = randomRange(0,3);
    }

    for(ll i=1;i<=n;i++){
        ll t = rotation_count[i];
        ll temp[n+1][n+1];

        for(ll j=1;j<=n;j++){
            for(ll k=1;k<=n;k++){
                temp[j][k] = plane_stack[i][j][k];
            }
        }

        if(rotation_direction[i]%2==0){
            if(t==3){
                for(ll j=1;j<=n;j++){
                    for(ll k=n;k>=1;k--){
                        temp[j][n-k+1] = plane_stack[i][k][j];
                    }
                }
                for(ll j=1;j<=n;j++){
                    for(ll k=1;k<=n;k++){
                        plane_stack[i][j][k] = temp[j][k];
                    }
                }
            }
            if(t>=2){
                for(ll j=1;j<=n;j++){
                    for(ll k=n;k>=1;k--){
                        temp[j][n-k+1] = plane_stack[i][k][j];
                    }
                }
                for(ll j=1;j<=n;j++){
                    for(ll k=1;k<=n;k++){
                        plane_stack[i][j][k] = temp[j][k];
                    }
                }
            }
            if(t>=1){
                for(ll j=1;j<=n;j++){
                    for(ll k=n;k>=1;k--){
                        temp[j][n-k+1] = plane_stack[i][k][j];
                    }
                }
                for(ll j=1;j<=n;j++){
                    for(ll k=1;k<=n;k++){
                        plane_stack[i][j][k] = temp[j][k];
                    }
                }
            }
        }
        else{
            if(t==3){
                for(ll j=n;j>=1;j--){
                    for(ll k=1;k<=n;k++){
                        temp[n-j+1][k] = plane_stack[i][k][j];
                    }
                }
                for(ll j=1;j<=n;j++){
                    for(ll k=1;k<=n;k++){
                        plane_stack[i][j][k] = temp[j][k];
                    }
                }
            }
            if(t>=2){
                for(ll j=n;j>=1;j--){
                    for(ll k=1;k<=n;k++){
                        temp[n-j+1][k] = plane_stack[i][k][j];
                    }
                }
                for(ll j=1;j<=n;j++){
                    for(ll k=1;k<=n;k++){
                        plane_stack[i][j][k] = temp[j][k];
                    }
                }
            }
            if(t>=1){
                for(ll j=n;j>=1;j--){
                    for(ll k=1;k<=n;k++){
                        temp[n-j+1][k] = plane_stack[i][k][j];
                    }
                }
                for(ll j=1;j<=n;j++){
                    for(ll k=1;k<=n;k++){
                        plane_stack[i][j][k] = temp[j][k];
                    }
                }
            }
        }
    }

    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            plane_stack[0][i][j] = 0;
        }
    }

    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            for(ll k=1;k<=n;k++){
                plane_stack[0][j][k] += plane_stack[i][j][k];
            }
        }
    }

    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            cout<<plane_stack[0][i][j]<<" ";
        }
        cout<<endl;
    }
}

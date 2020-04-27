// @author mann2108
// confusion_operations (One approach to reduce the score and maximize the points)

#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
typedef long long int ll;

#define pb push_back

int main(){
    ll n;
    cin>>n;

    vector<vector<ll> > MAT1,MAT2;
    ll inputs;

    for(ll i=0;i<n;i++){
        vector<ll> row;
        for(ll j=0;j<n;j++){
            cin>>inputs;
            row.pb(inputs);
        }
        MAT1.pb(row);
    }

    for(ll i=0;i<n;i++){
        vector<ll> row;
        for(ll j=0;j<n;j++){
            cin>>inputs;
            row.pb(inputs);
        }
        MAT2.pb(row);
    }

    // set each col with best configuration.

    vector<pair<ll,ll> > moves(n,{-1,LLONG_MAX});

    for(ll i=0;i<n;i++){

        vector<ll> temp_col;

        for(ll j=0;j<n;j++){
            temp_col.pb(MAT1[j][i]);
        }

        for(ll rotation=0;rotation<n;rotation++){
            ll cost = 0;
            for(ll j=0;j<n;j++){
                cost+=abs(temp_col[j]-MAT2[j][i]);
            }
            if(cost<moves[i].second){
                moves[i].second = cost;
                moves[i].first = rotation;
            }
            ll temp_first_value = temp_col[0];
            for(ll j=0;j<n-1;j++){
                temp_col[j]=temp_col[j+1];
            }
            temp_col[n-1]=temp_first_value;
        }

    }

    ll moves_count = 0;

    for(ll i=0;i<n;i++){
        moves_count+=moves[i].first;
    }

    cout<<moves_count<<endl;

    for(ll i=0;i<n;i++){
        for(ll j=0;j<moves[i].first;j++){
            cout<<"COL"<<" "<<i+1<<" \n";
        }
    }
}

/// @author mann2108
/// ILLUMINATI SEASON 6
/// Queries with Bags (Brute Force using Array)

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, q;
    cin>>n>>q;
    ll arr[n+1] = {};
    ll no_of_bags = n;
    ll a,b;
    ll cnt = 1;
    while(q--){
        ll choice;
        cin>>choice;
        if(choice==1){
            cin>>a>>b;
            if(arr[a]==arr[b] and arr[a]!=0)continue;
            no_of_bags-=1;
            ll x = arr[a];
            ll y = arr[b];
            if(x==0 and y==0){
                arr[a]=cnt;
                arr[b]=cnt;
            }
            else if(x==0){
                arr[a] = cnt;
                for(ll i=1;i<=n;i++){
                    if(arr[i]==y)arr[i]=cnt;
                }
            }
            else if(y==0){
                arr[b] = cnt;
                for(ll i=1;i<=n;i++){
                    if(arr[i]==x)arr[i]=cnt;
                }
            }
            else{
                for(ll i=1;i<=n;i++){
                    if(arr[i]==x or arr[i]==y)arr[i]=cnt;
                }
            }
            cnt++;
        }
        else if(choice==2){
            cin>>a>>b;
            if(arr[a]==arr[b] and arr[a]!=0)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else{
            cout<<no_of_bags<<endl;
        }
    }
}
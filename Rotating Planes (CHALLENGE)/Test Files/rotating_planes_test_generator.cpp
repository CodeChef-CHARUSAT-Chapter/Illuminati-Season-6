/// @author mann2108
/// Problem : Rotating Planes (Challenge)

#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

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
    ofstream fin,fout;
    fin.open("input_file_100.txt");
    fout.open("output_file_100.txt");
    ll n = 100;
    fin<<n<<endl;

    vector<ll> vec(n+1,1);
    vector<vector<ll> > vec2(n+1,vec);
    vector<vector<vector<ll> > > plane_stack(n+1,vec2);

    //for(ll i=0;i<=n;i++)
    //ll plane_stack[n+1][n+1][n+1];

    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            for(ll k=1;k<=n;k++){
                cout<<plane_stack[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            for(ll k=1;k<=n;k++){
                plane_stack[i][j][k] = randomRange((ll)1,(ll)1000);
                if(k!=n)
                    fin<<plane_stack[i][j][k]<<" ";
                else
                    fin<<plane_stack[i][j][k];
            }
            if(j!=n)
            fin<<endl;
        }
        fin<<endl;
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
        rotation_count[i] = randomChoice();
    }

    /*for(ll i=1;i<=n;i++)cout<<rotation_direction[i]<<" ";
    cout<<endl;
    for(ll i=1;i<=n;i++)cout<<rotation_count[i]<<" ";
    cout<<endl;
    cout<<endl;*/


    for(ll i=1;i<=n;i++){

        //cout<<"********************"<<endl;

        ll t = rotation_count[i];
        ll temp[n+1][n+1];

        for(ll j=1;j<=n;j++){
            for(ll k=1;k<=n;k++){
                temp[j][k] = plane_stack[i][j][k];
            }
        }

        if(rotation_direction[i]%2==0){

            for(ll r1=1;r1<=t;r1++){
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
                /*for(ll j=1;j<=n;j++){
                    for(ll k=1;k<=n;k++){
                        cout<<plane_stack[i][j][k]<<" ";
                    }
                    cout<<endl;
                }
                cout<<endl;*/
            }


        }else{

            for(ll r1=1;r1<=t;r1++){
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
                /*for(ll j=1;j<=n;j++){
                    for(ll k=1;k<=n;k++){
                        cout<<plane_stack[i][j][k]<<" ";
                    }
                    cout<<endl;
                }
                cout<<endl;*/
            }


        }
    }

    /*for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            for(ll k=1;k<=n;k++){
                cout<<plane_stack[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }*/



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
            if(j!=n)
            fout<<plane_stack[0][i][j]<<" ";
            else
            fout<<plane_stack[0][i][j];
        }
        fout<<endl;
    }
    fin.close();
    fout.close();
}

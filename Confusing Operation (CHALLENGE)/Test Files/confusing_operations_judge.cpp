/// Custom judge for confusion operations

#include "spoj.h"
#include <iostream>
#include <string>

using namespace std;
typedef int ll;

ll n,x,sum1=0;
ll MAT1[(ll)1e3][(ll)1e3];
ll MAT2[(ll)1e3][(ll)1e3];
string get_string_from_input(FILE *input){
    char c;
    string s = "";
    fscanf(spoj_t_out," %c",&c);
    s+=c;
    while(true){
        fscanf(spoj_t_out,"%c",&c);
        if(isspace(c))break;
        s+=c;
    }
    return s;
}

int main(){
    spoj_init();
    fscanf(spoj_p_in, "%d", &n);



    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            fscanf(spoj_p_in, "%d", &x);
            MAT1[i][j]=x;
        }
    }

    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            fscanf(spoj_p_in, "%d", &x);
            MAT2[i][j]=x;
        }
    }

    ll k;

    fscanf(spoj_t_out,"%d",&k);
    fprintf(spoj_p_info,"%d\n",k);

    for(ll i=0;i<k;i++){
        string s=get_string_from_input(spoj_p_in);
        ll index;

        if(s=="ROW"){
            fscanf(spoj_t_out,"%d",&index);
            fprintf(spoj_p_info,"%s %d\n",s.c_str(),index);

            ll first_element = MAT1[index][0];
            for(ll j=0;j<n-1;j++){
                MAT1[index][j] = MAT1[index][j+1];
            }
            MAT1[index][n-1]=first_element;

        }
        else if(s=="COL"){
            fscanf(spoj_t_out,"%d",&index);
            fprintf(spoj_p_info,"%s %d\n",s.c_str(),index);

            ll first_element = MAT1[0][index];
            for(ll j=0;j<n-1;j++){
                MAT1[j][index] = MAT1[j+1][index];
            }
            MAT1[n-1][index]=first_element;

        }
        else{
            fprintf(spoj_p_info,"%s %d\n","ERROR_INVALID_STRING\n",index);
        }
    }

    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            sum1+=abs(MAT1[i][j]-MAT2[i][j]);
        }
    }

    sum1+=(n*k);

    fprintf(spoj_score,"%d\n", sum1);
    return SPOJ_RV_POSITIVE;
}

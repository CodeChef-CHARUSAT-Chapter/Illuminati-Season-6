#include "spoj.h"
#include <iostream>
#include <string>
using namespace std;
typedef int ll;
ll n,x,sum1=0;

string get_string_from_input(FILE *input, int max_length){
    char str[max_length + 1];
    char ch;
    // omit all white spaces before the string
    do {
        fscanf(input, "%c", &ch);
    } while (isspace(ch));

    int i = 0;
    do {
        str[i++] = ch;
    } while (fscanf(input, "%c", &ch) == 1 && !isspace(ch));
    str[i] = '\0';

    return string(str);
}

int main()
{
	spoj_init();
	fscanf(spoj_p_in, "%d", &n);


	ll MAT1[n][n];
    ll MAT2[n][n];

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
        fprintf(spoj_p_info,"%d\n",i);
        string s=get_string_from_input(spoj_p_in,3);
        ll index;
        fscanf(spoj_t_out,"%d",&index);
    }

    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            sum1+=abs(MAT1[i][j]-MAT2[i][j]);
        }
    }

	fprintf(spoj_score,"%d\n", sum1);
	return SPOJ_RV_POSITIVE;
}

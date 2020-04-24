#include "spoj.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n=100, len, P[10001], x, F[10001], S[1000001], sum1=0, temp1;
typedef int ll;
int main()
{

	spoj_init();

    vector<ll> vec1(n+1,0);
    vector<vector<ll> > user_output(n+1,vec1);
    vector<vector<ll> > expected_output(n+1,vec1);

    ll user_sum = 0;
    ll expected_sum = 0;




    for(int i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            fscanf(spoj_p_out, "%d", &x);
            user_output[i][j]=x;
            expected_sum+=x;
        }
    }

    for(int i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            fscanf(spoj_t_out, "%d", &x);
            expected_output[i][j]=x;
            user_sum+=x;
        }
    }

    fprintf(spoj_p_info, "USER_SUM : %d\n", user_sum);

    sum1 = abs(user_sum-expected_sum);

    fprintf(spoj_p_info, "EXPECTED_SUM : %d\n", expected_sum);
    fprintf(spoj_p_info, "SCORE : %d\n", sum1);


	fprintf(spoj_score,"%d\n", sum1);
	return SPOJ_RV_POSITIVE;
}

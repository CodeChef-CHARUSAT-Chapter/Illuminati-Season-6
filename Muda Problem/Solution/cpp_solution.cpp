#include<bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
using namespace std;
signed main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
    	string s;
    	cin>>s;
    	ll gr  = 0,i;
    	for(i=0;i<s.length();i++)
    	{
    		if(s[i]=='M' and i <= (s.length() - 4))
    		{
    			ll cn = 1;
    			if(s[i+1]=='u') cn++;
    			if(s[i+2]=='d') cn++;
    			if(s[i+3]=='a') cn++;
    			gr = max(gr , cn);
    		}
    		else if(s[i]=='u' and i-1>=0 and i <= (s.length() - 3))
    		{
    			ll cn = 1;
    			if(s[i+1]=='d') cn++;
    			if(s[i+2]=='a') cn++;
    			gr = max(gr , cn);
    		}
    		else if(s[i]=='d' and i-1>=1 and i <= (s.length() - 2))
    		{
    			ll cn = 1;
    			if(s[i+1]=='a') cn++;
    			gr = max(gr , cn);
    		}
    		else if(s[i]=='a' and i-1>=2) gr = max(gr,1LL);
    	}
    	cout<<4LL - gr<<"\n";
    }
}

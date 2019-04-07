
#include <bits/stdc++.h>
#define mem(ar,num) memset(ar,num,sizeof(ar))
#define me(ar) memset(ar,0,sizeof(ar))
#define lowbit(x) (x&(-x))
#define Pb push_back
#define  FI first
#define  SE second
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define IOS ios::sync_with_stdio(false)
#define DEBUG cout<<endl<<"DEBUG"<<endl; 
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int    prime = 999983;
const int    INF = 0x7FFFFFFF;
const LL     INFF =0x7FFFFFFFFFFFFFFF;
const double pi = acos(-1.0);
const double inf = 1e18;
const double eps = 1e-6;
const LL     mod = 1e9 + 7;
LL qpow(LL a,LL b){LL s=1;while(b>0){if(b&1)s=s*a%mod;a=a*a%mod;b>>=1;}return s;}
LL gcd(LL a,LL b) {return b?gcd(b,a%b):a;}
int dr[2][4] = {1,-1,0,0,0,0,-1,1};
typedef pair<int,int> P;
int n,m;
int  FF(int t){
	if(t == 0) return 0;
	if(t == 1) return 1;
	if(t == 2) return 0;
	if(t == 3) return 1;
	if(t == 4) return 2;
	if(t % 2 == 1) return 0;
	if(FF(t/2) == 1)
		return 2;
	else
		return 1;
}
int FF2(int t){
	if(t == 0) return 0;
	if(t == 1) return 1;
	if(t == 2) return 2;
	return t%2 == 0;
}
const int maxn = 1000+10;
int dp[maxn];
int main(void)
{
	// _int32 a;

	// dp[0] = 0;
	// for(int i = 1;i <= 1000; ++i){
	// 	set<int> se;
	// 	se.insert(dp[i-1]);
	// 	if(i % 2== 0)
	// 		se.insert(dp[i/2]);
	// 	int cnt = 0;
	// 	while(se.count(cnt) == 1)
	// 		cnt++;
	// 	dp[i] = cnt;
	// }
	// for(int i = 1;i <= 1000; ++i){
	// 	// bitset<7> b(i);
	// 	assert(dp[i] == FF(i));
	// 	cout<<i<<" "<<dp[i]<<endl;
	// }
    cin>>n>>m;
    LL t=0;
    for(int i = 1;i <= n; ++i){
    	int a;scanf("%d",&a);
    	if(m&1)
    		t ^= FF(a);
   		else
   			t ^= FF2(a);
    }
    if(t)
    	cout<<"Mario"<<endl;
    else
    	cout<<"Luigi"<<endl;

   return 0;
}

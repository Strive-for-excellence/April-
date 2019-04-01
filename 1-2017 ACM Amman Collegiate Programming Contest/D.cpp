#include <bits/stdc++.h>

#define mem(ar,num) memset(ar,num,sizeof(ar))

#define me(ar) memset(ar,0,sizeof(ar))

#define lowbit(x) (x&(-x))

#define Pb push_back

#define  FI first

#define  SE second

#define For(I,a,b) for(int I = a; I < b; ++I)

#define IOS ios::sync_with_stdio(false)

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

const int maxn = 1e6+10;

long long fac[maxn],invfac[maxn];

void init(int n){

	fac[0] = 1;

	for(int I = 1;i <= n; ++I) fac[I] = fac[I-1]*I%mod;

    invfac[n] = qpow(fac[n],mod-2);

    for(int I = n-1;i >= 0; --I) invfac[I] = invfac[I+1]*(I+1)%mod;

} 

LL C(LL a,LL b){

	return fac[a]*invfac[a-b]%mod*invfac[b]%mod;

}



int main(void)

{

	init(maxn-1);

	int T;cin>>T;

	while(T--){

		int a,b;scanf("%d%d",&a,&b);

		printf("%lld\n",2*C(a-1,b)%mod);

	}



  

   return 0;

}

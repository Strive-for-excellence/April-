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

int a[maxn];

void solve(){

 	LL n,s;scanf("%lld%lld",&n,&s);	

 	if(n >= 2&& s == 1)

 	  {

 	  	puts("-1");

 		return ;

	   }

 	if(n%2 == 0 && s % 2 == 1){

 		puts("-1");

 		return ;

	 }

	if(n*9 < s){

		puts("-1");

		return ;

	}

 	for(int I = 1;i <= n/2; ++I){

 		if(s == 0)

 		  a[I] = a[n-I+1] = 0;

 		else {

 		  	 a[I] = min(9LL,s/2);

 		  	 a[n-I+1] = a[I];

 		  	 s -= 2*a[I];

		   } 

	    }

	if(n&1)

	   a[n/2+1] = s;

	for(int I = 1;i <= n; ++I)

	  printf("%d",a[I]);

	puts("");

}

int main(void)

{

	int T;cin>>T;

	while(T--){

		solve();

	} 

  

   return 0;

}

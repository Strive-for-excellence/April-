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

const int maxn = 1e5+10;

LL a[maxn];

int nxt[maxn];

int main(void)

{

  int T;cin>>T;

  while(T--){

  	int n,k;cin>>n>>k;

  	set<int> se;

	map<int,int> ma;

  	for(int I = 1;i <= n; ++I){

  		scanf("%d",&a[I]);

  		ma[a[I]] = n+i;

	  }

	

	for(int I = n;i >= 1; --I){

	   nxt[I] = ma[a[I]];

	   ma[a[I]] = I;

	}

//	for(int I =1;i <= n; ++I) 

//	 cout<<nxt[I]<<" ";

//	 cout<<endl;

	int cnt = 0;

	for(int I = 1;i <= n; ++I){

		if(!se.empty()&&*se.begin() == I){

			se.erase(*se.begin());

			se.insert(nxt[I]);

			continue;

		}

		cnt++;

		if(se.size() >= k){

			auto it = se.end();

			it--;

			//cout<<*it<<endl;

		 se.erase(it);

		}

		se.insert(nxt[I]);

	}

	cout<<cnt<<endl;

  }

  

   return 0;

}

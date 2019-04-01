#include <bits/stdc++.h>
#define mem(ar,num) memset(ar,num,sizeof(ar))
#define me(ar) memset(ar,0,sizeof(ar))
#define lowbit(x) (x&(-x))
#define Pb push_back
#define  FI first
#define  SE second
#define For(i,a,b) for(int i = a; i < b; ++i)
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
const int maxn = 2000+10;
LL a[maxn];
LL sum[maxn];
int n;

int main(void){
  int T;cin>>T;
  while(T--){
    cin>>n;
    for(int i = 1;i <= n; ++i){
      scanf("%lld",&a[i]);
      sum[i] = sum[i-1]+a[i];
    }
    LL cnt = 0;
    cnt += n;
    for(int i = 1;i <= n; ++i){
      LL t = a[i];
      for(int j = i+1;j <= n; ++j){
        t = t/gcd(a[j],t)*a[j];
        if((sum[j]-sum[i-1]) % t == 0)
          cnt++;
        if(t > sum[n]) break;
      }
      
    }
    cout<<cnt<<endl;
  }
  return 0;
}

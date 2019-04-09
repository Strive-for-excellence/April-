庸人(1505656319) 19:29:43

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
const int maxn = 20;
string s[maxn];
map<char,int> ma;
int ch[300];
int a[maxn];
int Get(string &s){
   int t = 0;
    for(auto c: s)
      t = t*10+a[ma[c]];
  return t;
}
int n;
bool check(){
  int sum =0;
  for(int i = 0;i < n-1; ++i){
    if(a[ma[s[i][0]]] ==0) return false;
    sum += Get(s[i]);
  }
  if(a[ma[s[n-1][0]]] == 0) return false;
  return sum == Get(s[n-1]);
}
int b[maxn];
int main(void)
{
   cin>>n;
   for(int i =0;i < n; ++i){
    cin>>s[i];
   }
   int cnt = 0;
   for(int i = 0;i < n; ++i){
     for(auto t:s[i])
       if(ma[t] == 0)
          ma[t] = ++cnt;//,ch[t] = cnt;
   }
   for(int i = 1;i <= 10; ++i)
      a[i] = i-1;
  int ans = 0;
   do{
    if(check())
    {
        bool yes = false;
        for(int i = 1;i <= cnt; ++i)
          if(a[i] != b[i])
            yes = true;
        if(yes)
          ans++;
       for(int i = 1;i <= cnt; ++i)
          b[i] = a[i];
    }
   }while(next_permutation(a+1,a+1+10));
   cout<<ans<<endl;
   return 0;
}


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
const int maxn = 1e4+10;
vector<P> G[maxn];
bool vis[maxn];
LL dis[maxn];
bool done[maxn];
int N;
void Dij(){
  for(int i = 0;i < N; ++i)
    dis[i] = INFF/10;
  dis[0] = 0;
  priority_queue<P> Q;
  Q.push(P(0,0));
  // DEBUG;
  while(!Q.empty()){
    P p = Q.top(); Q.pop();
    // cout<<p.second<<endl;
    int x = p.second;
    if(done[x]) continue;
    // cout<<x<<" "<<dis[x]<<endl;
    done[x] = true;
    for(auto c: G[x]){
      if(done[c.first]) continue;
      int to = c.FI;//,w = c.SE;
      if(dis[to] > dis[x]+c.SE){
        dis[to] = dis[x]+c.SE;
        Q.push(P(-dis[to],to));
      }
    } 
  }
}
LL sum = 0;
// bool vis[maxn];
void bfs(){
  queue<int> Q;
  Q.push(N-1);
  vis[N-1] =0;
  while(!Q.empty()){
    int p = Q.front(); Q.pop();
    for(auto c:G[p]){
      if(dis[c.first] +c.second== dis[p]){
        sum +=c.second;
        if(!vis[c.first]){
          vis[c.first] = true;
          Q.push(c.first);
        }
      }
    }
  }
}
int main(void)
{
  int T;cin>>N>>T;
  while(T--){
    int u,v,w;scanf("%d%d%d",&u,&v,&w);
    G[u].Pb(P(v,w));
    G[v].Pb(P(u,w));
  }
  // DEBUG;
  Dij();
  // cout<<N-1<<endl;
  // cout<<dis[N-1]<<endl;
  // DEBUG;
  bfs();
  cout<<2*sum<<endl;

   return 0;
}

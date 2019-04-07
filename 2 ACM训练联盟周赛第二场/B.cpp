#include<bits/stdc++.h>
using namespace std;
#define lson (o << 1)
#define rson (o << 1|1)
const int maxn = 1e5+10;
const int INF = 1e9;
#define int long long 
typedef long long LL;
struct Tree{
  LL min,max,sum,add;
};
Tree tree[maxn<<2];
LL a[maxn];
void pushup(int o,int l,int r){
  tree[o].min = min(tree[lson].min,tree[rson].max);
  tree[o].max = max(tree[lson].max,tree[rson].max);
  tree[o].sum = tree[lson].sum + tree[rson].sum;
}
void pushdown(int o,int l,int r){
  int m = (l+r)>>1;
  if(tree[o].add){
    tree[lson].add += tree[o].add;
    tree[lson].sum += (m-l+1)*tree[o].add;
    tree[lson].min += tree[o].add;
    tree[lson].max += tree[o].add;

    tree[rson].add += tree[o].add;
    tree[rson].sum += (r-m)*tree[o].add;
    tree[rson].min += tree[o].add;
    tree[lson].max += tree[o].add;
    tree[o].add = 0;
  }
}
void up(Tree & a,Tree b){
  a.min = min(a.min,b.min);
  a.max = max(a.max,b.max);
  a.sum += b.sum;
}
void build(int o,int l,int r){
  tree[o].add = 0;
  // cout<<l<<" "<<r<<endl;
  if(l == r)
    {
      tree[o].min = tree[o].max = tree[o].sum = a[l];
      tree[o].add = 0;
      // cout<<l <<" "<<a[l]<<endl;
    }
  else{
    int m = (l+r)>>1;
    build(lson,l,m);
    build(rson,m+1,r);
    pushup(o,l,r);
  }
}
void Update(int o,int l,int r,int L,int R,int v){
  if(L <= l && R >= r){
    tree[o].add += v;
    tree[o].sum += 1ll*(r-l+1)*v;
    tree[o].max += v;
    tree[o].min += v;
    return ;
  }
  pushdown(o,l,r);
  int m = (l+r)/2;
  if(L <= m)
    Update(lson,l,m,L,R,v);
  if(R > m)
    Update(rson,m+1,r,L,R,v);
  pushup(o,l,r);
}
Tree Query(int o,int l,int r,int L,int R){
  
  if(L <= l && R >= r)
  {
    return tree[o];
  }
  Tree tmp;
  tmp.min = INF,tmp.max = -INF,tmp.sum = 0;
  pushdown(o,l,r);
  int m = (l+r)>>1;
  if(L <= m)
    up(tmp,Query(lson,l,m,L,R));
  if(R > m)
    up(tmp,Query(rson,m+1,r,L,R));
  // cout<<tmp.sum<<endl;
  return tmp;
}
LL n,m,k;
struct TT{
  int l,r;
  TT(int l = 0,int r = 0):l(l),r(r){}
};
// bool operator <(const TT &a,const TT &b){
//   return 
// }
TT chan[maxn];
LL ex[maxn];
LL nxt[maxn];


bool check(LL x){
  // cout<<x<<endl;
  build(1,1,m);
  LL kk = k;
  for(int i = 1;i <= m; ++i){
    LL t = Query(1,1,m,i,i).sum;
    if(t >= x)  continue;
    if(x-t > kk) return false;
    if(nxt[i] < i) return false;
    kk -= x-t;

    Update(1,1,m,i,nxt[i],x-t);
  }
  return true;
}
int32_t main(void){

  cin>>n>>m>>k;
  for(int i = 1;i <= n; ++i){
    scanf("%lld%lld",&chan[i].l,&chan[i].r);
    int A;scanf("%lld",&A);
    ex[chan[i].l] += A;
    ex[chan[i].r+1] -= A;
    nxt[chan[i].l] = max(nxt[chan[i].l],(LL)chan[i].r);
  }
  for(int i = 1;i <= m; ++i){
    ex[i] += ex[i-1];
    a[i] = ex[i];
    nxt[i] = max(nxt[i],nxt[i-1]);
  }

  LL l = 0,r = 3e9;
  while(r >= l){
    LL mid = (l+r)>>1;
    if(check(mid))
      l = mid+1;
    else
      r = mid-1;
  }

  cout<<r<<endl;
  return 0;
}

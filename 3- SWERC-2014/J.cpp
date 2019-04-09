ULL mod1 = 1e10+7;
ULL mod2 = 1e11+7;
const int maxn = 2000+10;
ULL gen,b[maxn],pm1[maxn],pm2[maxn];
char ar[maxn][maxn],br[maxn][maxn];
int r,c,n,m;
void Getgen(){
  rep(i,0,r){
    ULL t = 0;
    rep(j,0,c)
      t = t*mod1+ar[i][j];
    gen = (gen*mod2)+t;
  }
}

int Match(){
  int res = 0;
  ULL  t = 0;
  rep(i,0,r)
    t = t*mod2+b[i];
  rep(i,r,n+1){
    if(t == gen) res++;
    t -= b[i-r]*pm2[r-1];
    t = t*mod2+b[i];
  }
  return res;
}
int main(void)
{
   pm1[0] = pm2[0] = 1;
   rep(i,1,maxn) pm1[i] = pm1[i-1]*mod1,pm2[i] = pm2[i-1]*mod2;
   cin>>r>>c>>n>>m;
   rep(i,0,r) cin>>ar[i];
   rep(i,0,n) cin>>br[i];
   Getgen();
   rep(i,0,n){
    rep(j,0,c)
      b[i] = b[i]*mod1+br[i][j];
   }
   int res = 0;
   
   rep(j,c,m+1){
    res += Match();
     rep(i,0,n){
      b[i] -= br[i][j-c]*pm1[c-1];
      b[i] = b[i]*mod1+br[i][j];
     }
   }
   cout<<res<<endl;

   return 0;
}

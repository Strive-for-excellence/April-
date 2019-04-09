
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
// const int maxn = 2e5+10;

const double PI = acos(-1.0);
struct Complex
{
    double r,i;
    Complex(double _r = 0,double _i = 0){
        r = _r; i = _i;
    }
    Complex operator +(const Complex &b) {
        return Complex(r+b.r,i+b.i);
    }
    Complex operator -(const Complex &b) {
        return Complex(r-b.r,i-b.i);
    }
    Complex operator *(const Complex &b){
        return Complex(r*b.r-i*b.i,r*b.i+i*b.r);
    }
};

void FFT(Complex y[],int n ,int on)
{
    for(int i = 0, j = 0; i < n; i++) {
        if(j > i) swap(y[i], y[j]);
        int k = n;
        while(j & (k >>= 1)) j &= ~k;
      j |= k;
     }
    for(int h = 2;h <= n;h <<= 1){
        Complex wn(cos(-on*2*PI/h),sin(-on*2*PI/h));
        for(int j = 0;j < n;j += h){
            Complex w(1,0);
            for(int k = j;k < j+h/2;k++){
                Complex u = y[k];
                Complex t = w*y[k+h/2];
                y[k] = u+t;
                y[k+h/2] = u-t;
                w = w*wn;
            }
        }
    }
    if(on == -1)
        for(int i = 0;i < n;i++)
            y[i].r /= n;
}
const int maxn = 1e6+10;
int A[maxn],B[maxn];
Complex a[maxn];
int main(void)
{
  int N,M;cin>>N;
  int aa;
  rep(i,0,N){
    scanf("%d",&aa);
    A[aa] = 1;
  }


  LL t = 1;
  while(t <= 4e5) t <<= 1;
  for(int i = 0;i <= t; ++i)
     {
      // if(i < 20)
      //   cout<<i<<" "<<A[i]<<endl;
       a[i] = Complex(A[i],0);
     }
  a[0].r = 1;
  FFT(a,t,1);
  for(int i = 0;i < t; ++i)
    a[i] = a[i]*a[i];
  FFT(a,t,-1);
  // for(int i = 0;i <= 10; ++i){
  //   cout<<i<<" "<<a[i].r<<endl;
  // }
  int cnt =0;

  cin>>M;
  rep(i,0,M){
    scanf("%d",&aa);
    if(a[aa].r > eps){
      cnt++;
    }
  }
  cout<<cnt<<endl;
    

   return 0;
}

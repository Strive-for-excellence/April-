#include <bits/stdc++.h>
#define next NEXT
#define int long long
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}
int euler_Phi(int n){
    int m=(int)sqrt(n+0.5);
    int ans=n;
    for(int i=2;i<=m;i++){
        if(n%i==0){
            ans=ans/i*(i-1);
            while(n%i==0) n/=i;
        }
    }
    if(n>1) ans=ans/n*(n-1);
    return ans;
}
ll powmod(ll a,ll b,ll p){
    if(b==0) return 1ll%p;
    if(b&1) return powmod(a,b-1,p)*a%p;
    return powmod(a*a%p,b>>1,p)%p;
}
int32_t main()
{
    int t;cin>>t;
    while(t--){
        ll x,y,a;cin>>x>>y>>a;
        if(y==0){
            cout<<1<<endl;
            continue;
        }
        y/=(x-1);//k;
        a/=gcd(y,a);//b
        x%=a;
        if(gcd(x,a)!=1){
            cout<<"Impossible!"<<endl;
            continue;
        }else{
            ll gg=euler_Phi(a);
            ll ans=1000000000000000000000;
            for(ll i=1;i*i<=gg;i++){
                if(gg%i) continue;
                if(powmod(x,i,a)==1){
                    ans=min(ans,i);
                }
                if(powmod(x,gg/i,a)==1){
                    ans=min(ans,gg/i);
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}

#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;

ll a[100010];
ll jl[100010];
ll mpow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1) ans*=a;
        a*=a;
        b>>=1;
    }
    return ans;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    reverse(a+1,a+1+n);

    for(int i=1;i<=n;i++) a[i]+=a[i-1];
    int q;cin>>q;
    bool flag=false;
    while(q--){
        if(flag==false) flag=1;
        else cout<<" ";
        int k;cin>>k;
        if(jl[k]) {cout<<jl[k];continue;}
        ll ans=0;
        int l=1,r=1;
        ll cs=0;
        while(1){
            //cout<<l<<" "<<r<<endl;
            ans+=(a[r]-a[l-1])*cs;
            cs++;
            l=r+1;
            if(l>n) break;
            r=l+mpow(k,cs)-1;
            r=min(r,n);
        }
        jl[k]=ans;
        cout<<ans;
    }

    return 0;
}

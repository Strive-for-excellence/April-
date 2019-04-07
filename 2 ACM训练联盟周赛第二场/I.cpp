#include<bits/stdc++.h>
using namespace std;const int N=1e3+7;typedef long long ll;
int f[N][N],a[N],n,m,T_T,i,j,pre,res;ll dp[N][N];vector<int>vec[N];
int main(){
	for(scanf("%d",&T_T);T_T--;){
		for(scanf("%d%d",&n,&m),i=1;i<=n;++i)scanf("%d",a+i);
		for(i=1;i<=n;++i)vec[i].clear();memset(dp,0,sizeof(dp));
		for(i=1;i<=n;++i){
			for(res=0,pre=0,j=i;j>=1;--j){
				res|=a[j];
				if(pre!=res)vec[i].push_back(j);
				pre=res;
				f[j][i]=res;
			}
		}
		for(i=1;i<=n;++i)dp[i][1]=f[1][i];
		for(j=2;j<=m;++j){
			for(i=j;i<=n;++i){
				for(auto&x:vec[i])
				if(x>=j)dp[i][j]=max(dp[i][j],dp[x-1][j-1]+f[x][i]);
				else break;
			}
		}printf("%lld\n",dp[n][m]);
	}
}

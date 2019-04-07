#include<bits/stdc++.h>
using namespace std;const int N=2e5+7;
struct data{int to,next,v;}e[N<<2];int cnt,fa[N],a[N],size[N],dfn[N],f[N],low[N],bridge[N],n,m,Q,i,j,k,ind,sum;
struct graph{
	int head[N];
	void ins(int u,int v,int w=0){e[++cnt].to=v;e[cnt].next=head[u];head[u]=cnt;e[cnt].v=w;}
	void insert(int u,int v,int w=0){ins(u,v,w);ins(v,u,w);}
}g1,g2;
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void dfs(int x,int fa){
	dfn[x]=low[x]=++ind;
	for(int i=g1.head[x];i;i=e[i].next)if(e[i].v!=fa){
		if(!dfn[e[i].to]){
			dfs(e[i].to,e[i].v);
			low[x]=min(low[x],low[e[i].to]);
		}else low[x]=min(low[x],dfn[e[i].to]);
		if(dfn[x]<low[e[i].to])bridge[e[i].v]=1;
	}
}
void dfs1(int x,int fa){
	size[x]=a[x];f[x]=sum;
	for(int i=g2.head[x];i;i=e[i].next)if(e[i].to!=fa){
		dfs1(e[i].to,x);size[x]+=size[e[i].to];
		f[x]=min(f[x],sum-size[e[i].to]);
	}f[x]=min(f[x],size[x]);
}
int main(){
	for(scanf("%d%d",&n,&m),i=1;i<=n;++i)fa[i]=i;
	for(i=1;i<=m;++i)scanf("%d%d",&k,&j),g1.insert(k,j,i);
	for(i=1;i<=n;++i)scanf("%d",a+i),sum+=a[i];
	dfs(1,0);for(i=1;i<=n;++i)for(j=g1.head[i];j;j=e[j].next)if(!bridge[e[j].v])
	fa[find(e[j].to)]=find(i);
	for(i=1;i<=n;++i)if(find(i)!=i)a[find(i)]+=a[i];
	for(i=1;i<=n;++i)for(j=g1.head[i];j;j=e[j].next)if(find(i)!=find(e[j].to))
		g2.ins(find(i),find(e[j].to));
	for(i=1;i<=n;++i)if(find(i)==i){dfs1(i,0);break;}
	for(scanf("%d",&Q),i=1;i<=Q;++i)scanf("%d",a+i);
	for(i=1;i<=Q;++i)printf("%d\n",f[find(a[i])]);
} 

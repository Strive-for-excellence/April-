#include<bits/stdc++.h>
using namespace std;const int N=1e5+7,M=N*8;typedef long long ll;
namespace FIFO{
	char ch,B[1<<20],*S=B,*T=B;
	#define getc() (S==T&&(T=(S=B)+fread(B,1,1<<20,stdin),S==T)?0:*S++)
	#define isd(c) (c>='0'&&c<='9')
	int aa,bb;int F(){
		while(ch=getc(),!isd(ch));ch=='-'?(aa=bb=0):(aa=ch-'0',bb=1);
		while(ch=getc(),isd(ch))aa=aa*10+ch-'0';return bb?aa:-aa;
	}
}
#define gi FIFO::F()
int a[M][2],b[N],sz=1,n,m,K,block,i,j,v[M],L,R;ll ans,res[N];
struct data{
	int l,r,id;
	friend bool operator<(data a,data b){
		if(a.l/block==b.l/block){
			if(a.l/block%2==0)return a.r<b.r;else return a.r>b.r;
		}else return a.l/block<b.l/block;
	}
}s[N];
void ins(int x,int val){
	int now=1,c;for(int i=16;i>=0;--i){
		c=x>>i&1;if(!a[now][c])a[now][c]=++sz;now=a[now][c];v[now]+=val;
	}
}
int query(int x){
	int now=1,c,c1,res=0;for(int i=16;i>=0;--i){
		c=x>>i&1;c1=K>>i&1;
		if(c1==0)res+=v[a[now][c^1]];
		now=a[now][c1^c];
	}
	return res;
}
void update(int x,int val){
	ans+=val*query(x);
	ins(x,val);
}
int main(){
	for(n=gi,m=gi,K=gi,i=1;i<=n;++i)b[i]=gi,b[i]^=b[i-1];
	for(i=1;i<=m;++i)s[i].l=gi,s[i].r=gi,s[i].l--,s[i].id=i;block=sqrt(n);
	for(sort(s+1,s+m+1),L=1,R=0,i=1;i<=m;++i){
		while(R<s[i].r)update(b[++R],1);
		while(R>s[i].r)update(b[R--],-1);
		while(L<s[i].l)update(b[L++],-1);
		while(L>s[i].l)update(b[--L],1);
		res[s[i].id]=ans;
	}
	for(i=1;i<=m;++i)printf("%lld\n",res[i]);
}

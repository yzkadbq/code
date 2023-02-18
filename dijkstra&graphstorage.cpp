#include<bits/stdc++.h>
#define inf 0b00111111001111110011111100111111
using namespace std;
const int maxn=500001;
int n,m;
struct node{
	int v,c,next;
} edge[maxn<<1];
int top=0,h[maxn];
void addedge(int u,int v,int c){
	top++;
	edge[top].v=v;
	edge[top].c=c;
	edge[top].next=h[u];
	h[u]=top;
	return;
}
int dis[maxn],vis[maxn];
int s;
void dijkstra(){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	int u=s;
	dis[s]=0;
	vis[s]=1;
	for(int i=1;i<n;i++){
		for(int j=h[u];j;j=edge[j].next){
			int v=edge[j].v;
			if(vis[v]) continue;
			if(dis[u]+edge[j].c<dis[v]){
				dis[v]=dis[u]+edge[j].c;
			}
		}
		int mina=inf;
		for(int j=1;j<=n;j++){
			if(!vis[j]){
				if(dis[j]<mina){
					mina=dis[j],u=j;
				}
			}
		}
		vis[u]=1;
	}
}
signed main(){
	cin>>n>>m>>s;
	int u,v,c;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>c;
		addedge(u,v,c);
	}
	/*for(int u=1;u<=n;u++){
		for(int i=h[u];i;i=edge[i].next){
			cout<<u<<"->"<<edge[i].v<<":"<<edge[i].c<<" ";
		}
		cout<<endl;
	}*/
	dijkstra();
	for(int i=1;i<=n;i++){
		if(dis[i]!=inf){
			cout<<dis[i]<<" ";
			continue;
		}
		cout<<"2147483647 ";
	}
	return 0;
}

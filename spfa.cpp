#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;

struct edge
{
	int to, len, nxt = -1;
}e[50010];

int dis[10010], num[10010], h[10010];
bool vis[10010];
int cnt;

void addedge(int u, int v, int w)
{
	cnt++;
	e[cnt].to = v;
	e[cnt].len = w;
	e[cnt].nxt = h[u];
	h[u] = cnt;
}

queue <int> q;

bool spfa()
{
	dis[1] = 0;
	q.push(1);
	num[1] = 1;
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		if(num[now] >= n)return 0;
		vis[now] = 0;
		//cout << now << "1\n";
		for(int i = h[now];i != -1;i = e[i].nxt)
		{
			//cout << now << "->" << e[i].to << "2\n";
			if(dis[e[i].to] > dis[now] + e[i].len)
			{
				dis[e[i].to] = dis[now] + e[i].len;
				if(!vis[e[i].to])
				{
					//if(num[e[i].to] >= n)return 0;
					num[e[i].to]++;
					vis[e[i].to] = 1;
					//cout << now << "->" << e[i].to << ":" << dis[e[i].to] << "::" << num[e[i].to] << "\n";
					q.push(e[i].to);
				}
			}
		}
	}
	return 1;
}

void init()
{
	cnt = 0;
	for(int i = 1;i <= cnt;i++)
	{
		e[i].to = 0;
		e[i].len = 0;
		e[i].nxt = -1;
	}
	for(int i = 1;i <= n;i++)
	{
		h[i] = 0;
		dis[i] = 2147483647;
		vis[i] = 0;
		num[i] = 0;
	}
	while(!q.empty())q.pop();
}

signed main()
{
	//ÎÞÏòÍ¼½¨·´Ïò±ß
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		init();
		for(int i = 1;i <= m;i++)
		{
			int u, v, w;
			cin >> u >> v >> w;
			if(w >= 0)
			{
				addedge(v, u, w);
			}
			addedge(u, v, w);
		}
		if(!spfa())cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}

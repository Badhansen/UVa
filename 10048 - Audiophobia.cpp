// Solved
#include<bits/stdc++.h>

using namespace std;

#define MM 101

struct edge{
    int u, v, w;
    bool operator<(const edge& p) const
    {
        return w < p.w;
    }
};

int pr[MM];
int dis[MM][MM];
int dir[MM];
vector<edge> e;
vector<int> g[MM];

int _find(int r)
{
    if(pr[r]==r) return r;
    return _find(pr[r]);
}
void kruskal(int n)
{
    sort(e.begin(), e.end());
    for (int i=1; i<=n; i++)
        pr[i]=i;

    int sz=e.size();
    int count=0;
    for (int i=0; i<sz; i++) {
        int u=_find(e[i].u);
        int v=_find(e[i].v);
        if (u != v){
            pr[u]=v;
            g[e[i].u].push_back(e[i].v);
            g[e[i].v].push_back(e[i].u);
            dis[e[i].u][e[i].v]=e[i].w;
            dis[e[i].v][e[i].u]=e[i].w;
            count++;
            if(count==n-1){
                break;
            }
        }
    }
}

void bfs(int s, int d)
{
    bool vis[MM];
    memset(vis, false, sizeof vis);
    vis[s]=true;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();

        for(int i=0; i<g[u].size(); i++){
            int v;
            v=g[u][i];
            if(!vis[v]){
                dir[v]=u;
                q.push(v);
                vis[v]=true;
                if(v==d){
                    return;
                }
            }
        }
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t=1;
    while(1){

        e.clear();
        for(int i=0; i<MM; i++){
            g[i].clear();
        }
        int c, s, q;



        scanf("%d%d%d", &c, &s, &q);

        if(!c && !s && !q) break;
        if(t!=1) printf("\n");
        for(int i=0; i<s; i++){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);

            edge get;
            get.u=u;
            get.v=v;
            get.w=w;
            e.push_back(get);
        }
        kruskal(c);
        printf("Case #%d\n", t++);

        for(int i=0; i<q; i++){
            int u, v;
            scanf("%d%d", &u, &v);
            bfs(u, v);
            if(_find(u)!=_find(v)){
                printf("no path\n");
            }
            else{
                int minMx=-1;
                while(u!=v){
                    //cout << u << " " << v << endl;
                    minMx=max(minMx, dis[v][dir[v]]);
                    v=dir[v];
                }
                printf("%d\n", minMx);
            }
        }
    }

    return 0;
}





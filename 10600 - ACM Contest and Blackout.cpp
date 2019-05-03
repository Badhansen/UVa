// Second best minimum spanning tree
// full ok code
#include<bits/stdc++.h>

using namespace std;

#define MM 101


struct edge {
    int u, v, w;
    bool operator<(const edge& p) const
    {
        return w < p.w;
    }
};
int pr[MM];
vector<edge> e;
bool flag[MM][MM];
bool taken[MM][MM];
int n, m;
int _find(int r)
{
    if(pr[r]==r) return r;
    return _find(pr[r]);
}
int kruskal(bool firstMst)
{
    for (int i=1; i<=n; i++)
        pr[i]=i;
    int s=0;
    int sz=e.size();
    for (int i=0; i<sz; i++) {
        int u=_find(e[i].u);
        int v=_find(e[i].v);
        if(!flag[e[i].u][e[i].v]){
            if (u != v) {
                pr[u]=v;
                s+=e[i].w;
                if(firstMst){
                    taken[e[i].u][e[i].v]=true;
                }
            }
        }

    }
    return s;
}

int main()
{
    int t=1, test;

    scanf("%d", &test);
    while(t<=test){
        e.clear();
        for(int i=0; i<MM; i++){
            for(int j=0; j<MM; j++){
                taken[i][j]=false;
                flag[i][j]=false;
            }

        }
        scanf("%d%d", &n, &m);
        for(int i=0; i<m; i++){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            edge get;
            get.u=u;
            get.v=v;
            get.w=w;
            e.push_back(get);
        }
        sort(e.begin(), e.end());

        bool firstMst=true;
        int first=kruskal(firstMst);
        int second, secondMx=INT_MAX;
        int sz=e.size();
        for(int i=0; i<sz; i++){
            int u, v, w;
            u=e[i].u;
            v=e[i].v;
            w=e[i].w;
            if(taken[u][v]){
                flag[u][v]=true;
                second=kruskal(!firstMst);
                if(second>=first){
                    secondMx=min(secondMx, second);
                }
                flag[u][v]=false;
            }
        }
        printf("%d %d\n", first, secondMx);
        t++;
    }
    return 0;
}



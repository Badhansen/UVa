// Solved
#include<bits/stdc++.h>

using namespace std;

#define MM 200001
typedef long long lng;

struct edge{
    int u, v, w;
    bool operator<(const edge& p) const
    {
        return w<p.w;
    }
};
int pr[MM];

int _find(int r)
{
    if(pr[r]==r)
        return r;
    return _find(pr[r]);
}

void kruskal(vector<edge> e, int n, int total)
{
    sort(e.begin(), e.end());
    for(int i=0; i<n; i++){
        pr[i]=i;
    }
    int cnt=0;
    lng mst=0;
    int sz=e.size();
    for(int i=0; i<sz; i++){
        int u=_find(e[i].u);
        int v=_find(e[i].v);
        if(u!=v){
            pr[u]=v;
            mst+=e[i].w;
            cnt++;
            if(cnt==n-1)
                break;
        }
    }
    printf("%lld\n", total-mst);
}
int main()
{
    int n, m;
    while(scanf("%d%d", &n, &m) && (n || m)){
        vector<edge> e;
        lng total=0;
        for(int i=0; i<m; i++){
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            total+=w;
            edge get;
            get.w=w;
            get.u=a;
            get.v=b;
            e.push_back(get);
        }
        kruskal(e, n, total);
    }


    return 0;
}

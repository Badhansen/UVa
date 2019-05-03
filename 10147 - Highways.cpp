// Solved
#include<bits/stdc++.h>

using namespace std;

#define MM 751

struct edge{
    int u, v;
    double w;
    bool operator<(const edge& p) const
    {
        return w < p.w;
    }
};

int pr[MM];
pair<int, int> p[1001];
vector<edge> e;
vector<int> g[MM];

int _find(int r)
{
    if(pr[r]==r) return r;
    return _find(pr[r]);
}
void kruskal(int n, int m)
{
    vector<pair<int, int> > path;
    sort(e.begin(), e.end());
    for (int i=1; i<=n; i++)
        pr[i]=i;
    for(int i=0; i<m; i++){
        int u, v;
        u=_find(p[i].first);
        v=_find(p[i].second);
        if (u != v){
            pr[u]=v;
        }
    }
    int sz=e.size();
    int count=0;
    for (int i=0; i<sz; i++) {
        int u=_find(e[i].u);
        int v=_find(e[i].v);
        if (u != v){
            pr[u]=v;
            printf("%d %d\n", e[i].u, e[i].v);
            count++;
        }
    }

    if(count==0){
        printf("No new highways need\n");
        return;
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t=1, test;
    scanf("%d", &test);
    while(t<=test){

        e.clear();
        int n, m;
        if(t!=1) printf("\n");
        scanf("%d", &n);
        double a[MM], b[MM];
        for(int i=1; i<=n; i++){
            cin >> a[i] >> b[i];
        }
        for(int i=1; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                edge get;
                double r=(a[j]-a[i])*(a[j]-a[i]) + (b[j]-b[i])*(b[j]-b[i]);
                r=sqrt(r);
                get.u=i;
                get.v=j;
                get.w=r;
                e.push_back(get);
            }
        }
        scanf("%d", &m);
        for(int i=0; i<m; i++){
            int u, v;
            scanf("%d%d", &u, &v);
            p[i].first=u;
            p[i].second=v;
        }
        kruskal(n, m);
        t++;
    }

    return 0;
}





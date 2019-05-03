// solved
#include<bits/stdc++.h>

using namespace std;

#define MM 201

struct edge {
    int u, v;
    double w;
    bool operator<(const edge& p) const
    {
        return w < p.w;
    }
};

int pr[MM];
vector<edge> e;

int _find(int r)
{
    if(pr[r]==r) return r;
    return _find(pr[r]);
}
double kruskal(int n)
{
    sort(e.begin(), e.end());
    for (int i=0; i<n; i++)
        pr[i]=i;

    int sz=e.size();
    double minMx;
    for (int i=0; i<sz; i++) {
        int u=_find(e[i].u);
        int v=_find(e[i].v);
        if(_find(0)==_find(1)) break;
        if (u != v){
            pr[u]=v;
            minMx=e[i].w;
        }
    }
    return minMx;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t=1;
    while(1){
        e.clear();
        int p;
        if(t!=1) printf("\n");
        scanf("%d", &p);
        if(p==0) break;
        double a[201], b[201];
        for(int i=0; i<p; i++){
            scanf("%lf%lf", &a[i], &b[i]);
        }
        for(int i=0; i<p; i++){
            for(int j=i+1; j<p; j++){
                edge get;
                double r=(a[j]-a[i])*(a[j]-a[i]) + (b[j]-b[i])*(b[j]-b[i]);
                r=sqrt(r);
                get.u=i;
                get.v=j;
                get.w=r;
                e.push_back(get);
            }
        }
        printf("Scenario #%d\n", t++);
        printf("Frog Distance = %.3f\n", kruskal(p));

    }

    return 0;
}



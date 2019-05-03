// Solved
#include<bits/stdc++.h>

using namespace std;

#define MM 100001

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

void init(int n)
{
    for(int i=0; i<n; i++){
        pr[i]=i;
    }
}
int sq(int n)
{
    return n*n;
}
void kruskal(vector<edge> e, int n)
{
    sort(e.begin(), e.end());
    int cnt=0;
    double mst=0.0;
    int sz=e.size();
    for(int i=0; i<sz; i++){
        int u=_find(e[i].u);
        int v=_find(e[i].v);
        if(u!=v){
            pr[u]=v;
            mst+=sqrt(e[i].w);
            cnt++;
            if(cnt==n-1)
                break;
        }
    }
    printf("%.2f\n", mst);
}
int main()
{
    int n, m;
    while(scanf("%d", &n)!=EOF){
        vector<edge> e;
        vector<pair<int, int> > v;

        for(int i=0; i<n; i++){
            int a, b;
            scanf("%d%d", &a, &b);
            v.push_back(make_pair(a, b));
        }
        init(n);
        scanf("%d", &m);
        for(int i=0; i<m; i++){
            int a, b;
            scanf("%d%d", &a, &b);
            a--, b--;
            int u=_find(a);
            int v=_find(b);
            if(u!=v){
                pr[u]=v;
            }
        }
        for(int i=0; i<n-1; i++){

            for(int j=i+1; j<n; j++){
                int temp=sq(v[i].first-v[j].first) + sq(v[i].second-v[j].second);
                edge get;
                get.w=temp;
                get.u=i;
                get.v=j;
                e.push_back(get);

            }
        }
        kruskal(e, n);
    }


    return 0;
}

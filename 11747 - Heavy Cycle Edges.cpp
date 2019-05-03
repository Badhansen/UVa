// Solved
#include<bits/stdc++.h>

using namespace std;
#define MM 1000001


struct edge {
    int u, v, w;
    bool operator<(const edge& p) const
    {
        return w < p.w;
    }
};

int pr[MM];
int test=1;

int _find(int r)
{
    if(pr[r]==r) return r;
    return _find(pr[r]);
    //return (pr[r] == r) ? r : _find(pr[r]);
}
void kruskal(vector<edge> e, int n)
{
    sort(e.begin(), e.end());
    for (int i=0; i<n; i++)
        pr[i]=i;

    vector<int> p;
    int sz=e.size();
    for (int i=0; i<sz; i++) {
        int u=_find(e[i].u);
        int v=_find(e[i].v);
        if (u != v) {
            pr[u]=v;
        }
        else{
            p.push_back(e[i].w);
        }
    }
    int siz=p.size();
    if(siz==0){
        printf("forest\n");
        return;
    }
    for(int i=0; i<siz; i++){
        if(i==siz-1){
            printf("%d\n", p[i]);
        }
        else{
            printf("%d ", p[i]);
        }
    }
}


int main()
{
    int t, n, m;
    while(scanf("%d%d", &n, &m) && n && m){
        vector<edge> e;
        for(int i=0; i<m; i++){
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            edge get;
            get.w=w;
            get.u=a;
            get.v=b;
            e.push_back(get);

        }
        kruskal(e, n);

    }
    return 0;
}



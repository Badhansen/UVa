// Solved
#include<bits/stdc++.h>

using namespace std;

#define MM 1000001

struct edge {
    int u, v;
    double w;
    bool operator < (const edge& p) const
    {
        return w < p.w;
    }
};

int pr[MM];
vector<edge> e;
int n, k;

int _find(int r)
{
    if(pr[r]==r) return r;
    return _find(pr[r]);

}
void kruskal(int n, int sa)
{
    sort(e.begin(), e.end());
    for (int i=0; i<n; i++)
        pr[i]=i;

    int count=n;
    double ans=0.0;
    int sz=e.size();
    for (int i=0; i<sz; i++) {
        int u=_find(e[i].u);
        int v=_find(e[i].v);
        if (u!=v) {
            pr[u]=v;
            count--;
            ans=max(ans, e[i].w);
            if (count<=sa)
                break;
        }
    }
    printf("%.2f\n", ans);
}

int main()
{
    int t=1, test;
    cin >> test;
    while(t<=test){
        int s, p;
        cin >> s >> p;
        e.clear();
        double a[501], b[501];
        for(int i=0; i<p; i++){
            cin >> a[i] >> b[i];
        }
        for(int i=0; i<p-1; i++){
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
        kruskal(p, s);
        t++;
    }
}


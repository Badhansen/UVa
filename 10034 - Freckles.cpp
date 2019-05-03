// Solved
#include<bits/stdc++.h>

using namespace std;
#define MM 1000001


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
void kruskal(int n)
{
    sort(e.begin(), e.end());
    for (int i=0; i<n; i++)
        pr[i]=i;

    int count=0;
    double s=0;
    int sz=e.size();
    for(int i=0; i<sz; i++) {
        int u=_find(e[i].u);
        int v=_find(e[i].v);

        if(u != v) {
            pr[u]=v;
            count++;
            s+=e[i].w;

            if(count==n-1) break;

        }
    }
    printf("%.2f\n", s);
}

int main()
{

    int t=1, test;
    cin >> test;
    while(t<=test){
        int n;
        cin >> n;
        e.clear();
        double a[101], b[101];
        for(int i=0; i<n; i++){
            cin >> a[i] >> b[i];
        }
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                edge get;
                double r=(a[j]-a[i])*(a[j]-a[i]) + (b[j]-b[i])*(b[j]-b[i]);
                r=sqrt(r);
                get.u=i;
                get.v=j;
                get.w=r;
                e.push_back(get);
            }
        }
        if(t!=1) cout << endl;
        kruskal(n);
        t++;
    }
    return 0;
}



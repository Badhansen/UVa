// solved
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
vector<edge> e;
map<string, int> m;

int _find(int r)
{
    if(pr[r]==r) return r;
    return _find(pr[r]);
    //return (pr[r] == r) ? r : _find(pr[r]);
}
long long kruskal(int n)
{
    sort(e.begin(), e.end());
    for (int i=1; i<=n; i++)
        pr[i]=i;

    int count=0;
    long long s=0;
    int sz=e.size();
    for (int i=0; i<sz; i++) {
        int u=_find(e[i].u);
        int v=_find(e[i].v);
        if (u != v) {
            pr[u] = v;
            count++;
            s += e[i].w;
            if (count == n - 1)
                break;
        }
    }
    return s;
}

int main()
{
    int N, M, t=1, test;
    long long total=0;
    scanf("%d", &test);
    while(t<=test){
        scanf("%d%d", &M, &N);
        int city=0;
        m.clear();
        cin.ignore();
        for(int i=0; i<N; i++){
            string a, b;
            int w;
            cin >> a >> b >> w;
            if(m.find(a)==m.end()){
                m[a]=++city;
            }
            if(m.find(b)==m.end()){
                m[b]=++city;
            }
            edge get;
            get.u=m[a];
            get.v=m[b];
            get.w=w;
            e.push_back(get);
        }

        if(t!=1) cout << endl;

        long long ans=kruskal(M);

        cout << ans << endl;

        t++;
        e.clear();
    }
    return 0;
}


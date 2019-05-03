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
int _find(int r)
{
    if(pr[r]==r) return r;
    return _find(pr[r]);
    //return (pr[r] == r) ? r : _find(pr[r]);
}
void kruskal(int n)
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
    cout << s << endl;
}

int main()
{
    int N, t=0;
    long long total=0;
    while(scanf("%d", &N)!=EOF){
        for(int i=0; i<N-1; i++){
            int a, b, w;
            cin >> a >> b >> w;
            total+=w;
        }
        if(t!=0) cout << endl;
        e.clear();
        pair<int, pair<int, int> > temp[11];
        int k;
        cin >> k;

        for(int i=0; i<k; i++){
            int a, b, w;
            cin >> a >> b >> w;
            edge get;
            get.u=a;
            get.v=b;
            get.w=w;
            e.push_back(get);
        }
        int M;
        cin >> M;
        for(int i=0; i<M; i++){
            int a, b, w;
            cin >> a >> b >> w;
            edge get;
            get.u=a;
            get.v=b;
            get.w=w;
            e.push_back(get);
        }
        cout << total << endl;
        kruskal(N);
        t++;
        total=0;

    }
    return 0;
}

// solved
#include<bits/stdc++.h>

using namespace std;

#define MM 201

struct edge {
    int u, v, w;
    bool operator<(const edge& p) const
    {
        return w > p.w;
    }
};

int pr[MM];
vector<edge> e;

int _find(int r)
{
    if(pr[r]==r) return r;
    return _find(pr[r]);
}
int kruskal(int n, int s, int d)
{
    sort(e.begin(), e.end());
    for (int i=0; i<n; i++)
        pr[i]=i;

    int sz=e.size();
    int maxMi;
    for (int i=0; i<sz; i++) {
        int u=_find(e[i].u);
        int v=_find(e[i].v);
        if(_find(d)==_find(s)) break;
        if (u != v){
            pr[u]=v;
            maxMi=e[i].w;
        }
    }
    return maxMi;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t=1;
    while(1){
        e.clear();
        int n, m;
        if(t!=1) printf("\n");
        scanf("%d%d", &n, &m);
        if(!n && !m) break;
        map<string, int> mcity;
        int city=0;
        cin.ignore();
        for(int i=0; i<m; i++){
            string a, b;
            int w;
            cin >> a >> b >> w;
            if(mcity.find(a)==mcity.end()){
                mcity[a]=city++;
            }
            if(mcity.find(b)==mcity.end()){
                mcity[b]=city++;
            }
            edge get;
            get.u=mcity[a];
            get.v=mcity[b];
            get.w=w;
            e.push_back(get);
        }
        string source, destination;
        cin >> source >> destination;
        int s, d;
        s=mcity[source];
        d=mcity[destination];

        printf("Scenario #%d\n", t++);
        printf("%d tons\n", kruskal(n, s, d));

    }

    return 0;
}




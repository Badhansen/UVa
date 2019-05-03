// Solved
#include<bits/stdc++.h>

using namespace std;

#define MM 100

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

void kruskal(vector<edge> e, int n)
{
    sort(e.begin(), e.end());
    for(int i=0; i<n; i++){
        pr[i]=i;
    }
    int cnt=0;
    int sz=e.size();
    for(int i=0; i<sz; i++){
        int u=_find(e[i].u);
        int v=_find(e[i].v);
        if(u!=v){
            pr[u]=v;
            if(e[i].u<e[i].v){
                printf("%c-%c %d\n", 'A'+e[i].u, 'A'+e[i].v, e[i].w);
            }
            else{
                printf("%c-%c %d\n", 'A'+e[i].v, 'A'+e[i].u, e[i].w);
            }
            cnt++;
            if(cnt==n-1)
                break;
        }
    }
}
int main()
{
    int t, ts=1, n, m;
    scanf("%d", &t);
    while(ts<=t){
        vector<edge> e;
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int w;
                char c;
                if(j==n-1){
                    scanf("%d", &w);
                }
                else{
                    scanf("%d%c", &w, &c);
                }

                if(w==0){
                    continue;
                }
                else{
                    edge get;
                    get.w=w;
                    get.u=i;
                    get.v=j;
                    e.push_back(get);
                }
            }
        }
        printf("Case %d:\n", ts++);
        kruskal(e, n);
    }


    return 0;
}


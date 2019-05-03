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
void kruskal(vector<edge> e, int n, int r)
{
    sort(e.begin(), e.end());
    int c=1;
    for (int i=0; i<n; i++)
        pr[i]=i;

    int count=0;
    double road=0, rail=0;
    int sz=e.size();
    for (int i=0; i<sz; i++) {
        int u=_find(e[i].u);
        int v=_find(e[i].v);
        if (u != v) {
            pr[u]=v;
            count++;
            if(e[i].w>r*r){
                rail+=sqrt(e[i].w);
                c++;
            }
            else{
                road+=sqrt(e[i].w);
            }

            if (count==n-1)
                break;
        }
    }

    printf("Case #%d: %d %.0f %.0f\n", test++, c, road, rail);
}

int sq(int n)
{
    return n*n;
}

int main()
{
    int t, n, r;
    scanf("%d", &t);
    while(t--){

        scanf("%d%d", &n, &r);

        vector<edge> e;
        vector<pair<int, int> > v;

        for(int i=0; i<n; i++){
            int a, b;
            scanf("%d%d", &a, &b);
            v.push_back(make_pair(a, b));
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
        kruskal(e, n, r);

    }
    return 0;
}


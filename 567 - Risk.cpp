// Solved
#include<bits/stdc++.h>

using namespace std;

int bfs (vector<int> graph[], int s, int d)
{

    int dis[22];
    bool vis[22];
    for (int i=0; i<22; i++)
    {
        dis[i]=0;
        vis[i]=false;
    }

    queue<int> Q;

    dis[s]=0;
    vis[s]=true;
    Q.push(s);
    while(!Q.empty())
    {

        int node=Q.front();
        if(node==d) break;
        Q.pop();

        for (int i=0; i<graph[node].size(); i++)
        {
            int v=graph[node][i];
            if (vis[v]==false)
            {
                dis[v]=dis[node]+1;
                vis[v]=true;
                Q.push(v);
            }
        }
    }
    return dis[d];
}

int main ()
{
    int test=1;
    int u, v, n, a, b, k=1, I;
    vector<int> graph[22];
    while(scanf("%d", &I)!=EOF)
    {
        for(int i=0; i<I; i++)
        {
            scanf("%d", &u);
            graph[k].push_back(u);
            graph[u].push_back(k);
        }

        if(k==19)
        {
            printf("Test Set #%d\n", test++);
            scanf("%d", &n);
            for(int i=0; i<n; i++)
            {
                scanf("%d%d", &a, &b);
                printf("%2d to %2d: %d\n", a, b, bfs(graph, a, b));
            }
            k=0;
            for(int i=0; i<22; i++)
            {
                graph[i].clear();
            }
            printf("\n");
        }

        k++;

    }
    return 0;
}

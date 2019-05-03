// solved
#include<bits/stdc++.h>

using namespace std;

#define MM 10001
vector<int> graph[MM];
int n, m;

void dfs(int u, bool visited[], int disc[], int low[], int parent[], bool ap[])
{
    static int time=0;
    int children=0;
    visited[u]=true;
    disc[u]=low[u]=++time;

    vector<int> :: iterator i;
    for(i=graph[u].begin(); i!=graph[u].end(); i++){
        int v=*i;

        if(!visited[v]){
            children++;
            parent[v]=u;
            dfs(v, visited, disc, low, parent, ap);
            low[u]=min(low[u], low[v]);

            if(parent[u]==-1 && children>1)
                ap[u]=true;
            if(parent[u]!=-1 && low[v]>=disc[u])
                ap[u]=true;
        }
        else if(v!=parent[u]){
            low[u]=min(low[u], disc[v]);
        }
    }

}
int ArticularPoint()
{
    bool visited[n+10];
    int disc[n+10];
    int low[n+10];
    int parent[n+10];
    bool ap[n+10];
    for(int i=0; i<n; i++){
        visited[i]=false;
        parent[i]=-1;
        ap[i]=false;
    }
    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs(i, visited, disc, low, parent, ap);
        }
    }
    int cnt=0;
    for(int i=0; i<n; i++){
        if(ap[i]){
            cnt++;
        }
    }
    return cnt;

}

int main()
{

    //freopen("in.txt", "w", stdout);

    while(1){
        scanf("%d", &n);
        if(n==0) break;
        for(int i=0; i<MM; i++){
            graph[i].clear();
        }
        int u, v;
        char ch;
        while(1){
            scanf("%d", &u);
            if(u==0) break;
            scanf("%c", &ch);
            u--;
            while(ch!='\n'){
                scanf("%d", &v);
                scanf("%c", &ch);

                v--;
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        }
        printf("%d\n", ArticularPoint());

    }
    return 0;
}



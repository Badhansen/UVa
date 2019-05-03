// Solved

#include<bits/stdc++.h>

using namespace std;

#define MM 101

vector<int> graph[MM];
int node, edge;

void dfs(int v, bool visited[], vector<int> &ts)
{
    visited[v]=true;
    vector<int> :: iterator i;
    for(i=graph[v].begin(); i!=graph[v].end(); i++){
        if(visited[*i]==false){
            dfs(*i, visited, ts);
        }
    }
    ts.push_back(v);
}
void tsort()
{
    bool visited[MM];
    vector<int> ts;
    for(int i=1; i<=node; i++){
        visited[i]=false;
    }
    for(int i=1; i<=node; i++){
        if(visited[i]==false){
            dfs(i, visited, ts);
        }
    }

    reverse(ts.begin(), ts.end());
    for(int i=0; i<ts.size(); i++){
        if(i==ts.size()-1){
            printf("%d\n", ts[i]);
        }
        else{
            printf("%d ", ts[i]);
        }
    }

}
int main()
{
    int i, j;
    while(scanf("%d%d", &node, &edge)!=EOF){
        if(node==0 && edge==0) break;
        for(i=0; i<MM; i++) graph[i].clear();
        for(i=0; i<edge; i++){
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
        }

        tsort();
    }

    return 0;
}

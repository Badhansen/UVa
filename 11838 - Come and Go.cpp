// Solved
#include<bits/stdc++.h>

using namespace std;

#define MM 2001

int node, edge;
list<int> graph[MM];
list<int> g[MM];

void dfs(int v, bool visited[])
{
    visited[v]=true;
    list<int> :: iterator i;
    for(i=g[v].begin(); i!=g[v].end(); i++){
        if(!visited[*i]){
            dfs(*i, visited);
        }
    }
}


void fillorder(int v, bool visited[], stack<int> &st)
{
    visited[v]=true;
    list<int> :: iterator i;
    for(i=graph[v].begin(); i!=graph[v].end(); i++){
        if(!visited[*i]){
            fillorder(*i, visited, st);
        }
    }
    st.push(v);
}

void getTranspose()
{
    for(int i=0; i<node; i++){

        list<int> :: iterator it;
        for(it=graph[i].begin(); it!=graph[i].end(); it++){
            g[*it].push_back(i);
        }
    }
}

void printSSC()
{
    bool visited[MM];
    stack<int> st;

    for(int i=0; i<node; i++){
        visited[i]=false;
    }

    for(int i=0; i<node; i++){
        if(visited[i]==false){
            fillorder(i, visited, st);
        }
    }

    getTranspose();

    for(int i=0; i<node; i++){
        visited[i]=false;
    }

    int component=0;

    while(!st.empty()){
        int v=st.top();
        st.pop();
        if(!visited[v]){
            component++;
            dfs(v, visited);
        }
    }
    if(component==1){
        cout << 1 << endl;
    }
    else{
        cout << 0 << endl;
    }

}
int main()
{
    while(scanf("%d%d", &node, &edge)){

        if(node==0 && edge==0) break;

        for(int i=0; i<edge; i++){
            int u, v, p;
            scanf("%d%d%d", &u, &v, &p);
            u--;
            v--;
            if(p==1)
                graph[u].push_back(v);
            else{
                graph[u].push_back(v);
                graph[v].push_back(u);
            }

        }

        printSSC();

        for(int i=0; i<node; i++){
            graph[i].clear();
            g[i].clear();
        }
    }

    return 0;
}


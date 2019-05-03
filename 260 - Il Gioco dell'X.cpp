// Solved
#include<bits/stdc++.h>

using namespace std;

int dr[] = {-1, -1, +0, +0, +1, +1};
int dc[] = {-1, +0, -1, +1, +0, +1};
bool vis[402][402];
string str[402];
int n;

queue<pair<int, int> > Q;

bool ok(int i, int j, char ch)
{
    if(i >= 0 && i < n && j >= 0 && j < n && !vis[i][j] && str[i][j] == ch)
        return true;
    return false;
}

bool bfs(queue<pair<int, int> > &Q, char ch)
{
    while(!Q.empty()){
        int u, v;
        u = Q.front().first;
        v = Q.front().second;
        Q.pop();
        for(int i=0; i<6; i++){
            int nu, nv;
            nu = u + dr[i];
            nv = v + dc[i];
            if(ok(nu, nv, ch)){
                Q.push({nu, nv});
                vis[nu][nv] = true;
            }
        }
    }

    for(int i=0; i<n; i++){
        if(vis[n-1][i]) return true;
    }
    return false;

}
int main ()
{
    int test = 1;
    while(cin >> n){
        if(n == 0) break;
        memset(vis, false, sizeof vis);
        for(int i=0; i<n; i++){
            cin >> str[i];
            if(i == 0){
                // for black
                for(int j=0; j<n; j++){
                    if(str[i][j] == 'b'){
                        Q.push({0, j});
                        vis[0][j] = true;
                    }

                }
            }
        }
        if(bfs(Q, 'b')){
            cout << test << " B" << endl;
        }
        else{
            cout << test << " W" << endl;
        }
        test++;
    }
    return 0;
}









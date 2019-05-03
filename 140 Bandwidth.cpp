// SOLVED
#include<bits/stdc++.h>

using namespace std;

const int maxn = 26;

int adj[maxn][maxn];
int alp[maxn];
int bestCost;
int solution[maxn];
int dis[maxn];
bool used[maxn];
int n;
string ans;

void backtrack(int id)
{
    if(id == n){
        string s = "";
        int cost = -1;
        for(int i=0; i<n; i++){
            s += (solution[i] + 'A');
            for(int j=0; j<26; j++){
                if(adj[alp[i]][j]){
                    cost = max(cost, abs(dis[alp[i]] - dis[j]));
                }
            }
        }
        if(bestCost > cost){
            bestCost = cost;
            ans = s;
        }
        return;
    }
    for(int i=0; i<n; i++){
        if(!used[i]){
            used[i] = true;
            solution[id] = alp[i];
            dis[alp[i]] = id;
            backtrack(id+1);
            used[i] = false;
        }
    }
}
int main()
{
    string s;
    while(getline(cin, s)){
        if(s == "#") break;
        n = 0;
        memset(used, false, sizeof used);
        memset(adj, 0, sizeof adj);
        bestCost = 0xffff;
        int len = s.size();
        for(int i=0; i<len; i++){
            int st = s[i] - 'A';
            if(!used[st]){
                alp[n++] = st;
                used[st] = true;
            }
            int j = i+2;
            while(s[j] != ';' && s[j] != '\0') {
                int ed = s[j]-'A';
                adj[st][ed] = 1;
                if(!used[ed]){
                    used[ed] = true;
                    alp[n++] = ed;
                }
                j++;
            }
            i = j;
        }
        sort(alp, alp+n);
        memset(used, false, sizeof used);
        backtrack(0);
        for(int i=0; i<n; i++){
            if(i == n-1){
                cout << ans[i] << " -> " << bestCost << endl;
            }
            else cout << ans[i] << " ";
        }
    }
    return 0;
}

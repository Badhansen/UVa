// Solved
#include <bits/stdc++.h>

using namespace std;

#define  MM 999
#define  inf 10000000

struct Node{
    int i, j, w;
    Node(){
    }
    Node(int a, int b, int c){
        i=a;
        j=b;
        w=c;
    }
    bool operator < (const Node &a) const {
        return w>a.w;
    }

};

int X[]={+0, +0, +1, -1};
int Y[]={+1, -1, +0, +0};

int dis[MM][MM];
int cost[MM][MM];
int row, col;

priority_queue <Node> pq;

bool valid(int x, int y)
{
    if((x>=0 && x<row) && (y>=0 && y<col))
        return true;
    return false;
}
void dijkstra(int x, int y, int c)
{
    for (int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            dis[i][j]=inf;
        }
    }

    pq.push(Node(x, y, c));

    dis[x][y]=c;
    while (!pq.empty()){

        Node top=pq.top();
        pq.pop();

        if (dis[top.i][top.j]<top.w) continue;

        for(int d=0; d<4; d++){
            int a, b;
            a=top.i;
            b=top.j;
            if(valid(a+X[d], b+Y[d])){
               if(dis[a][b]+cost[a+X[d]][b+Y[d]]<dis[a+X[d]][b+Y[d]]){
                    dis[a+X[d]][b+Y[d]]=dis[a][b]+cost[a+X[d]][b+Y[d]];
                    pq.push(Node(a+X[d], b+Y[d], dis[a+X[d]][b+Y[d]]));
                }
            }

        }
    }
}


int main()
{
    int test;
    cin >> test;
    for(int i=0; i<test; i++){
        cin >> row >> col;
        row;
        col;
        for(int r=0; r<row; r++){
            for(int c=0; c<col; c++){
                cin >> cost[r][c];
            }
        }
        dijkstra(0, 0, cost[0][0]);
        cout << dis[row-1][col-1] << endl;

    }

    return 0;
}

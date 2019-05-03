// Solved
#include<bits/stdc++.h>

using namespace std;

#define filein()       freopen("in.txt", "r", stdin)
#define fileout()      freopen("out.txt", "w", stdout)

#define MM 100008

int  p[MM], r[MM], setSize[MM];
map<string, int> m;

int findSet(int x)
{
    if (p[x]==x){
        return x;
    }
    p[x]=findSet(p[x]);
    return p[x];

}
bool isSame(int x, int y)
{
    return findSet(x)==findSet(y);
}
void unionSet(int x, int y)
{
    if (!isSame(x, y)){

        int a, b;
        a=findSet(x);
        b=findSet(y);

        if (r[a]>r[b]){
            p[b]=a;
            setSize[a]+=setSize[b];
        }
        else{
            p[a]=b;
            setSize[b]+=setSize[a];
            if(r[a]==r[b]) r[a]++;
        }
    }
}

int sizeOfSet(int i)
{
    return setSize[findSet(i)];
}
int main()
{

    int test;
    cin >> test;
    for(int i=0; i<test; i++){
        m.clear();
        int n;
        cin >> n;
        int cnt=0;
        for(int j=0; j<n; j++){
            string a, b;
            cin >> a >> b;
            if(!m.count(a)){
                setSize[cnt]=1;
                r[cnt]=0;
                p[cnt]=cnt;
                m[a]=cnt++;

            }
            if(!m.count(b)){
                setSize[cnt]=1;
                r[cnt]=0;
                p[cnt]=cnt;
                m[b]=cnt++;
            }
            unionSet(m[a], m[b]);

            cout << sizeOfSet(m[a]) << endl;
        }
    }


    return 0;
}

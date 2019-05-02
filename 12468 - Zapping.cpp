#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int a, b;
    while (1){
        cin >> a >> b;
        if (a==-1 && b==-1)
            break;
        else {
            cout << min (abs (a-b), (100-max(a, b))+min (a, b)) << endl;
        }
    }
    return 0;
}


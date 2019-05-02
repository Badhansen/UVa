#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int n, sum=0, number;
    cin >> n;
    for (int i=0; i<n; i++){
        string str;
        cin >> str;
        if (str=="donate"){
            cin >> number;
            sum+=number;
        }
        else {
            cout << sum << endl;
        }
    }
    return 0;
}

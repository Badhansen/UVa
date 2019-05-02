#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int c=1;
    char str[10];
    while (1){
        cin >> str;
        if (str[0]=='*'){
            break;
        }
        if (str[0]=='H'){
            cout << "Case " << c++ << ": "<< "Hajj-e-Akbar" << endl;
        }
        else {
            cout << "Case " << c++ << ": "<< "Hajj-e-Asghar" << endl;
        }
    }
    return 0;
}


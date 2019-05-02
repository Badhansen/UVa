#include<bits/stdc++.h>

using namespace std;
int main ()
{
    int c=1;
    string ara;
    while (1){
        cin >> ara;
        if (ara=="#")
            break;
        if (ara=="HELLO")
            cout << "Case " << c << ": "<< "ENGLISH" << endl;
        else if (ara=="HOLA")
            cout << "Case " << c << ": "<< "SPANISH" << endl;
        else if (ara=="HALLO")
            cout << "Case " << c << ": "<< "GERMAN" << endl;
        else if (ara=="BONJOUR")
            cout << "Case " << c << ": "<< "FRENCH" << endl;
        else if (ara=="CIAO")
            cout << "Case " << c << ": "<< "ITALIAN" << endl;
        else if (ara=="ZDRAVSTVUJTE")
            cout << "Case " << c << ": "<< "RUSSIAN" << endl;
        else
            cout << "Case " << c << ": "<< "UNKNOWN" << endl;
        c++;
    }
    return 0;
}

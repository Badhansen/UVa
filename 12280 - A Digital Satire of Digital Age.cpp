// Solved
#include<bits/stdc++.h>

using namespace std;

/*

    @author: Badhan Sen
    CSE-14, JUST.
    mail: galaxybd9@gmail.com
*/

string sEqual[20], sGreater[20], sLess[20];

void in()
{
    // For Equal
    sEqual[0] = "........||........";
    sEqual[1] = ".../\\...||.../\\...";
    sEqual[2] = "../..\\..||../..\\..";
    sEqual[3] = "./....\\.||./....\\.";
    sEqual[4] = "/......\\||/......\\";
    sEqual[5] = "\\______/||\\______/";
    sEqual[6] = "........||........";

    // For Less than
    sLess[0] = ".../\\...||........";
    sLess[1] = "../..\\..||........";
    sLess[2] = "./....\\.||.../\\...";
    sLess[3] = "/......\\||../..\\..";
    sLess[4] = "\\______/||./....\\.";
    sLess[5] = "........||/......\\";
    sLess[6] = "........||\\______/";

    // For Greater than
    sGreater[0] = "........||.../\\...";
    sGreater[1] = "........||../..\\..";
    sGreater[2] = ".../\\...||./....\\.";
    sGreater[3] = "../..\\..||/......\\";
    sGreater[4] = "./....\\.||\\______/";
    sGreater[5] = "/......\\||........";
    sGreater[6] = "\\______/||........";

}

int main ()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);


    int t = 1, n;
    cin >> n;
    while(n--){
        string str[20];
        for(int i=0; i<8; i++){
            cin >> str[i];
        }

        int leftWeight = 0, rightWeight = 0, lp, rp;
        vector<char> leftArray, rightArray;

        // left side array insert
        for(int i=2; i<7; i++){
            for(int j=0; j<8; j++){
                if(str[i][j]>='A' && str[i][j]<='Z'){
                    //cout << str[i][j] << " Left " << endl;
                    leftArray.push_back(str[i][j]);
                }
                if(str[i][j]=='_'){
                    lp = i;
                }
            }
        }

        // Right side array insert
        for(int i=2; i<7; i++){
            for(int j=8; j<18; j++){
                if(str[i][j]>='A' && str[i][j]<='Z'){
                    //cout << str[i][j] << " Right " << endl;
                    rightArray.push_back(str[i][j]);
                }
                if(str[i][j]=='_'){
                    rp = i;
                }
            }
        }

        // for leftWeight
        for(int i=0; i<leftArray.size(); i++){
            int w = int(leftArray[i]);
            //cout << w << endl;
            while(w){
                int r = w%2;
                if(r) leftWeight += 500;
                else leftWeight += 250;
                w /= 2;
            }
            //cout << leftWeight << endl;
        }

        // for rightWeight
        for(int i=0; i<rightArray.size(); i++){
            int w = int(rightArray[i]);
            while(w){
                int r = w%2;
                if(r) rightWeight += 500;
                else rightWeight += 250;
                w /= 2;
            }
        }

        in();
        if((lp==rp) && (leftWeight==rightWeight)){
            cout << "Case " << t++ << ":" << endl;
            cout << "The figure is correct." << endl;
            continue;
        }
        else if((lp<rp) && (leftWeight<rightWeight)){
            cout << "Case " << t++ << ":" << endl;
            cout << "The figure is correct." << endl;
            continue;
        }
        else if((lp>rp) && (leftWeight>rightWeight)){
            cout << "Case " << t++ << ":" << endl;
            cout << "The figure is correct." << endl;
            continue;
        }
        else if(leftWeight==rightWeight){
            // insert the value
            for(int i=0, j=1; i<leftArray.size(); i++){
                sEqual[4][j++] = leftArray[i];
            }
            for(int i=0, j=11; i<rightArray.size(); i++){
                sEqual[4][j++] = rightArray[i];
            }
            cout << "Case " << t++ << ":" << endl;
            for(int i=0; i<7; i++){
                cout << sEqual[i] << endl;
            }
        }
        else if(leftWeight>rightWeight){
            // insert the value
            for(int i=0, j=1; i<leftArray.size(); i++){
                sGreater[5][j++] = leftArray[i];
            }
            for(int i=0, j=11; i<rightArray.size(); i++){
                sGreater[3][j++] = rightArray[i];
            }
            cout << "Case " << t++ << ":" << endl;
            for(int i=0; i<7; i++){
                cout << sGreater[i] << endl;
            }
        }
        else{
             // insert the value
            for(int i=0, j=1; i<leftArray.size(); i++){
                sLess[3][j++] = leftArray[i];
            }
            for(int i=0, j=11; i<rightArray.size(); i++){
                sLess[5][j++] = rightArray[i];
            }
            cout << "Case " << t++ << ":" << endl;
            for(int i=0; i<7; i++){
                cout << sLess[i] << endl;
            }
        }

    }


    return 0;
}







#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int a, b , total ,req , counter;
    map<long long , int>maping;

    long long in;

    while(cin >> a){

        if(!a)break;

        maping.clear();

        cin >> b;

        while(a--){

            cin >> in;

            maping[in]=1;
        }

        bool check = true;

        while(b--){

            cin >> total >> req;

            counter = 0;

            while(total--){

                cin >> in;

                if(maping[in]==1)counter++;
            }
            if(counter<req)check=false;
        }

        if(check==true)cout << "yes" << endl;
        else cout << "no" << endl;
    }

    return 0;
}

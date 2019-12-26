#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int a;
    cin >> a;

    scanf("\n");

    string ar , br , cr;

    while(a--){

        getline(cin , ar);
        stringstream ss(ar);

        ss >> br;

        ss >> cr;

        if(br=="Simon" && cr == "says"){



            ss >> br;

            cout << br;

            while(ss >> br){

                cout << " " << br;
            }

            cout << endl;
        }
    }

    return 0;
}

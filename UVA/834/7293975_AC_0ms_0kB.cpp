#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(void)
{
    int a, b , c , d , rem;

    while(cin >> a >> b){

        cout << "[";
        bool check = false;

        while(true){


            cout << a/b ;

            a = a%b;

            if(a==0)break;


            if(check==false){cout << ";";check=true;}
            else cout << ",";

            swap(a , b);
        }
        cout << "]" << endl;
    }

    return 0;
}

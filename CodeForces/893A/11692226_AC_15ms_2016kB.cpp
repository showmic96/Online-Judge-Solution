#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int n;
    cin >> n;

    int now1 = 1 , now2 = 2;

    bool check = true;

    for(int i=0;i<n;i++){

        int in;
        cin >> in;

        if(in!=now1&&in!=now2)check = false;

        if(in==now1){

            for(int i=1;i<=3;i++){

                if(i==now1||i==now2)continue;
                now2 = i;
                break;
            }
        }

        else if(in==now2){

            for(int i=1;i<=3;i++){

                if(i==now1||i==now2)continue;
                now1 = i;
                break;
            }
        }
    }

    if(check==true)cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int a , b , in;
    cin >> a;
    bool check;

    for(int i=0;i<a;i++){

        check = true ;
        cin >> b;

        while(b--){

            cin >> in;
            if(in%3!=0)check=false;
        }

        printf("Case #%d: ",i+1);

        if(check==true)cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}

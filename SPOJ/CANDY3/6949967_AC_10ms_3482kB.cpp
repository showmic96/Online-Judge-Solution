#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int a;

    cin >> a;

    long long sum = 0 , num , in;

    while(a--){

        getchar();
        
        sum = 0;
        cin >> num;

        for(int i=0;i<num;i++){

            cin >> in;

            sum+=in;
            sum%=1000000000;
        }

        if(sum%num==0)cout << "YES" << endl;
        else cout << "NO" << endl;

    }

    return 0;
}

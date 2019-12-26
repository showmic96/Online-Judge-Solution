#include<bits/stdc++.h>
typedef long long ll;

using namespace std;

int main(void)
{
    int a;
    cin >> a;
    int i=0;
    while(a--){i++;
        int j;cin >> j;
        int d=1 ,in;
        for(int b=0;b<j;b++){

            cin >> in;
            if(in==d)d++;
        }

        printf("Case %d: ",i);

        cout << j-d+1 << endl;
    }
    return 0;
}

// In the name of Allah the most Merciful .

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int x , y;
    int ar[1010];

    while(cin >> x >> y){

        if(!x&&!y)break;

        for(int i=1;i<=x;i++)cin >> ar[i];

        int a , b , c;

        for(int i=0;i<y;i++){

            cin >> a >> b >> c;

            ar[a]-=c;
            ar[b]+=c;
        }

        bool check = true;

        for(int i=1;i<=x;i++){

            if(ar[i]<0)check=false;
        }

        if(check==false)cout << "N" << endl;
        else cout << "S" << endl;

    }

    return 0;
}

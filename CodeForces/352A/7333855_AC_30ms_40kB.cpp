#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int ar[10000];

int main(void)
{
    int a;

    cin >> a;

    for(int i=0;i<a;i++){

        cin >> ar[i];
    }

    sort (ar , ar+a);

    int d = 0;

    while(ar[d]==0)d++;
    int ans = 0 , sum=0;
    int counter =0;
    for(int i=d;i<a;i++){

            counter++;
            sum+=ar[i];

            if(sum%9==0){ans=counter;}

    }

    bool check = false;
    if(d==0){cout << -1 << endl;return 0;}
    if(d!=0)for(int i=0;i<ans;i++){check=true;cout << 5;}
    if(check==true)for(int i=0;i<d;i++){check=true;cout << 0;}

    if(check==false)cout << 0;

    cout << endl;



    return 0;
}


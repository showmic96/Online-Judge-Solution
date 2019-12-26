#include<bits/stdc++.h>

using namespace std;

int main(void)
{
    long long a , b , c=0 , d , e , f,a1=1,a2=1,a3=1,b1=0,b2=0,b3=0;
    cin >> a >> b;
    long long as[a],bs[b];
    for(c=0;c<a;c++)cin >> as[c];
    for(c=0;c<b;c++)cin >> bs[c];
    sort(as,as+a);
    sort(bs,bs+b);
    if(as[a-1]<bs[0]&&(2*as[0]<bs[0])){
            if(2*as[0]<=as[a-1])cout << as[a-1] << endl;
            else cout << 2*as[0] << endl;
    }
    else cout << -1 << endl;

    return 0;
}

// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t;
    cin >> t;

    for(int i=0;i<t;i++){
        double n , m , a , b;
        cin >> n >> m >> a >> b;

        double x = (m*(a+b)-a*n)/b;

        printf("Case #%d: ",i+1);

        if(x>=0&&x<=10){

            printf("%.2lf\n",x);
        }

        else {
            cout << "Impossible" << endl;
        }

    }

    return 0;
}

// In the name of Allah the Most Merciful .

#include<bits/stdc++.h>
using namespace std;


int main(void)
{
    string ar;
    char x;
    double h , m;

    while(cin >> ar){

        stringstream ss(ar);
        ss >> h;
        ss >> x;
        ss >> m;

        if(h==0&&m==0)break;

        h+=(m/60);
        m/=5;


        printf("%.3lf\n", min(abs(m-h),min(abs(12-m+h),abs(12-h+m)))*30);

    }

    return 0;
}

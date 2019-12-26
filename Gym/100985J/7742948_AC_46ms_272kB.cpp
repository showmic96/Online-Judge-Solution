// In the name of Allah the most Merciful.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct myStruct{

    double x , y , r;
}person[10010];

int main(void)
{
    int n;
    cin >> n;

    for(int i=0;i<n;i++)cin >> person[i].x >> person[i].y >> person[i].r;

    for(int i=0;i<n-1;i++){

        for(int j=i+1;j<n;j++){

            double dis = sqrt((person[i].x-person[j].x)*(person[i].x-person[j].x) + (person[i].y-person[j].y)*(person[i].y-person[j].y));

            if(dis<=person[i].r+person[j].r)cout << i+1 << " " << j+1 << endl;
        }
    }


    return 0;
}

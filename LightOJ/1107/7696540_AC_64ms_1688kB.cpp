// In the name of Allah the most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t , x1 , y1 , x2 , y2 , n;
    cin >> t;

    for(int i=0;i<t;i++){

        cin >> x1 >> y1 >> x2 >> y2;

        cin >> n;

        printf("Case %d:\n",i+1);

        int in1 ,in2;

        while(n--){
            cin >> in1 >> in2;
            if(in1>=x1&&in1<=x2&&in2>=y1&&in2<=y2)cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }

    return 0;
}

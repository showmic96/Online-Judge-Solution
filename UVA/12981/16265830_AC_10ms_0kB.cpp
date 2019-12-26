// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t , tc = 0;

    scanf("%d",&t);
    while(t--){

        vector<int>v1 , v2;

        int in1 , in2 , in3 , in4;

        scanf("%d %d %d %d",&in1 , &in2 , &in3 , &in4);
        v1.push_back(in1);
        v1.push_back(in2);
        v1.push_back(in4);
        v1.push_back(in3);

        scanf("%d %d %d %d",&in1 , &in2 , &in3 , &in4);
        v2.push_back(in1);
        v2.push_back(in2);
        v2.push_back(in4);
        v2.push_back(in3);

        bool check = false;

        for(int i=0;i<5;i++){

            if(v1[0]==v2[(i+0)%4]&&v1[1]==v2[(i+1)%4]&&v1[2]==v2[(i+2)%4]&&v1[3]==v2[(i+3)%4])check = true;
        }

        if(check==true)printf("Case #%d: POSSIBLE\n",++tc);
        else printf("Case #%d: IMPOSSIBLE\n",++tc);
    }

    return 0;
}

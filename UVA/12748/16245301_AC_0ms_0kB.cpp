// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair< pair<int , int> , int > > v;

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        v.clear();
        int n , m;
        scanf("%d %d",&n , &m);

        for(int i=0;i<n;i++){

            int in1 , in2 , in3;
            scanf("%d %d %d",&in1 , &in2, &in3);
            v.push_back(make_pair(make_pair(in1 , in2) , in3));
        }

        printf("Case %d:\n",++c);
        while(m--){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);
            bool check = false;

            for(int i=0;i<n;i++){

                int x = v[i].first.first;
                int y = v[i].first.second;
                int r = v[i].second;

                int dis = (in1-x)*(in1-x)+(in2-y)*(in2-y);

                if(dis<=r*r){

                    check = true;
                    break;
                }
            }

            if(check==true)printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}

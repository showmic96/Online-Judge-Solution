// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        queue<int>q1 , q2;
        int n , m;
        scanf("%d %d",&n , &m);

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            q1.push(in);
            q2.push(i);
        }

        int counter = 1;

        for(int i=0;i<n;i++){

            int mx = 0 , idx = -1 , si = q1.size();

            for(int j=0;j<si;j++){

                int u = q1.front();
                int v = q2.front();

                if(u>mx){

                    mx = u;
                    idx = v;
                }

                q1.pop();
                q2.pop();

                q1.push(u);
                q2.push(v);
            }

            if(idx==m)break;
            counter++;

            for(int j=0;j<si;j++){

                int u = q1.front();
                int v = q2.front();

                q1.pop();
                q2.pop();

                if(v==idx)break;

                q1.push(u);
                q2.push(v);
            }
        }

        printf("%d\n",counter);
    }

    return 0;
}

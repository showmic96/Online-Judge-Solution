// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

char x[100];

int main(void)
{
    int n , m , t;
    int tc;
    scanf("%d",&tc);
    while(tc--){

        scanf("%d %d",&n , &m);
        queue<int> left , right;

        for(int i=0;i<m;i++){

            int in;
            scanf("%d %s",&in , &x);

            if(x[0]=='l')left.push(in);
            else right.push(in);
        }

        int now = 1 , cur = 0 , ans = 0;

        while(left.empty()==false||right.empty()==false){

            if(now==1){

                if(left.empty()==true){}
                else{

                    cur = 0;
                    while(cur+left.front()<=n*100){

                        cur+=left.front();
                        left.pop();
                        if(left.empty()==true)break;
                    }
                }
                now = 2;
                ans++;
            }
            else{

                if(right.empty()==true){}
                else{

                    cur = 0;
                    while(cur+right.front()<=n*100){

                        cur+=right.front();
                        right.pop();
                        if(right.empty()==true)break;
                    }
                }
                now = 1;
                ans++;
            }
        }

        printf("%d\n",ans);
    }
    return 0;
}

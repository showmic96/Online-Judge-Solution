// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        int n , x , y , ans = -1 , d = 1e9 , c = 0;
        scanf("%d %d %d",&n , &x , &y);

        for(int i=0;i<n;i++){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);
            if(in1<=x&&in2>=y){

                if(in1<d){

                    ans = i+1;
                    d = in1;
                    c = in2;
                }

                else if(in1==d){

                    if(in2>c){

                        c = in2;
                        ans = i+1;
                    }
                }
            }
        }

        printf("%d\n",ans);
    }
    return 0;
}

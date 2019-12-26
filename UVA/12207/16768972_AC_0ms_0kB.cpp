// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
char ar[10];

int main(void)
{
    int p , q , c = 0;
    while(scanf("%d %d",&p , &q)==2){

        if(p==0&&q==0)break;
        printf("Case %d:\n",++c);


        deque<int>current;
        for(int i=1;i<=min(p,2000);i++)current.push_back(i);

        while(q--){

            scanf("%s",&ar);

            if(ar[0]=='N'){

                printf("%d\n",(int)current.front());
                current.push_back(current.front());
                current.pop_front();
            }
            else{

                int in;
                scanf("%d",&in);
                //printf("%d\n",in);

                int si = current.size();
                for(int i=0;i<si;i++){

                    int t = current.front();

                    if(t==in){

                        current.pop_front();
                    }
                    else{

                        current.pop_front();
                        current.push_back(t);
                    }
                }

                current.push_front(in);
            }
        }
    }
    return 0;
}

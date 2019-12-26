// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 10000+9;

int parent[2*MAX];

int Find(int x)
{
    if(parent[x]==x)return x;
    return parent[x] = Find(parent[x]);
}

int main(void)
{
    int n;
    while(scanf("%d",&n)==1){

        for(int i=0;i<=2*n;i++)parent[i] = i;

        int in1 , in2 , in3;

        while(scanf("%d %d %d",&in1 , &in2 , &in3)==3){

            if(!in1&&!in2&&!in3)break;

            if(in1==1){

                if(Find(in2)==Find(in3+n)){

                    printf("-1\n");
                }

                else{

                    int px = Find(in2);
                    int py = Find(in3);

                    parent[py] = px;

                    parent[Find(in3+n)] = Find(in2+n);
                }
            }

            else if(in1==2){

                if(Find(in2)==Find(in3)){

                    printf("-1\n");
                }

                else{

                    parent[Find(in2)] = Find(in3+n);
                    parent[Find(in3)] = Find(in2+n);
                }
            }

            else if(in1==3){

                if(Find(in2)==Find(in3))printf("1\n");
                else printf("0\n");
            }

            else{

                if(Find(in2)==Find(in3+n))printf("1\n");
                else printf("0\n");
            }
        }
    }
    return 0;
}

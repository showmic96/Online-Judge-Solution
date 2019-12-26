// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5+9;

bool isPrime[MAX+9];
int level[MAX+9];

void seive()
{
    memset(isPrime , true , sizeof(isPrime));

    for(int i=2;i<=MAX;i++){

        if(isPrime[i]){

            for(int j=2*i;j<=MAX;j+=i){

                isPrime[j] = false;
            }
        }
    }
}

void bfs(int u)
{
    queue<int>current;
    current.push(u);

    level[u] = 1;

    while(!current.empty()){

        u = current.front();
        current.pop();

        int l = level[u];

        vector<int>v;

        while(u){

            v.push_back(u%10);
            u/=10;
        }


        reverse(v.begin() , v.end());

        for(int i=1;i<=9;i++){

            int temp = i;
            temp*=10;
            temp+=v[1];
            temp*=10;
            temp+=v[2];
            temp*=10;
            temp+=v[3];

            if(isPrime[temp]){

                if(!level[temp]){

                    level[temp] = l+1;
                    current.push(temp);
                }
            }
        }

        for(int i=0;i<=9;i++){

            int temp = v[0];
            temp*=10;
            temp+=i;
            temp*=10;
            temp+=v[2];
            temp*=10;
            temp+=v[3];

            if(isPrime[temp]){

                if(!level[temp]){

                    level[temp] = l+1;
                    current.push(temp);
                }
            }
        }

        for(int i=0;i<=9;i++){

            int temp = v[0];
            temp*=10;
            temp+=v[1];
            temp*=10;
            temp+=i;
            temp*=10;
            temp+=v[3];

            if(isPrime[temp]){

                if(!level[temp]){

                    level[temp] = l+1;
                    current.push(temp);
                }
            }
        }

        for(int i=1;i<=9;i++){

            int temp = v[0];
            temp*=10;
            temp+=v[1];
            temp*=10;
            temp+=v[2];
            temp*=10;
            temp+=i;

            if(isPrime[temp]){

                if(!level[temp]){

                    level[temp] = l+1;
                    current.push(temp);
                }
            }
        }
    }
}

int main(void)
{
    seive();
    int t;
    scanf("%d",&t);
    while(t--){

        int st , en;
        scanf("%d %d",&st , &en);

        memset(level , 0 , sizeof(level));

        bfs(st);

        if(level[en]==0)printf("Impossible\n");
        else printf("%d\n",level[en]-1);
    }
    return 0;
}

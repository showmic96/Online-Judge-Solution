// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1234;
vector<int>edges[MAX];
int level[MAX];
bool isPrime[MAX];
vector<int>primes;

void seive()
{
    for(int i=0;i<MAX;i++)isPrime[i] = true;

    for(int i=2;i<MAX;i++){

        for(int j=2;i*j<MAX;j++){

            if(isPrime[i]==true)isPrime[i*j] = false;
        }

        if(isPrime[i]==true)primes.push_back(i);
    }
}
void setUp()
{
    for(int i=0;i<MAX;i++){

        level[i] = 12345678;
    }
}

void pre_cal()
{

    seive();
    for(int i=1;i<MAX;i++){

        int lim = sqrt(i);
        int t = i;

        for(int j=0;primes[j]<=lim;j++){

            if(t%primes[j]==0){

                edges[i].push_back(primes[j]);

                int temp;

                while(t%primes[j]==0){

                    temp = t/primes[j];
                    //if(isPrime[t/primes[j]]==true)edges[i].push_back(t/primes[j]);
                    t/=primes[j];
                }

                if(isPrime[temp]==true&&temp!=1)edges[i].push_back(temp);
            }
        }
    }
}

void bfs(int st , int en){

    queue<int>current;
    current.push(st);

    level[st] = 0;

    while(!current.empty()){

        int temp = current.front();
        current.pop();

        int si = edges[temp].size();

        for(int i=0;i<si;i++){

            if(level[temp + edges[temp][i]]>level[temp]+1){

                if(temp+edges[temp][i]>en)continue;

                level[temp+ edges[temp][i]] = level[temp] + 1;

                current.push(temp+ edges[temp][i]);
            }
        }
    }
}

int main(void)
{
    pre_cal();

    /*for(int i=1;i<50;i++){

        cout << "Value " << i << " : ";
        for(int j=0;j<edges[i].size();j++)cout << edges[i][j] << " ";
        cout << endl;
    }*/

    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){

        setUp();
        int s , t;
        scanf("%d %d",&s , &t);
        bfs(s , t);
        if(level[t]==12345678)level[t] = -1;
        printf("Case %d: %d\n",i+1 , level[t]);
    }
    return 0;
}

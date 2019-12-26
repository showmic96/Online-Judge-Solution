// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX =  33000+9;
bool isPrime[MAX+9];
vector<int>primes;
vector<int>v[10005];
int c;

void seive()
{
    for(int i=0;i<=MAX;i++)isPrime[i] = true;
    for(int i=2;i<=MAX;i++){

        if(isPrime[i]){

            for(int j=2*i;j<=MAX;j+=i){

                isPrime[j] = false;
            }

            primes.push_back(i);
        }
    }
}

void pre()
{
    seive();
    c = 0;
    vector<int>temp;
    for(int i=0;i<primes.size()-1;i++){

        temp.push_back(primes[i+1]-primes[i]);
    }

    for(int i=0;i<temp.size();i++){

        v[c].push_back(primes[i]);

        for(int j=i;j<temp.size();j++){

            if(temp[i]==temp[j]){

                v[c].push_back(primes[j+1]);
            }
            else break;

            i = j;
        }
        if(v[c].size()<3){
            v[c].clear();
        }
        else c++;
    }
}

int main(void)
{
    pre();

    int x , y;
    while(scanf("%d %d",&x , &y)==2){

        if(x==0&&y==0)break;
        
        if(x>y)swap(x , y);

        for(int i=0;i<c;i++){

            if(v[i][0]>=x&&v[i][v[i].size()-1]<=y){

                for(int j=0;j<v[i].size();j++){

                    if(j>0)printf(" ");
                    printf("%d",v[i][j]);
                }

                printf("\n");
            }
        }

    }
    return 0;
}

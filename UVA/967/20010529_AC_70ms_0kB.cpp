// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e6+9;
vector<ll>primes , ans;
bool prime[MAX+9];

void sieve()
{
    for(int i=0;i<=MAX;i++)prime[i] = true;
    for(int i=2;i<=MAX;i++){
        if(prime[i]==true){
            for(int j=2*i;j<=MAX;j+=i){
                prime[j]=false;
            }
            primes.push_back(i);
        }
    }
}
vector<int> g(int x)
{
    vector<int>temp;
    while(x){
        temp.push_back(x%10);
        x/=10;
    }
    reverse(temp.begin() , temp.end());
    return temp;
}
void pre()
{
    sieve();
    for(int i=100;i<=1000000;i++){
        if(prime[i]==true){
            vector<int>v = g(i);
            bool check = true;
            for(int j=0;j<v.size();j++){
                ll now = 0;
                for(int k=0;k<v.size();k++){
                    now*=10;
                    now+=v[(j+k)%v.size()];
                }
                if(prime[now]==false){
                    check = false;
                    break;
                }
            }
            if(check)ans.push_back(i);
        }
    }
}

int main(void)
{
    pre();
    int a , b;
    while(scanf("%d",&a)==1){
        if(a==-1)break;
        scanf("%d",&b);
        int fin = upper_bound(ans.begin() , ans.end() , b) - lower_bound(ans.begin() , ans.end() , a);
        if(fin==1)printf("%d Circular Prime.\n",fin);
        else if(fin>1)printf("%d Circular Primes.\n",fin);
        else printf("No Circular Primes.\n");
    }
    return 0;
}

// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 3e6+9;
int prime[MAX+9];
bool taken[MAX+9];

void sieve()
{
    for(int i=0;i<=MAX;i++)prime[i] = i;

    for(int i=2;i<=MAX;i++){

        if(prime[i]==i){

            for(int j=2*i;j<=MAX;j+=i){

                prime[j] = i;
            }
        }
    }
}

void Add(int x)
{
    while(x>1){

        int temp = prime[x];
        bool check = false;

        while(x%temp==0){

            x/=temp;
            check = true;
        }

        if(check==true){

            taken[temp] = true;
        }
    }
}

bool Check(int x)
{
    while(x>1){

        int temp = prime[x];
        bool check = false;

        while(x%temp==0){

            x/=temp;
            check = true;
        }

        if(check==true){

            if(taken[temp]==true)return false;
        }
    }

    return true;
}

int main(void)
{
    sieve();
    memset(taken , false , sizeof(taken));

    int n;
    scanf("%d",&n);

    vector<int>v , ans;

    for(int i=0;i<n;i++){

        int in;
        scanf("%d",&in);
        v.push_back(in);
    }

    for(int i=0;i<n;i++){

        if(Check(v[i])){

            ans.push_back(v[i]);
            Add(v[i]);
        }

        else break;
    }

    if(ans.size()<n){

        for(int i=v[ans.size()]+1;;i++){

            if(Check(i)){

                Add(i);
                ans.push_back(i);
                break;
            }
        }

        for(int i=2;ans.size()<n;i++){

            if(Check(i)){

                ans.push_back(i);
                Add(i);
            }
        }
    }

    for(int i=0;i<n;i++){

        if(i>0)printf(" ");
        printf("%d",ans[i]);
    }

    return 0;
}

// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 17;
bool taken[MAX];

int n , ans[MAX];

bool is_prime(int x)
{
    //cout << x << endl;
    if(x==2)return true;
    if(x%2==0)return false;
    int lim = sqrt(x);
    for(int i=3;i<=lim;i+=2){

        if(x%i==0)return false;
    }

    //cout << x << endl;
    return true;
}

void f(int idx)
{

    if(idx==n){

        if(is_prime(ans[idx-1]+ans[0])==false)return ;

        cout << 1;
        for(int i=1;i<n;i++)cout << " " << ans[i];
        cout << endl;
        return;
    }

    for(int i=2;i<=n;i++){

        //cout << idx << " " << i << endl;

        if(taken[i]==false){

            //cout << ans[i-1] << " " << j << endl;

            if(is_prime(i+ans[idx-1])==false){continue;}
            taken[i] = true;

            //ans.push_back(j);

            ans[idx] = i;

            f(idx+1);

            taken[i] = false;
        }
    }

    return ;
}

int main(void)
{
    int c = 0;
    while(cin >> n){

        if(c!=0)printf("\n");
        printf("Case %d:\n", ++c);
        memset(taken , false , sizeof(taken));
        taken[1] = true;
        ans[0] = 1;

        f(1);
    }

    return 0;
}

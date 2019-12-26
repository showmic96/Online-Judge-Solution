// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int>sq;
int sum[51000];

void pre()
{
    for(int i=0;i<=226;i++){

        sq.push_back(i*i);
    }

    memset(sum , 0 , sizeof(sum));

    for(int i=0;i<=226;i++){

        for(int j=0;j<=226;j++){

            if(sq[i]+sq[j]<=50000){

                sum[sq[i]+sq[j]] = 1;
            }
        }
    }
}

int main(void)
{
    pre();

    int t;
    scanf("%d",&t);
    while(t--){

        int n;
        scanf("%d",&n);

        bool check = false;

        for(int i=0;i<=226;i++){

            int temp = n-i*i;
            if(temp<0)break;

            if(sum[temp]==1){

                int a[3];

                a[0] = i;

                for(int i1=0;i1<=226;i1++){

                    int t = i1*i1;
                    if(binary_search(sq.begin() , sq.end() , temp-t)){

                        a[1] = i1;
                        a[2] = sqrt(temp-t);
                        break;
                    }
                }

                sort(a , a+3);

                printf("%d %d %d\n",a[0] , a[1] , a[2]);
                check = true;
                break;
            }
        }

        if(check)continue;
        printf("-1\n");
    }
    return 0;
}

// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1005;
const ll INF = 1e18;

int ar[MAX][MAX] , two[MAX][MAX] , five[MAX][MAX];
int ptwo[MAX][MAX] , pfive[MAX][MAX];
ll dtwo[MAX][MAX] , dfive[MAX][MAX];

int main(void)
{
    int n;bool zero = false;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%lld",&ar[i][j]);
            if(ar[i][j]==0){
                zero = true;
                two[i][j] = 1e9;
                five[i][j] = 1e9;
            }
            while(ar[i][j]%2==0&&ar[i][j]>0)two[i][j]++ , ar[i][j]/=2;
            while(ar[i][j]%5==0&&ar[i][j]>0)five[i][j]++ , ar[i][j]/=5;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dtwo[i][j] = INF;
            dfive[i][j] = INF;
        }
    }
    dtwo[0][0] = two[0][0];
    dfive[0][0] = five[0][0];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i-1>=0){
                if(dtwo[i][j]>dtwo[i-1][j]+two[i][j]){
                    dtwo[i][j] = dtwo[i-1][j]+two[i][j];
                    ptwo[i][j] = 1;
                }
                if(dfive[i][j]>dfive[i-1][j]+five[i][j]){
                    dfive[i][j] = dfive[i-1][j]+five[i][j];
                    pfive[i][j] = 1;
                }
            }
            if(j-1>=0){
                if(dtwo[i][j]>dtwo[i][j-1]+two[i][j]){
                    dtwo[i][j] = dtwo[i][j-1]+two[i][j];
                    ptwo[i][j] = 2;
                }
                if(dfive[i][j]>dfive[i][j-1]+five[i][j]){
                    dfive[i][j] = dfive[i][j-1]+five[i][j];
                    pfive[i][j] = 2;
                }
            }
        }
    }
    if(zero==true&&min(dtwo[n-1][n-1], dfive[n-1][n-1])>1){

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(ar[i][j]==0){
                    two[i][j] = -1e9;
                    five[i][j] = -1e9;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i-1>=0){
                    if(dtwo[i][j]>dtwo[i-1][j]+two[i][j]){
                        dtwo[i][j] = dtwo[i-1][j]+two[i][j];
                        ptwo[i][j] = 1;
                    }
                    if(dfive[i][j]>dfive[i-1][j]+five[i][j]){
                        dfive[i][j] = dfive[i-1][j]+five[i][j];
                        pfive[i][j] = 1;
                    }
                }
                if(j-1>=0){
                    if(dtwo[i][j]>dtwo[i][j-1]+two[i][j]){
                        dtwo[i][j] = dtwo[i][j-1]+two[i][j];
                        ptwo[i][j] = 2;
                    }
                    if(dfive[i][j]>dfive[i][j-1]+five[i][j]){
                        dfive[i][j] = dfive[i][j-1]+five[i][j];
                        pfive[i][j] = 2;
                    }
                }
            }
        }

        if(dtwo[n-1][n-1]<dfive[n-1][n-1]){
            printf("%lld\n",1LL);
            int i = n-1 , j = n-1;
            string q = "";
            while(true){
                if(i==0&&j==0)break;
                if(ptwo[i][j]==1)q+='D';
                else q+='R';
                int temp = ptwo[i][j];
                if(temp==1)i--;
                else j--;
            }
            for(int i=q.size()-1;i>=0;i--)printf("%c",q[i]);
            printf("\n");
        }
        else{
            printf("%lld\n",1LL);
            int i = n-1 , j = n-1;
            string q = "";
            while(true){
                if(i==0&&j==0)break;
                if(pfive[i][j]==1)q+='D';
                else q+='R';
                int temp = pfive[i][j];
                if(temp==1)i--;
                else j--;
            }
            for(int i=q.size()-1;i>=0;i--)printf("%c",q[i]);
            printf("\n");
        }
    }
    else if(dtwo[n-1][n-1]<dfive[n-1][n-1]){
        printf("%lld\n",dtwo[n-1][n-1]);
        int i = n-1 , j = n-1;
        string q = "";
        while(true){
            if(i==0&&j==0)break;
            if(ptwo[i][j]==1)q+='D';
            else q+='R';
            int temp = ptwo[i][j];
            if(temp==1)i--;
            else j--;
        }
        for(int i=q.size()-1;i>=0;i--)printf("%c",q[i]);
        printf("\n");
    }
    else{
        printf("%lld\n",dfive[n-1][n-1]);
        int i = n-1 , j = n-1;
        string q = "";
        while(true){
            if(i==0&&j==0)break;
            if(pfive[i][j]==1)q+='D';
            else q+='R';
            int temp = pfive[i][j];
            if(temp==1)i--;
            else j--;
        }
        for(int i=q.size()-1;i>=0;i--)printf("%c",q[i]);
        printf("\n");
    }

    return 0;
}

// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int in1 , in2 ,in3 , in4;
double dp[16][16][16][16][5][5];
bool vis[16][16][16][16][5][5];

double f(int i1 , int i2 , int i3 , int i4 , int j1 , int j2)
{

    if(i1+(j1==1)+(j2==1)>=in1&&i2+(j1==2)+(j2==2)>=in2&&i3+(j1==3)+(j2==3)>=in3&&i4+(j1==4)+(j2==4)>=in4)return 0.0;
    if(vis[i1][i2][i3][i4][j1][j2]==true)return dp[i1][i2][i3][i4][j1][j2];
    vis[i1][i2][i3][i4][j1][j2] = true;

    int rem1 = 13-i1;
    int rem2 = 13-i2;
    int rem3 = 13-i3;
    int rem4 = 13-i4;
    int rem = rem1+rem2+rem3+rem4+(j1==0)+(j2==0);

    double value = 1;

    if(rem1>0)value+=(double)((double)rem1/(double)rem)*(double)f(i1+1 , i2 , i3 , i4 , j1 , j2);
    if(rem2>0)value+=(double)((double)rem2/(double)rem)*(double)f(i1 , i2+1 , i3 , i4 , j1 , j2);
    if(rem3>0)value+=(double)((double)rem3/(double)rem)*(double)f(i1 , i2 , i3+1 , i4 , j1 , j2);
    if(rem4>0)value+=(double)((double)rem4/(double)rem)*(double)f(i1 , i2 , i3 , i4+1 , j1 , j2);

    if(j1==0){

        double t1 , t2 , t3 , t4;

        t1=(double)((double)1/(double)rem)*f(i1 , i2 , i3 , i4 , 1 , j2);
        t2=(double)((double)1/(double)rem)*f(i1 , i2 , i3 , i4 , 2 , j2);
        t3=(double)((double)1/(double)rem)*f(i1 , i2 , i3 , i4 , 3 , j2);
        t4=(double)((double)1/(double)rem)*f(i1 , i2 , i3 , i4 , 4 , j2);

        value+=min(t1 , min(t2 , min(t3 , t4)));
    }

    if(j2==0){

        double t1 , t2 , t3 , t4;

        t1=(double)((double)1/(double)rem)*f(i1 , i2 , i3 , i4 , j1 , 1);
        t2=(double)((double)1/(double)rem)*f(i1 , i2 , i3 , i4 , j1 , 2);
        t3=(double)((double)1/(double)rem)*f(i1 , i2 , i3 , i4 , j1 , 3);
        t4=(double)((double)1/(double)rem)*f(i1 , i2 , i3 , i4 , j1 , 4);

        value+=min(t1 , min(t2 , min(t3 , t4)));
    }

    return dp[i1][i2][i3][i4][j1][j2] = value;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        memset(vis , false , sizeof(vis));
        scanf("%d %d %d %d",&in1 , &in2 , &in3 , &in4);

        int need = 0;
        if(in1>13)need+=in1-13;
        if(in2>13)need+=in2-13;
        if(in3>13)need+=in3-13;
        if(in4>13)need+=in4-13;

        if(in1>15||in2>15||in3>15||in4>15||(in1+in2+in3+in4)>54||need>2){printf("Case %d: %.3f\n",++c, -1.0);continue;}
        printf("Case %d: %.3f\n",++c , f(0 , 0 , 0 , 0 , 0 , 0));
    }

    return 0;
}

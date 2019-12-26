// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int ar[10005];

int main(void)
{
    int x , y , z;

    memset(ar , 0 , sizeof(ar));

    while(scanf("%d %d %d",&x , &y , &z)==3){

        for(int i=x;i<z;i++)ar[i] = max(ar[i] , y);
    }
    
    int l = 0 , h = 0;
    
    printf("%d %d",1 , ar[1]);
    int counter = 1;
    
    for(int i=2;i<10005;i++){
        
        if(ar[i]!=ar[i-1]){
            
            printf(" %d %d",i , ar[i]);
        }
    }
    
    printf("\n");

    return 0;
}

#include<iostream>
#include<algorithm>
using namespace std;
int main(void)
{
    int num;
    int ara[2000000];
    while(cin>>num)
    {
        if(num==0)
            break;
        
            for(int i=0; i<num; i++)
                cin>>ara[i];
            sort(ara,ara+num);
            for(int i=0; i<num; i++)
            {
                if(i==num-1)
                    cout<<ara[i]<<endl;
 
                else
                    cout<<ara[i]<<" ";
            }
        
    }
    return 0;
}
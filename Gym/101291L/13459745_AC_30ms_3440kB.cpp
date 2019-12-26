// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

vector<long>v1 , v2;
bool check;

pair<int , int > _merge(int a , int b , int c , int d)
{
    pair<int , int> temp;
    temp = make_pair(-1 , -1);

    if(a==c){

        temp = make_pair(a , b+d);
        return temp;
    }

    if(a==d){

        temp = make_pair(a , b+c);
        return temp;
    }

    if(b==c){

        temp = make_pair(b , a+d);
        return temp;
    }

    if(b==d){

        temp = make_pair(b , a+c);
        return temp;
    }

    return temp;
}

int main(void)
{
    for(int i=0;i<3;i++){

        int in1 , in2;
        scanf("%d %d",&in1 , &in2);
        v1.push_back(in1);
        v2.push_back(in2);
    }

    check = false;

    for(int i=0;i<3;i++){

        for(int j=0;j<3;j++){

            if(i==j)continue;

            for(int k=0;k<3;k++){

                if(i==k||k==j)continue;

                pair<int, int> pa = _merge(v1[i] , v2[i] , v1[j] , v2[j]);
                if(pa.first==-1)continue;

                pair<int,int> temp = _merge(pa.first , pa.second , v1[k] , v2[k]);

                if(temp.first==temp.second&&temp.first>0)check = true;
                
                temp = _merge(pa.second , pa.first , v1[k] , v2[k]);

                if(temp.first==temp.second&&temp.first>0)check = true;
            }

            for(int k=0;k<3;k++){

                if(i==k||k==j)continue;

                pair<int, int> pa = _merge(v2[i] , v1[i] , v1[j] , v2[j]);
                if(pa.first==-1)continue;

                pair<int,int> temp = _merge(pa.first , pa.second , v1[k] , v2[k]);

                if(temp.first==temp.second&&temp.first>0)check = true;
                
                temp = _merge(pa.second , pa.first , v1[k] , v2[k]);

                if(temp.first==temp.second&&temp.first>0)check = true;
            }
        }
    }

    if(check)printf("YES\n");
    else printf("NO\n");

    return 0;
}

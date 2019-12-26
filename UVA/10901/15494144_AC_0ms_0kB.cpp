// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

char x[100];
int ans[10005];

int main(void)
{
    int n , m , t;
    bool blank = false;
    int tc;
    scanf("%d",&tc);
    while(tc--){

        scanf("%d %d %d",&n , &t , &m);

        if(blank==true)printf("\n");
        blank = true;

        queue<pair<int , int> > left , right;

        for(int i=0;i<m;i++){

            int in;
            scanf("%d %s",&in , &x);

            if(x[0]=='l')left.push(make_pair(in , i));
            else right.push(make_pair(in , i));
        }

        int now = 1 , cur = 0;

        while(left.empty()==false||right.empty()==false){

            if(left.empty()){

                cur = max(cur , right.front().first);

                if(now==1)cur+=t;
                int counter = 0;

                while(right.empty()==false&&right.front().first<=cur){

                    ans[right.front().second] = cur+t;
                    right.pop();
                    counter++;
                    if(counter==n)break;
                }
                cur+=t;
                now = 1;
            }
            else if(right.empty()){

                cur = max(cur , left.front().first);

                if(now==2)cur+=t;
                int counter = 0;

                while(left.empty()==false&&left.front().first<=cur){

                    ans[left.front().second] = cur+t;
                    left.pop();
                    counter++;
                    if(counter==n)break;
                }
                cur+=t;
                now = 2;
            }
            else if(cur>=left.front().first&&cur>=right.front().first){

                if(now==1){
                    int counter = 0;
                    cur = max(cur , left.front().first);

                    while(left.empty()==false&&left.front().first<=cur){

                        ans[left.front().second] = cur+t;
                        left.pop();
                        counter++;
                        if(counter==n)break;
                    }
                    now = 2;
                }
                else{
                    int counter = 0;
                    cur = max(cur , right.front().first);
                    while(right.empty()==false&&right.front().first<=cur){

                        ans[right.front().second] = cur+t;
                        right.pop();
                        counter++;
                        if(counter==n)break;
                    }
                    now = 1;
                }

                cur+=t;
            }
            else{

                if(left.front().first<right.front().first){

                    cur = max(cur , left.front().first);

                    int counter = 0;
                    if(now==2)cur+=t;
                    while(left.empty()==false&&left.front().first<=cur){

                        ans[left.front().second] = cur+t;
                        left.pop();
                        counter++;
                        if(counter==n)break;

                    }

                    cur+=t;
                    now = 2;
                }
                else if(right.front().first<left.front().first){

                    cur = max(cur , right.front().first);
                    int counter = 0;
                    if(now==1)cur+=t;
                    while(right.empty()==false&&right.front().first<=cur){

                        ans[right.front().second] = cur+t;
                        right.pop();
                        counter++;
                        if(counter==n)break;
                    }

                    cur+=t;
                    now = 1;
                }
                else{

                    cur = max(cur , left.front().first);

                    if(now==1){
                        int counter = 0;
                        while(left.empty()==false&&left.front().first<=cur){

                            ans[left.front().second] = cur+t;
                            left.pop();
                            counter++;
                            if(counter==n)break;
                        }
                        now = 2;
                    }
                    else{

                        int counter = 0;
                        while(right.empty()==false&&right.front().first<=cur){

                            ans[right.front().second] = cur+t;
                            right.pop();
                            counter++;
                            if(counter==n)break;
                        }
                        now = 1;
                    }

                    cur+=t;
                }
            }
        }

        for(int i=0;i<m;i++)printf("%d\n",ans[i]);
    }
    return 0;
}

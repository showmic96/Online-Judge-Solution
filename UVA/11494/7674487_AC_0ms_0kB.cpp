// In the name of Allah the most Merciful .

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int x1 , y1 , x2 , y2 , x , y;

    while(cin >> x1 >> y1 >> x2 >> y2){

        if(!x1&&!y1&&!x2&&!y2)break;

        if(x1==x2&&y1==y2)cout << 0 << endl;
        else{

            bool check = false;

            x = x1;
            y = y1;

            while(x<=8){

                x++;
                if(x==x2&&y==y2){check=true;break;}
            }

            x = x1;
            y = y1;

            while(x>=0){

                x--;
                if(x==x2&&y==y2){check=true;break;}
            }

            x = x1;
            y = y1;

            while(y<=8){

                y++;
                if(x==x2&&y==y2){check=true;break;}
            }

            x = x1;
            y = y1;

            while(y>=0){

                y--;
                if(x==x2&&y==y2){check=true;break;}
            }

            x = x1;
            y = y1;

            while(x<=8&&y<=8){

                x++;
                y++;
                if(x==x2&&y==y2){check=true;break;}
            }

            x = x1;
            y = y1;

            while(x<=8&&y>=0){

                x++;
                y--;
                if(x==x2&&y==y2){check=true;break;}
            }

            x = x1;
            y = y1;

            while(x>=0&&y<=8){

                x--;
                y++;
                if(x==x2&&y==y2){check=true;break;}
            }

            x = x1;
            y = y1;

            while(x>=0&&y>=0){

                x--;
                y--;
                if(x==x2&&y==y2){check=true;break;}
            }

            if(check==true)cout << 1 << endl;
            else cout << 2 << endl;
        }
    }

    return 0;
}

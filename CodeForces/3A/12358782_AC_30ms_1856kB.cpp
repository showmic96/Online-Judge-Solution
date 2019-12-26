// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

vector<string>v;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    char c[5];

    int x1 , y1 , x2 , y2;

    cin >> c;

    x1 = c[0]-'a';
    y1 = c[1]-'0'-1;

    cin >> c;

    x2 = c[0]-'a';
    y2 = c[1]-'0'-1;

    int x = x2-x1;
    int y = y2-y1;

    while(x!=0||y!=0){

        if(x==0){

            if(y>0){

                v.push_back("U");
                y--;
            }

            else{

                v.push_back("D");
                y++;
            }
        }

        else if(y==0){

            if(x>0){

                v.push_back("R");
                x--;
            }

            else{

                v.push_back("L");
                x++;
            }
        }

        else{

            if(x>0&&y>0){

                v.push_back("RU");
                x--;y--;
            }

            else if(x>0&&y<0){

                v.push_back("RD");
                x--;y++;
            }

            else if(x<0&&y>0){

                v.push_back("LU");
                x++;y--;
            }

            else{

                v.push_back("LD");
                x++;y++;
            }
        }
    }

    cout << v.size() << endl;

    for(int i=0;i<v.size();i++){

        cout << v[i] << endl;
    }

    return 0;
}

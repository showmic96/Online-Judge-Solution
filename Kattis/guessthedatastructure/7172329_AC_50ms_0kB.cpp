#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int a , in1 , in2;
    while(cin >> a){

        stack<int>stack_in;
        queue<int>queue_in;
        priority_queue<int>pqueue_in;

        bool isQueue = true , isStack = true , isPqueue = true;

        for(int i=0;i<a;i++){

            cin >> in1 >> in2;

            if(in1==1){

                stack_in.push(in2);
                queue_in.push(in2);
                pqueue_in.push(in2);
            }

            if(in1==2){

                if(stack_in.empty()==true)isStack = false;
                if(queue_in.empty()==true)isQueue = false;
                if(pqueue_in.empty()==true)isPqueue = false;

                if(isStack == true){

                    int temp = stack_in.top();

                    stack_in.pop();

                    if(temp!=in2)isStack = false;
                }

                if(isQueue == true){

                    int temp = queue_in.front();

                    queue_in.pop();

                    if(temp!=in2)isQueue = false;
                }

                if(isPqueue == true){

                    int temp = pqueue_in.top();

                    pqueue_in.pop();

                    if(temp!=in2)isPqueue = false;
                }
            }

        }

        int counter = 0;

        if(isStack==true)counter++;
        if(isQueue==true)counter++;
        if(isPqueue==true)counter++;

        if(counter>=2)cout << "not sure" << endl;
        else if(counter == 0 ) cout << "impossible" << endl;
        else{

            if(isStack==true)cout << "stack" << endl;
            if(isQueue==true)cout << "queue" << endl;
            if(isPqueue==true)cout << "priority queue" << endl;
        }
    }
    return 0;
}

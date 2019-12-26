
//package lab.assignment;

import java.util.*;

class Main {
    
    public static void main(String arg[]){
        
        int n , d , r;
        
        Scanner sc = new Scanner(System.in);
        
        while(sc.hasNext()){
            
            n = sc.nextInt();
            d = sc.nextInt();
            r = sc.nextInt();
            
            if(n==0&&d==0&&r==0)break;
            
            int ar[] = new int [n];
            int br[] = new int [n];
            
            for(int i=0;i<n;i++)ar[i]=sc.nextInt();
            for(int i=0;i<n;i++)br[i]=sc.nextInt();
            
            Arrays.sort(ar);
            Arrays.sort(br);
            
            int sum = 0;
            
            for(int i=0;i<n;i++){
                
                int temp = ar[i] + br[n-i-1];
                
                if(temp>d){
                    
                    sum+=(temp-d)*r;
                }
            }
            
            System.out.println(sum);
        }
    }
    
}

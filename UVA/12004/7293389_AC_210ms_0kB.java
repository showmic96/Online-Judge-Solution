
//package lab.assignment;
import java.util.*;
import java.math.*;
public class Main {
    
    public static void main(String arg[]){
        
        Scanner sc = new Scanner (System.in);
        
        long a = sc.nextInt() , b , ans;
        
        for(int i=0;i<a;i++){
            
            ans = 0;
            b = sc.nextInt();
            
            ans = (b*(b-1)/2);
            
            if(ans%2==1)System.out.printf("Case %d: %d/%d\n", i+1 , ans,2);
            else System.out.printf("Case %d: %d\n", i+1 , ans/2);
        }
    }
}
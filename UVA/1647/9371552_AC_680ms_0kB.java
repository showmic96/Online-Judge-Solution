// In the name of Allah the Most Merciful. 

import java.util.*;
import java.math.*;

class Main{
    
    public static void main(String arg[]){
        
        Scanner sc = new Scanner(System.in);
        BigInteger data [] = new BigInteger[1234];
        
        data[1] = new BigInteger("0");
        
        for(int i=2;i<1234;i++){
            
            data[i] = data[i-1].multiply(BigInteger.valueOf(2));
            
            if(i%2==1){
                
                data[i] = data[i].subtract(BigInteger.valueOf(1));
            }
            
            else{
                
                data[i] = data[i].add(BigInteger.valueOf(1));
            }
        }
        
        while(sc.hasNext()){
            
            int in = sc.nextInt();
            
            System.out.println(data[in]);
        }
    }
}
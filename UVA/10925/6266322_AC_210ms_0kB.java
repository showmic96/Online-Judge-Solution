import java.util.*;
import java.math.*;

class Main{
    
    public static void main(String arg[]){
        
        Scanner sc = new Scanner(System.in);
        int i =0;
        while(sc.hasNext()){
            i++;
            int a = sc.nextInt();
            int b = sc.nextInt();
            
            if(a==0&&b==0)break;
            
            BigInteger in = new BigInteger("0");
            BigInteger total = new BigInteger("0");
            
            for(int k=0;k<a;k++){
                
                in=sc.nextBigInteger();
                total=total.add(in);
                
            }
            
            System.out.print("Bill #"+i+" costs "+total);
            total=total.divide(BigInteger.valueOf(b));
            System.out.print(": each friend should pay "+total);
            System.out.println();
            System.out.println();
        }
    }
}
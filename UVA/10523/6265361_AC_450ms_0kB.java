import java.util.*;
import java.math.*;
class Main{
    
    public static void main(String arg[]){
        
        Scanner sc = new Scanner(System.in);
        int i;
        BigInteger b = new BigInteger("0");
        //BigInteger c = new BigInteger("1");
        BigInteger d = new BigInteger("2");
        
        while(sc.hasNext()){
            i = sc.nextInt();
            b=sc.nextBigInteger();
            //c=sc.nextBigInteger();
            BigInteger c = new BigInteger("0");
            
            for(int j=1;j<=i;j++){
            d=b.pow(j);
            d=d.multiply(BigInteger.valueOf(j));
            c=c.add(d);
            
            }
            System.out.println(c);
            
            
            
            
        }
        
    }
}
import java.util.*;
import java.math.*;
class Main{
    
    public static void main(String arg[]){
        
        Scanner sc = new Scanner(System.in);
        
        BigInteger b = new BigInteger("0");
        BigInteger c = new BigInteger("17");
        
        while(sc.hasNext()){
            
            BigInteger a = new BigInteger("1");
            long k = sc.nextLong();
            //a = sc.nextBigInteger();
            for(long j=k;j>1;j--){
                
                a=a.multiply(BigInteger.valueOf(j));
            
            }
            
            String ar = a.toString();
            
            long y =0;
            
            
            char [] br = ar.toCharArray();
            
            for(int h=0;h<br.length;h++){
                
                if(br[h]=='1')y+=1;
                if(br[h]=='2')y+=2;
                if(br[h]=='3')y+=3;
                if(br[h]=='4')y+=4;
                if(br[h]=='5')y+=5;
                if(br[h]=='6')y+=6;
                if(br[h]=='7')y+=7;
                if(br[h]=='8')y+=8;
                if(br[h]=='9')y+=9;
            }
            
            
            //System.out.println(br[0]);
            System.out.println(y);
            
        }
        
    }
}
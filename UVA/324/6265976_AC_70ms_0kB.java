import java.util.*;
import java.math.*;

class Main{
    
    public static void main(String arg[]){
        
        Scanner sc = new Scanner(System.in);
        
        while(sc.hasNext()){
            
        int a = sc.nextInt();
        if(a==0)break;
        BigInteger k = new BigInteger("1");
        for(int b=1;b<=a;b++){
            k=k.multiply(BigInteger.valueOf(b));
        }
        String ar = k.toString();
        
        char [] br = ar.toCharArray();
        int count0=0,count1=0,count2=0,count3=0,count4=0,count5=0,count6=0,count7=0,count8=0,count9=0;
        for(int b=0;b<ar.length();b++){
            
            if(br[b]=='0')count0++;
            if(br[b]=='1')count1++;
            if(br[b]=='2')count2++;
            if(br[b]=='3')count3++;
            if(br[b]=='4')count4++;
            if(br[b]=='5')count5++;
            if(br[b]=='6')count6++;
            if(br[b]=='7')count7++;
            if(br[b]=='8')count8++;
            if(br[b]=='9')count9++;
        }
        
        System.out.println(a + "! --");
        System.out.println("(0)   " + count0 + "   (1)   " +count1+ "   (2)   " + count2 + "   (3)   " + count3 + "   (4)   "+count4 );
        System.out.println("(5)   " + count5 + "   (6)   " +count6+ "   (7)   " + count7 + "   (8)   " + count8 + "   (9)   "+count9 );
        
        }
        
        
    }
}
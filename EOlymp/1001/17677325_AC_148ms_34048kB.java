import java.util.*;
import java.text.*;
import java.math.*;

public class Solution {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger a = sc.nextBigInteger();
        BigInteger b = sc.nextBigInteger();
        String s1 = a.toString();
        String s2 = b.toString();

        BigInteger t1 = new BigInteger(s1 , 2);
        BigInteger t2 = new BigInteger(s2 , 2);

        t1 = t1.add(t2);
        String ans = t1.toString(2);
        System.out.println(ans);
    }
}


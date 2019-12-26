import java.util.Scanner;
 
class Main {
 
	static int Rev(int n){
		int x=n;
		int k,j=0;
		while(x!=0){
			 k=x%10;
			 j=j*10+k;
			 x/=10;
		}
		return j;
 
	}
	static boolean isPrime(int n){
		for(int i=2;i<=Math.sqrt(n);i++){
			if(n%i==0){
				return false;
			}
		}
		return true;
	}
private static Scanner in = new Scanner(System.in);
	public static void main(String[] args) {
		while(in.hasNext()){
		int n = in.nextInt();
		int m = Rev(n);
		if(isPrime(n)==true){
 
 
			if(n!=m &&  n>9 && isPrime(m)==true){
 
				System.out.println(n + " is emirp.");
			}else {
 
				System.out.println(n + " is prime.");
			}
		}
		else{
 
			System.out.println(n + " is not prime.");
		}
 
 
	}
 
}
}
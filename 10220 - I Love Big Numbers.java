package UVA_BIGINTEGER_PROBLEM;
/*
 * Uva problem solved
 * 10220 - I Love Big Numbers !
 * AC
 */
import java.math.BigInteger;
import java.util.Scanner;

class factorial {
	public static int _sum(BigInteger x){
		String s=x.toString();
		int sum=0;
		for (int i=0; i<s.length(); i++){
			int d=(int) (s.charAt(i)-'0');
			sum+=d;
		}
		return sum;
	}
	public static void main(String[] args){
		BigInteger[] fic=new BigInteger [1001];
		fic[0]=BigInteger.ZERO;
		fic[1]=BigInteger.ONE;
		
		int[] sum=new int[1001];
		
		for (int i=2; i<=1000; i++){
			fic[i]=fic[i-1].multiply(BigInteger.valueOf(i));
		}
		for (int i=0; i<=1000; i++){
			sum[i]=_sum(fic[i]);
		}
		Scanner n=new Scanner (System.in);
		while (n.hasNext()){
			int num=n.nextInt();
			System.out.println(sum[num]);
		}
		n.close();
	}
}

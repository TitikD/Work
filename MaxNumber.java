import java.util.Scanner;
public class MaxNumber {
	public static void main(String[] args) {
		int max,a,b,c;
		Scanner scan = new Scanner (System.in);
		a = scan.nextInt();
		b = scan.nextInt();
		c = scan.nextInt();
		scan.close();
		if(a>b){
			max = a;
		}else{
			max = b;
		}
		if(c>max){
			max=c;
		}
		System.out.print(max);
	}
}

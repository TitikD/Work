import java.util.Scanner;
public class ZeroCounter {
	
	//Нахождение нолей среди всех цифр в натуральном числа с помощью деления на 10 и нахождения остатка
	public int numberOfZeroes(int n){ 
		int zeroCounter = 0 ;
		while(true){
			int balance = n % 10;
			if(balance == 0){
				zeroCounter++;
			}
			n /= 10;
			if(1>n){
				break;
			}
		}
	return zeroCounter;
	}
	
	
	//Ввод данных и вызов функции numberOfZeroes.
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		scan.close();
		ZeroCounter z = new ZeroCounter();
		int zeroCounter = z.numberOfZeroes(n);
		System.out.println(zeroCounter);
	}
}

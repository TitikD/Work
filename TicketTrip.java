import java.util.Scanner;
public class TicketTrip {
	
	//Поиск выгодного варианта для покупки билетов по 60, 10, 1 штук в наборе, по цене 440, 125, 15 соответственно.
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		scan.close();	
		int	balance60Kit = n%60; 				
		n -= balance60Kit;  			
		int	answer60Kit = n/60;			
		if(balance60Kit>=35){					//Выгоднее будет купить 35 билетов по цене 60
			answer60Kit++;			
			balance60Kit=0;			
		}
		int balance10Kit = balance60Kit%10;
		n = balance60Kit-balance10Kit;
		int answer10Kit = n/10;
		if(balance10Kit>=9){					//Выгодней будет купить 9 билетов по цене 10
			answer10Kit++;
			balance10Kit = 0;
		}
		System.out.print(balance10Kit+" ");		//Остаток от набора по 10 билетов является ответом для кол-во набора по 1
		System.out.print(answer10Kit+" ");
		System.out.print(answer60Kit);	
	}
}

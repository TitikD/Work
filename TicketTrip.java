import java.util.Scanner;
public class TicketTrip {
	
	//����� ��������� �������� ��� ������� ������� �� 60, 10, 1 ���� � ������, �� ���� 440, 125, 15 ��������������.
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		scan.close();	
		int	balance60Kit = n%60; 				
		n -= balance60Kit;  			
		int	answer60Kit = n/60;			
		if(balance60Kit>=35){					//�������� ����� ������ 35 ������� �� ���� 60
			answer60Kit++;			
			balance60Kit=0;			
		}
		int balance10Kit = balance60Kit%10;
		n = balance60Kit-balance10Kit;
		int answer10Kit = n/10;
		if(balance10Kit>=9){					//�������� ����� ������ 9 ������� �� ���� 10
			answer10Kit++;
			balance10Kit = 0;
		}
		System.out.print(balance10Kit+" ");		//������� �� ������ �� 10 ������� �������� ������� ��� ���-�� ������ �� 1
		System.out.print(answer10Kit+" ");
		System.out.print(answer60Kit);	
	}
}

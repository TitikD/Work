import java.util.Scanner;
public class Triangle {
	
	//���������, ���������� �� ����������� � ����� ������� ���������.
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int a = scan.nextInt();
		int b = scan.nextInt();
		int c = scan.nextInt();
		scan.close();
		
		// �������� ����� ���� ������ ������ ���� ������ ������� ������� ��� �������� ������������.
		if(a+b>c && a+c>b && b+c>a){			
			System.out.print("YES");
		}else{
			System.out.print("NO");
		}

	}
}

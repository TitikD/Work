import java.util.Scanner;
public class MaximumNumber {
	
	//���������� �������� ����� �� 3 ���������.
	public static void main(String[] args) {
		Scanner scan = new Scanner (System.in);
		int a = scan.nextInt();
		int b = scan.nextInt();
		int c = scan.nextInt();
		scan.close();
		int[]x = {a, b, c};
		int maxNumber = (int)Double.NEGATIVE_INFINITY;
		
		//������� ��������� ������� � ������������ �������� maxNumber.
		for(int i = 0;i<x.length;i++){
			if(maxNumber<x[i]){						
				maxNumber=x[i];
			}
		}
		System.out.println(maxNumber);
	}
}
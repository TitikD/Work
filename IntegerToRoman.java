import java.util.Scanner;
public class IntegerToRoman {
	
		//Конвертер арабских в римские цифры до 100
		public static void main(String[] args){
			Scanner scan = new Scanner(System.in);
			int x = scan.nextInt();
			scan.close();
		    String answer = "";	
		    
		    //От вводимого значение отнимается найбольшая ближайшая замена арабских чисел и добавление соответствубщей римской.  
		    while(x == 100){
		    	answer += "C";
		    	x -= 100;
		    }
		    while(x>=90){
		    	answer+="XC";
		    	x-=90;
		    }
		    while(x >= 50){
		    	answer += "L";
		    	x -= 50;
		    }
		    while(x >= 40){
		    	answer += "XL";
		    	x -= 40;
		    }
		    while(x >= 10 ){
		    	answer += "X";
		    	x -= 10;
		    }
		    while(x >= 9){
		    	answer += "IX";
		    	x -= 9;
		    }
		    while(x >= 5){
		    	answer += "V";
		    	x -= 5;
		    }
		    while(x >= 4){
		    	answer += "IV";
		    	x -= 4;
		    }
		    while( x>=1 ){
		    	answer += "I";
		    	x -= 1;
		    }	   
		    System.out.println(answer);
	}	
}

import java.util.Scanner;

public class unit1_HW1 {

	public static void main(String[] args) {
		
		int crn1, crn2, credits1, credits2;
		String studentId;
		String studentName;
		String class1;
		String [] items1;
		String [] items2;
		String class2;
		Scanner myScan = new Scanner (System.in);
		
		
		System.out.println("Enter the Student's Id: ");
		studentId = myScan.nextLine();
		
		System.out.println("Enter the Student's full name: ");
		studentName = myScan.nextLine();
		
		System.out.println("Enter crn/credit hours for the first class(like 5665/3): ");
		class1 = myScan.nextLine();
		items1 = class1.split("/");
		crn1 = Integer.parseInt(items1[0]);
		credits1 = Integer.parseInt(items1[1]);
		
		System.out.println("Enter crn/credit hours for the second class(like 5665/3): ");
		class2 = myScan.nextLine();
		items2 = class2.split("/");
		crn2 = Integer.parseInt(items2[0]);
		credits2 = Integer.parseInt(items2[1]);
		
		double money1, money2;
		money1 = 120.25*credits1;
		money2 = 120.25*credits2;
		
		System.out.println("Thank you!");
		System.out.println("Fee invoice prepared for: "+studentName+"\n");
		System.out.println("\tSIMPLE COLLEGE\n\tORLANDO FL 10101");
		System.out.println("\t***************************\n");
		System.out.println("\tFee Invoice Prepared for:\n\t["+studentName+"]["+studentId+"]\n");
		System.out.println("\t1 Credit Hour = $120.25\n\n\tCRN\tCredit Hours");
		System.out.println("\t"+crn1+"\t"+credits1+"\t\t\t$"+money1);
		System.out.println("\t"+crn2+"\t"+credits2+"\t\t\t$"+money2);
		System.out.println("\t\tHealth & id fees\t$35.00");
		System.out.println("\t_________________________________________");
		System.out.println("\t\tTotal Payments\t$"+(35+money1+money2));
	}

}

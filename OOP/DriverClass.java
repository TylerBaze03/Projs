<<<<<<< HEAD
import java.util.ArrayList;
import java.util.Arrays;
//Tyler Bazemore
//COP 3330-23 FALL 0V03
//Unit4_HW2
// 9/13/2023
public class DriverClass {
	public static void main(String[] args) {
		
		String fullName = "Erika T. Jones";
		String employeeNumber = "ej789";
		double payRate = 100.0, hoursWorked = 1.0;
		// TA will change the payrate and the hours worked to test your code
		
		Employee e;
		e = new Employee(fullName, employeeNumber, payRate, hoursWorked);
		
		System.out.println(e); // To Test your to String method
		
		e.printCheck(); // This prints the check of Erika T. Jones
		
		
		Company company = new Company();
		company.hire ( new Employee ("Saeed Happy", "sh895" , 2 , 200) );
		company.hire (e);
		//Company.printCompanyInfo();
		

		company.hire( new Employee("Enrico Torres" , "et897" , 3 , 150) );
		
		
		//You may add as many employees to company as you want.
		//The TAs will add their own employees
		//Make sure that each employee of company has a unique employeeNumber
		
		
		company.printCheck("ab784");
		
		
		company.deleteEmployeesBySalary(256.36);
		
		
		company.reverseEmployees();
		
		
		System.out.println(company.SearchByName("WaLiD WiLLiAms") );
		
		
		company.printEmployees();
		
		System.out.println("Bye!");
	}
}
//____________________________
class Employee{
	private String fullName;
	private String employeeNumber;
	private double payRate;
	private double hoursWorked;
	
	public Employee (String aName, String empNum, double pay, double hours) {
		fullName = aName;
		employeeNumber = empNum;
		payRate = pay;
		hoursWorked = hours;
	}
	public String getName() {
		return fullName;
	}
	public String getNumber() {
		return employeeNumber;
	}
	public double getPay() {
		return payRate;
	}
	public double getHours() {
		return hoursWorked;
	}
	public void printCheck() {
		System.out.println("-------------------------------------------------");
		System.out.println("\tEmployee's name:\t"+fullName);
		System.out.println("\tEmployee's number:\t"+employeeNumber);
		System.out.println("\tHourly rate of pay:\t"+payRate+"\n");
		System.out.println("\tTotal Gross Pay:\t$"+(payRate*hoursWorked)+"\n");
		System.out.println("\tDeductions\n");
		System.out.println("\tTax (6%):\t\t$"+((payRate*hoursWorked) * .94)+"\n");
		System.out.println("\tNet Pay:\t\t"+((payRate*hoursWorked) - ((payRate*hoursWorked)*.6))+ " Dollars");
		System.out.println("-------------------------------------------------");
	}
	public String toString() {
		return "[" + employeeNumber + "/" + fullName + ", " + hoursWorked + " Hours @ " + payRate + " per hour]";
	}
	
}
//____________________________
class Company {
	private ArrayList<Employee> employeeList;
	private String companyName;
	private static String companyTaxId;
//Add static Setters and Getters for companyTaxId. We assume that
//all companies share the same companyTaxId and that may change
//Add Setter and Getter for the companyName
//No need to add a Setter and Getter for employeeList
	public Company() {
		employeeList = new ArrayList<Employee>();
		companyName = "People's Place";
		companyTaxId = "v1rtua7C0mpan1";
	}
	public boolean hire ( Employee employee ) {
		for (int i = 0;i< employeeList.size();i++) {
			//employee.employeeNumber : employeeList
			if (employeeList.get(i).getNumber() == (employee.getNumber())) {
				return false;
				
			}
		}
//Add empoyee to employeeList
//Note well that we can't add an employee whose employeeNumber already 
//assigned to another employee. In that case, this method returns false.
//This method returns true otherwise
		employeeList.add(employee);
		return true;
	}
	public void printCompanyInfo() {
		System.out.println("Company Name:" + companyName + " Tax Id: " + companyTaxId + " Number of employees: " + employeeList.size());
//This method prints the compay name, the tax id and the current number //of employees
//You may choose to print that any way you like!
	}
	public void printEmployees() {
		for (int i = 0;i < employeeList.size();i++) {
			System.out.println(employeeList.get(i).toString());
		}
//This methods prints all employees (One employee per line)
//Note that you already havetoString in Employye
	}
	public int countEmployees( double maxSalary ) {
		int underPay = 0;
		for(int i = 0; i < employeeList.size();i++ ) {
			if (employeeList.get(i).getPay() < maxSalary) {
				underPay++;
			}
		}
		return underPay;
//This method returns the number of employees paid less than maxSalary
	}
	public boolean SearchByName (String fullName ) {
		for (int i = 0; i < employeeList.size();i++) {
			if (employeeList.get(i).getName() == fullName) {
				return true;
			}
		}
		return false;
//This method returns true if fullName exists as an employee.
//It returns false otherwise
//this is a not a case sensitive search.
	}
	public void reverseEmployees () {
		int j = employeeList.size() - 1;
		Employee tmp;
		for (int i = 0; i < j; i++) {
			tmp = employeeList.get(i);
			employeeList.set(i, employeeList.get(j));
			employeeList.set(j, tmp);
			j--;
		}
//This method reverses the order in which the employees were added to 
//the list.The last employee is swapped with the first employee, the 
//second last with the secondand so on..
	}
	public void deleteEmployeesBySalary (double targetSalary ) {
		for (int i = 0; i < employeeList.size();i++) {
			if (employeeList.get(i).getPay() == targetSalary) {
				employeeList.remove(i);
			}
		}
//This method deletes all employees who are paid targetSalary as a net //salary
	}
	public void printCheck ( String employeeNumber) {
		for (int i = 0; i < employeeList.size(); i++) {
			//System.out.println(employeeList.get(i).getNumber());
			if (employeeNumber == employeeList.get(i).getNumber()) {
				employeeList.get(i).printCheck();
			}
		}
	
//This method prints the check of the employee whose employee number is
//employeeNumber. It prints NO SUCH EMPLOYEE EXISTS if employeeNumber is 
//not a registered employee number.
	}
=======
import java.util.ArrayList;
import java.util.Arrays;
//Tyler Bazemore
//COP 3330-23 FALL 0V03
//Unit4_HW2
// 9/13/2023
public class DriverClass {
	public static void main(String[] args) {
		
		String fullName = "Erika T. Jones";
		String employeeNumber = "ej789";
		double payRate = 100.0, hoursWorked = 1.0;
		// TA will change the payrate and the hours worked to test your code
		
		Employee e;
		e = new Employee(fullName, employeeNumber, payRate, hoursWorked);
		
		System.out.println(e); // To Test your to String method
		
		e.printCheck(); // This prints the check of Erika T. Jones
		
		
		Company company = new Company();
		company.hire ( new Employee ("Saeed Happy", "sh895" , 2 , 200) );
		company.hire (e);
		//Company.printCompanyInfo();
		

		company.hire( new Employee("Enrico Torres" , "et897" , 3 , 150) );
		
		
		//You may add as many employees to company as you want.
		//The TAs will add their own employees
		//Make sure that each employee of company has a unique employeeNumber
		
		
		company.printCheck("ab784");
		
		
		company.deleteEmployeesBySalary(256.36);
		
		
		company.reverseEmployees();
		
		
		System.out.println(company.SearchByName("WaLiD WiLLiAms") );
		
		
		company.printEmployees();
		
		System.out.println("Bye!");
	}
}
//____________________________
class Employee{
	private String fullName;
	private String employeeNumber;
	private double payRate;
	private double hoursWorked;
	
	public Employee (String aName, String empNum, double pay, double hours) {
		fullName = aName;
		employeeNumber = empNum;
		payRate = pay;
		hoursWorked = hours;
	}
	public String getName() {
		return fullName;
	}
	public String getNumber() {
		return employeeNumber;
	}
	public double getPay() {
		return payRate;
	}
	public double getHours() {
		return hoursWorked;
	}
	public void printCheck() {
		System.out.println("-------------------------------------------------");
		System.out.println("\tEmployee's name:\t"+fullName);
		System.out.println("\tEmployee's number:\t"+employeeNumber);
		System.out.println("\tHourly rate of pay:\t"+payRate+"\n");
		System.out.println("\tTotal Gross Pay:\t$"+(payRate*hoursWorked)+"\n");
		System.out.println("\tDeductions\n");
		System.out.println("\tTax (6%):\t\t$"+((payRate*hoursWorked) * .94)+"\n");
		System.out.println("\tNet Pay:\t\t"+((payRate*hoursWorked) - ((payRate*hoursWorked)*.6))+ " Dollars");
		System.out.println("-------------------------------------------------");
	}
	public String toString() {
		return "[" + employeeNumber + "/" + fullName + ", " + hoursWorked + " Hours @ " + payRate + " per hour]";
	}
	
}
//____________________________
class Company {
	private ArrayList<Employee> employeeList;
	private String companyName;
	private static String companyTaxId;
//Add static Setters and Getters for companyTaxId. We assume that
//all companies share the same companyTaxId and that may change
//Add Setter and Getter for the companyName
//No need to add a Setter and Getter for employeeList
	public Company() {
		employeeList = new ArrayList<Employee>();
		companyName = "People's Place";
		companyTaxId = "v1rtua7C0mpan1";
	}
	public boolean hire ( Employee employee ) {
		for (int i = 0;i< employeeList.size();i++) {
			//employee.employeeNumber : employeeList
			if (employeeList.get(i).getNumber() == (employee.getNumber())) {
				return false;
				
			}
		}
//Add empoyee to employeeList
//Note well that we can't add an employee whose employeeNumber already 
//assigned to another employee. In that case, this method returns false.
//This method returns true otherwise
		employeeList.add(employee);
		return true;
	}
	public void printCompanyInfo() {
		System.out.println("Company Name:" + companyName + " Tax Id: " + companyTaxId + " Number of employees: " + employeeList.size());
//This method prints the compay name, the tax id and the current number //of employees
//You may choose to print that any way you like!
	}
	public void printEmployees() {
		for (int i = 0;i < employeeList.size();i++) {
			System.out.println(employeeList.get(i).toString());
		}
//This methods prints all employees (One employee per line)
//Note that you already havetoString in Employye
	}
	public int countEmployees( double maxSalary ) {
		int underPay = 0;
		for(int i = 0; i < employeeList.size();i++ ) {
			if (employeeList.get(i).getPay() < maxSalary) {
				underPay++;
			}
		}
		return underPay;
//This method returns the number of employees paid less than maxSalary
	}
	public boolean SearchByName (String fullName ) {
		for (int i = 0; i < employeeList.size();i++) {
			if (employeeList.get(i).getName() == fullName) {
				return true;
			}
		}
		return false;
//This method returns true if fullName exists as an employee.
//It returns false otherwise
//this is a not a case sensitive search.
	}
	public void reverseEmployees () {
		int j = employeeList.size() - 1;
		Employee tmp;
		for (int i = 0; i < j; i++) {
			tmp = employeeList.get(i);
			employeeList.set(i, employeeList.get(j));
			employeeList.set(j, tmp);
			j--;
		}
//This method reverses the order in which the employees were added to 
//the list.The last employee is swapped with the first employee, the 
//second last with the secondand so on..
	}
	public void deleteEmployeesBySalary (double targetSalary ) {
		for (int i = 0; i < employeeList.size();i++) {
			if (employeeList.get(i).getPay() == targetSalary) {
				employeeList.remove(i);
			}
		}
//This method deletes all employees who are paid targetSalary as a net //salary
	}
	public void printCheck ( String employeeNumber) {
		for (int i = 0; i < employeeList.size(); i++) {
			//System.out.println(employeeList.get(i).getNumber());
			if (employeeNumber == employeeList.get(i).getNumber()) {
				employeeList.get(i).printCheck();
			}
		}
	
//This method prints the check of the employee whose employee number is
//employeeNumber. It prints NO SUCH EMPLOYEE EXISTS if employeeNumber is 
//not a registered employee number.
	}
>>>>>>> b756d6d (Updating repositroy using git)
}//end of class Company
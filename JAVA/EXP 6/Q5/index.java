import java.util.Scanner;
class Employee{
	int empid;
    String name;
    double salary;
    Employee(){
    	System.out.println("This is employee default constructor");
    }

   Employee(int emid,String name,double salary){
	   this.empid = emid;
	   this.name = name;	   
	   this.salary = salary;
   }
    String name()
   {
	  return name;
   }
    double salary()
    {
    	return salary;
    }
    void increase_salary(int i) {
    	double x;
    	x=((salary*i)/100)+salary;
       System.out.print("Increased salary ="+" "+x);
   }
   
}
class Manager extends Employee{
	String department;
	Manager(int e,String n,double sal,String d){
		super(e,n,sal);
		department = d;
	}
	void display() {
		Scanner sc=new Scanner(System.in);
		 System.out.println("Name of the employee"+" "+super.name());
		   System.out.println("salary of a employee"+" "+super.salary());		
		System.out.print("department is"+ " "+ department+"\n");
		System.out.println("Enter the percentage by which a salary is to be increased");
	    int ps=sc.nextInt();
		super.increase_salary(ps);
		
	}
	
}
public class index {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the name of the employee");
		String name=sc.nextLine();
		System.out.println("Enter the id of the employee");
		int id=sc.nextInt();
		System.out.println("Enter the salary of the employee");
		double sal=sc.nextDouble();
		Manager M = new Manager(id,name,sal,"CS");
		M.display();
		
   }
}

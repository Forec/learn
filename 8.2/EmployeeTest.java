/**
 * @author Forec_
 * used to test personal class
 */

package date_8_2;

public class EmployeeTest {
	public static void main(String[]args){
		Employee[]staff = new Employee[3];
		staff[0] = new Employee("Carl Cracker",75000,1987,12,15);
		staff[1] = new Employee();
		staff[2] = new Employee("Tony fuck",5000,1990,3,15);
		for (Employee e:staff)
			e.raiseSalary(100);
		for (Employee e:staff)
			System.out.println("name="+e.getName()+",salary="+e.getSalary()+",hireDay="
					+e.getHireDay()+",id="+e.getID());
	}
}

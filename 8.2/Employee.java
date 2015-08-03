/**
 * define class Employee
 */

package date_8_2;

import java.util.*;

class Employee {
	private String name;
	private double salary;
	private Date hireday;
	private int id;
	/**
	 * store id
	 */
	private static int nextID = 0;

	{
		id = ++nextID;
	}
	/**
	 * @see date_8_2.Employee#raiseSalary(double)
	 * @see <a href ="http://github.com/forec/learn">Store in github</a>
	 */
	
	public Employee(){
		name = "undefine";
		salary = 0 ;
		hireday = new Date();
	}
	public Employee(String n,double s,int year,int month,int day){
		name = n;
		salary = s;
		GregorianCalendar calendar = new GregorianCalendar(year,month-1,day);
		hireday = calendar.getTime();
	}
	public String getName(){
		return name;
	}
	public double getSalary(){
		return salary;
	}
	public Date getHireDay(){
		return hireday;	//   This method is not safe
	//	return hireday.clone();
	}
	/**
	 * Raise the salary of an employee
	 * @param byPercent the percentage by which to raise the salary
	 * @return the amout of the raise
	 */
	public void raiseSalary(double byPercent){
		salary +=( salary * byPercent/100 );
	}
	public int getID(){
		return id;
	}
	public void setID(int id){
		this.id = id;
	}
}

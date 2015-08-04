package date_8_4;

import java.util.Date;
import java.lang.Object;

class Employee implements Comparable<Employee> , Cloneable{		// 实现接口Comparable
	private String name;
	private String work;
	private int salary;
	private Date hireday;
	private int id = ++nextID;
	private static int nextID = 0;
	public Employee(){
		name = "undefined";
		work = "none";
		salary = 0;
		hireday = new Date();
	}
	public Employee(String name,String work,int salary,Date hireday){
		this.name = name;
		this.work = work;
		this.salary = salary;
		this.hireday = hireday;
	}
	public String getName(){
		return name;
	}
	public String getWork(){
		return work;
	}
	public Date getHireday(){
		return (Date)hireday.clone();
	}
	public int getID(){
		return id;
	}
	public void setID(int id){
		this.id = id;
	}
	public String toString(){
		return "name="+name+",id="+id+",work="+work+",salary="+salary+",hireday="+hireday;
	}
	public boolean equals(Object otherObject){
		if (this == otherObject)
			return true;
		if (otherObject == null)
			return false;
		if (getClass()!=otherObject.getClass())
			return false;
		Employee other = (Employee)otherObject;
		return name.equals(other.name) && work.equals(other.work) && salary == other.salary 
				&& hireday.equals(other.hireday);
	}
	public int hashCode(){
		return (7*name.hashCode()+13*work.hashCode()+11*salary+17*hireday.hashCode())%10000;
	}
	public int compareTo(Employee other){
		return id - other.id;
	}
	public Employee clone()throws CloneNotSupportedException{
		Employee cloned =  (Employee) super.clone();
		cloned.hireday = (Date)hireday.clone();
		return cloned;
	}
	/**
	 * 要谨慎对待子类克隆，一旦为Employee类定义clone方法，任何人都可以使用它克隆Manager对象，可能发生错误。
	 * 所以将Object类中的clone声明为protected。
	 * 如果想让用户调用clone则覆盖为public方法。
	 */
}
/**
 * @author Forec_
 * test abstract class
 */

package date_8_3;

public class TestPerson {
	public static void main(String []args){
		Person[] stus = new Person[4];
		stus[0] = new Student("forec","network");
		stus[1] = new Student("chang","security");
		stus[2] = new Employee();
		stus[3] = new Manager("ming","secratry",10,2015,8,1,10);
		System.out.println(stus[0] instanceof Person);
		System.out.println(stus[2] instanceof Manager);
		for (Person p: stus)
			System.out.println("name = "+p.getName()+", "+p.getDescription());
		System.out.println(stus[3]);
	//	System.out.println(((Manager)stus[3]).getSalary());
	}
}

/**
 * equals: (using @Override to point out)
 * 1.equals(Object otherObject){}
 * 2.this == otherObject ?
 * 3.otherObject == null ?
 * 4.getClass() == otherObject.getClass() ?
 * 5.Classname other = (Classname) otherObject
 * 		return field1 = other.field1 && ... ;
 * *For array types , using Arrays.equals()
 */

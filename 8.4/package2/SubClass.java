package package2;
import package1.SuperClass;

public class SubClass extends SuperClass {
	public static void main(String[]args){
	//	SuperClass sup = new SuperClass();
		SubClass sub = new SubClass();
		sub.method();
	/**	sup.method();  
	 * 
	 * 类SubClass确实是继承了类SuperClass（包括它的method方法）,
	 * 所以在类SubClass中可以调用自己的method方法。
	 * 但类SuperClass的protected方法对其不同包子类SubClass来说是不可见的
	 */
	}
}

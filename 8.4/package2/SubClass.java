package package2;
import package1.SuperClass;

public class SubClass extends SuperClass {
	public static void main(String[]args){
	//	SuperClass sup = new SuperClass();
		SubClass sub = new SubClass();
		sub.method();
	/**	sup.method();  
	 * 
	 * ��SubClassȷʵ�Ǽ̳�����SuperClass����������method������,
	 * ��������SubClass�п��Ե����Լ���method������
	 * ����SuperClass��protected�������䲻ͬ������SubClass��˵�ǲ��ɼ���
	 */
	}
}

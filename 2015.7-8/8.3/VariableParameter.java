/**
 * @author Forec_
 * ���Խ��Ѿ����������һ������������ķ������¶���Ϊ�ɱ�����ķ���
 * �����ƻ��Ѿ����ڵĴ���
 */
package date_8_3;

public class VariableParameter {
	public static double max(double...values){
		double largest = Double.NEGATIVE_INFINITY;
		for (double v:values)
			if (v>largest)
				largest = v;
		return largest;
	}
	public static void main(String ...args){   // ����һ�����鴫�ݸ��ɱ�������������һ������
		System.out.println(max(11,2,45,12,432,5,342,0.4,4,43,5,-2.4,24,-33.2,412,3,21));
		System.out.printf("%d %s",new Object[]{new Integer(1),"widgets"});
		/**
		 * printf��ʵ�֣�
		 * public class PrintStream{
		 * 	public PrintStream printf(String fmt, Object...args){return format(fmt,args);}}
		 * ������������һ��Ϊ��ʽ�ַ�����һ��ΪObject[]����
		 */
	}
}


/**
 * @author Forec_
 * 可以将已经存在且最后一个参数是数组的方法重新定义为可变参数的方法
 * 不会破坏已经存在的代码
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
	public static void main(String ...args){   // 允许将一个数组传递给可变参数方法的最后一个参数
		System.out.println(max(11,2,45,12,432,5,342,0.4,4,43,5,-2.4,24,-33.2,412,3,21));
		System.out.printf("%d %s",new Object[]{new Integer(1),"widgets"});
		/**
		 * printf的实现：
		 * public class PrintStream{
		 * 	public PrintStream printf(String fmt, Object...args){return format(fmt,args);}}
		 * 共两个参数，一个为格式字符串，一个为Object[]数据
		 */
	}
}


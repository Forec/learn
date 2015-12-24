package date_8_9;

public class StaticInnerClass {
	public static void main(String []args){
		double [] d = {11,23.4,3,5,-1};
		ArrayAlg.Pair p =ArrayAlg.minmax(d);
	//	Pair a = new Pair(1,2);   error
	//	Test a = new Test();      error
	//	TimePrinter a = new TimePrinter();   right? Because there's a public class(also named TimePrinter in Review.java
		System.out.println("min = "+p.getFirst());
		System.out.println("max = "+p.getSecond());
	}
}

class ArrayAlg{
	public static Pair minmax(double[] values){
		double min = Double.MAX_VALUE;
		double max = Double.MIN_VALUE;
		for (double v:values){
			if (min>v) min = v;
			if (max <v) max = v;
		}
		return new Pair(min,max);
	}
	public static class Pair{   // Must be static because Pair is built in static method "minmax"
		private double first;
		private double second;
		public Pair(double f,double s){
			first =f;
			second = s;
		}
		public double getFirst(){
			return first;
		}
		public double getSecond(){
			return second;
		}
	}
	public class Test{
		private int t = 0;
		public Test(){
			t = 1;
		}
		public int getT(){
			return t;
		}
	}
}
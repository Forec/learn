/**
 * @author from yeohcooller
 * test the authority of protected
 */
package package2;  
      
    import package1.SuperClass;  
      
    public class SubClass1 extends SuperClass {  
        public static void main(String[] args) {  
            SubClass1 sub1 = new SubClass1();  
   //         SubClass2 sub2 = new SubClass2();  
            sub1.method();  //Compile OK  
            /**
            *sub2.method();  //Compile Error  
            */
        }  
      
    }  
    class SubClass2 extends SuperClass{  
    	/**
          *protected void method(){
          *super.method();
          *}
          *	Add these codes and sub2.method() will be right
          * 不能在一个子类中访问另一个子类的protected方法，尽管这两个子类继承自同一个父类。
          */
    }  
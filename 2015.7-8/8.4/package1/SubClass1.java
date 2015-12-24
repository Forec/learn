package package1;

public class SubClass1 extends SuperClass {  
    public static void main(String[] args) {  
        SuperClass sup = new SuperClass();  
        SubClass1 sub1 = new SubClass1();  
        SubClass2 sub2 = new SubClass2();  
        sup.method();  //Compile OK  
        sub1.method();  //Compile OK  
        sub2.method();  //Compile OK  
    }  
}  
class SubClass2 extends SuperClass{  
      
}  
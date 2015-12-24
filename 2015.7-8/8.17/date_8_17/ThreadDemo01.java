package date_8_17;


public class ThreadDemo01 {

	public static void main(String[] args) {
		//		MyThread t1 = new MyThread("thread A");
		//		MyThread t2 = new MyThread("thread B");
		//		t1.run();
		//		t2.run();
		//		// 线程的启动通过start启动
		//		t1.start();
		//		t2.start();
		//	
		MyRunnable r1 = new MyRunnable("A");
		MyRunnable r2= new MyRunnable("B");
		Thread t1 = new Thread(r1);
		Thread t2 = new Thread(r2);
		t1.start();
		t2.start();
	}
}

class MyThread extends Thread{
	private String name;

	public MyThread(String name){
		this.name = name;
	}
	public void run() {
		for (int i = 0 ; i< 10; i ++)
			System.out.println(name+":"+i);
		super.run();
	}
}

class MyRunnable implements Runnable{
	private String name;
	public MyRunnable(String name){
		this.name = name;
	}
	public void run(){
		for (int i = 0; i< 10;i++)
			System.out.println(name+":"+i);
	}
}

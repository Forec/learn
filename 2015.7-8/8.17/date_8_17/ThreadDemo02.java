package date_8_17;

class RunnableDemo implements Runnable{
		private String name;
		public RunnableDemo(String name) {
			this.name = name;
		}
		public void run(){
			for (int i  = 0 ; i < 50 ; i++)
			{
//				try {
//					Thread.sleep(1000);
//				} catch (InterruptedException e) {
//					e.printStackTrace();
//				}
				System.out.println(name+":"+i);
				if ( i == 10){
					System.out.println("礼让");
					Thread.yield();
				}
			}
		}
}


public class ThreadDemo02 {
	public static void main(String[] args) {
		RunnableDemo r1 = new RunnableDemo("A");
		RunnableDemo r2 = new RunnableDemo("B");
		Thread t1 = new Thread(r1);
		Thread t2 = new Thread(r2);
//		System.out.println(t1.isAlive());
		t1.start();
		t2.start();
		try {
			t2.sleep(10);
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
//		for (int i = 0 ;i  <50;i++){
//			if (i>10){
//				try{
//					t1.join();
//				}catch(InterruptedException e){
//					e.printStackTrace();
//				}
//			}
//			System.out.println("主线程："+i);
//		}
//		System.out.println(t1.isAlive());
//		t2.start();
		
	}
}

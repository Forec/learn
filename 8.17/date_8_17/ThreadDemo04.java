package date_8_17;

class MythreadDemo implements Runnable{
	
	private int ticket = 5;
	
	public void run(){
		for (int i = 0 ; i <10;i++){
			tell();
		}
	}
	public synchronized void tell(){
		if (ticket>0){
				try {
					Thread.sleep(500);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
				System.out.println("车票："+ticket--);
			}
	}
}

public class ThreadDemo04 {
	public static void main(String[] args) {
		MythreadDemo mythreadDemo = new MythreadDemo();
		Thread t1 = new Thread(mythreadDemo);
		Thread t2 = new Thread(mythreadDemo);
		Thread t3 = new Thread(mythreadDemo);
		t1.start();
		t2.start();
		t3.start();
	}
}

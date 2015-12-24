package date_8_10;

import java.awt.*;
import javax.swing.*;

public class SimpleFrameTest {
	public static void main(String[]args){
		EventQueue.invokeLater(new Using(100,100));
		EventQueue.invokeLater(new Using(500,400));
	}
}

class Using implements Runnable{
	private int location_x = 0;
	private int location_y = 0;
	private boolean isLocationSet;
	{
		isLocationSet = false;
	}
	public Using(int x,int y){
		location_x = x;
		location_y = y;
		boolean isLocationSet = true;
	}
	public void run(){
		SimpleFrame frame = new SimpleFrame();
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setTitle("Himiss");
		frame.setResizable(false);			//是否可以改变窗口大小
//		frame.setLocation(500,500);			//初始化窗口位置
		if (!isLocationSet)
			frame.setLocationByPlatform(true);	//是否由系统决定窗口位置
		else {
			frame.setLocationByPlatform(false);
			frame.setLocation(location_x,location_y);
		}
//		frame.setExtendedState(Frame.MAXIMIZED_BOTH);   //初始化窗口最大
//		frame.setUndecorated(false);	//设置是否显示标题栏,关闭按钮等装饰,false显示
//		frame.toBack();
		frame.setVisible(true);				
		System.out.println(System.getProperty("user.dir"));
	}
}

class SimpleFrame extends JFrame{
	private int DEFAULT_WIDTH ;
	private int DEFAULT_HEIGHT;
	public SimpleFrame(){
		Toolkit kit = Toolkit.getDefaultToolkit();
		Dimension screensize = kit.getScreenSize();
		DEFAULT_WIDTH = screensize.width/2;
		DEFAULT_HEIGHT = screensize.height/2;
		setSize(DEFAULT_WIDTH,DEFAULT_HEIGHT);
		Image img = new ImageIcon("icon.gif").getImage();
		setIconImage(img);
		add(new MyComponent());
		pack();
	}
}

class MyComponent extends JComponent{
	public static final int Message_x = 75;
	public static final int Message_y = 100;
	public static final int DEFAULT_WIDTH = 500;
	public static final int DEFAULT_HEIGHT = 400;
	public void paintComponent(Graphics g){
		g.drawString("testMessage , Hello world",Message_x,Message_y);
	}
	@Override public Dimension getPreferredSize(){
		return new Dimension(DEFAULT_WIDTH,DEFAULT_HEIGHT);
	}
}
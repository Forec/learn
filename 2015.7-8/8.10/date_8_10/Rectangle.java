package date_8_10;

import java.awt.*;
import java.awt.geom.*;
import javax.swing.*;

public class Rectangle {
	public static void main(String []args){
		EventQueue.invokeLater(new Runs());
	}
}

class Runs implements Runnable{
	public void run(){
		MyFrame test = new MyFrame();
		test.setLocation(400,400);
		test.setSize(300,300);
		test.setTitle("Hello Rect");
		Image img = new ImageIcon("icon.gif").getImage();
		test.setIconImage(img);
		test.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		test.setVisible(true);
	}
}

class MyFrame extends JFrame{
	public MyFrame(){
		add(new MyComp());
	//	add(new MyCompLine());
		pack();
	}
}

class MyComp extends JComponent{
	public void paintComponent(Graphics g){
		Graphics2D g2 = (Graphics2D)g;
		Rectangle2D newrec = new Rectangle2D.Float(20.0F,20.0F,100F,50F);
		g2.draw(newrec);
		System.out.println("MyComp has been drawed");
		g2.setPaint(Color.RED);
		g2.drawString("testsecond",25,25);
	}
	@Override public Dimension getPreferredSize(){
		return new Dimension(100,50);
	}
}

class MyCompLine extends JPanel{
	public void paintComponent(Graphics g){
		super.paintComponent(g);
		Graphics2D g2 = (Graphics2D)g;
		Ellipse2D newell = new Ellipse2D.Float(20.0F,20.0F,100F,50F);
		g2.draw(newell);
		Point2D p1 = new Point2D.Float(70F,45F);
		Point2D p2 = new Point2D.Float(120F,75F);
		Line2D line = new Line2D.Float(p1,p2);
		g2.draw(line);
		System.out.println("MyCompLine has been drawed");
	}
	@Override public Dimension getPreferredSize(){
		return new Dimension(200,300);
	}
}
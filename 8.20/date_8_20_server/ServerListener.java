package date_8_20_server;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;


//import javax.swing.JOptionPane;

public class ServerListener extends Thread {

	private ServerSocket serverSocket;

	static int count = 1;
	public void run(){
		try{
			serverSocket = new ServerSocket(12345);
			while (true){
				Socket socket = serverSocket.accept();
				ChatSocket cs = new ChatSocket(socket);
				cs.setCount(count);
				ChatManager.getChatManager().add(cs);
				cs.start();
				socket.getOutputStream().write(((count++)+"号客户端成功连入\n").getBytes("UTF-8"));
			}	
		}
		catch(IOException e){
			e.printStackTrace();
		}
	}
}
package date_8_20_server;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.UnsupportedEncodingException;
import java.net.Socket;


public class ChatSocket extends Thread {
	Socket socket;
	int count;
	public void setCount(int count) {
		this.count = count;
	}
	public ChatSocket(Socket s){
		this.socket = s;
	}
	public void out(String out){
		try {
			socket.getOutputStream().write(out.getBytes("UTF-8"));
		} catch (UnsupportedEncodingException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	public void run(){
		try {
			BufferedReader br = new BufferedReader(
									new InputStreamReader(
											socket.getInputStream(),"UTF-8"));

			String line = null;
			while ((line=br.readLine())!=null){
				ChatManager.getChatManager().publish(this, "客户端"+count+":"+line+"\n");
				System.out.println("客户端"+count+":"+line);
			}	
			br.close();
		}
		catch(IOException e){
			e.printStackTrace();
		}
	}
}

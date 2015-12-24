package date_8_20_client;

import java.awt.EventQueue;
//import java.net.ServerSocket;

public class StartClient {
//	private ServerSocket server;
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					MainWindow frame = new MainWindow();
					frame.setVisible(true);
					ChatManager.getChatManager().setWindow(frame);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}
}

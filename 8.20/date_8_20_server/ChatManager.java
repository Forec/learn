package date_8_20_server;

import java.util.Vector;

public class ChatManager {
	
	private ChatManager(){}
	private static final ChatManager cm = new ChatManager();
	public static ChatManager getChatManager(){
		return cm;
	}
	
	Vector<ChatSocket> sos  = new Vector<ChatSocket>();
	public void add(ChatSocket cs){
		sos.add(cs);
	}
	public void publish(ChatSocket cslocal,String out){
		for (int i = 0 ; i < sos.size() ; i ++){
			ChatSocket cs = sos.get(i);
			if (!cs.equals(cslocal)){
				cs.out(out);
			}
		}
	}
}

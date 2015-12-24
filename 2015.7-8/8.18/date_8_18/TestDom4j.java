package date_8_18;


import org.dom4j.Document;
import org.dom4j.DocumentException;
import org.dom4j.DocumentHelper;

public class TestDom4j {
	public static void main(String[] args) {
		String xml = "<root><people>forec</people></root>";
		try {
			Document document = DocumentHelper.parseText(xml);
			System.out.println(document.asXML());
		} catch (DocumentException e) {
			e.printStackTrace();
		}
		
	}
}

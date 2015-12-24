package date_8_17;

import java.io.File;
import java.io.IOException;



//import javax.lang.model.element.Element;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
//import javax.xml.soap.Node;


import org.w3c.dom.Document;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.w3c.dom.Element;
import org.xml.sax.SAXException;

public class TestXML {

	public static void main(String[] args) {
		try {
			DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
			DocumentBuilder builder = factory.newDocumentBuilder();
			Document document = builder.parse(new File("Language.xml"));
			Element root = (Element) document.getDocumentElement();
			System.out.println("cat = "+root.getAttribute("cat"));
			NodeList list = root.getElementsByTagName("lan");
			for (int i = 0 ;i <list.getLength();i++){
				Element lan = (Element) list.item(i);
				System.out.println("----------------");
				System.out.println("id="+lan.getAttribute("id"));
//				Element name = (Element) lan.getElementsByTagName("name").item(0);
//				Element ide = (Element) lan.getElementsByTagName("ide").item(0);
//				System.out.println("name="+name.getTextContent()+"    ide="+ide.getTextContent());
				NodeList c = lan.getChildNodes();
				for (int j = 0 ; j < c.getLength();j++){
					Node ccElement =   c.item(j);
					if ( ccElement instanceof Element)
						System.out.println(ccElement.getNodeName()+":"+ccElement.getTextContent());
				}
			}
		
		} catch (ParserConfigurationException e) {
			e.printStackTrace();
		} catch (SAXException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

}

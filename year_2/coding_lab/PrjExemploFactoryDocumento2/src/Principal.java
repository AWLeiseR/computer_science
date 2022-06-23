
public class Principal {

	public static void main(String[] args) {
		
		Application app1 = new FirstApp();
		
		Document doc = app1.createDocument(FirstApp.TYPE_2);
		
		doc.open();
		
		Application app2 = new SecondApp();
		
		Document doc2 = app2.createDocument(SecondApp.TYPE_B);
		
		doc2.open();

	}

}

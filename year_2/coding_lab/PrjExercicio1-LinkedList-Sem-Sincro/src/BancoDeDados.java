import java.util.ArrayList;
import java.util.Collection;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Vector;

public class BancoDeDados {

	public static void main(String[] args) throws InterruptedException {
		// TODO Auto-generated method stub
		
		Collection<String> sqls = 
				new LinkedList<String>();
		
		ProducaoSql p1 = new ProducaoSql(0, 10, sqls);
		Thread t1 = new Thread(p1);
		
		ProducaoSql p2 = new ProducaoSql(10, 20, sqls);
		Thread t2 = new Thread(p2);
		
		ProducaoSql p3 = new ProducaoSql(20, 30, sqls);
		Thread t3 = new Thread(p3);
		
		t1.start();
		t2.start();
		t3.start();
		
		t1.join();
		t2.join();
		t3.join();
		
		System.out.println("Threads produtoras de SQLs finalizadas!");
		
		for (int i = 0; i < 30; i++) {
			if (!sqls.contains("SQL: " + i)) {
				throw new IllegalStateException("não encontrei a SQL " + i);
			}
		}
		
		if (sqls.contains(null)) {
			throw new IllegalStateException("não devia ter null aqui dentro!");
		}
		
		for (int i = 0; i < sqls.size(); i++){
			System.out.println(((LinkedList)sqls).get(i));
		}
		
		System.out.println("Fim da execucao com sucesso");
		
		

	}

}

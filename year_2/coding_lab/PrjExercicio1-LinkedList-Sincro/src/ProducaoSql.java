import java.util.Collection;

public class ProducaoSql implements Runnable {
	
	private int comeco;
	
	private int fim;
	
	private Collection<String> sqls;
	
	
	public ProducaoSql(int pComeco, int pFim, Collection<String> pSqls){
		this.comeco = pComeco;
		this.fim = pFim;
		this.sqls = pSqls;
		
	}
	
	@Override
	public void run() {
		// TODO Auto-generated method stub
		for (int i = comeco; i < fim; i++){
			//synchronized (sqls) {
				sqls.add("SQL: "+i);
			//}
		}

	}

}

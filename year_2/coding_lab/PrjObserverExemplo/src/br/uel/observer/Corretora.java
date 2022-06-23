package br.uel.observer;

public class Corretora implements Observer {

	private String nome;
	
	public Corretora(String nome){
		this.nome = nome;
	}
	
	@Override
	public void notificarAlteracao(Subject subject) {
		System.out.println("Corretora " + this.nome + " sendo notificada");
		Acao acao = (Acao)subject;
		System.out.println("A ação " + acao.getCodigo() +" teve o seu valor alterado para "
							+ acao.getValor());
		
	}

}

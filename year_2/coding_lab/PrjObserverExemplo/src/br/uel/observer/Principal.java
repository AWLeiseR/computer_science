package br.uel.observer;

public class Principal {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Acao acao = new Acao("VALE5", 12.78);
		
		Observer corretora1 = new Corretora("Santander");
		
		Observer corretora2 = new Corretora("Itau");
		
		acao.registrarInteressado(corretora1);
		acao.registrarInteressado(corretora2);
		
		Observer pf1 = new PessoaFisica("João", "111.111.111-11");
		
		Observer pf2 = new PessoaFisica("Maria", "222.222.222-22");
		
		acao.registrarInteressado(pf1);
		acao.registrarInteressado(pf2);
		
		acao.setValor(15);
		System.out.println("===================================");
		
		acao.cancelarInteresse(corretora2);
		
		acao.setValor(11);
		System.out.println("===================================");
		
		acao.cancelarInteresse(pf1);
		
		acao.setValor(14);
		System.out.println("===================================");

	}

}

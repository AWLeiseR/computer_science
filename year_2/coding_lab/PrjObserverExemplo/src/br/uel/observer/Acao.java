package br.uel.observer;

import java.util.HashSet;
import java.util.Set;

public class Acao implements Subject{
	
	private String codigo;
	
	private double valor;
	
	public Acao(String codigo, double valor){
		this.codigo = codigo;
		this.valor = valor;
	}
	
	private Set<Observer> interessados = 
			new HashSet<Observer>();
	
	public void registrarInteressado(Observer interessado){
		this.interessados.add(interessado);
	}
	
	public void cancelarInteresse(Observer interessado){
		this.interessados.remove(interessado);
	}
	
	public double getValor(){
		return this.valor;
	}
	
	public void setValor(double valor){
		this.valor = valor;
		this.notificar();
	}
	
	public String getCodigo() {
		return codigo;
	}

	public void notificar() {
		for(Observer interessado : this.interessados){
			interessado.notificarAlteracao(this);
		}
	}
	

}

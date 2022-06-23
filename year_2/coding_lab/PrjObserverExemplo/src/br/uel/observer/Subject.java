package br.uel.observer;

public interface Subject {
	
	public void registrarInteressado(Observer interessado);
	
	public void cancelarInteresse(Observer interessado);
	
	public void notificar();

}

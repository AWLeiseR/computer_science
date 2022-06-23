package br.uel;

import java.util.*;

public abstract class Template {
	
	public void ordena(String vetor[]) {
		Arrays.sort(vetor);
		posicaoNaLista(vetor);
	}
	
	abstract void posicaoNaLista(String vetor[]);
}

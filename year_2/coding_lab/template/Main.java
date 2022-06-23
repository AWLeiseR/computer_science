package br.uel;
import java.util.*;

public class Main {

	public static void main(String[] args) {
		
		Scanner scan = new Scanner(System.in);
		
		int n = scan.nextInt();
		
		Musica vetor[] = new Musica[n];
		
		vetor[0] = new Musica("WAKE ME UP", "AVICCI", "WAKE ME UP");
		vetor[1] = new Musica("Do I Wanna Know", "Artic Monkeys", "AM");
		vetor[2] = new Musica("Esse cara sou eu", "Roberto Carlos", "Especial Fim De Ano");
		vetor[3] = new Musica("Equalizar", "pitty", "Equalize");
		vetor[4] = new Musica("Crossing Field", "Lisa", "SAO");
		
		String vetorNome[] = new String[n];
		String vetorArtista[] = new String[n];
		for(int i = 0; i < n; i++) {
			vetorNome[i] = vetor[i].nome;
			vetorArtista[i] = vetor[i].artista;
		}
		vetor[3].ordena(vetorNome);		
		vetor[4].ordena(vetorArtista);

	}

}

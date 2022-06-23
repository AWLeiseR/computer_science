package br.uel;

public class Musica extends Template{
	String nome, artista, album;
	
	public Musica(String nome, String artista, String album) {
		this.nome = nome;
		this.artista = artista;
		this.album = album;
	}

	@Override
	void posicaoNaLista(String vetor[]) {
		for(int i=0; i<vetor.length;i++) {
			if(this.nome == vetor[i]) {
				System.out.printf("A musica %s esta na %d posicao na lista\n",vetor[i] ,i+1);
			}else if(this.artista == vetor[i]){
				System.out.printf("O artista %s esta na %d posicao na lista\n",vetor[i] ,i+1);
			}
		}
		
	}
	
	
}

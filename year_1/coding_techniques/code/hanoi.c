/*#include <stdio.h>
 #include <stdlib.h>

void hanoi(int n, char a, char b, char c){
/* mova n discos do pino a para o pino b usando
  o pino c como intermediario                    
  if (n == 1)
     printf("mova disco %d de %c para %c\n", n, a, b);
   else
   {
     hanoi(n - 1, a, c, b);                            // H1
     printf("mova disco %d de %c para %c\n", n, a, b);
     hanoi(n - 1, c, b, a);                            // H2
  }
 }
 
int main(void){
   int numDiscos;
   printf("Insira um numero:");
   scanf("%d",&numDiscos);
   hanoi(numDiscos, 'A', 'B', 'C');
   return 0;
}*/
#include <stdlib.h>
#include <stdio.h>

void jogar(int arg,int pa[],int pb[],int pc[]);

void movedisco(int arg,int origem,int destino,int pa[],int pb[],int pc[]){
	int i,discoi;

  //move o disco do pinoA para o pinoC	 
  if(origem==1 && destino==3){	
	//busca o disco mais de cima do pino A,e armazena o conteudo dele na variavel pinoi
		for(i=0;i<arg;i++) {
			if(pa[i]!=0){
				discoi=pa[i];
				pa[i]=0;
				break;
			}
			else{
			continue;
			}
		}
		//busca no pinoC a primeira posição vazia de baixo pra cima, e armazena o disco do A caso o disco que ja estiver no pinoC for maior que o proximo a armazenar 
		//pc=pc+4;
		for(i=arg-1;i>=0;i--){
			if (pc[i]==0){
					if(pc[i+1]<discoi){
					pc[i]=discoi;
					break;	
					}
					else{
						printf("\nMovimento invalido!");
					}
			}
			//pc--;
		}
  }
    //move o disco do pinoA para o pinoB	 
  else if(origem==1 && destino==2){ 
    	for(i=0;i<arg;i++) {
			if(pa[i]!=0){
				discoi=pa[i];
				printf("%d",discoi);
				pa[i]=0;
				break;
			}
			else{
			  //pa++;
			  continue;
		    }
	    }
	 // pb=pb+4;  
	  for(i=arg-1;i>=0;i--){
           if (pb[i]==0 && pb[i-1]<discoi){
		   		   pb[i]=discoi;
				   break;	
		   		}
		   		else{
		   			printf("\nMovimento invalido!");
		   		}
		   }
		  // pb--;
      }
    	

     //move o disco do pinoB para o pinoC	 
    else if(origem==2 && destino==3){ 
    	for(i=0;i<arg;i++) {
			if(pb[i]!=0){
				discoi=pb[i];
				pb[i]=0;
				break;
			}
			else{
			 // pb++;
		    }
	    }
	  //pc=pc+4;  
	  for(i=arg-1;i>=0;i--){
           if (pc[i]==0){
		   		if(pc[i+1]<discoi){
		   		   pc[i]=discoi;
				   break;	
		   		}
		   		else{
		   			printf("\nMovimento invalido!");
		   		}
		   }
		   //pc--;
      }
    }
    //move o disco do pinoB para o pinoA	 
    else if(origem==2 && destino==1){ 
    	for(i=0;i<arg;i++) {
			if(pb[i]!=0){
				discoi=pb[i];
				pb[i]=0;
				break;
			}
			else{
			  //pb++;
			  continue;
		    }
	    }
	  //pa=pa+4;
	  for(i=arg-1;i>=0;i--){
           if (pa[i]==0){
		   		if(pa[i+1]<discoi){
		   		   pa[i+1]=discoi;
				   break;	
		   		}
		   		else{
		   			printf("\nMovimento invalido!");
		   		}
		   }
		   //pa--;
      }
    }
    //move o disco do pinoC para o pinoA	 
    else if(origem==3 && destino==1){ 
    	for(i=0;i<arg;i++) {
			if(pc[i]!=0){
				discoi=pc[i];
				pc[i]=0;
				break;
			}
			else{
			  //pc++;
		    }
	    }
	   //pa=pa+4; 
	  for(i=arg-1;i>=0;i--){
           if (pa[i]==0){
		   		if(pa[i+1]<discoi){
		   		   pa[i]=discoi;
				   break;	
		   		}
		   		else{
		   			printf("\nMovimento invalido!");
		   		}
		   }
		   //pa--;
      }
    }
    //move o disco do pinoC para o pinoB	 
    else if(origem==3 && destino==2){ 
    	for(i=0;i<arg;i++) {
			if(pc[i]!=0){
				discoi=pc[i];
				pc[i]=0;
				break;
			}
			else{
			 // pc++;
		    }
	    }
	   //pb=pb+4;
	  for(i=arg-1;i>=0;i--){
           if (pb[i]==0){
		   		if(pb[i+1]<discoi){
		   		   pb[i]=discoi;
				   break;	
		   		}
		   		else{
		   			printf("\nMovimento invalido!");
		   		}
		   }
		   //pb--;
      }
    }

    //chama função jogar para mostrar o jogo despois do movimento do disco
	jogar(arg,pa,pb,pc);
	system("pause");
    system("cls");	
}

void jogar(int arg,int *pa,int *pb,int *pc){
	int i,origem,destino,contb=0,contc=0,movimentos=0;

	system("cls");
	for(i=0;i<arg;i++){
		printf("\n    ");
	      if (pa[i]==0)  
		  	printf(" | "); 
			  else 
			  	printf("(%i)", pa[i]);
	      if (pb[i]==0)  
		  	printf("   | "); 
			  else 
			  	printf("  (%i)",pb[i]);
	      if (pc[i]==0)  
		  	printf("  | "); 	
			  else printf(" (%i) ",pc[i]);
		  
   }
	 printf("\n   ==============\n");
     printf("     1    2   3  ");
     printf("\n   ==============\n\n");


   for(i=0;i<arg;i++){
     if(pb[i]==(i+1)){
	   contb++;
	 }
     if(pc[i]==(i+1)){
	   contc++;
	 }
	 /*pb++;
	 pc++;*/
   }
   if(contb==arg || contc==arg){ 
   	 printf("\nParabens!! voce venceu o jogo com %i movimentos!\n",movimentos); 
   }

     printf("Digite 1 para coluna 1, 2 para coluna 2 e  3 para coluna 3 \n\n");
     printf("Origem: ");
     scanf("%i",&origem);
     printf("\nDestino: ");
     scanf("%i",&destino);
     movimentos++;
     //fazendo os ponteiros voltarem para primeira posição para mandar por parametro
     /*pa=pa-4;
     pb=pb-4;
     pc=pc-4;*/
	 movedisco(arg,origem,destino,pa,pb,pc);
     /*if(origem==1 && destino==3)
	 	movedisco(arg,origem,destino,pa,pb,pc);
	else if(origem==1 && destino==2)
	 	movedisco(arg,origem,destino,pa,pb,pc);
	else if(origem==2 && destino==3)
	 	movedisco(arg,origem,destino,pa,pb,pc);
	else if((origem==2)&&(destino==1))
	 	movedisco(arg,origem,destino,pa,pb,pc);
	else if((origem==3)&&(destino==1))
	 	movedisco(arg,origem,destino,pa,pb,pc);
	else if((origem==3)&&(destino==2))
	 	movedisco(arg,origem,destino,pa,pb,pc);*/
}

 void instrucoes(){
   printf("\n- Voce so pode movimentar um disco de cada vez.");
   printf("\n\n- Um disco maior NAO pode ficar em cima de um menor.");
   printf("\n\n- O jogo termina quando voce conseguir colocar todos os discos (do maior ao menor) no pino C.");
   printf("\n\n- Bom jogo!!\n\n\n");
   system("pause");
   system("cls");
 }

int main(){
	int opcao,veta[5],vetb[5],vetc[5],arg=5,i;
	

 //Enquanto opcao for diferente de 3
  while (opcao != 3){
      printf("\n\n\n\t\t----------TORRE DE HANOI----------\n\n");
		printf(" 1 - Jogar\n");
		printf(" 2 - Insrucoes\n");
	   	printf(" 3 - Sair\n\n");

	   	printf("-Digite opcao: ");
	  	scanf("%i",&opcao);
		system("cls");         
        
	   if(opcao==1){

			for(i=0;i<arg;i++){
				veta[i]=i+1;
				vetb[i]=0;
				vetc[i]=0;
			}
			jogar(arg,veta,vetb,vetc);//chama funcao jogar
	   }
	   if(opcao==2){
	   		instrucoes();
	   }   

	   
  }  
  return 0;
}
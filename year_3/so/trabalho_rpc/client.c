/* Cliente RPC simples */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "agenda.h"


void inserir(CLIENT *clnt) {
   char nome[100], endereco[100],telefone[100];
   pessoa p;
   int *result;

   /* junta os parametros em um struct */
   printf("Nome: ");
   fgets(p.nome,100,stdin);
   p.nome[strlen(p.nome)-1]='\0';
   //scanf("%s", nome);
   //scanf("%*c");
   //strcpy(p.nome, nome);

   printf("Endereço: ");
   fgets(p.endereco,100,stdin);
   p.endereco[strlen(p.endereco)-1]='\0';
   //scanf("%s", endereco);
   //scanf("%*c");
   //strcpy(p.endereco, endereco);

   printf("Telefone: ");
   fgets(p.telefone,100,stdin);
   p.telefone[strlen(p.telefone)-1]='\0';
   //scanf("%s", telefone);
   //scanf("%*c");
   //strcpy(p.telefone, telefone);
   
   /* chama a função remota */
   result = inserir_1 (&p, clnt);
  
   if (result == NULL) {
      printf ("Problemas ao chamar a função remota\n");
      exit (1);
   }else{
      printf("\nContato inserido com sucesso\n");
      
      
   }
}

int consultar(CLIENT *clnt) {
   char nome[100];
   pessoa p;
   pessoa *result;

   /* junta os parametros em um struct */
   printf("Nome: ");
   fgets(p.nome,100,stdin);
   p.nome[strlen(p.nome)-1]='\0';
   //scanf("%s", nome);
   //strcpy(p.nome, nome);
   strcpy(p.endereco, "");
   strcpy(p.telefone, "");

   /* chama a função remota */
   result = consultar_1 (&p, clnt);
    printf("===============================\n\n");
   if (result == NULL) {
      printf ("Problemas ao chamar a função remota\n");
      exit (1);
   } else if (strcmp(result->nome, "undefined") == 0) {
      printf("Contato nao encontrada!\n");
      return 0;
   } else {
      printf("Nome: %s\n", result->nome);
      printf("Endereço: %s\n", result->endereco);
      printf("Telefone: %s\n", result->telefone);
      printf("\n");
      return 1;
      
   }
}

void remover(CLIENT *clnt) {
   char nome[100];
   pessoa p;
   int *result;

   /* junta os parametros em um struct */
   printf("Nome: ");
   fgets(p.nome,100,stdin);
   p.nome[strlen(p.nome)-1]='\0';
   //scanf("%s", nome);
   //strcpy(p.nome, nome);
   strcpy(p.endereco, "");
   strcpy(p.telefone, "");

   /* chama a função remota */
   result = remover_1 (&p, clnt);
   if (result == NULL) {
      printf ("Problemas ao chamar a função remota\n");
      exit (1);
   }else{
      printf("\nContato removido\n");
      
      
   }
}

void alterar(CLIENT *clnt) {
    char nome[100], endereco[100], telefone[100];
   pessoa p;
   int *result;
    
       /* junta os parametros em um struct */
      printf("Nome do contato: ");
      fgets(p.nome,100,stdin);
      p.nome[strlen(p.nome)-1] = '\0';
      //scanf("%s", nome);
      //scanf("%*c");
      //strcpy(p.nome, nome);

      printf("Novo endereço: ");
      fgets(p.endereco,100,stdin);
      p.endereco[strlen(p.endereco)-1] = '\0';
      //scanf("%s", endereco);
      //scanf("%*c");
      //strcpy(p.endereco, endereco);

      printf("Novo telefone: ");
      fgets(p.telefone,100,stdin);
      p.telefone[strlen(p.telefone)-1] = '\0';
      //scanf("%s", telefone);
      //scanf("%*c");
      //strcpy(p.telefone, telefone);

      /* chama a função remota */
      result = alterar_1 (&p, clnt);
      if (result == NULL) {
         printf ("\nProblemas ao chamar a função remota\n");
         exit (1);
      }else{
         printf("\nContato alterado\n");
         
      } 

  
   
}



int main ( int argc, char *argv[]) {
   CLIENT *clnt;

   /* verifica se o cliente foi chamado corretamente */
   if (argc != 2) {
      fprintf (stderr,"Usage: %s hostname\n",argv[0]);
      exit (1);
   }

   /* cria uma struct CLIENT que referencia uma interface RPC */
   clnt = clnt_create (argv[1], AGENDA_PROG, AGENDA_VERSION, "udp");
   
   if (clnt == (CLIENT *) NULL){
      clnt_pcreateerror (argv[1]);
      exit(1);
   }
   
   int op;
   
   while (op!=0){
      printf("1. Inserir pessoa\n");
      printf("2. Consultar pessoa\n");
      printf("3. Alterar pessoa\n");
      printf("4. Remover pessoa\n");
      printf("0. Sair\n");
      printf(" > ");
      scanf("%d", &op);
      scanf("%*c");

      if (op == 1) {
         inserir(clnt);
      } else if (op == 2) {
         consultar(clnt);
      } else if (op == 3) {
         alterar(clnt);
      } else if (op == 4) {
         remover(clnt);
      } else if(op == 0){
        continue; 
      }else{
         printf("Opção inválida!\n");
      }
      printf("\nPressione a tecla Enter para continuar\n");
      printf("==========================================\n");
      getchar();
      
   }
   
   

   return 0;
} 

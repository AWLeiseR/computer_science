#include <stdio.h>
#include <stdlib.h>
#include "agenda.h"

char* filename = "agenda.txt";
char* tempfilename = "tempfile";

int * inserir_1_svc (pessoa *p, struct svc_req *rqstp) {
   static int result;

   FILE *arquivo = fopen(filename, "ab");
   fwrite(p, sizeof(pessoa), 1, arquivo);
   fclose(arquivo);
   printf("Contato %s inserido\n",p->nome);
   return (&result);
}

pessoa * consultar_1_svc (pessoa *c, struct svc_req *rqstp) {
   static int result;
   static pessoa p;
   printf("Buscando contato %s \n",c->nome);
   FILE *arquivo = fopen(filename, "rb");
   if (arquivo == NULL) {
      printf("Falha na abertura do arquivo\n");
   }

   while (1) {
      fread(&p, sizeof(struct pessoa), 1, arquivo);
      if (feof(arquivo)) {
         printf("Contato nao encontrado\n");
         strcpy(p.nome, "undefined");   
         break;
      }

      if (strcmp(p.nome, c->nome) == 0) {
         printf("Contato encontrado\n");
         break;
      }
   }
   
   fclose(arquivo);
   return &p;
} 

int * alterar_1_svc (pessoa *p, struct svc_req *rqstp) {
   static int result;
   pessoa aux;

   FILE *arquivo;
   printf("Alterando contato %s\n",p->nome);
   arquivo = fopen(filename, "rb");
   int i = 0;
   int mudar = -1;
   while (!feof(arquivo)) {
      fread(&aux, sizeof(struct pessoa), 1, arquivo);
      if(strcmp(aux.nome, p->nome) == 0) {
         mudar = i;
         break;
      }
      i++;
   }
   fclose(arquivo);

   if (mudar != -1) {
      arquivo = fopen(filename, "r+b");
      fseek(arquivo, mudar*sizeof(struct pessoa), SEEK_SET);
      fwrite(p, sizeof(pessoa), 1, arquivo);
      fclose(arquivo);
   }


   return (&result);
} 


int * remover_1_svc (pessoa *p, struct svc_req *rqstp) {
   static int result;

   FILE* arquivo = fopen(filename, "rw");
   FILE* novoArquivo = fopen(tempfilename, "w");
   pessoa aux;
   printf("Removendo contato %s\n",p->nome);
   while(!feof(arquivo)){
      fread(&aux, sizeof(struct pessoa), 1, arquivo);
      if(strcmp(aux.nome, p->nome) != 0){
         fwrite(&aux, sizeof(struct pessoa), 1, novoArquivo);
      }
   }

   fclose(novoArquivo);
   fclose(arquivo);
   remove(filename);
   rename(tempfilename, filename);

   return (&result);
} 

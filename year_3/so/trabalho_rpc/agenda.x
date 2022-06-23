/* agenda.x : definição da interface */

#define PROGRAM_NUMBER 1111111
#define VERSION_NUMBER 1

/* tipo de dado que será passado aos procedimentos remotos */
struct pessoa{
        char nome[200];
        char endereco[200];
        char telefone[200];
};

/* Definição da interface que será oferecida aos clientes */
program AGENDA_PROG{
  
   version AGENDA_VERSION
   {
     int INSERIR (pessoa) = 1;
     pessoa CONSULTAR (pessoa) = 2;
     int ALTERAR (pessoa) = 3;
     int REMOVER (pessoa) = 4;
   }
   = VERSION_NUMBER;
}
= PROGRAM_NUMBER;

 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){
    FILE *arq;
    int alfabeto[26];
    int i=0,palavra=0,linha=0;
    char c1,c2[200],c3[200];
    float percentual[26];
    int tamanho, letra_palavra[26],total;
    
    for(i=0;i<26;i++){
        alfabeto[i]=0;
    }
    

    arq=fopen("texto.txt","r");
    if(arq==NULL){
        perror("");
        exit(1);
    }
    while(1){
        c1=getc(arq);
        if(feof(arq)){
            break;
        }
        while(1){
            if(c1==97+i){
                alfabeto[i]++;
                break;
            }else if(i>=122){
                    i=0;
                    break;
            }
            i++;
        }
    }
    rewind(arq);
    while(1){
        fscanf(arq,"%s",c3);
        if(feof(arq)){
            break;
        }
        palavra++;
    }
    rewind(arq);
     while(1){
        fgets(c2,200,arq);
        linha++;
        if(feof(arq)){
            break;
        }
        
    }

    
    printf("arquivo tem (%d)palavras,(%d)linhas\n",palavra,linha);
    i=97;
    //c1='a'
    for(int z=0;z<26;z++){
        printf("A letra %c aparece %d vezes\n",i,alfabeto[z]);
        i++;
    }
    printf("++++++++++++++++++++++++++");
    printf("Questao 6\n");
    rewind(arq);
    tamanho=0;
    total=0;
    for(i=0;i<26;i++){
        letra_palavra[i]=0;
    }
    while(1){
        fscanf(arq,"%s",c2);
        tamanho=strlen(c2);
        letra_palavra[tamanho]++;
        total++;
         if(feof(arq)){
            break;
        }
        
        
        
       
    }
    for(i=0;i<26;i++){
        percentual[i]=letra_palavra[i]/(total*1.0);
        printf("palavra com %d letras aparece (%d) vezes,",i,letra_palavra[i]);
        printf("percentual de %f\n",percentual[i]);
    }

    printf("++++++++++++++++++++++++++");

    fclose(arq);
    return 0;
}
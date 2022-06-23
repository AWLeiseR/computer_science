#include<funcoes.h>

float h_view_lo = -6.500000;
float h_view_hi = 6.500000;
float v_view_lo = -3.500000;
float v_view_hi = 3.500000;

int integral_steps = 1000;
int axis = 1;
int connectDots = 0;

char grafico [25][80];
double matrix[10][10];
double auxMatrix[10][10];
double L[10][10];
double res[10];

int linha,coluna, auxColuna;
int negativo = 0;


int getLinha(){
    return linha;
}

void setLinha(int linha1){
    linha = linha1;
}

int getColuna(){
    return coluna;
}

void setColuna(int coluna1){
    coluna = coluna1;
}

void insertElementMatrix(int linha,int coluna,double element){
    if(element < 0)
        negativo=1;

    matrix[linha][coluna]=element;
    
}

int getAuxColuna(){
    return auxColuna;
}

void setAuxColuna(int coluna){
    if(auxColuna < coluna)
        auxColuna = coluna;
}

void resetAuxColuna(){
    auxColuna = 1;
}

void imprimeSettings(){
    
    printf("\nh_view_lo: %f\n",h_view_lo);
    printf("h_view_hi: %f\n",h_view_hi);
    printf("v_view_lo: %f\n",v_view_lo);
    printf("v_view_hi: %f\n",v_view_hi);
    printf("integral_steps: %d\n\n",integral_steps);
    printf("Draw Axis: %s\n",axis?"ON":"OFF");
    printf("Connect Dots: %s\n\n",connectDots?"ON":"OFF");

}

void resetSettings(){

    h_view_lo = -6.500000;
    h_view_hi = 6.500000;
    v_view_lo = -3.500000;
    v_view_hi = 3.500000;

    integral_steps = 1000;
    axis = 1;
    connectDots = 0;

}

void setHView(float hviewlo, float hviewhi){
    
    if(hviewlo < hviewhi){
    
        h_view_lo = hviewlo;
        h_view_hi = hviewhi;  
    
    }else{
    
        printf("\nERROR: h_view_lo must be smaller than h_view_hi\n\n");
    
    }

}

void setVView(float vviewlo, float vviewhi){
    
    if(vviewlo < vviewhi){
    
        v_view_lo = vviewlo;
        v_view_hi = vviewhi;
    
    }else{
    
        printf("\nERROR: v_view_lo must be smaller than v_view_hi\n\n");
    
    }
    
}

void axisOn(){
    axis = 1;
}

void axisOff(){
    axis = 0;
}

void limpaGrafico(){
    int i,j;
    for(i=0;i<25;i++){
        for(j=0;j<80;j++){
            
            grafico[i][j] = ' '; 
            
        }
    
    }
}

void printAxis(float somaV,float pixelV,float somaH,float pixelH){
    
    int i,j,x,z;
    float auxV = v_view_lo, auxH = h_view_lo;

    i= (0 - auxV)/pixelV;
    j= (0 - auxH)/pixelH;

    if(i < 25 && i > 0){
        
        for(x=0;x<80;x++){
            grafico[i][x] = '-';
        }
    
    }
    
    if(j < 80 && j > 0 ){
        
        for(z=0;z<25;z++){
            grafico[z][j]='|';
    
        }
    }
    
    if(i < 25 && i > 0 && j < 80 && j > 0){
        grafico[i][j]= '+';
    }
    

    //printf("%d %d\n",i,j);

}

void imprimeGrafico(){
    int i,j;

    for(i=24;i>=0;i--){
        for(j=0;j<80;j++){
            
            printf("%c",grafico[i][j]);

        }
        printf("\n");
    }
}

void plotFunction(TreeNode * tree){
    int i,menor;
    
    float somaV=v_view_lo;
    float somaH=h_view_lo;
    
    float aux;

    float pixelH = (h_view_hi - h_view_lo) / 80;
    
    float pixelV = (v_view_hi - v_view_lo) / 25;
    printf("\n");
    if(tree){
        
        limpaGrafico();
        
        if(axis){
        printAxis(somaV,pixelV,somaH,pixelH);
        }

        for(i = 0; i < 80; i++){
            
            aux = calcula(tree,somaH);
            
            //printf("%f\n",aux);

            menor = (int) floor((aux - somaV)/pixelV);
            
            if(menor>0 && menor < 25){
                grafico[menor][i] = '*';
            }
            
            somaH=h_view_lo + ( i * pixelH);
        }
        imprimeGrafico();
    }else{
        printf("No Function defined!\n");
    }
    
}

void setIntegralSteps(float step){
    
    if(step > 0){
        integral_steps = (int)step;
    }else{
        printf("\nERROR: integral_steps must be a positive non-zero integer\n\n");
    }
    
}

void integrate(TreeNode* tree,float downLimit, float upLimit){

    if(downLimit < upLimit){
        
        int i;
        float base = (upLimit - downLimit) / integral_steps;
        printf("down -> %f up -> %f base ->%f ",downLimit,upLimit,base);
        float integral = 0;
        for(i=0;i<integral_steps;i++){
            
            integral=integral+calcula(tree,downLimit+(i*base))*base;
        }
        printf("\n\n%f\n\n",integral);
    }else{
        
        printf("\nERROR: lower limit must be smaller than upper limit\n");
    
    }
    
}

void imprimeCabecalho(){

    int i, espacos=(auxColuna*(17+negativo*2))+1;
    
    printf("+-");
    for(i=0;i<espacos;i++){
        printf(" ");
    }
    printf("-+\n");
}

void limpaMatrix(){
	int i,j;
    negativo = 0;
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			matrix[i][j]=0;
		}
	}
}

void imprimeMatrix(TreeNode* tree){
    int i,j;
    if(tree){
        printf("\n\n");
        imprimeCabecalho();
        for(i = 0; i < linha; i++){
            printf("| ");
            for(j = 0; j < auxColuna; j++){
                if(matrix[i][j] < 0 ){
                    printf(" %.10e ",matrix[i][j]);
                }else if(matrix[i][j] > 0 && negativo == 1){
                    printf("  %.10e ",matrix[i][j]);
                }else{
                    printf(" %.10e",matrix[i][j]);
                }
                
            }
            printf("  |\n");
        }
        imprimeCabecalho();
    }else{
        printf("\nNo Matrix defined!");
        printf("\n");
    }
    
    
}

// function for elementary operation of swapping two rows 
void swap_row(double mat[linha][auxColuna], int i, int j) { 
    double temp;
    int k;
    for (k=0; k<=auxColuna; k++) { 
        temp = mat[i][k]; 
        mat[i][k] = mat[j][k]; 
        mat[j][k] = temp; 
    } 
} 

int calculaLU(){
    int i,j,y;
	float maxValor;
    int indice;

	for(i=0;i<auxColuna;i++){
		L[i][i]=1;
	}

	for(j=0;j<linha;j++){//anda coluna
        indice=j;
        
        maxValor=auxMatrix[indice][j];
        for(i = j+1; i < auxColuna; i++){
            
                
            if(abs(auxMatrix[i][j]) > maxValor){
                maxValor = auxMatrix[i][j];
                
                indice= i; 
            }                 
        } 
        
        if(!auxMatrix[j][indice] || isnan( auxMatrix[j][indice])!=0 ){
            return j;
        } 
            

        if(indice != j) 
            swap_row(auxMatrix, j, indice);  

		
		
		for(y=1+j;y<linha;y++){//anda linha
			
				L[y][j] = auxMatrix[y][j]/auxMatrix[j][j];; // multiplicador
				
				for(i=0;i<auxColuna;i++){//percorre as colunas da linha
					
				 	auxMatrix[y][i] -= L[y][j]*auxMatrix[j][i];
				
				}
		}
	}

    return -1;
}

void transferirMatrix(){
    int i,j;
    
    for(i=0;i<linha;i++){
        for(j=0;j<auxColuna;j++){
            auxMatrix[i][j]=matrix[i][j];
        }
    }
}

void calculaDeterminante(TreeNode* tree){
    int i;
    float det=1;
    if(tree){
        if(linha == auxColuna){
        if(linha==1){

            det=matrix[0][0];
        
        }else if(linha == 2){
          
            det=(matrix[0][0]*matrix[1][1])-(matrix[0][1]*matrix[1][0]);
        
        }else{
            
            transferirMatrix();
            calculaLU();
            for(i=0;i<auxColuna;i++){
                det = det*auxMatrix[i][i];
            }
        
        }
        
            printf("\n\n%f\n\n",det);
        }else{
            printf("\n\nMatrix format incorrect!\n\n");
        }
    }else{
        printf("\nNo Matrix defined!\n\n");
    }
    
    
}

void backSub() { 
  int i,j;
    for (i = linha-1; i >= 0; i--) { 
        
        res[i] = auxMatrix[i][linha]; 
  
        for (j = i+1; j<linha; j++) { 
    
            res[i] -= auxMatrix[i][j] * res[j]; 
        } 
  
        res[i] = res[i] / auxMatrix[i][i]; 
    } 
  
    printf("\nMatrix x:\n\n"); 
    for (i = 0; i<linha; i++){
        printf("%lf\n", res[i]);
    } 
         
} 

void resolveSistemaLinear(){
    int resulte ;
        
    if(linha+1 == auxColuna  ){
        transferirMatrix();
        resulte=calculaLU();
        if(resulte != -1){
            
            if (!auxMatrix[resulte][linha] && isnan(auxMatrix[resulte][linha])!=0){
                printf("\n\nSI - The Linear System has no solution\n\n"); 
            }else{
                printf("\n\nSPI - The Linear System has infinitely many solutions\n\n");
            }
            
        }else{
            backSub();
        }

    }else{
        printf("\n\nMatrix format incorrect!\n\n");
    }
}

void imprimeAbout(){
    printf("\n+----------------------------------------------+\n");
    printf("|                                              |\n");
    printf("|       201800560631 - Alan Willy Leiser       |\n");
    printf("|                                              |\n");
    printf("+----------------------------------------------+\n\n");
}

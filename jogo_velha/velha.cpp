#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define DIM 3

int vez;
int menu(void);
void clear(void);
void zeraTabuleiro(int tabuleiro[][DIM]);
void exibeTabuleiro(int tabuleiro[][DIM]);
void jogar(int tabuleiro[][DIM]);
int checaLocal(int tabuleiro[][DIM], int linha, int coluna);
int checaLinha(int tabuleiro[][DIM]);
int checaColuna(int tabuleiro[][DIM]);
int checaDiagonal(int tabuleiro[][DIM]);
int checaEmpate(int tabuleiro[][DIM]);
int checaTermino(int tabuleiro[][DIM], int vez);
void jogada(int tabuleiro[][DIM]);
char jogar1[30] , jogar2[30];
 
 
int main(void){
	system("color 04");
	setlocale(LC_ALL, "Portuguese_Brazil");
    int tabuleiro[DIM][DIM],
    	continuar;
 
    do{
    	
        vez=1;
        continuar=menu();
        if(continuar==1){
        	
            jogar(tabuleiro);
            
        }
 
    }while(continuar);
 
    return 0;
}
 
int menu(void)
{
    int opcao;
 
        printf("\t\tNosso Primeiro Jogo -- Jogo da Velha (Editado por Pedro Martins)\n");
        printf("\n<1>Jogar uma partida.\n");
        printf("<0>Sair.\n"); 
        printf("\nOp��o: ");
 
        scanf("%d", &opcao);
        
        if(opcao==1){
        	system("cls");
        	fflush(stdin);  
			printf("\nDigite o nome do jogador 1: ");
			gets(jogar1);
		    fflush(stdin);
		    printf("\nDigite o nome do jogador 2: ");
		    gets(jogar2);
		    fflush(stdin);
		}
 
        switch(opcao)
        {
           case 1:
           case 0:
                break;
           default:
                clear();
                printf("Op��o inv�lida. Tente novamente!\n");
        }
 
    return opcao;
}
 
void clear(void)
{
    int count=0;
 
    while(count!=100)
    {
        putchar('\n');
        count++;
    }
}
 
void zeraTabuleiro(int tabuleiro[][DIM])
{
    int linha, coluna;
    for(linha=0;linha<DIM;linha++){
        for(coluna=0;coluna<DIM;coluna++){
            tabuleiro[linha][coluna] = 0;
        }
    }
}
 
void exibeTabuleiro(int tabuleiro[][DIM])
{
    int linha, coluna;
    putchar('\n');
 
    for(linha=0;linha<DIM;linha++){
        for(coluna=0;coluna<DIM;coluna++){
            if(tabuleiro[linha][coluna]==0){
                printf("   ");
            }
            else if(tabuleiro[linha][coluna]==1){
                 printf(" X ");
            }
            else{
                 printf(" O ");
 			}
            if(coluna!=(DIM-1)){
                printf("|");
            }
        }
        putchar('\n');
    }
    putchar('\n');
}
 
void jogar(int tabuleiro[][DIM])
{
    int continua;
    zeraTabuleiro(tabuleiro);
 
    do
    {
        clear();
        exibeTabuleiro(tabuleiro);
        jogada(tabuleiro);
 
    }while(checaTermino(tabuleiro, vez)!=1);
}
 
 
int checaLocal(int tabuleiro[][DIM], int linha, int coluna)
{
    if(linha<0 || linha>(DIM-1) || coluna<0 || coluna>(DIM-1) || tabuleiro[linha][coluna]!=0){
        return 0;
    }
    else{
        return 1;
    }
}
 
int checaLinha(int tabuleiro[][DIM]){
    int linha, coluna,
        soma;
 
    for(linha=0;linha<DIM;linha++){
        soma=0;
 
        for(coluna=0;coluna<DIM;coluna++){
            soma += tabuleiro[linha][coluna];
 		}
        if(soma==DIM || soma == (-1)*DIM){
            return 1;
        }
    }
 
    return 0;
}
 
int checaColuna(int tabuleiro[][DIM]){
    int linha, coluna,
        soma;
 
 
    for(coluna=0;coluna<DIM;coluna++){
        soma=0;
 
        for(linha = 0 ; linha < DIM ; linha++){
            soma += tabuleiro[linha][coluna];
        }
 
        if(soma==DIM || soma==(-1)*DIM){
            return 1;
        }
    }
 
    return 0;
}
 
int checaDiagonal(int tabuleiro[][DIM])
{
    int linha,
        diagonal_principal=0,
        diagonal_secundaria=0;
 
    for(linha=0;linha<DIM;linha++){
        diagonal_principal += tabuleiro[linha][linha];
        diagonal_secundaria += tabuleiro[linha][DIM-linha-1];
    }
 
    if(diagonal_principal==DIM || diagonal_principal==(-1)*DIM ||
       diagonal_secundaria==DIM || diagonal_secundaria==(-1)*DIM){
       return 1;
   }
 
    return 0;
}
 
int checaEmpate(int tabuleiro[][DIM])
{
    int linha, coluna;
 
    for(linha = 0 ; linha < DIM ; linha++)
        for(coluna = 0 ; coluna < DIM ; coluna++)
            if(tabuleiro[linha][coluna] == 0)
                return 0;
 
    return 1;
}
 
int checaTermino(int tabuleiro[][DIM], int vez)
{
    if(checaLinha(tabuleiro))
    {
    	system("cls");
        if(vez%2==0){
	        printf("Jogo encerrado. %s venceu !\n\n", jogar1);
	        exibeTabuleiro(tabuleiro);
	        return 1;
	    }
	   	if(vez%2==1){
	        printf("Jogo encerrado. %s venceu !\n\n", jogar2);
	        exibeTabuleiro(tabuleiro);
	        return 1;
	    }
    }
 
    if(checaColuna(tabuleiro))
    {
    	system("cls");
    	if(vez%2==0){
	        printf("Jogo encerrado. %s venceu !\n\n", jogar1);
	        exibeTabuleiro(tabuleiro);
	        return 1;
	    }
	   	if(vez%2==1){
	        printf("Jogo encerrado. %s venceu !\n\n", jogar2);
	        exibeTabuleiro(tabuleiro);
	        return 1;
	    }
    }
 
    if(checaDiagonal(tabuleiro))
    {
    	system("cls");
       	if(vez%2==0){
	        printf("Jogo encerrado. %s venceu !\n\n", jogar1);
	        exibeTabuleiro(tabuleiro);
	        return 1;
	    }
	   	if(vez%2==1){
	        printf("Jogo encerrado. %s venceu !\n\n", jogar2);
	        exibeTabuleiro(tabuleiro);
	        return 1;
	    }
    }
 
    if(checaEmpate(tabuleiro))
    {
    	system("cls");
        printf("Jogo encerrado. Deu velha !!\n\n");
        exibeTabuleiro(tabuleiro);
        return 1;
    }
 
    return 0;
}
 
void jogada(int tabuleiro[][DIM])
{
    int linha, coluna;
    vez++;
    if((vez % 2) == 0){
    	printf("\n--> %s \n", jogar1);
	}else{
    	printf("\n--> %s \n", jogar2);;
	}
 
    do
    {
        printf("Linha: ");
        scanf("%d", &linha);
        linha--;
 
        printf("Coluna: ");
        scanf("%d", &coluna);
        coluna--;
 
        if(checaLocal(tabuleiro, linha, coluna) == 0)
            printf("Posi��o ocupada ou inexistente, escolha outra.\n");
 
    } while(checaLocal(tabuleiro, linha, coluna) == 0);
 
    if(vez%2)
        tabuleiro[linha][coluna] = -1;
    else
        tabuleiro[linha][coluna] = 1;
}
 

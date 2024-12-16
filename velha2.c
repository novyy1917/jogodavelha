#include <stdio.h>
#include <stdlib.h>

int main(){
	int i, j;
	char jogo[3][3];
	int venceu = 1;
	int vez = 1;
	int fimDeJogo = 0;
	int velha = 0;
	
	char j1 = 'X';
	char j2 = 'O';
	
	void iniciar(){
		for(i = 0; i < 3; i++){
			for(j = 0; j < 3; j++){
				jogo[i][j] = 'v';
			}
		}
	}
	
	int validCoor(int x, int y){
		if(x >= 0 && x < 3){
			if(y >= 0 && y < 3 && jogo[x][y] == 'v')
				return 1;
		}
			return 0;
	}
	void vezQuem(){
		if(vez == 1){
			printf("  Vez do X!\n");
			vez = 0;
		} else {
			printf("  Vez do O!\n");
			vez = 1;
		}
	}
	
	//VERIFICAÇÃO DE VITÓRIA
	//CUIDADO TODOS OS CHARACTERES SÃO V NO MOMENTO
	
	int venceuLinhas(){
		for(i = 0; i < 3; i++){
			for(j = 0; i < 2; i++){
				if(jogo[i][j] == jogo[i][j+1]){
					if(jogo[i][j] == 'o' || jogo[i][j] == 'x'){venceu++;}
				}
			}
			if(venceu == 3){
				venceu = 1;
				return 1;
			}
			venceu = 1;
		}
		return 0;
	}
	
	int venceuCol(){
		for(i = 0; i < 3; i++){
			for(j = 0; j < 2; j++){
				if(jogo[j][i] == jogo[j+1][i]){
					if(jogo[i][j] == 'o' || jogo[i][j] == 'x'){venceu++;}
				}
			}
			if(venceu == 3){
				venceu = 1;
				return 1;
			}
		}
		venceu = 1;
		return 0;
	}
	
	int venceuDiagPri(){
		for(i = 0; i < 2; i++){
			if(jogo[i][i] == jogo[i+1][i+i]){
				if(jogo[i][j] == 'o' || jogo[i][j] == 'x'){venceu++;}
			}
		}
		if(venceu == 3){
			venceu = 1;
			return 1;
		} else {
			venceu = 1;
			return 0;
		}
	}
	
	int venceuDiagSec(){
		for(i = 0; i < 2; i++){
			if(jogo[i][3 - i - 1] == jogo[i + 1][3 - i - 2]){
				if(jogo[i][j] == 'o' || jogo[i][j] == 'x'){venceu++;}
			}
		}
		if(venceu == 3){
			return 1;
		} else {
			venceu = 1;
			return 0;
		}
	}
	
	/*
	 * x 00 01 02
	 * x 10 11 12
	 * x 20 21 22
	 *   y  y  y
	*/
	
	void renderJogo(){
		vezQuem();
		printf("  -------\n");
		for(i = 0; i < 3; i++){
			printf("%d ", i);
			for(j = 0; j < 3; j++){
				printf("|%c", jogo[i][j]);
			}
			printf("|\n");
			printf("  -------\n");
		}
		printf("X  0 1 2 Y\n");
	}
	
	void bemVindo(){
		printf("Bem vindo a Terminal da velha!\n");
	}
	
	void input(){
		int jogadaX;
		int jogadaY;
		
		printf("Digite o eixo X da sua jogada!\n");
		scanf("%d", &jogadaX);
		
		printf("Agora o eixo Y!\n");
		scanf("%d", &jogadaY);
		
		if(validCoor(jogadaX, jogadaY)){
			if(vez == 1){
				jogo[jogadaX][jogadaY] = 'x';
			} else {
				jogo[jogadaX][jogadaY] = 'o';
			}
			if(venceuLinhas() || venceuCol() || venceuDiagPri() || venceuDiagSec()){
				fimDeJogo = 1;
			}
		}
	}
	
	bemVindo();
	iniciar();
	for(i = 0; i < 9; i++){
		if(fimDeJogo == 1){
			printf("Fim de Jogo!");
			if(vez == 1){
				printf("%cvenceu!", j1);
			} else {
				printf("%cvenceu!", j2);
			}
		} else {
			renderJogo();
			input();
		}
	}
	velha = 1;
	if(velha == 1){
		printf("Deu velha!");
	}
}

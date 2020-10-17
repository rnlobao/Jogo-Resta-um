//Nome: Robson Novato Lobão
//Matrícula: 20.1.4018
//Turma: BCC201 Turma 41

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// cores e formato de texto
#define ANSI_RESET            "\x1b[0m"  
#define ANSI_BOLD             "\x1b[1m"  
#define ANSI_COLOR_BLACK      "\x1b[30m"
#define ANSI_COLOR_RED        "\x1b[31m"
#define ANSI_COLOR_GREEN      "\x1b[32m"
#define ANSI_COLOR_YELLOW     "\x1b[33m"
#define ANSI_COLOR_BLUE       "\x1b[34m"
#define ANSI_COLOR_MAGENTA    "\x1b[35m"
#define ANSI_COLOR_CYAN       "\x1b[36m"
#define ANSI_COLOR_WHITE      "\x1b[37m"
#define ANSI_BG_COLOR_BLACK   "\x1b[40m"
#define ANSI_BG_COLOR_RED     "\x1b[41m"
#define ANSI_BG_COLOR_GREEN   "\x1b[42m"
#define ANSI_BG_COLOR_YELLOW  "\x1b[43m"
#define ANSI_BG_COLOR_BLUE    "\x1b[44m"
#define ANSI_BG_COLOR_MAGENTA "\x1b[45m"
#define ANSI_BG_COLOR_CYAN    "\x1b[46m"
#define ANSI_BG_COLOR_WHITE   "\x1b[47m"

// macros para facilitar o uso
#define BOLD(string)       ANSI_BOLD             string ANSI_RESET
#define BLACK(string)      ANSI_COLOR_BLACK      string ANSI_RESET
#define BLUE(string)       ANSI_COLOR_BLUE       string ANSI_RESET
#define RED(string)        ANSI_COLOR_RED        string ANSI_RESET
#define GREEN(string)      ANSI_COLOR_GREEN      string ANSI_RESET
#define YELLOW(string)     ANSI_COLOR_YELLOW     string ANSI_RESET
#define BLUE(string)       ANSI_COLOR_BLUE       string ANSI_RESET
#define MAGENTA(string)    ANSI_COLOR_MAGENTA    string ANSI_RESET
#define CYAN(string)       ANSI_COLOR_CYAN       string ANSI_RESET
#define WHITE(string)      ANSI_COLOR_WHITE      string ANSI_RESET
#define BG_BLACK(string)   ANSI_BG_COLOR_BLACK   string ANSI_RESET
#define BG_BLUE(string)    ANSI_BG_COLOR_BLUE    string ANSI_RESET
#define BG_RED(string)     ANSI_BG_COLOR_RED     string ANSI_RESET
#define BG_GREEN(string)   ANSI_BG_COLOR_GREEN   string ANSI_RESET
#define BG_YELLOW(string)  ANSI_BG_COLOR_YELLOW  string ANSI_RESET
#define BG_BLUE(string)    ANSI_BG_COLOR_BLUE    string ANSI_RESET
#define BG_MAGENTA(string) ANSI_BG_COLOR_MAGENTA string ANSI_RESET
#define BG_CYAN(string)    ANSI_BG_COLOR_CYAN    string ANSI_RESET
#define BG_WHITE(string)   ANSI_BG_COLOR_WHITE   string ANSI_RESET

// caracteres uteis para tabelas
#define TAB_HOR "\u2501" // ━ (horizontal)
#define TAB_VER "\u2503" // ┃ (vertical)
#define TAB_TL  "\u250F" // ┏ (top-left)
#define TAB_ML  "\u2523" // ┣ (middle-left)
#define TAB_BL  "\u2517" // ┗ (bottom-left)
#define TAB_TJ  "\u2533" // ┳ (top-join)
#define TAB_MJ  "\u254B" // ╋ (middle-join)
#define TAB_BJ  "\u253B" // ┻ (bottom-join)
#define TAB_TR  "\u2513" // ┓ (top-right)
#define TAB_MR  "\u252B" // ┫ (middle-right)
#define TAB_BR  "\u251B" // ┛ (bottom-right)

//só definindo as funções usadas por enquanto
void comandoc(int C, int D, int **matriz, int n, int m);
void comandob(int C, int D, int **matriz, int n, int m);
void comandoe(int C, int D, int **matriz, int n, int m);
void comandod(int C, int D, int **matriz, int n, int m);
void printarmatriz(int **matriz, int n, int m);
void comandoajuda(int **matriz, int n, int m, int ajudas);
int **criaMatriz(int n, int m);
void liberamatriz(int **matriz, int n, int m);

//recebendo oq o usuário digitar como arquivo do jogo
int main(int argc, char *agrv[]) {
	printf("\n");
	printf("                                   ");
	printf(BOLD(BG_RED("VAMOS JOGAR RESTA UM!!")) "\n");
	printf("0 = peças\n# = casa bloqueada\n");
	//n e m vai ditar o tamanho da matriz, nessa primeira parte eu li os valores do tamanho da matriz e seus valores dentro da matriz e printei para o usuário (passei o arquivo em texto "para dentro do programa"). Sem ajudas externas
	int n, m;
	int jogadaspossiveis = 0;
	char resposta1;
	int **matriz;
	FILE *arquivo;
	//a parte da geração do jogo aleatório foi feito com a ajuda do site: http://linguagemc.com.br/valores-aleatorios-em-c-com-a-funcao-rand/ e com a ajuda do aluno Pedro Lucas, se o usuário não dar um arquivo a gente cria de acordo com uns valores aleatoriamente escolhidos e da pra ele jogar, se ele nao quiser o jogo sai
	srand(time(NULL)); 
	if (agrv[1] == NULL) {
		printf("Você não vinculou arquivo nenhum!\nDeseja criar um jogo aleatório(s/n)? ");
		scanf("%c", &resposta1);
		getchar();
		if (resposta1 == 's') {
			int aleatorio1 = 3 + rand() % 5, aleatorio2 = 3 + rand() % 5;
			arquivo = fopen("jogoaleatorio.txt", "w");
			fprintf(arquivo, "%d %d\n", aleatorio1, aleatorio2);
			n = aleatorio1;
			m = aleatorio2;
			matriz = criaMatriz(n, m);
			for (int i = 0; i < aleatorio1; i++) {
				for (int j = 0; j < aleatorio2; j++) {
					matriz[i][j] = -1 + rand() % 3; 
					fprintf(arquivo, "%d ", matriz[i][j]); }
					fprintf(arquivo, "\n");} 
			fclose(arquivo);
			n = 0; m = 0;
			arquivo = fopen("jogoaleatorio.txt", "r");
			fscanf(arquivo, "%d %d", &n, &m);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					fscanf(arquivo, "%d", &matriz[i][j]); }}} 
			
		if (resposta1 == 'n') {
			printf("Até mais então usuário!\n");
			exit(-1); }
		 }
	else if (agrv[1] != NULL) {
		arquivo = fopen(agrv[1], "r"); 
		fscanf(arquivo, "%d %d", &n, &m);
		matriz = criaMatriz(n, m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				fscanf(arquivo, "%d", &matriz[i][j]); }} }
	
	
	
	//tabuleiro feito!! Ajuda do arquivo disponibilizado no moodle (esse deu trabalho viu)
	printarmatriz(matriz, n, m);
		
	//abaixo está o menu, feito com a ajuda do arquivo disponivel no moodle, sem grandes dificuldades foi mais entender o uso dos macros.
	printf("\n");
	printf("                                         ");
	printf(WHITE(BG_BLUE("---MENU---")) "\n");
	printf("\n");
	printf(TAB_TL);
	for (int i = 0; i < 90; i++) {
		if (i == 8 || i == 16)
			printf(TAB_TJ);
		else
			printf(TAB_HOR); }
	printf(TAB_TR);
	printf("\n");
	printf(TAB_VER "Comando:"TAB_VER""BLUE("   c  ")" "TAB_VER"Digite a posição da linha e coluna da peça que movimentará para cima     " TAB_VER);
	printf("\n");
	printf(TAB_ML);
	for (int i = 0; i < 90; i++) {
		if (i == 8 || i == 16)
			printf(TAB_MJ);
		else
			printf(TAB_HOR); }
	printf(TAB_MR"\n");

	printf(TAB_VER "Comando:"TAB_VER""BLUE("   b  ")" "TAB_VER"Digite a posição da linha e coluna da peça que movimentará para baixo    " TAB_VER);
	printf("\n");
	printf(TAB_ML);
	for (int i = 0; i < 90; i++) {
		if (i == 8 || i == 16)
			printf(TAB_MJ);
		else
			printf(TAB_HOR); }
	printf(TAB_MR);
	printf("\n");
		
	printf(TAB_VER "Comando:"TAB_VER""BLUE("   e  ")" "TAB_VER"Digite a posição da linha e coluna da peça que movimentará para esquerda " TAB_VER);
	printf("\n");
	printf(TAB_ML);
	for (int i = 0; i < 90; i++) {
		if (i == 8 || i == 16)
			printf(TAB_MJ);
		else
			printf(TAB_HOR); }
	printf(TAB_MR);
	printf("\n");
	
	printf(TAB_VER "Comando:"TAB_VER""BLUE("   d  ")" "TAB_VER"Digite a posição da linha e coluna da peça que movimentará para direita  " TAB_VER);
	printf("\n");
	printf(TAB_ML);
	for (int i = 0; i < 90; i++) {
		if (i == 8 || i == 16)
			printf(TAB_MJ);
		else
			printf(TAB_HOR); }
	printf(TAB_MR);
	printf("\n");
	
	printf(TAB_VER "Comando:"TAB_VER""BLUE(" ajuda")" "TAB_VER"Digite quantos ajudas você quer ter                                      " TAB_VER);
	printf("\n");
	printf(TAB_ML);
	for (int i = 0; i < 90; i++) {
		if (i == 8 || i == 16)
			printf(TAB_MJ);
		else
			printf(TAB_HOR); }
	printf(TAB_MR);
	printf("\n");
	
	printf(TAB_VER "Comando:"TAB_VER""BLUE(" salvar")""TAB_VER"Digite para salvar seu jogo em um arquivo .txt                           " TAB_VER);
	printf("\n");
	printf(TAB_ML);
	for (int i = 0; i < 90; i++) {
		if (i == 8 || i == 16)
			printf(TAB_MJ);
		else
			printf(TAB_HOR); }
	printf(TAB_MR);
	printf("\n");

	printf(TAB_VER "Comando:"TAB_VER""BLUE(" sair ")" "TAB_VER"Digite para sair do jogo sem salvá-lo                                    " TAB_VER);
	printf("\n");
	printf(TAB_BL);
	for (int i = 0; i < 90; i++) {
		if (i == 8 || i == 16)
			printf(TAB_BJ);
		else
			printf(TAB_HOR); }
	printf(TAB_BR);
	printf("\n");



	//Agora vou to pedindo pro usuário o comando e logo após seus argumentos, está dentro de um do while pra quando o usuário digitar sair simplesmente desligar o programa.
	char total[50];
	char comando[50];
	char ajudaC, ajudaD;
	int C, D;
	int ajudas;
	do {
		printf("\nQual o seu comando e argumento (linha/coluna): ");
		fgets(total, 50, stdin);
		int tamanho = strlen(total) - 1;
		total[tamanho] = '\0';
		
		for (int i = 0; i < tamanho; i++) {
			comando[i] = total[i];
			if (total[i] == ' ') {
				comando[i] = '\0';
				break; } }

		if ((strcmp(comando, "ajuda") != 0) && (strcmp(comando, "salvar") != 0)) {
			for (int i = 0; i < tamanho; i++) {
				if (total[i] == ' ') {
					ajudaC = total[i + 1];
					ajudaD = total[i + 2];
					ajudaC -= 65;
					ajudaD -= 65;
					C = ajudaC;
					D = ajudaD;} } }

		if (strcmp(comando, "ajuda") == 0) {
			for (int i = 0; i < tamanho; i++) {
				if (total[i] == ' ') {
					ajudas = total[i + 1] - '0'; } } }
		
		//validando a entrada de dado para ver se os valores de C e D se encontram na matriz, no jogo, e se o movimento que o usuário quer fazer é de acordo com as regras. Sem ajudas externas, fiz dentro de um do while para quando ele escrever algo que nao funcione rodar o codigo de novo. A logica por trás da validação de entrada é semelhante em todos os casos alternando só pra onde o i ou j vai andar
		if (strcmp(comando, "c") == 0) {
			do {
				//usei o break para não imprimir varias mensagens de erro quando ele se enquadra em 2 erros diferentes
				//esse olha se os valores de C e D dados estão dentro dos valores de raizes
				if (C >= n || D >= m || C < 0|| D < 0) {
					printf("Por favor digite um valor adequado ao tamanho da matriz!\n\n");
					break;}
				//esse olha se o ponto escolhido é um 0 ou um -1, esses não podem ser movimentados
				if (matriz[C][D] == -1 || matriz[C][D] == 0) {
					printf("Certifique-se que a posição escolhida não tem uma peça 0 ou -1!\n\n");
					break; }
				//esse confere se a linha escolhida não é a primeira
				if (C == 0) {
					printf("Não tem como movimentar a peça para cima, essa é a primeira linha!\n\n");
					break; }
				if (C == 1) {
					printf("Não tem como movimentar a peça para cima, essa é a segunda linha!!\n\n");
					break; }
				//confere se a casa de cima é um 0 ou -1
				if (matriz[C-1][D] == 0 || matriz[C-1][D] == -1) {
					printf("A casa de cima não pode ser um 0 nem um -1\n\n");
					break; }
				//esse olha se o de cima é 1, se sim ele olha se o 2 linhas pra cima é -1 ou 1, se for não há espaço para colocar a pecinha
				if ((matriz[C-1][D] == 1) && (matriz[C-2][D] != 0)) {
					printf("Esse movimento não é possível de ser feito já que as duas casas acima não comportam outra peça!\n\n");
					break; }
				else  {
					comandoc(C, D, matriz, n, m);
					break; }	
			} while (C >= n || D >= m || C < 0|| D < 0 || matriz[C][D] == -1 || matriz[C][D] == 0 || C == 0 || C == 1 || matriz[C-1][D] == -1||  matriz[C-1][D] == 0 || ((matriz[C-1][D] == 1) && (matriz[C-2][D] != 0)) ); }

	
		if (strcmp(comando, "b") == 0) {
			do {
				//usei o break para não imprimir varias mensagens de erro quando ele se enquadra em 2 erros diferentes
				//esse olha se os valores de C e D dados estão dentro dos valores de raizes
				if (C >= n || D >= m || C < 0|| D < 0) {
					printf("Por favor digite um valor adequado ao tamanho da matriz!\n\n");
					break;}
				//esse olha se o ponto escolhido é um 0 ou um -1, esses não podem ser movimentados
				if (matriz[C][D] == -1 || matriz[C][D] == 0) {
					printf("Certifique-se que a posição escolhida não tem uma peça 0 ou -1!\n\n");
					break; }
				//esse confere se a linha escolhida não é a última
				if (C == n-1) {
					printf("Não tem como movimentar a peça para baixo, essa é a última linha!\n\n");
					break; }
				if (C == n-2) {
					printf("Não tem como movimentar a peça para baixo, essa é a penúltima linha!!\n\n");
					break; }
				//confere se a casa de baixo é um 0 um -1
				if (matriz[C+1][D] == 0 || matriz[C+1][D] == -1) {
					printf("A casa de baixo não pode ser um 0 nem um -1\n\n");
					break; }
				//esse olha se o de baixo é 1, se sim ele olha se o 2 linhas pra baixo é -1 ou 1, se for não há espaço para colocar a pecinha
				if ((matriz[C+1][D] == 1) && (matriz[C+2][D] != 0)) {
					printf("Esse movimento não é possível de ser feito já que as duas casas abaixo não comportam outra peça!\n\n");
					break; }
				else  {
					comandob(C, D, matriz, n, m);
					break; }	
			} while (C >= n || D >= m || C < 0|| D < 0 || matriz[C][D] == -1 || matriz[C][D] == 0 || C == n-1 || C == n-2 || matriz[C+1][D] == -1 || matriz[C+1][D] == 0 || ((matriz[C+1][D] == 1) && (matriz[C+2][D] != 0)) ); }
		
		if (strcmp(comando, "e") == 0) {
			do {
				//usei o break para não imprimir varias mensagens de erro quando ele se enquadra em 2 erros diferentes
				//esse olha se os valores de C e D dados estão dentro dos valores de raizes
				if (C >= n || D >= m || C < 0|| D < 0) {
					printf("Por favor digite um valor adequado ao tamanho da matriz!\n\n");
					break;}
				//esse olha se o ponto escolhido é um 0 ou um -1, esses não podem ser movimentados
				if (matriz[C][D] == -1 || matriz[C][D] == 0) {
					printf("Certifique-se que a posição escolhida não tem uma peça 0 ou -1!\n\n");
					break; }
				//esse confere se o lugar escolhido não está na borda
				if (D == 0) {
					printf("Não tem como movimentar a peça para esquerda, a borda é logo ali!\n\n");
					break; }
				if (D == 1) {
					printf("Não tem como movimentar a peça para esquerda, a borda está a 2 casas de distância!!\n\n");
					break; }
				//confere se a casa da esquerda é um 0 ou -1
				if (matriz[C][D-1] == 0 || matriz[C][D-1] == -1) {
					printf("A casa da esquerda não pode ser um 0 nem um -1\n\n");
					break; }
				//esse olha se o da esquerda é 1, se sim ele olha se o 2 casas para esquerda é -1 ou 1, se for não há espaço para colocar a pecinha	
				if ((matriz[C][D-1] == 1) && (matriz[C][D-2] != 0)) {
					printf("Esse movimento não é possível de ser feito já que as duas casas para esquerda não comportam outra peça!\n\n");
					break; }
				else  {
					comandoe(C, D, matriz, n, m);
					break; }	
			} while (C >= n || D >= m || C < 0|| D < 0 || matriz[C][D] == -1 || matriz[C][D] == 0 || D == 0 || D == 1 || matriz[C][D-1] == 0 || matriz[C][D-1] == 0 || ((matriz[C][D-1] == 1) && (matriz[C][D-2] != 0)) ); }
		
		
		if (strcmp(comando, "d") == 0) {
			do {
				//usei o break para não imprimir varias mensagens de erro quando ele se enquadra em 2 erros diferentes
				//esse olha se os valores de C e D dados estão dentro dos valores de raizes
				if (C >= n || D >= m || C < 0|| D < 0) {
					printf("Por favor digite um valor adequado ao tamanho da matriz!\n\n");
					break;}
				//esse olha se o ponto escolhido é um 0 ou um -1, esses não podem ser movimentados
				if (matriz[C][D] == -1 || matriz[C][D] == 0) {
					printf("Certifique-se que a posição escolhida não tem uma peça 0 ou -1!\n\n");
					break; }
				//esse confere se o lugar escolhido não está na borda
				if (D == n-1) {
					printf("Não tem como movimentar a peça para direita, a borda é logo ali!\n\n");
					break; }
				if (D == n-2) {
					printf("Não tem como movimentar a peça para direita, a borda está a 2 casas de distância!!\n\n");
					break; }
				//confere se a casa da direita é um 0 ou -1
				if (matriz[C][D+1] == 0 || matriz[C][D+1] == -1) {
					printf("A casa da direita não pode ser um 0\n\n");
					break; }
				//esse olha se o da direita é 1, se sim ele olha se o 2 casas para direita é -1 ou 1, se for não há espaço para colocar a pecinha	
				if ((matriz[C][D+1] == 1) && (matriz[C][D+2] != 0)) {
					printf("Esse movimento não é possível de ser feito já que as duas casas para direita não comportam outra peça!\n\n");
					break; }
				else  {
					comandod(C, D, matriz, n, m);
					break; }	
			} while (C >= n || D >= m || C < 0|| D < 0 || matriz[C][D] == -1 || matriz[C][D] == 0 || D == n-1 || D == n-2 || matriz[C][D+1] == -1 || matriz[C][D+1] == 0 || ((matriz[C][D+2] == 1) && (matriz[C][D+2] != 0)) ); }
	
		//esse comando foi bem trabalhoso, lá embaixo explico mais sobre os problemas
		if (strcmp(comando, "ajuda") == 0) {
			comandoajuda(matriz, n, m, ajudas); }
			
		//nada demais ele só pega o nome que o usuário quer dar ao seu arquivo e salva no diretório, fiz alguns malabarismos desenvolvedores para não printar um \n junto com o nome do arquivo, basicamente eu dou um fopen "w" é um arquivo com nome dado pelo usuário.
		if (strcmp(comando, "salvar") == 0) {
			char nomedojogosalvo[100];
			for (int i = 0; i <= tamanho; i++) {
				if (total[i] == ' ') {
					for (int j = 0; j < tamanho; j++) {
						nomedojogosalvo[j] = total[i + j + 1]; } } }
			int tamanhodonomejogosalvo = strlen(nomedojogosalvo);
			nomedojogosalvo[tamanhodonomejogosalvo] = '\0';
			FILE *jogosalvo = fopen(nomedojogosalvo, "w");
			fprintf(jogosalvo, "%d %d\n\n", n, m);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) { 
					fprintf(jogosalvo, "%2d ", matriz[i][j]);}
				fprintf(jogosalvo, "\n");}  
			fclose(jogosalvo);
			printf("Seu jogo foi salvo como: %s\n", nomedojogosalvo);
			continue;} 
			
		//sabendo se o jogador ganhou ou nao, é um mecanismo simples de contagem de pinos, se tiver apenas um, significa que ele ganhou
		int contadorde1 = 0;
		for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) { 
					if (matriz[i][j] == 1)
						contadorde1++; }}
		if (contadorde1 == 1) {
			printf("\n"BOLD(BG_BLUE("VOCÊ GANHOU PARABÉNS!!")) "\n");	
			break; }
			
		//sabendo se o jogador já perdeu. Aqui nos deparamos com um grande problema, durante muito tempo eu fiquei tentando prever até as 2 últimas jogadas, mas foi além da minha capacidade, esse detector de derrota é bem enrolado e só avisa quando realmente não há jogadas possíveis, basicamente procura os 1s e olha se perto deles tem um outro 1 com um 0 logo após, se não houver nenhum ai ela printa que perdeu e encerra o jogo. Ajuda do aluno Pedro Lucas e Augusto Guilarducci
		for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (matriz[j][i] == 1) {
						if (((i+2 < n)) && (i+1 >= 0) && (matriz[i+1][j] == 1) && (matriz[i+2][j] == 0))
							jogadaspossiveis++;
						if (((i-2 >= 0)) && (i-1 >= 0) &&(matriz[i-1][j] == 1) && (matriz[i-2][j] == 0))
							jogadaspossiveis++;
						if (((j+2 < m) && (j+1 >= 0)) && (matriz[i][j+1] == 1) && (matriz[i][j+2] == 0))
							jogadaspossiveis++;
						if (((j-2 >= 0) && (j-1 >= 0)) && (matriz[i][j-1] == 1) && (matriz[i][j-2] == 0)) 
							jogadaspossiveis++;  } } }
		if (jogadaspossiveis == 0) {
			printf("\n"BOLD(BG_RED("VOCÊ PERDEU MAIS SORTE NA PRÓXIMA!!")) "\n");
			break; }
		jogadaspossiveis = 0; 	
	} while (strcmp(total, "sair") != 0);	
	fclose(arquivo);
	liberamatriz(matriz, n, m);
	return 0;}
		
void comandoc(int C, int D, int **matriz, int n, int m) {
//aqui foram feitos os movimentos, se chegou aqui significa que o movimento é possível entao o valor escolhido vira 0, o respectivo tambem e o respectivo2 vira 1. Sem ajuda externa.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((i == C) && (j == D)) {
				matriz[i][j] = 0; }
			else if ((i == C-2) && (j == D)) {
				matriz[i][j] = 1; }
			else if ((i == C-1) && (j == D)) {
				matriz[i][j] = 0; } } }
	printarmatriz(matriz, n, m);} 
	
//os raciocinios foram identicos só alterando de acordo com a direçãp
void comandob(int C, int D, int **matriz, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((i == C) && (j == D)) {
				matriz[i][j] = 0; }
			else if ((i == C+2) && (j == D)) { 
				matriz[i][j] = 1; }
			else if ((i == C+1) && (j == D)) {
				matriz[i][j] = 0; } } }
	printarmatriz(matriz, n, m);}

void comandoe(int C, int D, int **matriz, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((i == C) && (j == D)) {
				matriz[i][j] = 0; }
			else if ((i == C) && (j == D-2)) { 
				matriz[i][j] = 1; }
			else if ((i == C) && (j == D-1)) {
				matriz[i][j] = 0; } } }
	printarmatriz(matriz, n, m);}
	

void comandod(int C, int D, int **matriz, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((i == C) && (j == D)) {
				matriz[i][j] = 0; }
			else if ((i == C) && (j == D+2)) {
				matriz[i][j] = 1; }
			else if ((i == C) && (j == D+1)) {
				matriz[i][j] = 0; } } }
	printarmatriz(matriz, n, m); }

	
	// esse comando lê a matriz, que tá sempre sendo atualizada ai durante o jogo, printa ela de acordo com umas regrinhas que eu dei pra fazer um tabuleiro mais bonito usando os arquivos do moodle, a implemntação dessa função foi a mais essencial na minha opinião, até cerca de 50% do trabalho eu ficava copiando e colando essa formulazinha, implementando a função eu poupei umas boas linhas de código.
void printarmatriz(int **matriz, int n, int m) {
	printf("\n");
	printf("    ");
	for (int j = 0; j < m; j++) {
		printf(" %-2c", j + 65 ); }
	printf("\n");		
	for (int i = 0; i <= (m * 3); i++) {
		if (i == 0) {
			printf("   "TAB_TL); }
		if (i == (m * 3)) {
			printf(TAB_TR); }
		else {
			printf(TAB_HOR);} }
	printf("\n");		
	for (int i = 0; i < n; i++) {
		printf(" %2c", i + 65);
		printf(TAB_VER);
		for (int j = 0; j < m; j++) {
			if (i % 2 == 0) {
				if (j % 2 == 0) {
					if (matriz[i][j] == 0)
						printf(BG_BLUE("   "));
					if (matriz[i][j] == 1)
						printf(BG_BLUE(" 0 "));
					if (matriz[i][j] == -1)
						printf(BG_BLUE(" # ")); }			
				else {
					if (matriz[i][j] == 0)
						printf(BG_RED("   "));
					if (matriz[i][j] == 1)
						printf(BG_RED(" 0 "));
					if (matriz[i][j] == -1)
						printf(BG_RED(" # ")); } }
			else {
				if ((j + 1) % 2 == 0) {
					if (matriz[i][j] == 0)
						printf(BG_BLUE("   "));
					if (matriz[i][j] == 1)
						printf(BG_BLUE(" 0 "));
					if (matriz[i][j] == -1)
						printf(BG_BLUE(" # ")); }
				else {
					if (matriz[i][j] == 0)
						printf(BG_RED("   "));
					if (matriz[i][j] == 1)
						printf(BG_RED(" 0 "));
					if (matriz[i][j] == -1)
						printf(BG_RED(" # ")); } } }
		printf(TAB_VER);
		printf("\n");}
	for (int i = 0; i <= (m * 3); i++) {
		if (i == 0) {
			printf("   "TAB_BL); }
		if (i == (m * 3)) {
			printf(TAB_BR); }
		else {
			printf(TAB_HOR);} }
	printf("\n"); }
	
	
//cara essa questão da ajuda foi muito complexa, devido ao fato de ter que ter uma noção de para onde o jogo vai caminhar. Ajuda do aluno Augusto guilarducci, Pedro Lucas http://linguagemc.com.br/o-comando-break/
//na parte do loop de matrizes eu ia conferindo se tem jogada possivel ai add 1 no contador e se é = ao numero que o usuario digitou, se sim ai acaba e já zera se quiser usar a função ajuda de novo
void comandoajuda(int **matriz, int n, int m, int ajudas) {
	int contadordeajuda = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matriz[i][j] == 1) {
				if (((j+2 < m)) && (j+1 >= 0) && (matriz[i][j+1] == 1) && (matriz[i][j+2] == 0)) {
					printf("Movimento sugerido: %c %c para direita\n", i+65, j+65);
					matriz[i][j] = 0;
					matriz[i][j+1] = 0;
					matriz[i][j+2] = 1;
					printarmatriz(matriz, n, m);
					contadordeajuda++;}
				else if (((j-2 >= 0)) && (j-1 >= 0) && (matriz[i][j-1] == 1) && (matriz[i][j-2] == 0)) {
					printf("Movimento sugerido: %c %c para esquerda\n", i+65, j+65); 
					matriz[i][j] = 0;
					matriz[i][j-2] = 0;
					matriz[i][j-2] = 1;
					printarmatriz(matriz, n, m);
					contadordeajuda++;}
				else if (((i+2 < n) && (i+1 >= 0)) && (matriz[i+1][j] == 1) && (matriz[i+2][j] == 0)) {
					printf("Movimento sugerido: %c %c para baixo\n", i+65, j+65);
					matriz[i][j] = 0;
					matriz[i+1][j] = 0;
					matriz[i+2][j] = 1;
					printarmatriz(matriz, n, m); 
					contadordeajuda++;}
				else if (((i-2 >= 0) && (i-1 >= 0)) && (matriz[i-1][j] == 1) && (matriz[i-2][j] == 0)) {
					printf("Movimento sugerido: %c %c para cima\n", i+65, j+65);
					matriz[i][j] = 0;
					matriz[i-1][j] = 0;
					matriz[i-2][j] = 1;
					printarmatriz(matriz, n, m);
					contadordeajuda++;} 
			if (contadordeajuda == ajudas)
				break;} 
		if (contadordeajuda == ajudas)
			break;} 
	if (contadordeajuda == ajudas)
			break;} 
	contadordeajuda = 0;
}

//alocando a matriz dinamicamente
int **criaMatriz(int n, int m) {
	int **matriz;
	matriz = malloc(n *sizeof(int*));
	for (int i = 0; i < n; i++) {
		matriz[i] = malloc(m * sizeof(int)); }
	return matriz; }
	
//libernado a memoria da matriz
void liberamatriz(int **matriz, int n, int m) {
	for (int i = 0; i < n; i++) {
		free(matriz[i]); }
	free(matriz); }


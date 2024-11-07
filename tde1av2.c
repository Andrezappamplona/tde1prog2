PARTE - 1
//1.Contar Produtos Abaixo de um Valor: Crie um programa que conte quantos produtos têm
um valor abaixo de um determinado valor fornecido pelo usuário.
#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 5

// Definindo a struct para o produto
typedef struct {
int id;
char nome[50];
float valor;
} Produto;

int main() {
Produto produtos[MAX_PRODUTOS];
int quantidade, i;
float valorLimite;
int contador = 0;

// Lendo a quantidade de produtos e verificando o limite
printf("Digite a quantidade de produtos (máximo %d): ", MAX_PRODUTOS);
scanf("%d", &quantidade);

if (quantidade > MAX_PRODUTOS) {
printf("A quantidade de produtos excede o limite de %d.\n", MAX_PRODUTOS);
return 1;
}

// Lendo os dados dos produtos

for (i = 0; i < quantidade; i++) {
printf("Produto %d:\n", i + 1);
printf("ID: ");
scanf("%d", &produtos[i].id);

printf("Nome: ");
getchar(); // Limpa o buffer para evitar problemas com fgets
fgets(produtos[i].nome, sizeof(produtos[i].nome), stdin);
produtos[i].nome[strcspn(produtos[i].nome, "\n")] = '\0'; // Remove o '\n' do final da
string

printf("Valor: ");
scanf("%f", &produtos[i].valor);
}

// Lendo o valor limite
printf("Digite o valor limite: ");
scanf("%f", &valorLimite);

// Contando produtos abaixo do valor limite
for (i = 0; i < quantidade; i++) {
if (produtos[i].valor < valorLimite) {
contador++;
}
}

// Exibindo o resultado
printf("Quantidade de produtos abaixo de R$ %.2f: %d\n", valorLimite, contador);

return 0;
}

//2. Buscar Produto pelo ID: Implemente um programa que permita ao usuário buscar um
produto pelo ID. Se o produto for encontrado, exiba suas informações; caso contrário, informe
que não foi encontrado.
int main() {
#include <stdio.h>

Produto* buscarPorID(Produto produtos[], int tamanho, int id) {
for (int i = 0; i < tamanho; i++) {
if (produtos[i].id == id) {
return &produtos[i];
}
}
return NULL;
}

Produto produtos[MAX_PRODUTOS];
// Lógica para leitura dos produtos...
int id;
printf("Digite o ID do produto que deseja buscar: ");
scanf("%d", &id);

Produto* encontrado = buscarPorID(produtos, MAX_PRODUTOS, id);
if (encontrado) {
printf("Produto encontrado: ID %d, Nome: %s, Valor: %.2f\n", encontrado->id,
encontrado->nome, encontrado->valor);
} else {
printf("Produto não encontrado.\n");
}
return 0;
}

// 3 - Atualizar Valor do Produto: Desenvolva um programa que permita ao usuário atualizar o
valor de um produto com base no seu ID.

#include <stdio.h>

void atualizarValor(Produto produtos[], int tamanho, int id, float novoValor) {
for (int i = 0; i < tamanho; i++) {
if (produtos[i].id == id) {
produtos[i].valor = novoValor;
printf("Valor do produto ID %d atualizado para %.2f\n", id, novoValor);
return;
}
}
printf("Produto com ID %d não encontrado.\n", id);
}

int main() {
Produto produtos[MAX_PRODUTOS];
// Lógica para leitura dos produtos...
int id;
float novoValor;
printf("Digite o ID do produto a ser atualizado: ");
scanf("%d", &id);
printf("Digite o novo valor: ");
scanf("%f", &novoValor);
atualizarValor(produtos, MAX_PRODUTOS, id, novoValor);
return 0;
}

//4.Calcular Média de Preços: Implemente um programa que calcule e retorne a média dos
preços dos produtos.

#include <stdio.h>

float calcularMedia(Produto produtos[], int tamanho) {
float soma = 0;
for (int i = 0; i < tamanho; i++) {
soma += produtos[i].valor;
}
return soma / tamanho;
}

int main() {
Produto produtos[MAX_PRODUTOS];
// Lógica para leitura dos produtos...
float media = calcularMedia(produtos, MAX_PRODUTOS);
printf("A média dos preços dos produtos é: %.2f\n", media);
return 0;
}

//5.Exibir Produtos Acima da Média: Crie um programa que exiba todos os produtos cujo preço
é superior à média calculada.

#include <stdio.h>

void exibirAcimaMedia(Produto produtos[], int tamanho, float media) {
printf("Produtos acima da média (%.2f):\n", media);
for (int i = 0; i < tamanho; i++) {
if (produtos[i].valor > media) {
printf("ID: %d, Nome: %s, Valor: %.2f\n", produtos[i].id, produtos[i].nome,
produtos[i].valor);

}
}
}

int main() {
Produto produtos[MAX_PRODUTOS];
// Lógica para leitura dos produtos...
float media = calcularMedia(produtos, MAX_PRODUTOS);
exibirAcimaMedia(produtos, MAX_PRODUTOS, media);
return 0;
}

PARTE 2
1 - Cadastro de Clubes: Crie um programa que permita ao usuário cadastrar um número
determinado de clubes (por exemplo, 10). Para cada clube, solicite que o usuário insira
o ID, nome, vitórias, empates, derrotas, gols pró e gols contra. O programa deve calcular
a pontuação de cada clube com base em suas vitórias, empates e derrotas. A pontuação deve ser calculada da seguinte forma: 3 pontos por vitória, 1 ponto por
empate, 0 pontos por derrota. Exiba a pontuação total de cada clube. #include <stdio.h>
#define MAX_CLUBES 10
// Definindo a struct para o Clube
typedef struct {
int id;
char nome[50];
int vitorias;
int empates;
int derrotas;
int gols_pro;
int gols_contra;
int pontos;

} Clube;
void calcularPontuacao(Clube *clube) {
clube->pontos = (clube->vitorias * 3) + (clube->empates * 1);
}
int main() {
Clube clubes[MAX_CLUBES];
int quantidade, i;

printf("Digite a quantidade de clubes (até %d): ", MAX_CLUBES);
scanf("%d", &quantidade);
for (i = 0; i < quantidade; i++) {
printf("Clube %d:\n", i + 1);
printf("ID: ");
scanf("%d", &clubes[i].id);
printf("Nome: ");
scanf(" %[^\n]s", clubes[i].nome);
printf("Vitórias: ");
scanf("%d", &clubes[i].vitorias);
printf("Empates: ");
scanf("%d", &clubes[i].empates);
printf("Derrotas: ");
scanf("%d", &clubes[i].derrotas);
printf("Gols Pró: ");
scanf("%d", &clubes[i].gols_pro);
printf("Gols Contra: ");
scanf("%d", &clubes[i].gols_contra);

calcularPontuacao(&clubes[i]);
printf("Pontuação total do clube %s: %d\n", clubes[i].nome, clubes[i].pontos);
}
return 0;
}
2 - Buscar Clube pelo ID: Desenvolva um programa que permita ao usuário buscar um
clube pelo ID. Se o clube for encontrado, exiba suas informações; caso contrário, informe que não foi encontrado. #include <stdio.h>
#include <string.h>
void buscarClubePorID(Clube clubes[], int quantidade, int id) {
int encontrado = 0;
for (int i = 0; i < quantidade; i++) {
if (clubes[i].id == id) {
encontrado = 1;
printf("Clube encontrado:\n");
printf("ID: %d\nNome: %s\nVitórias: %d\nEmpates: %d\nDerrotas: %d\nGols Pró:
%d\nGols Contra: %d\nPontuação: %d\n", clubes[i].id, clubes[i].nome, clubes[i].vitorias, clubes[i].empates, clubes[i].derrotas, clubes[i].gols_pro, clubes[i].gols_contra, clubes[i].pontos);
break;
}
}
if (!encontrado) {
printf("Clube com ID %d não encontrado.\n", id);
}
}
3 - Exibir Clubes com Gols Pró Acima da Média: Crie um programa que calcule a média
de gols pró de todos os clubes e exiba apenas os clubes que têm um número de gols
pró superior a essa média.

#include <stdio.h>
float calcularMediaGolsPro(Clube clubes[], int quantidade) {
int totalGolsPro = 0;
for (int i = 0; i < quantidade; i++) {
totalGolsPro += clubes[i].gols_pro;
}
return (float)totalGolsPro / quantidade;
}
void exibirClubesAcimaMediaGolsPro(Clube clubes[], int quantidade) {
float mediaGolsPro = calcularMediaGolsPro(clubes, quantidade);
printf("Clubes com gols pró acima da média (%.2f):\n", mediaGolsPro);
for (int i = 0; i < quantidade; i++) {
if (clubes[i].gols_pro > mediaGolsPro) {
printf("Nome: %s | Gols Pró: %d\n", clubes[i].nome, clubes[i].gols_pro);
}
}
}
4 - Exibir saldo de gols: Crie um programa que calcule o saldo de gols de todos os
clubes e exiba o nome e o saldo de cada clube. #include <stdio.h>
void exibirSaldoGols(Clube clubes[], int quantidade) {
printf("Saldo de gols de cada clube:\n");
for (int i = 0; i < quantidade; i++) {
int saldoGols = clubes[i].gols_pro - clubes[i].gols_contra;
printf("Nome: %s | Saldo de Gols: %d\n", clubes[i].nome, saldoGols);
}
}

5 – Exibir dados do melhor e do pior clube: Crie um programa que exiba os dados do
clube campeão e do último colocado. #include <stdio.h>
void exibirSaldoGols(Clube clubes[], int quantidade) {
printf("Saldo de gols de cada clube:\n");
for (int i = 0; i < quantidade; i++) {
int saldoGols = clubes[i].gols_pro - clubes[i].gols_contra;
printf("Nome: %s | Saldo de Gols: %d\n", clubes[i].nome, saldoGols);
}
}

#include <stdio.h>
#include <string.h>
#include <string.h>
#include <ctype.h>

// Define o tamanho da tabela hash
#define TAMANHO 5571

// Define uma estrutura para armazenar os dados do município
typedef struct {
  char nome[50]; // Nome do município
  char estado[3]; // Sigla do estado
  // Outros campos que sejam necessários
} Municipio;

// Define uma função hash que recebe o nome e o estado do município e retorna um valor entre 0 e TAMANHO-1
int hash_municipio(char *nome, char *estado) {
  int valor = 0;
  for (int i = 0; nome[i] != '\0'; i++) {
    nome[i] = toupper(nome[i]);
  }
  for (int i = 0; estado[i] != '\0'; i++) {
    estado[i] = toupper(estado[i]);
  }
  int i = 0, j = 0;
  while (nome[i] != '\0' || estado[j] != '\0') {
    valor = (valor * 31 + nome[i]) * 31 + estado[j];
    i++;
    j++;
  }
  return valor % TAMANHO;
}

// Exemplo de uso da função hash
int main() {
  // Cria um vetor de municípios
  Municipio municipios[5] = {
    {"Santa Terezinha de Itaipu", "PR"},
    {"São Paulo", "SP"},
    {"Rio de Janeiro", "RJ"},
    {"Porto Alegre", "RS"},
    {"Belo Horizonte", "MG"}
  };
  // Calcula e imprime o valor do hash para cada município
  for (int i = 0; i < 5; i++) {
    int valor = hash_municipio(municipios[i].nome, municipios[i].estado);
    printf("O valor do hash para %s - %s é %d\n", municipios[i].nome, municipios[i].estado, valor);
  }
  return 0;
}


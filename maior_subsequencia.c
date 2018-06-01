#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

#define TAMREGISTROS 10
#define LIMPA_BUFFER __fpurge(stdin)

#ifdef WIN32
    #define LIMPA_TELA system("cls")
#else
    #define LIMPA_TELA system("clear")
#endif

void preencheRegistros(int *registros){
    int i;
    for (i = 0; i < TAMREGISTROS; ++i){
      registros[i] = rand() % (TAMREGISTROS+300);
    }
}

int maximo(int maiorSequencia, int atual){
  return maiorSequencia > atual ? maiorSequencia : atual;
}

int tamMaiorSequenciaQuadratica(int *registros,int *tamSubSequencias,int *predecessor){
  //Código para identificar maior sequencia
  int j, i, maiorSequencia;

  for(j=1; j<= TAMREGISTROS; j++){
    tamSubSequencias[j] = 1;
    predecessor[j] = 0;
    for(i=1; i<= j-1; i++){
      if((registros[i]<registros[j]) && (tamSubSequencias[i] + 1 > tamSubSequencias[j])){
        tamSubSequencias[j] = tamSubSequencias[i] + 1;
        predecessor[j] = i;
      }
    }
  }

  maiorSequencia = 0;

  for(i=1; i<= TAMREGISTROS; i++){
    maiorSequencia = maximo(maiorSequencia, tamSubSequencias[i]);
  }

  return maiorSequencia;
}

void maiorSequenciaX(int *tamSubSequencias,int maiorSequencia, int *predecessor, int *registros){
  int j = 0;

  while(tamSubSequencias[j] != maiorSequencia){
    j = j + 1;
  };

  while(j>0){
    printf(" %d ", registros[j] );
    j = predecessor[j];
  }
}

void imprimeRegistros(int *registros){
  int i;
  printf("\n\nREGISTROS\n");
  printf("--------------------------------------------\n" );
  for (i = 0; i < TAMREGISTROS; i++){
    printf("%d - ",registros[i]);
  }
}

int menu(){
  int op;
  printf("\n\n\n======================================== MENU =====================================================\n");
  printf("1 - Maior Sequencia Crescente em O(n^2)\n");
  printf("2 - Printar o vetor original\n");
  printf("0 - SAIR");
  printf("\n\n");
  printf("Digite a opcao desejada: ");
  scanf("%d", &op);
  return op;
}


int main(){

  int registros[TAMREGISTROS], opcao, maiorSequencia;
  int tamSubSequencias[TAMREGISTROS+1], predecessor[TAMREGISTROS+1];

  preencheRegistros(registros);

  do{
    opcao = menu();
    switch (opcao) {
      case 0: printf("Encerrando ...\n");
      break;
      case 1:
        LIMPA_TELA;
        maiorSequencia = tamMaiorSequenciaQuadratica(registros, tamSubSequencias, predecessor);
        printf("\nA maior sequencia possui %d elementos", maiorSequencia);
        maiorSequenciaX(tamSubSequencias,maiorSequencia,predecessor,registros);
      break;
      case 2:
        LIMPA_TELA;
        imprimeRegistros(registros);
      break;
      default:
        printf("Opcao Inexistente\n");
    }
  }while (opcao!=0);
  return 0;
}

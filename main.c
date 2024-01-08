

#include <stdio.h>

int main(void) {


  // TRABALHO PIZZARIA: Fabiano Bastos Hugo Martins / Matheus Oliveira
  
  

  
      //VETORES
  
    int codigosDoPedido[10];
    float valorPedidosPizza[5];
    int qtdDeItensPedido[10];    
    char sexoClientes[5];


     //VARIAVEIS PARA OS CLIENTES
  
    int clientesMulheres = 0;
    int clientesNaoInformaramSexo = 0; 
    
     //VARIAVEIS PARA SOMAR
  
    float somaCompraHomens = 0;
    float valorPedidosTotal = 0;
    
    
     // VARIAVEIS PARA OPCOES
  
    int opcao = 0;
    char voltar;

    //VARIAVEIS PRA MEDIA, VALORES ACIMA E ABAIXO DE 40 REAIS
  
  int itensSexoNaoInformado = 0;
  int valoresAbaixo = 0;
  int valoresAcima = 0;
  float valorCompraExaminar=0;
  float mediaCompras=0;

   int codigoMaisVendidos=0;
   int numeroDeVendas = 0;



  //PROCESSAMENTO!!!!


  
     printf("BEM VINDO A PARMÊ PIZZARIA!!!\n\n");



  
    // CADASTRANDO OS PEDIDOS DA PIZZARIA
  
    for (int i = 0; i < 5; i++) {
        printf("DIGITE UM CÓDIGO ENTRE 01 E 10: ");
        scanf("%d", &codigosDoPedido[i]);
      

        while (codigosDoPedido[i] < 1 || codigosDoPedido[i] > 10) {
            printf("Erro: Código Inválido!!!! Digite um código válido: ");
            scanf("%d", &codigosDoPedido[i]);
                     }


      

             printf("ITENS QUE FORAM VENDIDOS: ");
             scanf("%d", &qtdDeItensPedido[i]);

      

        while (qtdDeItensPedido[i] < 0) {
            printf("Quantidade Inválida, Informar um valor Válido: ");
            scanf("%d", &qtdDeItensPedido[i]);          
        }

      

        printf("SEXO (f, m ou n Caso não queira informar): ");
        scanf(" %c", &sexoClientes[i]);

        if (sexoClientes[i] == 'f' || sexoClientes[i] == 'F') {
            clientesMulheres++;
        } else if (sexoClientes[i] == 'n' || sexoClientes[i] == 'N') {
            clientesNaoInformaramSexo++;
        }

        printf("VALOR DO PEDIDO: R$ ");
        scanf("%f", &valorPedidosPizza[i]);

        while (valorPedidosPizza[i] < 0) {
            printf("Pedido de valor inválido, Favor Informar um valor Válido: ");
            scanf("%f", &valorPedidosPizza[i]);
        }

        valorPedidosTotal += valorPedidosPizza[i];

        printf("\nPARABÉNS! CADASTRO FINALIZADO\n\n");
    }

    do {

      
        //CODIGO PARA O MENU PRINCIPAL


      
        printf("MENU PRINCIPAL\n");
        printf("Qual opção você deseja?\n");
        printf("1 - Informações específicas de um código\n");
        printf("2 - Informações de todos os pedidos cadastrados\n");
        printf("3 - Finalizar o programa\n");
        printf("R: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:


              
                // SE DIGITAR A OPCAO 01 É PRA PERGUNTAR QUAL CODIGO EU QUERO PROCURAR


              
                printf("DIGITE O CÓDIGO: ");
                int codigoDigitado;
                scanf("%d", &codigoDigitado);



              int codigoVerificado=0;

                for (int i = 0; i < 10; i++) {
                    if (codigoDigitado == codigosDoPedido[i]) {
                        printf("Valor Gasto pelo código %d: R$ %.2f\n", codigosDoPedido[i], valorPedidosPizza[i]);
                        printf("Este cliente é do sexo: %c\n", sexoClientes[i]);

                        codigoVerificado=1;
                      
                      
                      
                    }
                }

                  if(!codigoVerificado){



                    printf("CÓDIGO %d NÃO FOI ENCONTRADO!\n",codigoDigitado);
                    
                    
                  }

              
                break;

            case 2:
                // SE DIGITAR A OPCAO 02 É PRA INFORMAR TUDO SOBRE AQUELE PEDIDO

                
                valoresAbaixo = 0;
                valoresAcima = 0;
               itensSexoNaoInformado = 0;
                
                printf("Digite um valor de pedido: ");
                scanf("%f", &valorCompraExaminar);

                for (int i = 0; i < 5; i++) {
                    if ( 40 > valorPedidosPizza[i]) {
                        valoresAbaixo++;
                    }
                    if ( valorCompraExaminar < valorPedidosPizza[i]) {
                        valoresAcima++;
                    }
                }


              
                printf("EXISTEM %d valores abaixo de R$40 reais\n", valoresAbaixo);

              
                printf("EXISTEM %d valores acima de R$%.2f\n", valoresAcima, valorCompraExaminar);

              
                printf("EXISTEM %d pedidos feitos por mulheres!\n", clientesMulheres);
              
                printf("EXISTEM %d clientes que não informaram o sexo.\n", clientesNaoInformaramSexo);

              
                printf("VALOR TOTAL DE PEDIDOS: R$ %.2f\n", valorPedidosTotal);


              
                mediaCompras = valorPedidosTotal / 5;


              
                printf("VALOR MÉDIO DE PEDIDOS: R$ %.2f\n", mediaCompras);


              


              for (int i = 0; i < 5; i++) {
                  if (sexoClientes[i] == 'n' || sexoClientes[i] == 'N') {
                      itensSexoNaoInformado += qtdDeItensPedido[i];
                  }
              }

              
                printf("Qtde itens por pessoas que não informaram o sexo: %d\n", itensSexoNaoInformado);
              


              int codigoMaisVendidos=0;
               int numeroDeVendas = 0;
              
              for (int i = 0; i < 5; i++) {
                if (qtdDeItensPedido[i] > numeroDeVendas) {
                    codigoMaisVendidos = codigosDoPedido[i];
                    numeroDeVendas = qtdDeItensPedido[i];
                }
              }

              printf("Código mais vendido: CÓDIGO %d (ITENS VENDIDOS: %d)\n", codigoMaisVendidos, numeroDeVendas);

           
              break;
          

            case 3:
                // SE DIGITAR A OPCAO 03 É PARA SAIR DO PROGRAMA
                voltar = 'n';
                break;
        }

        if (voltar != 'n') {
            printf("Deseja retornar ao menu? (s ou n): \n ");
            scanf(" %c", &voltar);
        }

    } while (voltar == 's');

    printf("Programa finalizado!");

    return 0;
}


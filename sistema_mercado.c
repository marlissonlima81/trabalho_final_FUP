#include <stdio.h>
#include <stdlib.h>
#include <string.h>


float Caixa();
void MenuProduto();
void MenuPrincipal();
void AdicionarProdutos();


typedef struct{
    float preco;

}DadosProdutos;
//falta adicionar mais produtos e encontrar uma maneira mais pratica de adicionar novos produtos pelo arquivo de texto
DadosProdutos leite,arroz,queijo,maca;







void AdicionarProdutos(){
    float carrinho = 0;
    char escolherproduto;
    float escolherquantidade;
    float valor_total;
    leite.preco = 7.99;
    arroz.preco = 4.99;
    queijo.preco = 2.99;
    maca.preco = 1.99;

    


    while(1){
        printf("Digite o número correspondente ao produto ou 'P' para parar de adicionar produtos ao carrinho: \n");
        scanf(" %c",&escolherproduto);
        if(escolherproduto=='0'){
            printf("Agora escolha a quantidade de unidades: \n");
            scanf("%f",&escolherquantidade);
            carrinho+=leite.preco*escolherquantidade;
            continue;
        }
        if(escolherproduto=='1'){
            printf("Agora escolha a quantidade de unidades: \n");
            scanf("%f",&escolherquantidade);
            carrinho+=arroz.preco*escolherquantidade;
            continue;
        }
        if(escolherproduto=='2'){
            printf("Agora escolha a quantidade de unidades: \n");
            scanf("%f",&escolherquantidade);
            carrinho+=queijo.preco*escolherquantidade;
            continue;
        }
        if(escolherproduto=='3'){
            printf("Agora escolha a quantidade de unidades: \n");
            scanf("%f",&escolherquantidade);
            carrinho+=maca.preco*escolherquantidade;
            continue;
        }

        if(escolherproduto=='P'){
            printf("R$:%.2f\n",carrinho);
            printf("Vá ao caixa para realizar o pagamento\n");
            Caixa(carrinho);
            break;
        }
    }   

}
float Caixa(double valor_total){
    char escolherPagamento;
    system("clear");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n ");
    printf(" Bem vindo ao Caixa!\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n");
    printf("Sua compra totalizou em R$: %.2f\n",valor_total);

    printf("Qual a forma de pagamento?\n Pix[P]\n Dinheiro[D]\n Cartão[C]\n ");
    printf("Digite a letra correspondente ao pagamento desejado: ");
    scanf(" %c",&escolherPagamento);

    if(escolherPagamento=='P'){
        printf("\nQR CODE DO PIX: \n");
        char qr_code[100];
        FILE *arquivo_pix = fopen("pix.txt","r");
        while(fgets(qr_code,100,arquivo_pix)!=NULL){
        printf("%s",qr_code);
        }

        fclose(arquivo_pix);
    

    }
    else if(escolherPagamento=='D'){
        
    }



}


void MenuProdutos(){
    
   
    char opcaomenuProdutos;
    printf("\nDigite 'C' para adicionar o produto ao carrinho \nOu digite 'V' para voltar ao menu principal: \n");
    scanf(" %c",&opcaomenuProdutos);
    if(opcaomenuProdutos=='V'){
        system("clear");
        MenuPrincipal();
    }
    else if(opcaomenuProdutos=='C'){
        AdicionarProdutos();
    }
    



}
//adicionar produtos diretamente no arquivo txt
void VerProduto(){
    FILE *produtos;
    char texto_str[50];
    
    produtos = fopen("produtos.txt","r");

    while(fgets(texto_str,50,produtos)!=NULL){
        printf("\n%s",texto_str);
    }

    fclose(produtos);
    

}
void MenuPrincipal(){
    int opcaomenu;
    
    printf("\n\n ========================== \n");
    printf(" Bem vindo ao supermercado! \n");
    printf(" ========================== \n");

    printf("\n\n /=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/ \n");
    printf(" 1-VER PRODUTOS DISPONIVEIS\n");
    printf(" 2-SAIR\n");
    printf(" /=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/\n");
    printf(" \nDigite a opção: ");
    scanf("%d",&opcaomenu);

    if(opcaomenu==1){
        printf("\n~~~~~~~~~~~~~~~~~~~~~~");
        VerProduto();
        printf("\n~~~~~~~~~~~~~~~~~~~~~~");
        MenuProdutos();
    }
    else if(opcaomenu==2){
        printf("\n ---Agradecemos a preferencia e volte novamente!!!---");
        exit(1);
    }



}



int main(){

    MenuPrincipal();

}

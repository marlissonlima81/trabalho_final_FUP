#include <stdio.h>
#include <stdlib.h>
#include <string.h>


float Caixa();
void MenuProduto();
void MenuPrincipal();
//void AdicionarProdutos();


typedef struct{
    char nome[100];
    char preco[100];
    char codigo[100];

}DadosProdutos;

typedef struct{
    float preco_produto;

}valor_produto;

valor_produto leite,arroz,feijao,macarrao,oleo;



//marlisson
//parte solicitada onde se usa um vetor de estrutura alocado dinamicamente
void Estoque(){
    system("clear");
    char escolha;
    char voltarmenu;
   
    printf(" Digite a quantidade de produtos para adicionar ao estoque:");
    int qtdDeProdutosEstoque;
    scanf("%d",&qtdDeProdutosEstoque);
    DadosProdutos *lista_de_produtos = (DadosProdutos*) malloc(qtdDeProdutosEstoque*sizeof(DadosProdutos));

    if(qtdDeProdutosEstoque==0){
        system("clear");
        MenuPrincipal();
    }
    
    else{
        printf("Escreva o nome do produto, o preço dele e o codigo(Siga a ordem!!!)\n");
        for(int i=0;i<qtdDeProdutosEstoque;i++){
            scanf(" %[^\n]",lista_de_produtos[i].nome);
            scanf(" %[^\n]",lista_de_produtos[i].preco);
            scanf(" %[^\n]",lista_de_produtos[i].codigo);
        }
        FILE *arquivo_produtos;
        arquivo_produtos = fopen("produtos.txt","a");
        for(int i=0;i<qtdDeProdutosEstoque;i++){
            fprintf(arquivo_produtos,"%s - ",lista_de_produtos[i].codigo);
            fprintf(arquivo_produtos,"%s - ",lista_de_produtos[i].nome);
            fprintf(arquivo_produtos,"%s\n",lista_de_produtos[i].preco);
        }
        fclose(arquivo_produtos);
        printf("Total de produtos adicionados: %d\n",qtdDeProdutosEstoque);
       
        printf("Você deseja remover algum produto do estoque?\n");
        printf("Digite 'R' para remover e 'N' para não\n");
        scanf(" %c",&escolha);
        if(escolha=='R'){
            char codigo_produto[100];
            printf("Digite o codigo do produto para remover do estoque\n");
            scanf(" %s",codigo_produto);
            for(int i=0;i<qtdDeProdutosEstoque;i++){
                if(lista_de_produtos[i].codigo==codigo_produto){
                    lista_de_produtos[i] = lista_de_produtos[qtdDeProdutosEstoque-1];
                    lista_de_produtos = (DadosProdutos*) realloc(lista_de_produtos,(qtdDeProdutosEstoque-1)*sizeof(DadosProdutos));
                    qtdDeProdutosEstoque--;

                    break;
                }
            }
            

            
        }
        else if(escolha=='N'){
            printf("Deseja voltar ao menu principal?");
            scanf(" %c",&voltarmenu);
            if(voltarmenu=='S'){
                system("clear");
                MenuPrincipal();

            }
        }


    }

    free(lista_de_produtos);

}


//matheus
void AdicionarProdutos(){
    float carrinho = 0;
    char escolherproduto;
    float escolherquantidade;
    float valor_total;
    leite.preco_produto = 7.99;
    arroz.preco_produto = 4.99;
    feijao.preco_produto = 5.99;
    oleo.preco_produto = 3.99;
    macarrao.preco_produto = 6.99;
    


    while(1){
        printf("Digite o número correspondente ao produto ou 'P' para parar de adicionar produtos ao carrinho: \n");
        scanf(" %c",&escolherproduto);
        if(escolherproduto=='0'){
            printf("Agora escolha a quantidade de unidades: \n");
            scanf("%f",&escolherquantidade);
            carrinho+=arroz.preco_produto*escolherquantidade;
            continue;
        }
        if(escolherproduto=='1'){
            printf("Agora escolha a quantidade de unidades: \n");
            scanf("%f",&escolherquantidade);
            carrinho+=leite.preco_produto*escolherquantidade;
            continue;
        }
        if(escolherproduto=='2'){
            printf("Agora escolha a quantidade de unidades: \n");
            scanf("%f",&escolherquantidade);
            carrinho+=feijao.preco_produto*escolherquantidade;
            continue;
        }
        if(escolherproduto=='3'){
            printf("Agora escolha a quantidade de unidades: \n");
            scanf("%f",&escolherquantidade);
            carrinho+=oleo.preco_produto*escolherquantidade;
            continue;
        }

        if(escolherproduto=='4'){
            printf("Agora escolha a quantidade de unidades: \n");
            scanf("%f",&escolherquantidade);
            carrinho+=macarrao.preco_produto*escolherquantidade;
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
    float dinheiroCliente;
    float dinheiroRestante;
    system("clear");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n ");
    printf(" Bem vindo ao Caixa!\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n");
    printf("Sua compra totalizou em R$: %.2f\n",valor_total);

    printf("Qual a forma de pagamento?\n Pix[P]\n Dinheiro[D]\n ");
    printf("\n\nDigite a letra correspondente ao pagamento desejado: ");
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
        printf("Digite a quantia de dinheiro para realizar o pagamento: ");
        scanf("%f",&dinheiroCliente);
        if(dinheiroCliente==valor_total){
            printf("Pagamento realizado com sucesso!\n");
            printf("Obrigado pela compra e volte sempre");
            
        }
        else if(dinheiroCliente<valor_total){
            while(dinheiroCliente<valor_total){
                printf("\n\nValor insuficiente para pagar pela compra\n Adicione R$ %.2f para completar o valor da compra: ",valor_total-dinheiroCliente);
                scanf("%f",&dinheiroRestante);
                dinheiroCliente+=dinheiroRestante;
            }
            printf("Obrigado pela compra e volte sempre");
            
        }
        else{
            printf("Troco:R$ %.2f\n",dinheiroCliente-valor_total);
            printf("Obrigado pela compra e volte sempre");
        }

        
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
//kaynan
void MenuPrincipal(){
    int opcaomenu;
    
    printf("\n\n ========================== \n");
    printf(" Bem vindo ao supermercado! \n");
    printf(" ========================== \n");

    printf("\n\n /=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/ \n");
    printf(" 1-VER PRODUTOS DISPONIVEIS\n");
    printf(" 2-ESTOQUE(APENAS FUNCIONÁRIOS)\n");
    printf(" 3-SAIR\n");
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
        Estoque();
    }
    else if(opcaomenu==3){
        printf("\n ---Agradecemos a preferencia e volte novamente!!!---");
        exit(1);

    }



}



int main(){

    MenuPrincipal();

}

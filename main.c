/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Miguel
 *
 * Created on 22 de Novembro de 2017, 11:25
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "LP_Leitura.h"
#include "LP_Utils.h"


#define FILAS 10
#define LUGARES 10
#define SALAS 4

#define MAX_CLI 500



/**
 *função que premite apresentar as 4 salas consola
 *utilizando a tabela de ascii, o caracter é igual a uma letra (A)
 *com a incrementação do "caracter", conseguimos escrever várias letras consecutivas 
 * @param salas é a matriz que permite armazenar os valores de cada sala
 * @param sala é esta variavél que nos mostra qual a sala que o utilizador escolheu
 */

void imprimeSala(char salas[SALAS][FILAS][LUGARES], int sala) {
    int i, j;
    char caracter;

    printf("\n\n\n\t\t\t\tSALA %d\n\n", sala);
    printf("1\t2\t3\t4\t5\t6\t7\t8\t9\t10\n\n");

    caracter = 65;

    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < LUGARES; j++) {

            printf("%c\t", salas[sala][i][j]);
        }
        printf("\t%c\n", caracter++);
    }
}

/**
 * 
 * @param sala é a variavél que nos mostra a sala escolhida pelo utilizador
 * @param bilhetesadulto corresponde aos bilhetes de adulto comprados pelo utilizador
 * @param bilhetescrianca corresponde aos bilhetes de criança comprados pelo utilizador
 * estas duas variáveis vão ser utilizadas para calcular o preço final dos bilhetes
 * @return preco, vai armazenar o valor das operções envolvidas, e quando chamada a função, esta ira devover esse valor 
 */

int precoBilhetes(int sala, int bilhetesadulto, int bilhetescrianca) {

    int preco;

    if (sala == 0)
        printf("\n\nVoce tem a pagar: %d€", preco = (6 * bilhetesadulto)+(4 * bilhetescrianca));

    if (sala == 1)
        printf("\n\nVoce tem a pagar: %d€", preco = (5 * bilhetesadulto)+(3 * bilhetescrianca));

    if (sala == 2)
        printf("\n\nVoce tem a pagar: %d€", preco = (8 * bilhetesadulto)+(5 * bilhetescrianca));

    if (sala == 3)
        printf("\n\nVoce tem a pagar: %d€", preco = (7 * bilhetesadulto)+(5 * bilhetescrianca));

    return preco;
}

/**
 * esta função tem como objetivo imprimir na consola os preços das diferentes salas
 * esses preços vão variar de acordo com a "sala" que o utilzador escolher 
 * @param sala representa a sala escolhida pelo utilizador
 */

void precosSala(int sala) {


    printf("\n\nOs lugares assinalos com '*' encontram-se disponívels\n");

    if (sala == 0) {
        printf("\n\n\n\t\t\tPreço dos bilhetes\n\n");
        printf("Adultos----------------------------->6€\n");
        printf("Crianças---------------------------->4€\n");
    }


    if (sala == 1) {
        printf("\n\n\t\t\tPreços dos bilhetes\n\n");
        printf("Adultos----------------------------->5€\n");
        printf("Crianças---------------------------->3€\n");
    }

    if (sala == 2) {
        printf("\n\n\t\t\tPreço dos bilhetes\n\n");
        printf("Adultos----------------------------->8€\n");
        printf("Crianças---------------------------->5€\n");
    }

    if (sala == 3) {
        printf("\n\n\t\t\tPreço dos bilhetes\n\n");
        printf("Adultos----------------------------->7€\n");
        printf("Crianças---------------------------->5€\n");

    }
}

/**
 * função permite efetuar o pagamento pela compra dos bilhetes
 * "troco" foi inicializado a 0, pois vai ser utilizado para operações entre outras variavéis
 * se o utilizador não introduzir o valor pedido, vai lhe ser constantemente pedido o que está em falta
 * e caso o dinheiro introduzido ultrapasse o preço, a função devolve o valor em exeço 
 * foi utilizado o valor absoluto para efeturar os calculos do "troco"
 * @param preco é uma variavél que está a ser chamada e que anteriormente foi returnada pela função precoBilhetes 
 */

void pagamentoBilhetes(float preco) {

    float pagamento, troco = 0;

    printf("\nInsira o pagamento: ");


    do {
        scanf("%f", &pagamento);
        troco = preco - pagamento;
        if (troco > 0) {
            printf("\nEstão em falta %0.1f€\n", troco);
            printf("Insira o restante: \n");
        }
        preco = preco - pagamento;
    } while (troco > 0);

    if (troco < 0) {
        troco = -(troco);
        printf("O troco é de: %0.1f€\n", troco);
        printf("Disfrute do filme!");
    } else
        printf("Disfrute do filme!\n");

}

/**
 * esta função permite imprimir na consola os preços de todas as salas existentes
 */

void tabelaPrecos() {


    printf("\n\n\t\tBilhetes sala 0\n\n");
    printf("Adultos----------------------------->6€\n");
    printf("Crianças---------------------------->4€\n");
    printf("\n\t\tBilhetes sala 1\n\n");
    printf("Adultos----------------------------->5€\n");
    printf("Crianças---------------------------->3€\n");
    printf("\n\t\tBilhetes sala 2\n\n");
    printf("Adultos----------------------------->8€\n");
    printf("Crianças---------------------------->5€\n");
    printf("\n\t\tBilhetes sala 3\n\n");
    printf("Adultos----------------------------->7€\n");
    printf("Crianças---------------------------->5€\n");

}

/**
 * função de um ficheiro que permite guardar as alterações da matriz num documento de texto
 * o documento de texto que guarda as informções tem o nome de "salascinema.txt"
 * @param salas é a matriz que permite armazenar os valores de cada sala
 * esta função imprime no ficheiro os lugares vazios "*" e os lugares ocupados "-"
 */

void guardarFicheiro(char salas[SALAS][FILAS][LUGARES]) {

    int s, i, j;
    FILE *salascinema;

    salascinema = fopen("salascinema.txt", "w");


    for (s = 0; s < SALAS; s++) {
        for (i = 0; i < FILAS; i++) {
            for (j = 0; j < LUGARES; j++) {
                fprintf(salascinema, "%c", salas[s][i][j]);
            }
            fprintf(salascinema, "\n");
        }

    }

    fclose(salascinema);
}

/**
 * esta função tem como objetivo ler caracter a caracter o ficheiro guardado em "salascinema.txt"
 * e imprimir na consola o conteúdo do ficheiro
 * @param salas é a matriz que contém armazenados os valores de cada sala
 */

void lerFicheiro(char salas[SALAS][FILAS][LUGARES]) {

    char ch;

    FILE *salascinema;
    salascinema = fopen("salascinema.txt", "rt");



    int p = 0, l = 0, c = 0;
    while ((ch = fgetc(salascinema)) != EOF) {
        if (ch == '\n') {
            l++;
            c = 0;
            continue;
        }
        if (l >= 10) {
            l = 0;
            p++;
        }
        salas[p][l][c] = ch;
        c++;
    }



}

/**
 * esta função tem como objetivo a reserva dos lugares por parte do utilizador
 * @param salas é a matriz que vai permitir armazenar os valores introduzidos pelo utilizador na matriz 
 * @param s esta variavél faz com que as alterações que o utilizador fez ao introduzir os lugares
 * aconteçam apenas na matriz (sala) que ele escolheu anteriormente e não em todas as salas
 * @param bilhetestotal esta variavél é utilizada para que o utilizador não saia do ciclo, ou seja,
 * continue a inserir lugares, enquanto não escolher os lugares para todos os bilhetes que comprou
 * enquanto a variavél bilhetestotal não for igualada pela variavél reservabilhetes, o ciclo continuará
 */

void escolhaLugares(char salas[SALAS][FILAS][LUGARES], int s, int bilhetestotal) {

    int r = 0, coluna, reservabilhetes = 0;
    char linha;

    do {
        do {

            if (r > 0)
                printf("\nLugar ocupado\nIntroduza novo lugar");

            do {
                printf("\n\nIndique a fila que pretende reservar (A-J): ");
                scanf(" %c", &linha);
            } while (linha < 65 || linha > 74);

            do {
                printf("\nIndique o lugar que pretende reservar (1-10): ");
                scanf("%d", &coluna);
            } while (coluna < 1 || coluna > 10);

            r++;

        } while (salas[s][linha - 65][coluna - 1] == '-');

        r = 0;

        salas[s][linha - 65][coluna - 1] = '-';

        reservabilhetes++;


    } while (reservabilhetes < bilhetestotal);
}

/**
 * esta função tem como objetivo dar ao utilizador a escolher para qual sala pretende reservar bilhetes
 * @param sala é a variavél utilizada para ler a sala que o utilizador escolheu 
 * @return nesta função o valor da sala é guardado, e sempre que esta função for chamada, o seu valor irá ser returnado
 */


int escolhaUtilizador(int sala) {


    printf("\n\t\tCOMPRA DE BILHETES E RESERVA DE LUGARES\n\n");

    printf("\nIndique a sala que pretende assistir o filme 0-3: ");
    scanf("%d", &sala);

    while (sala < 0 || sala > 3) {
        printf("Opcao invalida\n");
        printf("\nEscolha uma sala 0-3: ");
        scanf("%d", &sala);
    }
    return sala;
}

/**
 * função que permite com que o programa corra "salas" e selecione um lugar livre para ser ocupado
 * ou seja, o programa apenas altera os valores da matriz se esse ligar tiver representado por '*'
 * @param salas é a matriz que permite armazenar lugares ocupados e vazios de cada sala
 * @param sala é esta variavél que nos dá a sala em que o utilizador pretende rezervar a sala 
 * @param nbilhetes representa o numero total de bilhetes reservados por um utiliza
 * o ciclo apenas acaba quando todos os bilhetes tiverem sido armazeandos num lugar da sala pretendida pelo utilizador
 */

void escolhaMaquina(char salas[SALAS][FILAS][LUGARES], int sala, int nbilhetes) {

    int i, j, marcados = 0;

    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < LUGARES; j++) {
            if (salas[sala][i][j] == '*') {
                salas[sala][i][j] = '-';
                marcados++;
                if (marcados == nbilhetes) {
                    i = FILAS;
                    j = LUGARES;
                }
            }
        }
    }
}

/**
 * nesta função temos o menu do programa, onde o utilizador pode escolher perante as opeções que lhe são apresentadas
 * @param opcao é a variavél que faz com que o ciclo não acabe enquanto o utilizador não introduzir uma das opções do menu
 * @return esta função retorna o valor da opção escolida pelo utilizador, fazedno com que  programa se reproduza em função dessa opção
 */

int funcaoMenu(int opcao) {

    do {
        printf("\n\n\n\t\t\tM E N U   P R I N C I P A L\n");
        printf("\n\tVisualizar Salas de Espetáculo ---------------------------------> 1");
        printf("\n\tLotação das salas ----------------------------------------------> 2");
        printf("\n\tPreço dos bilhetes ---------------------------------------------> 3");
        printf("\n\tComprar bilhetes e reserva de lugares --------------------------> 4");
        printf("\n\tLog out --------------------------------------------------------> 0");
        printf("\n\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
    } while ((opcao != 0) && (opcao != 1) && (opcao != 2) && (opcao != 3) && (opcao != 4));
}

/**
 * função onde o utilizador tem de escolher uma das quatro salas exsitentes
 * sendo que o ciclo existente na função faz com que o utilizador seja obrigado a introduzir um valor dentro dos pedidos 
 * @param sala é o que permite ao utilizador escolher a sala que pretende 
 * @return esta função retorna o valor introduzido pelo utilizador
 */

int escolhaSala(int sala) {

    printf("\nEscolha uma sala 0-3: ");
    scanf("%d", &sala);

    while (sala < 0 || sala > 3) {
        printf("Opcao invalida\n");
        printf("\nEscolha uma sala 0-3: ");
        scanf("%d", &sala);
    }
    return sala;
}



typedef struct cliente {
    char nome[20];
    int idade;
    char utilizador[20];
    char password[20];


} Info;

/**
 * esta funçãp lê dados de um ficheiro e preenche a lista de alunos 
 * @param clientes é um apontador para o primeiro aluno a preencher
 * @param quantos é um apontador para o número de alunos que existem atualmente na lista
 */


void lerDados(Info *clientes, int *quantos) {
    FILE *utilizador;
    int a;
    if ((utilizador = fopen("utilizador.bin", "rb")) == NULL) {
        *quantos = 0;
        perror(NULL);

        return;
    }

    a = fread(quantos, sizeof (int), 1, utilizador);
    if (a != 0) {
        fread(clientes, sizeof (Info), *quantos, utilizador);
    } else {
        *quantos = 0;
    }
    fclose(utilizador);
}

/**
 * esta função escreve o conteúdo da lista de alunos em ficheiro
 * @param clientes é um apontador para o primeiro aluno da lista
 * @param quantos é a variavél quemostra quantos alunos existem na lista
 */

void escreverDados(Info *clientes, int quantos) {
    FILE *utilizador;

    if ((utilizador = fopen("utilizador.bin", "wt")) == NULL) {
        perror(NULL);
        return;
    }

    fwrite(&quantos, sizeof (int), 1, utilizador);
    fwrite(clientes, sizeof (Info), quantos, utilizador);

    fclose(utilizador);
}

/**
 * função que adiciona um aluno à lista de alunos, se esta ainda tiver espaço
 * @param clientes é um apontador para o primeiro aluno da lista
 * @param quantos é um apontador para o número de alunos que existem atualmente na lista
 */

void adicionaClientes(Info *clientes, int *quantos) {
    int i, x;

    if (*quantos < MAX_CLI) {

        readInt(&clientes[*quantos].idade, 0, 9999, "Introduza a sua idade: ");
        readString(clientes[*quantos].nome, (MAX_CLI - 1), "Introduza o seu nome: ");

        do {
            x = 0;
            readString(clientes[*quantos].utilizador, (MAX_CLI - 1), "Nome de Utilizador: ");

            for (i = 0; i < *quantos; i++) {
                if (strcmp(clientes[i].utilizador, clientes[*quantos].utilizador) == 0)
                    x++;

            }

            if (x == 1)
                printf("Utilizador já existe\n");

        } while (x == 1);

        readString(clientes[*quantos].password, (MAX_CLI - 1), "Password: ");

        (*quantos)++;

    } else printf("A lista de clientes está cheia.");
}

/**
 * função que permite ao utilizador escolher a opção que pretende
 * @param menu é a variavél que permite ao utilizador introduzir a sua escolha 
 * @return esta função retorna a variavél "menu", ou seja, a opção escolhida pelo utilizador
 * com o objetivo de o programa contnuar em função dessa opção
 */

int menuOpcoes(int menu) {

    do {

        printf("\n\n\t Criar conta --------------------->1\n");
        printf("\t Login --------------------------->2\n");
        printf("\t Lista de utilizadores ----------->3\n");
        printf("\t Sair do programa ---------------->0\n");
        scanf("%d", &menu);

    } while (menu != 0 && menu != 1 && menu != 2 && menu != 3);
    return (menu);
}

/**
 * função que permite visualizar todas as contas existentes
 * @param clientes vai buscar informações sobre as contas
 * @param menu esta função apenas funcionará se no menu for escolhida a opção 3
 */

void listaClientes(Info *clientes, int quantos, int menu) {
    int z;
    if (menu == 3) {
        for (z = 0; z < quantos; z++)
            printf("Nome: %s (Utilizador: %s)\n", clientes[z].nome, clientes[z].utilizador);
    }
}

/**
 * função que permite ao utilizador escolher se quer ser ele a escolher o seu lugar 
 * na sala, ou se quer que seja o programa a atribuir-lhe um lugar
 * @param escolha é a variavél que permite ao utilizador escolher a opção
 * para o programa a ler
 * @return a função retorna o valor escolhido pelo utilizador
 */

int lugarSala(int escolha) {
    do {
        printf("\n\nEscolher lugar - prima 1");
        printf("\nLugar escohido pela máquina - prima 2\n");
        scanf("%d", &escolha);

    } while (escolha != 2 && escolha != 1);
}

/**
 * função que verifica se os dados que o utilizador introduziu para fazer o login
 * coincidem com os dados utilizados no registo
 * se os dados coinciderem, o utilizador faz o login com sucesso, continuando o programa
 * caso os dados estejam errados, o utilizador não consegue avançar, necessitando assim 
 * de criar um novo registo ou de introduzir novamente os dados para login
 * esta função compara o que o utilizador introduz no momento do login, 
 * com os dados guardados em ficheiro
 * @param clientes é um apontador para o primeiro aluno da lista
 * @param menu contém o valor anteriormente introduzido pelo utilizador, 
 * fazendo com que a função funcione em função dessa escolha
 * @return apenas retorna a variavél "secc", apenas se tanto a password
 * como o nome introduzidos pelo utilizador sejam compativéis
 */


int logIn(Info *clientes, int menu) {

    int enc = 0, i = 0, cont = 0, succUtilizador = 0, succPassword = 0, succ = 0;
    char utilizador[30], password[30];

    if (menu == 2) {

        printf("Introduza o seu nome de utilizador: ");
        scanf("%s", &utilizador);
        printf("Introduza a password: ");
        scanf("%s", &password);

        while (enc == 0 && i < MAX_CLI) {
            if (strcmp(clientes[i].utilizador, utilizador) == 0) {
                enc = 1;
                succUtilizador = 1;
            } else
                enc = 0;
            i++;

        }

        if (enc == 0) {
            printf("Utilizador não existe");
            cont++;
        }

        i = 0;
        if (enc == 1) {
            while (enc == 1 && i < MAX_CLI) {
                if (strcmp(clientes[i].password, password) == 0) {
                    enc = 2;
                    succPassword = 1;
                } else
                    enc = 1;
                i++;
            }
            if (enc == 1) {
                printf("Password incorreta");
                cont++;
            } else
                printf("Login realizado com sucesso!!!");

        }
        if (succUtilizador == 1 && succPassword == 1) {
            succ = 1;
            return succ;
        }


    }
}

int main(int argc, char** argv) {


    int opcao, sala, s, bilhetesadulto, bilhetescrianca, escolha, reservabilhetes = 0, bilhetestotal, preco, sucesso = 0, menu, quantos, bilhete, i, j, k=0;
    char salas[SALAS][FILAS][LUGARES];
    Info clientes[MAX_CLI];

    //função que começa-se por ler o cnteúdo guardado em ficheiro, para inicializar as matrizes
    lerFicheiro(salas);
    //função que permite ler do ficheiro os dados dos registos já efetuados por utilizadores
    lerDados(clientes, &quantos);


    do {
        //é chamada uma função que mostra ao utilizador um menu, para este escolher uma opção
        menu = menuOpcoes(menu);


        if (menu == 1) {

            //função que permite ao utilizador introduzir os seus dados
            //pessoais para fazer o seu registo
            adicionaClientes(clientes, &quantos);

            //função que permite guardar os dados o registo do 
            //utilizador em ficheiro
            escreverDados(clientes, quantos);

            printf("\nRegisto criado com sucesso!!!\n");



        }

        //função que mostra todos as contas existentes
        listaClientes(clientes, quantos, menu);

        //função que verifica se os dados que o utilizador introduziu para 
        //fazer o login coincidem com os dados utilizados no registo
        sucesso = logIn(clientes, menu);



        if (sucesso == 1) {


            do {
                opcao = funcaoMenu(opcao);
                //é chamada a funçãoMenu que permite mostrar ao utilizador 
                //todas as funcionalidades do programa depois de introduzido o login corretamente



                switch (opcao) {

                    case 1:
                    {

                        printf("\n\nEstas são todas as salas de cinema disponíveis:\n");

                        for (s = 0; s < 4; s++) {
                            imprimeSala(salas, s);
                            //é chamada a função que escreve as matrizes na consola 
                            //de forma ao utilizador as conseguir visualizar
                        }
                        break;
                    }


                    case 2:
                    {

                        //função onde o utilizador tem a opção de escolher uma das quatro salas exsitentes
                        sala = escolhaSala(sala);

                        printf("\n\nOs lugares assinalos com '*' encontram-se disponívels\n");
                        imprimeSala(salas, sala);
                        //é chamada a função que irá imprimir na consola apenas uma das salas   
                        //essa sala será escolhida pelo utilizador

                        break;
                    }



                    case 3:
                    {

                        tabelaPrecos();
                        //é chamada a função que imprime os preços 
                        //dos bilhetes de todas as salas na consola

                        break;
                    }




                    case 4:
                    {

                        //nesta função o utilizador escolhe para qual sala quer comprar bilhetes
                        sala = escolhaUtilizador(sala);

                        //é imprimida na consola a matriz da sala que o utilizador escolheu
                        //mostrando os lugares disponiveis
                          imprimeSala(salas, sala);
                        
                        
                        //são apresentados os preços apenas relativamente à sala escolhida pelo utilizador
                        precosSala(sala);



                        do {
                            bilhete = 0;
                            printf("\n\n\tQuantidade de bilhetes de adultos:");
                            scanf("%d", &bilhetesadulto);
                            printf("\n\tQuantidade de bilhetes de criança:");
                            scanf("%d", &bilhetescrianca);
                            if (bilhetescrianca + bilhetesadulto > 20) {
                                printf("Não é possível reservar tantos bilhetes!");
                                bilhete++;
                            }
                            
                        } while (bilhete > 0);


                        if (bilhetescrianca + bilhetesadulto > 0) {

                            //função que permite ao utilizador escolher se quer ser ele a escolher o seu lugar 
                            //na sala, ou se quer que seja o programa a atribuir-lhe um lugar
                            escolha = lugarSala(escolha);



                            //opção que permite ao utilizador escolher os prórpios lugares
                            if (escolha == 1) {

                                //é chamada a função que permite ao utilizador introduzir o seu lugar
                                escolhaLugares(salas, sala, bilhetescrianca + bilhetesadulto);

                                //é novamente imprimida a sala que foi escolhida pelo utilizador
                                //mostrando já os seus lugares reservados
                                imprimeSala(salas, sala);

                                //é chamada a função que permite guardar as matrizes alteradas num ficheiro
                                guardarFicheiro(salas);

                                //função que calcula o preço total a pagar e o apresenta na consola
                                preco = precoBilhetes(sala, bilhetesadulto, bilhetescrianca);

                                //função que permite efetuar o pagamento
                                pagamentoBilhetes(preco);

                            }

                            //opçãõ que faz com que seja o programa a escolher os lugares
                            if (escolha == 2) {

                                //função que vai percorrer cada linha da matriz da sala escolhida 
                                //e marcar como reservados apenas os lugares que se encontarem disponiveis
                                escolhaMaquina(salas, sala, bilhetescrianca + bilhetesadulto);


                                reservabilhetes++;
                                bilhetestotal = bilhetescrianca + bilhetesadulto;

                                //é chamada a função que irá guardar em ficheiro as alterações efetuadas na matriz
                                guardarFicheiro(salas);

                                //função que irá imprimir na consola a sala escolhida pelo utilizador
                                //mostrando já os lugares alterados pelo prorama
                                imprimeSala(salas, sala);

                                //função que calcula o preço total a pagar e o apresenta na consola
                                preco = precoBilhetes(sala, bilhetesadulto, bilhetescrianca);

                                //função que permite efetuar o pagamento
                                pagamentoBilhetes(preco);

                            }

                        }
                        break;
                    }
                    default:
                        printf("Opção inválida");
                }
            } while (opcao != 0);
        }
    } while (menu != 0);


    return (EXIT_SUCCESS);
}
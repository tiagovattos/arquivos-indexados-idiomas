// Trabalho 2� Ano BCC
// Autor: Tiago Vattos Zamboni
// Disciplina: Algoritmos e Estrutura de Dados
// Arquivos indexados - Escola de idiomas

#include <iostream>
#include <string.h>
#include <locale>

using namespace std;

struct indices {
    int codigo;
    int endereco;
};

struct idiomas {
    int codigoIdioma;
    char descricao[20];
    int status;
};

struct licoes {
    int codigoLicao;
    int codigoIdioma;
    int totalNiveis;
    int status;
};

struct usuarios {
    int codigoUsuario;
    char nome[35];
    int codigoIdiomaEscolhido;
    int nivelAtual;
    int pontuacaoTotal;
    int status;
};

struct exercicios {
    int codigoExercicio;
    int codLicao;
    int nivelDificuldade;
    char descricao[200];
    int respostaCorreta;
    int valorPontuacao;
    int status;
};

// Prototipa��o das fun��es
void inclusaoIdioma (struct indices[], struct idiomas[], int &, int );
void inclusaoUsuario (struct indices [], struct usuarios [], int &, int , struct indices [], struct idiomas [], int);
void inclusaoLicao (struct indices [], struct licoes [], int &, int , struct indices [], struct idiomas [], int);
void inclusaoExercicio (struct indices[], struct exercicios[], int&, int, struct indices[], struct licoes[], int);

void exaustivaIdiomas(struct indices[], struct idiomas[], int);
void exaustivaUsuarios(struct indices[], struct usuarios[], int, struct indices[], struct idiomas[], int);
void exaustivaLicoes(struct indices [], struct licoes [], int, struct indices[], struct idiomas[], int);
void exaustivaExercicios(struct indices[], struct exercicios[], int);

int buscarIdiomas(struct indices[], struct idiomas[], int, int);
int buscarUsuarios(struct indices[], struct usuarios[], int, int);
int buscarLicoes(struct indices[], struct licoes[], int, int);
int buscarExercicios(struct indices[], struct exercicios[], int, int);

void reorganizarIdiomas(struct indices[], struct idiomas[], int&);
void reorganizarLicoes(struct indices[], struct licoes[], int&);
void reorganizarExercicios(struct indices[], struct exercicios[], int&);
void reorganizarUsuarios(struct indices[], struct usuarios[], int&);

void ordenarUsuarios(struct usuarios[], int);
bool compararPorPontuacaoTotal(const usuarios&, const usuarios&);

int main() {
    // dados
    // Acentua��o console
    setlocale(LC_ALL, "portuguese");

    // ---------------------------------------------


    struct idiomas dadosIdiomas[20];
    struct indices indicesIdiomas[20];

    dadosIdiomas[0].codigoIdioma = 1;
    strcpy(dadosIdiomas[0].descricao, "Ingl�s");
    dadosIdiomas[0].status = 0;
    indicesIdiomas[0].codigo = 1;
    indicesIdiomas[0].endereco = 0;

    dadosIdiomas[1].codigoIdioma = 2;
    strcpy(dadosIdiomas[1].descricao, "Alem�o");
    dadosIdiomas[1].status = 0;
    indicesIdiomas[1].codigo = 2;
    indicesIdiomas[1].endereco = 1;

    dadosIdiomas[2].codigoIdioma = 3;
    strcpy(dadosIdiomas[2].descricao, "Espanhol");
    dadosIdiomas[2].status = 0;
    indicesIdiomas[2].codigo = 3;
    indicesIdiomas[2].endereco = 2;

    dadosIdiomas[3].codigoIdioma = 4;
    strcpy(dadosIdiomas[3].descricao, "Franc�s");
    dadosIdiomas[3].status = 0;
    indicesIdiomas[3].codigo = 4;
    indicesIdiomas[3].endereco = 3;

    int contIdiomas = 4;

    // ---------------------------------------------

    struct licoes dadosLicoes[20];
    struct indices indicesLicoes[20];

    dadosLicoes[0].codigoLicao = 1;
    dadosLicoes[0].codigoIdioma = 1;
    dadosLicoes[0].totalNiveis = 3;
    dadosLicoes[0].status = 0;
    indicesLicoes[0].codigo = 1;
    indicesLicoes[0].endereco = 0;

    dadosLicoes[1].codigoLicao = 2;
    dadosLicoes[1].codigoIdioma = 2;
    dadosLicoes[1].totalNiveis = 1;
    dadosLicoes[1].status = 0;
    indicesLicoes[1].codigo = 2;
    indicesLicoes[1].endereco = 1;

    dadosLicoes[2].codigoLicao = 3;
    dadosLicoes[2].codigoIdioma = 3;
    dadosLicoes[2].totalNiveis = 1;
    dadosLicoes[2].status = 0;
    indicesLicoes[2].codigo = 3;
    indicesLicoes[2].endereco = 2;

    dadosLicoes[3].codigoLicao = 4;
    dadosLicoes[3].codigoIdioma = 4;
    dadosLicoes[3].totalNiveis = 1;
    dadosLicoes[3].status = 0;
    indicesLicoes[3].codigo = 4;
    indicesLicoes[3].endereco = 3;

    int contLicoes = 4;

    // ---------------------------------------------

    struct usuarios dadosUsuarios[20];
    struct indices indicesUsuarios[20];

    dadosUsuarios[0].codigoUsuario = 1;
    strcpy(dadosUsuarios[0].nome, "Jo�o");
    dadosUsuarios[0].codigoIdiomaEscolhido = 1;
    dadosUsuarios[0].nivelAtual = 1;
    dadosUsuarios[0].pontuacaoTotal = 0;
    dadosUsuarios[0].status = 0;
    indicesUsuarios[0].codigo = 1;
    indicesUsuarios[0].endereco = 0;

    dadosUsuarios[1].codigoUsuario = 2;
    strcpy(dadosUsuarios[1].nome, "Maria");
    dadosUsuarios[1].codigoIdiomaEscolhido = 2;
    dadosUsuarios[1].nivelAtual = 1;
    dadosUsuarios[1].pontuacaoTotal = 0;
    dadosUsuarios[1].status = 0;
    indicesUsuarios[1].codigo = 2;
    indicesUsuarios[1].endereco = 1;

    dadosUsuarios[2].codigoUsuario = 3;
    strcpy(dadosUsuarios[2].nome, "Pedro");
    dadosUsuarios[2].codigoIdiomaEscolhido = 3;
    dadosUsuarios[2].nivelAtual = 1;
    dadosUsuarios[2].pontuacaoTotal = 0;
    dadosUsuarios[2].status = 0;
    indicesUsuarios[2].codigo = 3;
    indicesUsuarios[2].endereco = 2;

    dadosUsuarios[3].codigoUsuario = 4;
    strcpy(dadosUsuarios[3].nome, "Ana");
    dadosUsuarios[3].codigoIdiomaEscolhido = 4;
    dadosUsuarios[3].nivelAtual = 1;
    dadosUsuarios[3].pontuacaoTotal = 0;
    dadosUsuarios[3].status = 0;
    indicesUsuarios[3].codigo = 4;
    indicesUsuarios[3].endereco = 3;

    int contUsuarios = 4;

    // ---------------------------------------------


    struct exercicios dadosExercicios[20];
    struct indices indicesExercicios[20];

    dadosExercicios[0].codigoExercicio = 1;
    dadosExercicios[0].codLicao = 1;
    dadosExercicios[0].nivelDificuldade = 1;
    strcpy(dadosExercicios[0].descricao, "Como se fala 'copo' em ingl�s?\n1. Glass\n2. Mug\n3. Tea");
    dadosExercicios[0].respostaCorreta = 1;
    dadosExercicios[0].valorPontuacao = 100;
    dadosExercicios[0].status = 0;
    indicesExercicios[0].codigo = 1;
    indicesExercicios[0].endereco = 0;

    dadosExercicios[1].codigoExercicio = 2;
    dadosExercicios[1].codLicao = 1;
    dadosExercicios[1].nivelDificuldade = 2;
    strcpy(dadosExercicios[1].descricao, "Como se fala 'vaca' em ingl�s?\n1. Vacuum\n2. Cow\n3. Sheep");
    dadosExercicios[1].respostaCorreta = 2;
    dadosExercicios[1].valorPontuacao = 100;
    dadosExercicios[1].status = 0;
    indicesExercicios[1].codigo = 2;
    indicesExercicios[1].endereco = 1;

    dadosExercicios[2].codigoExercicio = 3;
    dadosExercicios[2].codLicao = 1;
    dadosExercicios[2].nivelDificuldade = 3;
    strcpy(dadosExercicios[2].descricao, "Como se fala 'ma��' em ingl�s?\n1. Apple\n2. Banana\n3. Orange");
    dadosExercicios[2].respostaCorreta = 1;
    dadosExercicios[2].valorPontuacao = 100;
    dadosExercicios[2].status = 0;
    indicesExercicios[2].codigo = 3;
    indicesExercicios[2].endereco = 2;

    dadosExercicios[3].codigoExercicio = 4;
    dadosExercicios[3].codLicao = 2;
    dadosExercicios[3].nivelDificuldade = 1;
    strcpy(dadosExercicios[3].descricao, "Como se fala '�gua' em alem�o?\n1. Wasser\n2. Luft\n3. Feuer");
    dadosExercicios[3].respostaCorreta = 1;
    dadosExercicios[3].valorPontuacao = 100;
    dadosExercicios[3].status = 0;
    indicesExercicios[3].codigo = 4;
    indicesExercicios[3].endereco = 3;

    dadosExercicios[4].codigoExercicio = 5;
    dadosExercicios[4].codLicao = 4;
    dadosExercicios[4].nivelDificuldade = 1;
    strcpy(dadosExercicios[4].descricao, "Como se fala 'livro' em franc�s?\n1. Livre\n2. Chaise\n3. Libro");
    dadosExercicios[4].respostaCorreta = 1;
    dadosExercicios[4].valorPontuacao = 100;
    dadosExercicios[4].status = 0;
    indicesExercicios[4].codigo = 5;
    indicesExercicios[4].endereco = 4;

    dadosExercicios[5].codigoExercicio = 6;
    dadosExercicios[5].codLicao = 3;
    dadosExercicios[5].nivelDificuldade = 1;
    strcpy(dadosExercicios[5].descricao, "Como se fala 'casa' em espanhol?\n1. Casa\n2. Perro\n3. Gato");
    dadosExercicios[5].respostaCorreta = 1;
    dadosExercicios[5].valorPontuacao = 100;
    dadosExercicios[5].status = 0;
    indicesExercicios[5].codigo = 6;
    indicesExercicios[5].endereco = 5;

    int contExercicios = 6;

    // ---------------------------------------------

    int opcao=-1;

    while (opcao != 0) {
        system("cls");
        cout << "Menu trabalho idiomas\n";
        cout << "=====================\n";
        cout << "0. Sair\n";
        cout << "1. Buscar\n";
        cout << "2. Incluir\n";
        cout << "3. Leitura exaustiva\n";
        cout << "4. Excluir\n";
        cout << "5. Reorganizar\n";
        cout << "6. Praticar exerc�cios\n";
        cout << "7. Melhores alunos\n";
        cout << "Escolha uma op��o: ";
        cin >> opcao;

        switch (opcao) {

            case 0: {
                cout << "\nSaindo do programa..." << endl;
                break;
            }

            case 1: {
                int opcaoLeitura = -1;
                while(opcaoLeitura != 0){
                    system("cls");
                    cout << "Menu busca\n";
                    cout << "==========\n";
                    cout << "0. Voltar" << endl;
                    cout << "1. Buscar idioma" << endl;
                    cout << "2. Buscar li��o" << endl;
                    cout << "3. Buscar exerc�cio" << endl;
                    cout << "4. Buscar usu�rio" << endl;
                    cout << "Escolha uma op��o: ";
                    cin >> opcaoLeitura;

                    switch(opcaoLeitura){
                    case 0:
                        break;

                    case 1: {
                        int codigoBuscaIdioma;
                        cout << "Digite o c�digo do idioma a ser buscado: ";
                        cin >> codigoBuscaIdioma;
                        int i;
                        i = buscarIdiomas(indicesIdiomas, dadosIdiomas, contIdiomas, codigoBuscaIdioma);
                        if(i == -1){
                            cout << "\nIdioma n�o cadastrado\n\n";
                        } else if (i == -2){
                            cout << "\nIdioma desativado\n\n";
                        } else {
                            cout << "\nC�digo Idioma: " << dadosIdiomas[i].codigoIdioma;
                            cout << "\tDescri��o: " << dadosIdiomas[i].descricao << endl << endl;
                        }
                        system("pause");
                        break;
                    }

                    case 2:{
                        int codigoBuscaLicao;
                        cout << "Digite o c�digo da li��o a ser buscada: ";
                        cin >> codigoBuscaLicao;
                        int i = buscarLicoes(indicesLicoes, dadosLicoes, contLicoes, codigoBuscaLicao);

                        if(i == -1){
                            cout << "\nLi��o n�o cadastrada\n\n";
                        } else if (i == -2){
                            cout << "\nLi��o desativada\n\n";
                        } else {
                            int j = buscarIdiomas(indicesIdiomas, dadosIdiomas, contIdiomas, dadosLicoes[i].codigoIdioma);
                            cout << "\nC�digo da Li��o: " << dadosLicoes[i].codigoLicao << endl;
                            cout << "Codigo Idioma: " << dadosLicoes[i].codigoIdioma << " - "<< dadosIdiomas[j].descricao;
                            cout << "\nTotal n�veis: " << dadosLicoes[i].totalNiveis << endl<< endl;
                        }
                        system("pause");
                        break;


                    }

                    case 3: {
                        int codigoBuscaExercicio;
                        cout << "Digite o c�digo do exerc�cio a ser buscado: ";
                        cin >> codigoBuscaExercicio;
                        int i;
                        i = buscarExercicios(indicesExercicios, dadosExercicios, contExercicios, codigoBuscaExercicio);
                        if(i == -1){
                            cout << "\nExerc�cio n�o cadastrado\n\n";
                        } else if (i == -2){
                            cout << "\nExerc�cio desativado\n\n";
                        } else {
                            cout << "\nC�digo Exerc�cio: " << dadosExercicios[i].codigoExercicio;
                            cout << "\tC�digo Li��o: " << dadosExercicios[i].codLicao;
                            cout << "\t    N�vel dificuldade: " << dadosExercicios[i].nivelDificuldade << endl;
                            cout << "Descri��o: " << dadosExercicios[i].descricao << endl;
                            cout << "Resposta Correta: " << dadosExercicios[i].respostaCorreta;
                            cout << "\tValor Pontua��o: " << dadosExercicios[i].valorPontuacao << endl << endl;
                        }
                        system("pause");
                        break;
                    }

                    case 4: {
                        int codigoBuscaUsuario;
                        cout << "Digite o c�digo do usu�rio a ser buscado: ";
                        cin >> codigoBuscaUsuario;
                        int i = buscarUsuarios(indicesUsuarios, dadosUsuarios, contUsuarios, codigoBuscaUsuario);
                        if(i == -1){
                            cout << "\nUsu�rio n�o cadastrado\n\n";
                        } else if (i == -2){
                            cout << "\nUsu�rio desativado\n\n";
                        } else {
                            int j = buscarIdiomas(indicesIdiomas, dadosIdiomas, contIdiomas, dadosUsuarios[i].codigoIdiomaEscolhido);
                            cout << "\nC�digo Usu�rio: " << dadosUsuarios[i].codigoUsuario << endl;
                            cout << "Nome: " << dadosUsuarios[i].nome << endl;
                            cout << "C�digo do Idioma Escolhido: " << dadosUsuarios[i].codigoIdiomaEscolhido;
                            cout << " - " << dadosIdiomas[j].descricao;
                            cout << "\nN�vel Atual: " << dadosUsuarios[i].nivelAtual << endl;
                            cout << "Pontua��o Total: " << dadosUsuarios[i].pontuacaoTotal << endl << endl;
                        }
                        system("pause");
                        break;
                    }
                    default:
                        cout << "\nOp��o inv�lida! Digite novamente.\n" << endl;
                        system("pause");
                        break;
                    }
                }
                break;
            }

            case 2: {
                int opcaoIncluir = -1;
                while(opcaoIncluir != 0){
                    system("cls");
                    cout << "Menu inclus�o\n";
                    cout << "=============\n";
                    cout << "0. Voltar" << endl;
                    cout << "1. Incluir idioma" << endl;
                    cout << "2. Incluir li��o" << endl;
                    cout << "3. Incluir exerc�cio" << endl;
                    cout << "4. Incluir usu�rio" << endl;
                    cout << "Escolha uma op��o: ";
                    cin >> opcaoIncluir;

                    switch(opcaoIncluir){
                    case 0:
                        break;

                    case 1: {
                        int codigoInclusaoIdioma;
                        cout << "Digite o c�digo do idioma a ser incluido: ";
                        cin >> codigoInclusaoIdioma;
                        int i = buscarIdiomas(indicesIdiomas, dadosIdiomas, contIdiomas, codigoInclusaoIdioma);
                        if(i == -1){
                            inclusaoIdioma(indicesIdiomas, dadosIdiomas, contIdiomas, codigoInclusaoIdioma);
                        } else if (i == -2){
                            cout << "\nIdioma j� cadastrado\nStatus: Desativado\n\n";
                        } else {
                            cout << "\nIdioma j� cadastrado\nStatus: Ativo\n\n";
                        }
                        system("pause");
                        break;
                    }

                    case 2: {
                        int codigoInclusaoLicao;
                        cout << "Digite o c�digo da li��o a ser incluida: ";
                        cin >> codigoInclusaoLicao;
                        int i = buscarLicoes(indicesLicoes, dadosLicoes, contLicoes, codigoInclusaoLicao);
                        if(i == -1){
                            inclusaoLicao(indicesLicoes, dadosLicoes, contLicoes, codigoInclusaoLicao, indicesIdiomas, dadosIdiomas, contIdiomas);
                        } else if (i == -2){
                            cout << "\nLi��o j� cadastrada\nStatus: Desativado\n\n";
                        } else {
                            cout << "\nLi��o j� cadastrada\nStatus: Ativo\n\n";
                        }
                        system("pause");
                        break;
                    }

                    case 3: {
                        int codigoInclusaoExercicio;
                        cout << "Digite o c�digo do exerc�cio a ser incluido: ";
                        cin >> codigoInclusaoExercicio;
                        int i;
                        i = buscarExercicios(indicesExercicios, dadosExercicios, contExercicios, codigoInclusaoExercicio);
                        if(i == -1){
                            inclusaoExercicio(indicesExercicios, dadosExercicios, contExercicios, codigoInclusaoExercicio, indicesLicoes, dadosLicoes, contLicoes);
                        } else if (i == -2){
                            cout << "\nExerc�cio j� cadastrado\nStatus: Desativado\n\n";
                        } else {
                            cout << "\nExercicio j� cadastrado\nStatus: Ativo\n\n";
                        }
                        system("pause");
                        break;
                    }

                    case 4: {
                        int codigoInclusaoUsuario;
                        cout << "Digite o c�digo do usu�rio a ser incluido: ";
                        cin >> codigoInclusaoUsuario;
                        int i;
                        i = buscarUsuarios(indicesUsuarios, dadosUsuarios, contUsuarios, codigoInclusaoUsuario);
                        if(i == -1){
                            inclusaoUsuario(indicesUsuarios, dadosUsuarios, contUsuarios, codigoInclusaoUsuario, indicesIdiomas, dadosIdiomas, contIdiomas);
                        } else if (i == -2){
                            cout << "\nUsu�rio j� cadastrado\nStatus: Desativado\n\n";
                        } else {
                            cout << "\nUsu�rio j� cadastrado\nStatus: Ativo\n\n";
                        }
                        system("pause");
                        break;
                    }

                    default:
                        cout << "\nOp��o inv�lida! Digite novamente.\n" << endl;
                        system("pause");
                        break;

                    }
                }
                break;
            }

            case 3: {
                int opcaoLeitura = -1;
                while(opcaoLeitura != 0){
                    system("cls");
                    cout << "Menu leitura exaustiva\n";
                    cout << "======================\n";
                    cout << "0. Voltar" << endl;
                    cout << "1. Leitura exaustiva idiomas" << endl;
                    cout << "2. Leitura exaustiva li��es" << endl;
                    cout << "3. Leitura exaustiva exerc�cios" << endl;
                    cout << "4. Leitura exaustiva usu�rios" << endl;
                    cout << "Escolha uma op��o: ";
                    cin >> opcaoLeitura;

                    switch(opcaoLeitura){
                    case 0:
                        break;
                    case 1:
                        exaustivaIdiomas(indicesIdiomas, dadosIdiomas, contIdiomas);
                        system("pause");
                        break;
                    case 2:
                        exaustivaLicoes(indicesLicoes, dadosLicoes, contLicoes, indicesIdiomas, dadosIdiomas, contIdiomas);
                        system("pause");
                        break;
                    case 3:
                        exaustivaExercicios(indicesExercicios, dadosExercicios, contExercicios);
                        system("pause");
                        break;
                    case 4:
                        exaustivaUsuarios(indicesUsuarios, dadosUsuarios, contUsuarios, indicesIdiomas, dadosIdiomas, contIdiomas);
                        system("pause");
                        break;
                    default:
                        cout << "\nOp��o inv�lida! Digite novamente.\n" << endl;
                        system("pause");
                        break;
                    }
                }
                break;
            }

            case 4: {
                int opcaoExclusao = -1;
                while(opcaoExclusao != 0){
                    system("cls");
                    cout << "Menu exclus�o\n";
                    cout << "=============\n";
                    cout << "0. Voltar" << endl;
                    cout << "1. Excluir idiomas" << endl;
                    cout << "2. Excluir li��es" << endl;
                    cout << "3. Excluir exerc�cios" << endl;
                    cout << "4. Excluir usu�rios" << endl;
                    cout << "Escolha uma op��o: ";
                    cin >> opcaoExclusao;

                    switch(opcaoExclusao) {
                    case 0:
                        break;
                    case 1:{
                        int codigoBuscaIdioma;
                        cout << "Digite o c�digo do idioma a ser excluido: ";
                        cin >> codigoBuscaIdioma;
                        int i;
                        i = buscarIdiomas(indicesIdiomas, dadosIdiomas, contIdiomas, codigoBuscaIdioma);
                        if(i == -1){
                            cout << "\nIdioma n�o cadastrado\n\n";
                        } else if (i == -2){
                            cout << "\nIdioma j� desativado\n\n";
                        } else {

                            int k = 0;

                            bool encontradoUsuario = false;

                            while(k<contUsuarios && encontradoUsuario == false){
                                int i = indicesUsuarios[k].endereco;
                                if(dadosUsuarios[i].status == 0 && dadosUsuarios[i].codigoIdiomaEscolhido == codigoBuscaIdioma){
                                    encontradoUsuario = true;
                                }
                                k++;
                            }

                            k=0;
                            bool encontradoLicao = false;

                            while(k<contLicoes && encontradoLicao == false){
                                int i = indicesLicoes[k].endereco;
                                if(dadosLicoes[i].status == 0 && dadosLicoes[i].codigoIdioma == codigoBuscaIdioma){
                                    encontradoLicao = true;
                                }
                                k++;
                            }

                            if(encontradoLicao == false && encontradoUsuario == false) {
                                char conf;
                                cout << "\nC�digo Idioma: " << dadosIdiomas[i].codigoIdioma;
                                cout << "\tDescri��o: " << dadosIdiomas[i].descricao << endl << endl;
                                cout << "\nConfirma a exclus�o?\n1. Sim\n2. N�o\nEscolha uma op��o: ";
                                cin >> conf;
                                if(conf == '1'){
                                    dadosIdiomas[i].status = 1;
                                    cout << "\nExclus�o realizada\n\n";
                                }
                            } else {
                                cout << "\nN�o foi poss�vel realizar a exclus�o";
                                if(encontradoLicao)
                                    cout << "\nH� li��es cadastradas com esse idioma";
                                if(encontradoUsuario)
                                    cout << "\nH� usu�rios cadastrados com esse idioma";
                                cout << endl << endl;
                            }
                        }
                        system("pause");
                        break;
                        }

                    case 2:{
                        int codigoBuscaLicao;
                        cout << "Digite o c�digo da li��o a ser excluida: ";
                        cin >> codigoBuscaLicao;
                        int i = buscarLicoes(indicesLicoes, dadosLicoes, contLicoes, codigoBuscaLicao);

                        if(i == -1){
                            cout << "\nLi��o n�o cadastrada\n\n";
                        } else if (i == -2){
                            cout << "\nLi��o j� desativada\n\n";
                        } else {

                            int k = 0;

                            bool encontradoExercicio = false;

                            while(k<contExercicios && encontradoExercicio == false){
                                int i = indicesExercicios[k].endereco;
                                if(dadosExercicios[i].status == 0 && dadosExercicios[i].codLicao == codigoBuscaLicao){
                                    encontradoExercicio = true;
                                }
                                k++;
                            }

                            if(encontradoExercicio == false){
                                char conf;
                                int j = buscarIdiomas(indicesIdiomas, dadosIdiomas, contIdiomas, dadosLicoes[i].codigoIdioma);
                                cout << "\nC�digo da Li��o: " << dadosLicoes[i].codigoLicao << endl;
                                cout << "Codigo Idioma: " << dadosLicoes[i].codigoIdioma;
                                cout << " - " << dadosIdiomas[j].descricao << endl;
                                cout << "Total n�veis: " << dadosLicoes[i].totalNiveis << endl<< endl;
                                cout << "\nConfirma a exclus�o?\n1. Sim\n2. N�o\nEscolha uma op��o: ";
                                cin >> conf;
                                if(conf == '1'){
                                    dadosLicoes[i].status = 1;
                                    cout << "\nExclus�o realizada\n\n";
                                }
                            } else {
                                cout << "\nN�o foi poss�vel realizar a exclus�o";
                                cout << "\nH� exerc�cios cadastrados com essa li��o\n\n";
                            }
                        }
                        system("pause");
                        break;
                        }

                    case 3:{
                        int codigoBuscaExercicio;
                        cout << "Digite o c�digo do exerc�cio a ser excluido: ";
                        cin >> codigoBuscaExercicio;
                        int i;
                        i = buscarExercicios(indicesExercicios, dadosExercicios, contExercicios, codigoBuscaExercicio);
                        if(i == -1){
                            cout << "\nExerc�cio n�o cadastrado\n\n";
                        } else if (i == -2){
                            cout << "\nExerc�cio j� desativado\n\n";
                        } else {
                            char conf;
                            cout << "\nC�digo Exerc�cio: " << dadosExercicios[i].codigoExercicio;
                            cout << "\tC�digo Li��o: " << dadosExercicios[i].codLicao;
                            cout << "\t    N�vel dificuldade: " << dadosExercicios[i].nivelDificuldade << endl;
                            cout << "Descri��o: " << dadosExercicios[i].descricao << endl;
                            cout << "Resposta Correta: " << dadosExercicios[i].respostaCorreta;
                            cout << "\tValor Pontua��o: " << dadosExercicios[i].valorPontuacao << endl << endl;
                            cout << "\nConfirma a exclus�o?\n1. Sim\n2. N�o\nEscolha uma op��o: ";
                            cin >> conf;
                            if(conf == '1'){
                                dadosExercicios[i].status = 1;
                                cout << "\nExclus�o realizada\n\n";
                            }
                        }
                        system("pause");
                        break;
                    }

                    case 4: {
                        int codigoBuscaUsuario;
                        cout << "Digite o c�digo do usu�rio a ser excluido: ";
                        cin >> codigoBuscaUsuario;
                        int i = buscarUsuarios(indicesUsuarios, dadosUsuarios, contUsuarios, codigoBuscaUsuario);
                        if(i == -1){
                            cout << "\nUsu�rio n�o cadastrado\n\n";
                        } else if (i == -2){
                            cout << "\nUsu�rio j� desativado\n\n";
                        } else {
                            int j = buscarIdiomas(indicesIdiomas, dadosIdiomas, contIdiomas, dadosUsuarios[i].codigoIdiomaEscolhido);
                            char conf;
                            cout << "\nC�digo Usu�rio: " << dadosUsuarios[i].codigoUsuario;
                            cout << "\tNome: " << dadosUsuarios[i].nome << endl;
                            cout << "C�digo do Idioma Escolhido: " << dadosUsuarios[i].codigoIdiomaEscolhido << " - " << dadosIdiomas[j].descricao << endl;
                            cout << "N�vel Atual: " << dadosUsuarios[i].nivelAtual << endl;
                            cout << "Pontua��o Total: " << dadosUsuarios[i].pontuacaoTotal << endl << endl;
                            cout << "\nConfirma a exclus�o?\n1. Sim\n2. N�o\nEscolha uma op��o: ";
                            cin >> conf;
                            if(conf == '1'){
                                dadosUsuarios[i].status = 1;
                                cout << "\nExclus�o realizada\n\n";
                            }
                        }
                        system("pause");
                        break;
                    }

                    default:
                        cout << "\nOp��o inv�lida! Digite novamente.\n" << endl;
                        system("pause");
                        break;
                    }
                }
                break;
            }

            case 5 : {
                int opcaoReorganizacao = -1;
                while(opcaoReorganizacao != 0){
                    system("cls");
                    cout << "Menu exclus�o\n";
                    cout << "=============\n";
                    cout << "0. Voltar" << endl;
                    cout << "1. Reorganizar idiomas" << endl;
                    cout << "2. Reorganizar li��es" << endl;
                    cout << "3. Reorganizar exerc�cios" << endl;
                    cout << "4. Reorganizar usu�rios" << endl;
                    cout << "Escolha uma op��o: ";
                    cin >> opcaoReorganizacao;

                    switch(opcaoReorganizacao){
                        case 0:
                            break;

                        case 1:{
                            reorganizarIdiomas(indicesIdiomas, dadosIdiomas, contIdiomas);
                            break;
                        }

                        case 2:{
                            reorganizarLicoes(indicesLicoes, dadosLicoes, contLicoes);
                            break;
                        }

                        case 3: {
                            reorganizarExercicios(indicesExercicios, dadosExercicios, contExercicios);
                            break;
                        }

                        case 4: {
                            reorganizarUsuarios(indicesUsuarios, dadosUsuarios, contUsuarios);
                        }
                    }
                }
                break;
            }

            case 6: {
                system("cls");
                int codigoUsuario;
                cout << "Digite o c�digo do usu�rio que praticar� o exerc�cio: ";
                cin >> codigoUsuario;
                int i = buscarUsuarios(indicesUsuarios, dadosUsuarios, contUsuarios, codigoUsuario);
                if(i==-1){
                    cout << "\nUsu�rio n�o cadastrado\n\n";
                } else if(i==-2){
                    cout << "\nUsu�rio destivado\n\n";
                } else {
                    cout << endl << dadosUsuarios[i].nome;
                    cout << "\nIdioma: " << dadosIdiomas[buscarIdiomas(indicesIdiomas, dadosIdiomas, contIdiomas, dadosUsuarios[i].codigoIdiomaEscolhido)].descricao;
                    cout << "\nN�vel atual: " << dadosUsuarios[i].nivelAtual << " - Pontua��o total: "<< dadosUsuarios[i].pontuacaoTotal << "\n\n";

                    int codigoLicao=0;
                    int totalNiveis;
                    for (int k = 0; k < contLicoes && codigoLicao == 0; k++) {
                        int o = indicesLicoes[k].endereco;
                        if (dadosLicoes[o].status == 0 && dadosLicoes[o].codigoIdioma == dadosUsuarios[i].codigoIdiomaEscolhido) {
                            codigoLicao = dadosLicoes[o].codigoLicao;
                            totalNiveis = dadosLicoes[o].totalNiveis;
                        }
                    }

                    bool temExercicio=false;
                    int exerciciosValidos[20] = {}, contExerciciosValidos=0;

                    for (int k = 0; k < contExercicios; k++) {
                        int p = indicesExercicios[k].endereco;
                        if (dadosExercicios[p].status == 0 && dadosExercicios[p].codLicao == codigoLicao && dadosExercicios[p].nivelDificuldade <= dadosUsuarios[i].nivelAtual) {
                            cout << "Exerc�cio " << dadosExercicios[p].codigoExercicio << endl;
                            cout << "N�vel dificuldade: " << dadosExercicios[p].nivelDificuldade << endl;
                            cout << "Valor Pontua��o: " << dadosExercicios[p].valorPontuacao << endl << endl;
                            exerciciosValidos[contExerciciosValidos] = dadosExercicios[p].codigoExercicio;
                            contExerciciosValidos++;
                            temExercicio=true;
                        }
                    }

                    if(temExercicio){
                        int codigoExercicioEscolhido;
                        cout << "Selecione um exerc�cio: ";
                        cin >> codigoExercicioEscolhido;

                        bool exercicioValido=false;

                        for(int i=0; i < contExerciciosValidos && exercicioValido == false; i++){
                            if(exerciciosValidos[i] == codigoExercicioEscolhido){
                                exercicioValido = true;
                            }
                        }

                        if(exercicioValido){
                            system("cls");
                            int respostaUsuario;
                            int t = buscarExercicios(indicesExercicios, dadosExercicios, contExercicios, codigoExercicioEscolhido);
                            cout << "Exerc�cio " << codigoExercicioEscolhido << endl;
                            cout << dadosExercicios[t].descricao << endl;
                            cout << "Digite sua resposta: ";
                            cin >> respostaUsuario;
                            if(respostaUsuario == dadosExercicios[t].respostaCorreta){
                                cout << "\nResposta correta\n\n";
                                dadosUsuarios[i].pontuacaoTotal += dadosExercicios[t].valorPontuacao;
                                while (dadosUsuarios[i].pontuacaoTotal >= (dadosUsuarios[i].nivelAtual * 100)) {
                                    dadosUsuarios[i].nivelAtual++;
                                    cout << "Subiu de n�vel - N�vel atual: " << dadosUsuarios[i].nivelAtual << endl;
                                }
                                if(dadosUsuarios[i].nivelAtual > totalNiveis){
                                    cout << "Certificado obtido!!!!! Parab�ns!!!!!!!!\n\n";
                                }

                            } else {
                                dadosUsuarios[i].pontuacaoTotal -= dadosExercicios[t].valorPontuacao * 0.10;
                                cout << "\nResposta incorreta\n\n";
                            }
                        } else {
                            cout << "\nExerc�cio bloqueado\n\n";
                        }
                    } else {
                        cout << "Lamento, n�o temos exerc�cios para esse idioma ainda\n\n";
                    }


                }
                system("pause");
                break;
            }

            case 7: {
                ordenarUsuarios(dadosUsuarios, contUsuarios);
                system("pause");
                break;
            }

            default:
                cout << "\nOp��o inv�lida! Digite novamente.\n" << endl;
                system("pause");
                break;
        }
    }

    return 0;
}

void inclusaoIdioma (struct indices idx[], struct idiomas x[], int &cont, int cod){
    x[cont].codigoIdioma = cod;
    cout << "Descricao: ";
    cin.ignore();
    cin.getline(x[cont].descricao, 20);
    x[cont].status = 0;
    int i;
    for (i = cont - 1; idx[i].codigo > cod; i--){
        idx[i+1].codigo = idx[i].codigo;
        idx[i+1].endereco = idx[i].endereco;
    }
    idx[i+1].codigo = cod;
    idx[i+1].endereco = cont;
    cout << "\nInclusao realizada com Sucesso\n\n";
    cont++;
}

void inclusaoLicao (struct indices idx[], struct licoes x[], int &cont, int cod, struct indices indicesIdiomas[], struct idiomas dadosIdiomas[], int contIdiomas){
    struct licoes licaoAux;

    licaoAux.codigoLicao = cod;
    cout << "Codigo idioma: ";
    cin >> licaoAux.codigoIdioma;
    int b = buscarIdiomas(indicesIdiomas, dadosIdiomas, contIdiomas, licaoAux.codigoIdioma);

    if(b==-1){
        cout << "\nIdioma n�o cadastrado\n\n";
    } else if (b==-2){
        cout << "\nIdioma desativado\n\n";
    } else {
        cout << "\t     : " << dadosIdiomas[b].descricao;
        cout << "\nTotal de n�veis: ";
        cin >> licaoAux.totalNiveis;
        licaoAux.status = 0;

        x[cont] = licaoAux;

        int i;
        for (i = cont - 1; idx[i].codigo > cod; i--){
            idx[i+1].codigo = idx[i].codigo;
            idx[i+1].endereco = idx[i].endereco;
        }
        idx[i+1].codigo = cod;
        idx[i+1].endereco = cont;
        cout << "\nInclusao realizada com Sucesso\n\n";
        cont++;
    }
}

void inclusaoExercicio (struct indices idx[], struct exercicios x[], int &cont, int cod, struct indices indicesLicoes[], struct licoes dadosLicoes[], int contLicoes){
    struct exercicios exercicioAux;

    exercicioAux.codigoExercicio = cod;
    cout << "Codigo li��o: ";
    cin >> exercicioAux.codLicao;
    int b = buscarLicoes(indicesLicoes, dadosLicoes, contLicoes, exercicioAux.codLicao);
    if(b==-1){
        cout << "\nLi��o n�o cadastrada\n\n";
    } else if (b==-2){
        cout << "\nLi��o desativada\n\n";
    } else {
        cout << "N�vel de dificuldade: ";
        cin >> exercicioAux.nivelDificuldade;
        cout << "Descri��o: ";
        cin.ignore();
        cin.getline(exercicioAux.descricao, 200);
        cout << "Resposta correta: ";
        cin >> exercicioAux.respostaCorreta;
        cout << "Valor Pontua��o: ";
        cin >> exercicioAux.valorPontuacao;
        exercicioAux.status = 0;
        x[cont] = exercicioAux;


        int i;
        for (i = cont - 1; idx[i].codigo > cod; i--){
            idx[i+1].codigo = idx[i].codigo;
            idx[i+1].endereco = idx[i].endereco;
        }
        idx[i+1].codigo = cod;
        idx[i+1].endereco = cont;
        cout << "\nInclusao realizada com Sucesso\n\n";
        cont++;
    }
}

void inclusaoUsuario (struct indices idx[], struct usuarios x[], int &cont, int cod, struct indices indicesIdiomas[], struct idiomas dadosIdiomas[], int contIdiomas){
    struct usuarios usuarioAux;

    usuarioAux.codigoUsuario = cod;
    cout << "Nome: ";
    cin.ignore();
    cin.getline(usuarioAux.nome, 35);
    cout << "Codigo idioma escolhido: ";
    cin >> usuarioAux.codigoIdiomaEscolhido;
    int b = buscarIdiomas(indicesIdiomas, dadosIdiomas, contIdiomas, usuarioAux.codigoIdiomaEscolhido);
    if(b==-1){
        cout << "\nIdioma n�o cadastrado\n\n";
    } else if(b == -2){
        cout << "\nIdioma desativado\n\n";
    } else {
        cout << "\t\t       :" << dadosIdiomas[b].descricao;
        cout << "\nNivel atual: ";
        cin >> usuarioAux.nivelAtual;
        cout << "PontuacaoTotal: ";
        cin >> usuarioAux.pontuacaoTotal;
        usuarioAux.status = 0;

        x[cont].codigoUsuario = usuarioAux.codigoUsuario;
        x[cont].codigoIdiomaEscolhido = usuarioAux.codigoIdiomaEscolhido;
        strcpy(x[cont].nome ,usuarioAux.nome);
        x[cont].nivelAtual = usuarioAux.nivelAtual;
        x[cont].pontuacaoTotal = usuarioAux.pontuacaoTotal;

        int i;
        for (i = cont - 1; idx[i].codigo > cod; i--){
            idx[i+1].codigo = idx[i].codigo;
            idx[i+1].endereco = idx[i].endereco;
        }
        idx[i+1].codigo = cod;
        idx[i+1].endereco = cont;
        cout << "\nInclusao realizada com Sucesso\n\n";
        cont++;
    }
}

void exaustivaIdiomas (struct indices idx[], struct idiomas x[], int cont){
    cout << endl;
    for (int k=0; k < cont; k++){
        int i = idx[k].endereco;
        if (x[i].status == 0){
            cout << "C�digo: " << x[i].codigoIdioma;
            cout << "\nDescricao: " << x[i].descricao << endl << endl;
        }
    }
}

void exaustivaUsuarios(struct indices idx[], struct usuarios u[], int cont, struct indices indicesIdiomas[], struct idiomas dadosIdiomas[], int contIdiomas) {
    cout << endl;
    for (int k = 0; k < cont; k++) {
        int i = idx[k].endereco;
        if (u[i].status == 0) {
            cout << "C�digo: " << u[i].codigoUsuario;
            cout << "\tNome: " << u[i].nome << endl;
            cout << "C�digo Idioma Escolhido: " << u[i].codigoIdiomaEscolhido;
            int j = buscarIdiomas(indicesIdiomas, dadosIdiomas, contIdiomas, u[i].codigoIdiomaEscolhido);
            cout << " - " << dadosIdiomas[j].descricao;
            cout << "\nN�vel Atual: " << u[i].nivelAtual << endl;
            cout << "Pontua��o Total: " << u[i].pontuacaoTotal << endl << endl;
        }
    }
}

void exaustivaLicoes(struct indices idx[], struct licoes u[], int cont, struct indices indicesIdiomas[], struct idiomas dadosIdiomas[], int contIdiomas) {
    cout << endl;
    for (int k = 0; k < cont; k++) {
        int i = idx[k].endereco;
        if (u[i].status == 0) {
            cout << "C�digo: " << u[i].codigoLicao << endl;
            cout << "C�digo Idioma: " << u[i].codigoIdioma;
            int j = buscarIdiomas(indicesIdiomas, dadosIdiomas, contIdiomas, u[i].codigoIdioma);
            cout << " - "<< dadosIdiomas[j].descricao << endl;
            cout << "Total N�veis: " << u[i].totalNiveis << endl << endl;
        }
    }
}

void exaustivaExercicios(struct indices idx[], struct exercicios u[], int cont) {
    cout << endl;
    for (int k = 0; k < cont; k++) {
        int i = idx[k].endereco;
        if (u[i].status == 0) {
            cout << "C�digo: " << u[i].codigoExercicio << endl;
            cout << "C�digo Li��o: " << u[i].codLicao << endl;
            cout << "N�vel dificuldade: " << u[i].nivelDificuldade << endl;
            cout << "Descri��o: " << u[i].descricao << endl;
            cout << "Resposta Correta: " << u[i].respostaCorreta << endl;
            cout << "C�digo Li��o: " << u[i].codLicao << endl;
            cout << "Valor Pontua��o: " << u[i].valorPontuacao << endl << endl;
        }
    }
}

int buscarIdiomas(struct indices idx[], struct idiomas idi[], int cont, int cod) {
    int i = 0, f = cont - 1;
    int m = (i + f) / 2;

    for (; f >= i && cod != idx[m].codigo; m = (i + f) / 2) {
        if (cod > idx[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }

    if (f >= i) {
        i = idx[m].endereco;
        if (cod == idx[m].codigo && idi[i].status == 0) {
            return i;
        } else if (cod == idx[m].codigo && idi[i].status == 1) {
            return -2;
        }
    }
    return -1;
}

int buscarUsuarios(struct indices idx[], struct usuarios u[], int cont, int cod) {
    int i = 0, f = cont - 1;
    int m = (i + f) / 2;

    for (; f >= i && cod != idx[m].codigo; m = (i + f) / 2) {
        if (cod > idx[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }

    if (f >= i) {
        i = idx[m].endereco;
        if (cod == idx[m].codigo && u[i].status == 0) {
            return i;
        } else if (cod == idx[m].codigo && u[i].status == 1) {
            return -2;
        }
    }
    return -1;
}

int buscarLicoes(struct indices idx[], struct licoes l[], int cont, int cod) {
    int i = 0, f = cont - 1;
    int m = (i + f) / 2;

    for (; f >= i && cod != idx[m].codigo; m = (i + f) / 2) {
        if (cod > idx[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }

    if (f >= i) {
        i = idx[m].endereco;
        if (cod == idx[m].codigo && l[i].status == 0) {
            return i;
        } else if (cod == idx[m].codigo && l[i].status == 1) {
            return -2;
        }
    }
    return -1;
}

int buscarExercicios(struct indices idx[], struct exercicios l[], int cont, int cod) {
    int i = 0, f = cont - 1;
    int m = (i + f) / 2;

    for (; f >= i && cod != idx[m].codigo; m = (i + f) / 2) {
        if (cod > idx[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }

    if (f >= i) {
        i = idx[m].endereco;
        if (cod == idx[m].codigo && l[i].status == 0) {
            return i;
        } else if (cod == idx[m].codigo && l[i].status == 1) {
            return -2;
        }
    }
    return -1;
}

void reorganizarIdiomas(struct indices idx[], struct idiomas x[], int &cont){
    struct indices novoIdx[20];
    struct idiomas novoX[20];

    int j=0;
    for (int k=0; k < cont; k++){
        int i = idx[k].endereco;
        if (x[i].status == 0){
            novoX[j].codigoIdioma = x[i].codigoIdioma;
            strcpy(novoX[j].descricao, x[i].descricao);
            novoX[j].status = 0;

            novoIdx[j].codigo = novoX[j].codigoIdioma;
            novoIdx[j].endereco = j;
            j++;
        }
    }
    cont = j;

    for(int n=0; n<cont; n++){
        x[n].codigoIdioma = novoX[n].codigoIdioma;
        strcpy(x[n].descricao, novoX[n].descricao);
        x[n].status = 0;

        idx[n].codigo = x[n].codigoIdioma;
        idx[n].endereco = n;
    }
}

void reorganizarLicoes(struct indices idx[], struct licoes x[], int &cont){
    struct indices novoIdx[20];
    struct licoes novoX[20];

    int j=0;
    for (int k=0; k < cont; k++){
        int i = idx[k].endereco;
        if (x[i].status == 0){
            novoX[j].codigoLicao = x[i].codigoLicao;
            novoX[j].codigoIdioma = x[i].codigoIdioma;
            novoX[j].totalNiveis = x[i].totalNiveis;
            novoX[j].status = 0;

            novoIdx[j].codigo = novoX[j].codigoLicao;
            novoIdx[j].endereco = j;
            j++;
        }
    }
    cont = j;

    for(int n=0; n<cont; n++){
        x[n].codigoLicao = novoX[n].codigoLicao;
        x[n].codigoIdioma = novoX[n].codigoIdioma;
        x[n].totalNiveis = novoX[n].totalNiveis;
        x[n].status = 0;

        idx[n].codigo = x[n].codigoLicao;
        idx[n].endereco = n;
    }
}

void reorganizarExercicios(struct indices idx[], struct exercicios x[], int &cont){
    struct indices novoIdx[20];
    struct exercicios novoX[20];

    int j=0;
    for (int k=0; k < cont; k++){
        int i = idx[k].endereco;
        if (x[i].status == 0){
            novoX[j].codigoExercicio = x[i].codigoExercicio;
            novoX[j].codLicao = x[i].codLicao;
            novoX[j].nivelDificuldade = x[i].nivelDificuldade;
            strcpy (novoX[j].descricao,x[i].descricao);
            novoX[j].respostaCorreta = x[i].respostaCorreta;
            novoX[j].valorPontuacao = x[i].valorPontuacao;
            novoX[j].status = 0;

            novoIdx[j].codigo = novoX[j].codigoExercicio;
            novoIdx[j].endereco = j;
            j++;
        }
    }
    cont = j;

    for(int n=0; n<cont; n++){
        x[n].codigoExercicio = novoX[n].codigoExercicio;
        x[n].codLicao = novoX[n].codLicao;
        x[n].nivelDificuldade = novoX[n].nivelDificuldade;
        strcpy (x[n].descricao, novoX[n].descricao);
        x[n].respostaCorreta = novoX[n].respostaCorreta;
        x[n].valorPontuacao = novoX[n].valorPontuacao;
        x[n].status = 0;

        idx[n].codigo = x[n].codigoExercicio;
        idx[n].endereco = n;
    }
}

void reorganizarUsuarios(struct indices idx[], struct usuarios x[], int &cont){
    struct indices novoIdx[20];
    struct usuarios novoX[20];

    int j=0;
    for (int k=0; k < cont; k++){
        int i = idx[k].endereco;
        if (x[i].status == 0){
            novoX[j].codigoUsuario = x[i].codigoUsuario;
            strcpy (novoX[j].nome,x[i].nome);
            novoX[j].codigoIdiomaEscolhido = x[i].codigoIdiomaEscolhido;
            novoX[j].nivelAtual = x[i].nivelAtual;
            novoX[j].pontuacaoTotal = x[i].pontuacaoTotal;
            novoX[j].status = 0;

            novoIdx[j].codigo = novoX[j].codigoUsuario;
            novoIdx[j].endereco = j;
            j++;
        }
    }
    cont = j;

    for(int n=0; n<cont; n++){
        x[n].codigoUsuario = novoX[n].codigoUsuario;
        strcpy (x[n].nome,novoX[n].nome);
        x[n].codigoIdiomaEscolhido = novoX[n].codigoIdiomaEscolhido;
        x[n].nivelAtual = novoX[n].nivelAtual;
        x[n].pontuacaoTotal = novoX[n].pontuacaoTotal;
        x[n].status = 0;

        idx[n].codigo = x[n].codigoUsuario;
        idx[n].endereco = n;
    }

}

bool compararPorPontuacaoTotal(const usuarios &a, const usuarios &b) {
    return a.pontuacaoTotal < b.pontuacaoTotal;
}

void ordenarUsuarios(struct usuarios dadosUsuarios[], int cont) {
    struct usuarios copiaUsuarios[cont];
    for (int i = 0; i < cont; i++) {
        copiaUsuarios[i] = dadosUsuarios[i];
    }

    for (int i = 0; i < cont - 1; i++) {
        for (int j = 0; j < cont - i - 1; j++) {
            if (compararPorPontuacaoTotal(copiaUsuarios[j], copiaUsuarios[j + 1])) {
                usuarios temp = copiaUsuarios[j];
                copiaUsuarios[j] = copiaUsuarios[j + 1];
                copiaUsuarios[j + 1] = temp;
            }
        }
    }

    cout << "-------------------" << endl;
    for (int i = 0; i < cont; i++) {
        cout << "C�digo: " << copiaUsuarios[i].codigoUsuario << endl;
        cout << "Nome: " << copiaUsuarios[i].nome << endl;
        cout << "Pontua��o Total: " << copiaUsuarios[i].pontuacaoTotal << endl;
        cout << "-------------------" << endl;
    }

}


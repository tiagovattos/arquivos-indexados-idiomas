// Trabalho 2º Ano BCC
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

// Prototipação das funções
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
    // Acentuação console
    setlocale(LC_ALL, "portuguese");

    // ---------------------------------------------


    struct idiomas dadosIdiomas[20];
    struct indices indicesIdiomas[20];

    dadosIdiomas[0].codigoIdioma = 1;
    strcpy(dadosIdiomas[0].descricao, "Inglês");
    dadosIdiomas[0].status = 0;
    indicesIdiomas[0].codigo = 1;
    indicesIdiomas[0].endereco = 0;

    dadosIdiomas[1].codigoIdioma = 2;
    strcpy(dadosIdiomas[1].descricao, "Alemão");
    dadosIdiomas[1].status = 0;
    indicesIdiomas[1].codigo = 2;
    indicesIdiomas[1].endereco = 1;

    dadosIdiomas[2].codigoIdioma = 3;
    strcpy(dadosIdiomas[2].descricao, "Espanhol");
    dadosIdiomas[2].status = 0;
    indicesIdiomas[2].codigo = 3;
    indicesIdiomas[2].endereco = 2;

    dadosIdiomas[3].codigoIdioma = 4;
    strcpy(dadosIdiomas[3].descricao, "Francês");
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
    strcpy(dadosUsuarios[0].nome, "João");
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
    strcpy(dadosExercicios[0].descricao, "Como se fala 'copo' em inglês?\n1. Glass\n2. Mug\n3. Tea");
    dadosExercicios[0].respostaCorreta = 1;
    dadosExercicios[0].valorPontuacao = 100;
    dadosExercicios[0].status = 0;
    indicesExercicios[0].codigo = 1;
    indicesExercicios[0].endereco = 0;

    dadosExercicios[1].codigoExercicio = 2;
    dadosExercicios[1].codLicao = 1;
    dadosExercicios[1].nivelDificuldade = 2;
    strcpy(dadosExercicios[1].descricao, "Como se fala 'vaca' em inglês?\n1. Vacuum\n2. Cow\n3. Sheep");
    dadosExercicios[1].respostaCorreta = 2;
    dadosExercicios[1].valorPontuacao = 100;
    dadosExercicios[1].status = 0;
    indicesExercicios[1].codigo = 2;
    indicesExercicios[1].endereco = 1;

    dadosExercicios[2].codigoExercicio = 3;
    dadosExercicios[2].codLicao = 1;
    dadosExercicios[2].nivelDificuldade = 3;
    strcpy(dadosExercicios[2].descricao, "Como se fala 'maçã' em inglês?\n1. Apple\n2. Banana\n3. Orange");
    dadosExercicios[2].respostaCorreta = 1;
    dadosExercicios[2].valorPontuacao = 100;
    dadosExercicios[2].status = 0;
    indicesExercicios[2].codigo = 3;
    indicesExercicios[2].endereco = 2;

    dadosExercicios[3].codigoExercicio = 4;
    dadosExercicios[3].codLicao = 2;
    dadosExercicios[3].nivelDificuldade = 1;
    strcpy(dadosExercicios[3].descricao, "Como se fala 'água' em alemão?\n1. Wasser\n2. Luft\n3. Feuer");
    dadosExercicios[3].respostaCorreta = 1;
    dadosExercicios[3].valorPontuacao = 100;
    dadosExercicios[3].status = 0;
    indicesExercicios[3].codigo = 4;
    indicesExercicios[3].endereco = 3;

    dadosExercicios[4].codigoExercicio = 5;
    dadosExercicios[4].codLicao = 4;
    dadosExercicios[4].nivelDificuldade = 1;
    strcpy(dadosExercicios[4].descricao, "Como se fala 'livro' em francês?\n1. Livre\n2. Chaise\n3. Libro");
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
        cout << "6. Praticar exercícios\n";
        cout << "7. Melhores alunos\n";
        cout << "Escolha uma opção: ";
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
                    cout << "2. Buscar lição" << endl;
                    cout << "3. Buscar exercício" << endl;
                    cout << "4. Buscar usuário" << endl;
                    cout << "Escolha uma opção: ";
                    cin >> opcaoLeitura;

                    switch(opcaoLeitura){
                    case 0:
                        break;

                    case 1: {
                        int codigoBuscaIdioma;
                        cout << "Digite o código do idioma a ser buscado: ";
                        cin >> codigoBuscaIdioma;
                        int i;
                        i = buscarIdiomas(indicesIdiomas, dadosIdiomas, contIdiomas, codigoBuscaIdioma);
                        if(i == -1){
                            cout << "\nIdioma não cadastrado\n\n";
                        } else if (i == -2){
                            cout << "\nIdioma desativado\n\n";
                        } else {
                            cout << "\nCódigo Idioma: " << dadosIdiomas[i].codigoIdioma;
                            cout << "\tDescrição: " << dadosIdiomas[i].descricao << endl << endl;
                        }
                        system("pause");
                        break;
                    }

                    case 2:{
                        int codigoBuscaLicao;
                        cout << "Digite o código da lição a ser buscada: ";
                        cin >> codigoBuscaLicao;
                        int i = buscarLicoes(indicesLicoes, dadosLicoes, contLicoes, codigoBuscaLicao);

                        if(i == -1){
                            cout << "\nLição não cadastrada\n\n";
                        } else if (i == -2){
                            cout << "\nLição desativada\n\n";
                        } else {
                            int j = buscarIdiomas(indicesIdiomas, dadosIdiomas, contIdiomas, dadosLicoes[i].codigoIdioma);
                            cout << "\nCódigo da Lição: " << dadosLicoes[i].codigoLicao << endl;
                            cout << "Codigo Idioma: " << dadosLicoes[i].codigoIdioma << " - "<< dadosIdiomas[j].descricao;
                            cout << "\nTotal níveis: " << dadosLicoes[i].totalNiveis << endl<< endl;
                        }
                        system("pause");
                        break;


                    }

                    case 3: {
                        int codigoBuscaExercicio;
                        cout << "Digite o código do exercício a ser buscado: ";
                        cin >> codigoBuscaExercicio;
                        int i;
                        i = buscarExercicios(indicesExercicios, dadosExercicios, contExercicios, codigoBuscaExercicio);
                        if(i == -1){
                            cout << "\nExercício não cadastrado\n\n";
                        } else if (i == -2){
                            cout << "\nExercício desativado\n\n";
                        } else {
                            cout << "\nCódigo Exercício: " << dadosExercicios[i].codigoExercicio;
                            cout << "\tCódigo Lição: " << dadosExercicios[i].codLicao;
                            cout << "\t    Nível dificuldade: " << dadosExercicios[i].nivelDificuldade << endl;
                            cout << "Descrição: " << dadosExercicios[i].descricao << endl;
                            cout << "Resposta Correta: " << dadosExercicios[i].respostaCorreta;
                            cout << "\tValor Pontuação: " << dadosExercicios[i].valorPontuacao << endl << endl;
                        }
                        system("pause");
                        break;
                    }

                    case 4: {
                        int codigoBuscaUsuario;
                        cout << "Digite o código do usuário a ser buscado: ";
                        cin >> codigoBuscaUsuario;
                        int i = buscarUsuarios(indicesUsuarios, dadosUsuarios, contUsuarios, codigoBuscaUsuario);
                        if(i == -1){
                            cout << "\nUsuário não cadastrado\n\n";
                        } else if (i == -2){
                            cout << "\nUsuário desativado\n\n";
                        } else {
                            int j = buscarIdiomas(indicesIdiomas, dadosIdiomas, contIdiomas, dadosUsuarios[i].codigoIdiomaEscolhido);
                            cout << "\nCódigo Usuário: " << dadosUsuarios[i].codigoUsuario << endl;
                            cout << "Nome: " << dadosUsuarios[i].nome << endl;
                            cout << "Código do Idioma Escolhido: " << dadosUsuarios[i].codigoIdiomaEscolhido;
                            cout << " - " << dadosIdiomas[j].descricao;
                            cout << "\nNível Atual: " << dadosUsuarios[i].nivelAtual << endl;
                            cout << "Pontuação Total: " << dadosUsuarios[i].pontuacaoTotal << endl << endl;
                        }
                        system("pause");
                        break;
                    }
                    default:
                        cout << "\nOpção inválida! Digite novamente.\n" << endl;
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
                    cout << "Menu inclusão\n";
                    cout << "=============\n";
                    cout << "0. Voltar" << endl;
                    cout << "1. Incluir idioma" << endl;
                    cout << "2. Incluir lição" << endl;
                    cout << "3. Incluir exercício" << endl;
                    cout << "4. Incluir usuário" << endl;
                    cout << "Escolha uma opção: ";
                    cin >> opcaoIncluir;

                    switch(opcaoIncluir){
                    case 0:
                        break;

                    case 1: {
                        int codigoInclusaoIdioma;
                        cout << "Digite o código do idioma a ser incluido: ";
                        cin >> codigoInclusaoIdioma;
                        int i = buscarIdiomas(indicesIdiomas, dadosIdiomas, contIdiomas, codigoInclusaoIdioma);
                        if(i == -1){
                            inclusaoIdioma(indicesIdiomas, dadosIdiomas, contIdiomas, codigoInclusaoIdioma);
                        } else if (i == -2){
                            cout << "\nIdioma já cadastrado\nStatus: Desativado\n\n";
                        } else {
                            cout << "\nIdioma já cadastrado\nStatus: Ativo\n\n";
                        }
                        system("pause");
                        break;
                    }

                    case 2: {
                        int codigoInclusaoLicao;
                        cout << "Digite o código da lição a ser incluida: ";
                        cin >> codigoInclusaoLicao;
                        int i = buscarLicoes(indicesLicoes, dadosLicoes, contLicoes, codigoInclusaoLicao);
                        if(i == -1){
                            inclusaoLicao(indicesLicoes, dadosLicoes, contLicoes, codigoInclusaoLicao, indicesIdiomas, dadosIdiomas, contIdiomas);
                        } else if (i == -2){
                            cout << "\nLição já cadastrada\nStatus: Desativado\n\n";
                        } else {
                            cout << "\nLição já cadastrada\nStatus: Ativo\n\n";
                        }
                        system("pause");
                        break;
                    }

                    case 3: {
                        int codigoInclusaoExercicio;
                        cout << "Digite o código do exercício a ser incluido: ";
                        cin >> codigoInclusaoExercicio;
                        int i;
                        i = buscarExercicios(indicesExercicios, dadosExercicios, contExercicios, codigoInclusaoExercicio);
                        if(i == -1){
                            inclusaoExercicio(indicesExercicios, dadosExercicios, contExercicios, codigoInclusaoExercicio, indicesLicoes, dadosLicoes, contLicoes);
                        } else if (i == -2){
                            cout << "\nExercício já cadastrado\nStatus: Desativado\n\n";
                        } else {
                            cout << "\nExercicio já cadastrado\nStatus: Ativo\n\n";
                        }
                        system("pause");
                        break;
                    }

                    case 4: {
                        int codigoInclusaoUsuario;
                        cout << "Digite o código do usuário a ser incluido: ";
                        cin >> codigoInclusaoUsuario;
                        int i;
                        i = buscarUsuarios(indicesUsuarios, dadosUsuarios, contUsuarios, codigoInclusaoUsuario);
                        if(i == -1){
                            inclusaoUsuario(indicesUsuarios, dadosUsuarios, contUsuarios, codigoInclusaoUsuario, indicesIdiomas, dadosIdiomas, contIdiomas);
                        } else if (i == -2){
                            cout << "\nUsuário já cadastrado\nStatus: Desativado\n\n";
                        } else {
                            cout << "\nUsuário já cadastrado\nStatus: Ativo\n\n";
                        }
                        system("pause");
                        break;
                    }

                    default:
                        cout << "\nOpção inválida! Digite novamente.\n" << endl;
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
                    cout << "2. Leitura exaustiva lições" << endl;
                    cout << "3. Leitura exaustiva exercícios" << endl;
                    cout << "4. Leitura exaustiva usuários" << endl;
                    cout << "Escolha uma opção: ";
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
                        cout << "\nOpção inválida! Digite novamente.\n" << endl;
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
                    cout << "Menu exclusão\n";
                    cout << "=============\n";
                    cout << "0. Voltar" << endl;
                    cout << "1. Excluir idiomas" << endl;
                    cout << "2. Excluir lições" << endl;
                    cout << "3. Excluir exercícios" << endl;
                    cout << "4. Excluir usuários" << endl;
                    cout << "Escolha uma opção: ";
                    cin >> opcaoExclusao;

                    switch(opcaoExclusao) {
                    case 0:
                        break;
                    case 1:{
                        int codigoBuscaIdioma;
                        cout << "Digite o código do idioma a ser excluido: ";
                        cin >> codigoBuscaIdioma;
                        int i;
                        i = buscarIdiomas(indicesIdiomas, dadosIdiomas, contIdiomas, codigoBuscaIdioma);
                        if(i == -1){
                            cout << "\nIdioma não cadastrado\n\n";
                        } else if (i == -2){
                            cout << "\nIdioma já desativado\n\n";
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
                                cout << "\nCódigo Idioma: " << dadosIdiomas[i].codigoIdioma;
                                cout << "\tDescrição: " << dadosIdiomas[i].descricao << endl << endl;
                                cout << "\nConfirma a exclusão?\n1. Sim\n2. Não\nEscolha uma opção: ";
                                cin >> conf;
                                if(conf == '1'){
                                    dadosIdiomas[i].status = 1;
                                    cout << "\nExclusão realizada\n\n";
                                }
                            } else {
                                cout << "\nNão foi possível realizar a exclusão";
                                if(encontradoLicao)
                                    cout << "\nHá lições cadastradas com esse idioma";
                                if(encontradoUsuario)
                                    cout << "\nHá usuários cadastrados com esse idioma";
                                cout << endl << endl;
                            }
                        }
                        system("pause");
                        break;
                        }

                    case 2:{
                        int codigoBuscaLicao;
                        cout << "Digite o código da lição a ser excluida: ";
                        cin >> codigoBuscaLicao;
                        int i = buscarLicoes(indicesLicoes, dadosLicoes, contLicoes, codigoBuscaLicao);

                        if(i == -1){
                            cout << "\nLição não cadastrada\n\n";
                        } else if (i == -2){
                            cout << "\nLição já desativada\n\n";
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
                                cout << "\nCódigo da Lição: " << dadosLicoes[i].codigoLicao << endl;
                                cout << "Codigo Idioma: " << dadosLicoes[i].codigoIdioma;
                                cout << " - " << dadosIdiomas[j].descricao << endl;
                                cout << "Total níveis: " << dadosLicoes[i].totalNiveis << endl<< endl;
                                cout << "\nConfirma a exclusão?\n1. Sim\n2. Não\nEscolha uma opção: ";
                                cin >> conf;
                                if(conf == '1'){
                                    dadosLicoes[i].status = 1;
                                    cout << "\nExclusão realizada\n\n";
                                }
                            } else {
                                cout << "\nNão foi possível realizar a exclusão";
                                cout << "\nHá exercícios cadastrados com essa lição\n\n";
                            }
                        }
                        system("pause");
                        break;
                        }

                    case 3:{
                        int codigoBuscaExercicio;
                        cout << "Digite o código do exercício a ser excluido: ";
                        cin >> codigoBuscaExercicio;
                        int i;
                        i = buscarExercicios(indicesExercicios, dadosExercicios, contExercicios, codigoBuscaExercicio);
                        if(i == -1){
                            cout << "\nExercício não cadastrado\n\n";
                        } else if (i == -2){
                            cout << "\nExercício já desativado\n\n";
                        } else {
                            char conf;
                            cout << "\nCódigo Exercício: " << dadosExercicios[i].codigoExercicio;
                            cout << "\tCódigo Lição: " << dadosExercicios[i].codLicao;
                            cout << "\t    Nível dificuldade: " << dadosExercicios[i].nivelDificuldade << endl;
                            cout << "Descrição: " << dadosExercicios[i].descricao << endl;
                            cout << "Resposta Correta: " << dadosExercicios[i].respostaCorreta;
                            cout << "\tValor Pontuação: " << dadosExercicios[i].valorPontuacao << endl << endl;
                            cout << "\nConfirma a exclusão?\n1. Sim\n2. Não\nEscolha uma opção: ";
                            cin >> conf;
                            if(conf == '1'){
                                dadosExercicios[i].status = 1;
                                cout << "\nExclusão realizada\n\n";
                            }
                        }
                        system("pause");
                        break;
                    }

                    case 4: {
                        int codigoBuscaUsuario;
                        cout << "Digite o código do usuário a ser excluido: ";
                        cin >> codigoBuscaUsuario;
                        int i = buscarUsuarios(indicesUsuarios, dadosUsuarios, contUsuarios, codigoBuscaUsuario);
                        if(i == -1){
                            cout << "\nUsuário não cadastrado\n\n";
                        } else if (i == -2){
                            cout << "\nUsuário já desativado\n\n";
                        } else {
                            int j = buscarIdiomas(indicesIdiomas, dadosIdiomas, contIdiomas, dadosUsuarios[i].codigoIdiomaEscolhido);
                            char conf;
                            cout << "\nCódigo Usuário: " << dadosUsuarios[i].codigoUsuario;
                            cout << "\tNome: " << dadosUsuarios[i].nome << endl;
                            cout << "Código do Idioma Escolhido: " << dadosUsuarios[i].codigoIdiomaEscolhido << " - " << dadosIdiomas[j].descricao << endl;
                            cout << "Nível Atual: " << dadosUsuarios[i].nivelAtual << endl;
                            cout << "Pontuação Total: " << dadosUsuarios[i].pontuacaoTotal << endl << endl;
                            cout << "\nConfirma a exclusão?\n1. Sim\n2. Não\nEscolha uma opção: ";
                            cin >> conf;
                            if(conf == '1'){
                                dadosUsuarios[i].status = 1;
                                cout << "\nExclusão realizada\n\n";
                            }
                        }
                        system("pause");
                        break;
                    }

                    default:
                        cout << "\nOpção inválida! Digite novamente.\n" << endl;
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
                    cout << "Menu exclusão\n";
                    cout << "=============\n";
                    cout << "0. Voltar" << endl;
                    cout << "1. Reorganizar idiomas" << endl;
                    cout << "2. Reorganizar lições" << endl;
                    cout << "3. Reorganizar exercícios" << endl;
                    cout << "4. Reorganizar usuários" << endl;
                    cout << "Escolha uma opção: ";
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
                cout << "Digite o código do usuário que praticará o exercício: ";
                cin >> codigoUsuario;
                int i = buscarUsuarios(indicesUsuarios, dadosUsuarios, contUsuarios, codigoUsuario);
                if(i==-1){
                    cout << "\nUsuário não cadastrado\n\n";
                } else if(i==-2){
                    cout << "\nUsuário destivado\n\n";
                } else {
                    cout << endl << dadosUsuarios[i].nome;
                    cout << "\nIdioma: " << dadosIdiomas[buscarIdiomas(indicesIdiomas, dadosIdiomas, contIdiomas, dadosUsuarios[i].codigoIdiomaEscolhido)].descricao;
                    cout << "\nNível atual: " << dadosUsuarios[i].nivelAtual << " - Pontuação total: "<< dadosUsuarios[i].pontuacaoTotal << "\n\n";

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
                            cout << "Exercício " << dadosExercicios[p].codigoExercicio << endl;
                            cout << "Nível dificuldade: " << dadosExercicios[p].nivelDificuldade << endl;
                            cout << "Valor Pontuação: " << dadosExercicios[p].valorPontuacao << endl << endl;
                            exerciciosValidos[contExerciciosValidos] = dadosExercicios[p].codigoExercicio;
                            contExerciciosValidos++;
                            temExercicio=true;
                        }
                    }

                    if(temExercicio){
                        int codigoExercicioEscolhido;
                        cout << "Selecione um exercício: ";
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
                            cout << "Exercício " << codigoExercicioEscolhido << endl;
                            cout << dadosExercicios[t].descricao << endl;
                            cout << "Digite sua resposta: ";
                            cin >> respostaUsuario;
                            if(respostaUsuario == dadosExercicios[t].respostaCorreta){
                                cout << "\nResposta correta\n\n";
                                dadosUsuarios[i].pontuacaoTotal += dadosExercicios[t].valorPontuacao;
                                while (dadosUsuarios[i].pontuacaoTotal >= (dadosUsuarios[i].nivelAtual * 100)) {
                                    dadosUsuarios[i].nivelAtual++;
                                    cout << "Subiu de nível - Nível atual: " << dadosUsuarios[i].nivelAtual << endl;
                                }
                                if(dadosUsuarios[i].nivelAtual > totalNiveis){
                                    cout << "Certificado obtido!!!!! Parabéns!!!!!!!!\n\n";
                                }

                            } else {
                                dadosUsuarios[i].pontuacaoTotal -= dadosExercicios[t].valorPontuacao * 0.10;
                                cout << "\nResposta incorreta\n\n";
                            }
                        } else {
                            cout << "\nExercício bloqueado\n\n";
                        }
                    } else {
                        cout << "Lamento, não temos exercícios para esse idioma ainda\n\n";
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
                cout << "\nOpção inválida! Digite novamente.\n" << endl;
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
        cout << "\nIdioma não cadastrado\n\n";
    } else if (b==-2){
        cout << "\nIdioma desativado\n\n";
    } else {
        cout << "\t     : " << dadosIdiomas[b].descricao;
        cout << "\nTotal de níveis: ";
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
    cout << "Codigo lição: ";
    cin >> exercicioAux.codLicao;
    int b = buscarLicoes(indicesLicoes, dadosLicoes, contLicoes, exercicioAux.codLicao);
    if(b==-1){
        cout << "\nLição não cadastrada\n\n";
    } else if (b==-2){
        cout << "\nLição desativada\n\n";
    } else {
        cout << "Nível de dificuldade: ";
        cin >> exercicioAux.nivelDificuldade;
        cout << "Descrição: ";
        cin.ignore();
        cin.getline(exercicioAux.descricao, 200);
        cout << "Resposta correta: ";
        cin >> exercicioAux.respostaCorreta;
        cout << "Valor Pontuação: ";
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
        cout << "\nIdioma não cadastrado\n\n";
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
            cout << "Código: " << x[i].codigoIdioma;
            cout << "\nDescricao: " << x[i].descricao << endl << endl;
        }
    }
}

void exaustivaUsuarios(struct indices idx[], struct usuarios u[], int cont, struct indices indicesIdiomas[], struct idiomas dadosIdiomas[], int contIdiomas) {
    cout << endl;
    for (int k = 0; k < cont; k++) {
        int i = idx[k].endereco;
        if (u[i].status == 0) {
            cout << "Código: " << u[i].codigoUsuario;
            cout << "\tNome: " << u[i].nome << endl;
            cout << "Código Idioma Escolhido: " << u[i].codigoIdiomaEscolhido;
            int j = buscarIdiomas(indicesIdiomas, dadosIdiomas, contIdiomas, u[i].codigoIdiomaEscolhido);
            cout << " - " << dadosIdiomas[j].descricao;
            cout << "\nNível Atual: " << u[i].nivelAtual << endl;
            cout << "Pontuação Total: " << u[i].pontuacaoTotal << endl << endl;
        }
    }
}

void exaustivaLicoes(struct indices idx[], struct licoes u[], int cont, struct indices indicesIdiomas[], struct idiomas dadosIdiomas[], int contIdiomas) {
    cout << endl;
    for (int k = 0; k < cont; k++) {
        int i = idx[k].endereco;
        if (u[i].status == 0) {
            cout << "Código: " << u[i].codigoLicao << endl;
            cout << "Código Idioma: " << u[i].codigoIdioma;
            int j = buscarIdiomas(indicesIdiomas, dadosIdiomas, contIdiomas, u[i].codigoIdioma);
            cout << " - "<< dadosIdiomas[j].descricao << endl;
            cout << "Total Níveis: " << u[i].totalNiveis << endl << endl;
        }
    }
}

void exaustivaExercicios(struct indices idx[], struct exercicios u[], int cont) {
    cout << endl;
    for (int k = 0; k < cont; k++) {
        int i = idx[k].endereco;
        if (u[i].status == 0) {
            cout << "Código: " << u[i].codigoExercicio << endl;
            cout << "Código Lição: " << u[i].codLicao << endl;
            cout << "Nível dificuldade: " << u[i].nivelDificuldade << endl;
            cout << "Descrição: " << u[i].descricao << endl;
            cout << "Resposta Correta: " << u[i].respostaCorreta << endl;
            cout << "Código Lição: " << u[i].codLicao << endl;
            cout << "Valor Pontuação: " << u[i].valorPontuacao << endl << endl;
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
        cout << "Código: " << copiaUsuarios[i].codigoUsuario << endl;
        cout << "Nome: " << copiaUsuarios[i].nome << endl;
        cout << "Pontuação Total: " << copiaUsuarios[i].pontuacaoTotal << endl;
        cout << "-------------------" << endl;
    }

}


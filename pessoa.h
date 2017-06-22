#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <QtSql>

#include "opencv2/core.hpp"

using namespace std;

class Pessoa{

public:
    Pessoa();

    int getId();
    string getMatricula();
    int getTipoPessoa();
    string getNome();
    string getSobrenome();
    string getMaterias();
    string getPathImagens();
    void getPessoaFromSQL(QSqlQuery query);

    void setId(int Id);
    void setMatricula(string Numero_matricula);
    void setTipoPessoa(int Tipo_Pessoa);
    void setNome(string Nome);
    void setSobrenome(string Sobrenome);
    void setMaterias(string Materias);
    void setPathImagens(string PATH_imagens);

    bool SalvaBD();
    void operator=(const Pessoa pessoa);

private:
    int Id;
    string Numero_matricula;
    int Tipo_Pessoa;
    string Nome;
    string Sobrenome;
    string Materias;
    string PATH_imagens;
};

#endif // PESSOA_H

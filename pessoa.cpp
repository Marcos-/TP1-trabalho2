#include "pessoa.h"
#include <iostream>
#include <string>

using namespace cv;

Pessoa::Pessoa()
{
    this->Id = -1;
    this->Numero_matricula = "";
    this->Tipo_Pessoa = 0;
    this->Nome = "";
    this->Sobrenome = "";
    this->Materias = "";
    this->PATH_imagens = "";
}

void Pessoa::operator=(Pessoa pessoa){
    this->Id = pessoa.getId();
    this->Numero_matricula = pessoa.getMatricula();
    this->Tipo_Pessoa = pessoa.getTipoPessoa();
    this->Nome = pessoa.getNome();
    this->Sobrenome = pessoa.getSobrenome();
    this->Materias = pessoa.getMaterias();
    this->PATH_imagens = pessoa.getPathImagens();
}

int Pessoa::getId(){ return this->Id;  }
string Pessoa::getMatricula(){ return this->Numero_matricula; }
int Pessoa::getTipoPessoa(){ return this->Tipo_Pessoa;  }
string Pessoa::getNome(){ return this->Nome; }
string Pessoa::getSobrenome(){ return this->Sobrenome; }
string Pessoa::getMaterias(){ return this->Materias;  }
string Pessoa::getPathImagens(){ return this->PATH_imagens;  }

void Pessoa::setId(int Id){ this->Id = Id; }
void Pessoa::setMatricula(string Numero_matricula){ this->Numero_matricula = Numero_matricula; }
void Pessoa::setTipoPessoa(int Tipo_Pessoa){ this->Tipo_Pessoa = Tipo_Pessoa; }
void Pessoa::setNome(string Nome){ this->Nome = Nome;  }
void Pessoa::setSobrenome(string Sobrenome){ this->Sobrenome = Sobrenome;  }
void Pessoa::setMaterias(string Materias){ this->Materias = Materias;  }
void Pessoa::setPathImagens(string PATH_imagens){ this->PATH_imagens = PATH_imagens;  }

bool Pessoa::SalvaBD(){
    QSqlQuery query;

    string queryStr = "INSERT INTO Pessoas (Tipo_Pessoa, numero_usuario, nome, sobrenome ,materias, PATH_imagens) VALUES (";
    queryStr += to_string(this->getTipoPessoa());
    queryStr += ", '";
    queryStr += this->getMatricula();
    queryStr += "', '";
    queryStr += this->getNome();
    queryStr += "', '";
    queryStr += this->getSobrenome();
    queryStr += "', '";
    queryStr += this->getMaterias();
    queryStr += "', '";
    queryStr += this->getPathImagens();
    queryStr += "');";


    QString queryTxt =  queryStr.c_str();

    bool sucessoBD = query.exec(queryTxt);
    return sucessoBD;
}

void Pessoa::getPessoaFromSQL(QSqlQuery query){

    this->Id =               query.value(0).toInt();
    this->Numero_matricula = query.value(1).toString().toStdString();
    this->Tipo_Pessoa =      query.value(2).toInt();
    this->Nome =             query.value(3).toString().toStdString();
    this->Sobrenome =        query.value(4).toString().toStdString();
    this->Materias =         query.value(5).toString().toStdString();
    this->PATH_imagens =     query.value(6).toString().toStdString();
}

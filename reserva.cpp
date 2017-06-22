#include "reserva.h"

Reserva::Reserva()
{

}


int Reserva::getId(){ return this->Id ; }
int Reserva::getFkPessoa(){  return this->fk_Pessoa ; }
string Reserva::getAutor(){  return this->Autor ; }
string Reserva::getProposta(){  return this->Proposta ; }
string Reserva::getRecorrente(){  return this->Recorrente ; }
string Reserva::getAula(){  return this->Aula ; }
string Reserva::getDataInicio(){  return this->DataInicio ; }
string Reserva::getDataFim(){  return this->DataFim ; }
string Reserva::getHorario(){  return this->Horario ; }
string Reserva::getNumSalas(){  return this->numSalas ; }
string Reserva::getMatriculas(){  return this->Matriculas ;}


void Reserva::setId(int Id){  this->Id = Id ;}
void Reserva::setFKPessoa(int fk){  this->fk_Pessoa = fk ;}
void Reserva::setAutor(string autor){  this->Autor = autor ;}
void Reserva::setProposta(string proposta){  this->Proposta = proposta ;}
void Reserva::setRecorrente(string recorrente){  this->Recorrente = recorrente ;}
void Reserva::setAula(string aula){  this->Aula = aula ;}
void Reserva::setHorario(string Horario){  this->Horario = Horario ;}
void Reserva::setDataInicio(string DataInicio){  this->DataInicio = DataInicio ;}
void Reserva::setDataFim(string DataFim){  this->DataFim = DataFim ;}
void Reserva::setNumSalas(string numSalas){  this->numSalas = numSalas ;}
void Reserva::setMatriculas(string matriculas){  this->Matriculas = matriculas ;}

void Reserva::getResevaFromSQL(QSqlQuery query){
    this->Id =               query.value(0).toInt();
    this->Autor =            query.value(1).toString().toStdString();
    this->Proposta =         query.value(2).toString().toStdString();
    this->Aula =             query.value(3).toString().toStdString();
    this->Recorrente =       query.value(4).toString().toStdString();
    this->numSalas =         query.value(5).toString().toStdString();
    this->Horario =          query.value(6).toString().toStdString();
    this->DataInicio =       query.value(7).toString().toStdString();
    this->DataFim =          query.value(8).toString().toStdString();
    this->Matriculas =       query.value(9).toString().toStdString();
    this->fk_Pessoa  =       query.value(10).toInt();
}

bool Reserva::SalvaBD(Pessoa* user){
    QSqlQuery query;

    string queryStr = "INSERT INTO Reservas (Autor, Proposta, Aula, Aula_recorrente, Num_Salas, Horario , Data_Inicio, Data_Fim, Matriculas, FK_PessoaID) VALUES ('";
    queryStr += user->getMatricula();
    queryStr += "', '";
    queryStr += this->getProposta();
    queryStr += "', '";
    queryStr += this->getAula();
    queryStr += "', '";
    queryStr += this->getRecorrente();
    queryStr += "', '";
    queryStr += this->getNumSalas();
    queryStr += "', '";
    queryStr += this->getHorario();
    queryStr += "', '";
    queryStr += this->getDataInicio();
    queryStr += "', '";
    queryStr += this->getDataFim();
    queryStr += "', '";
    queryStr += this->getMatriculas();
    queryStr += "', '";
    queryStr += to_string(user->getId());
    queryStr += "');";


    QString queryTxt =  queryStr.c_str();

    bool sucessoBD = query.exec(queryTxt);
    return sucessoBD;
}

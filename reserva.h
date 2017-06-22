#ifndef RESERVA_H
#define RESERVA_H

#include <QtSql>
#include "pessoa.h"

using namespace std;

class Reserva{
    public:
        Reserva();
        int getId();
        int getFkPessoa();
        string getAutor();
        string getProposta();
        string getRecorrente();
        string getAula();
        string getDataInicio();
        string getDataFim();
        string getHorario();
        string getNumSalas();
        string getMatriculas();

        void getResevaFromSQL(QSqlQuery query);

        void setId(int Id);
        void setFKPessoa(int fk);
        void setAutor(string autor);
        void setProposta(string proposta);
        void setRecorrente(string recorrente);
        void setAula(string aula);
        void setHorario(string Horario);
        void setDataInicio(string DataInicio);
        void setDataFim(string DataFim);
        void setNumSalas(string numSalas);
        void setMatriculas(string matriculas);

        bool SalvaBD(Pessoa* user);

    private:
        int Id;
        int fk_Pessoa;
        string Autor;
        string Proposta;
        string Aula;
        string Recorrente;
        string Horario;
        string DataInicio;
        string DataFim;
        string numSalas;
        string Matriculas;
};

#endif // RESERVA_H

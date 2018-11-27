#include "numerique.h"

std::map<std::string, double> variables;

Numerique::Numerique() : m_constante(0), m_variable("0"), m_valeurs({}), m_operateur(Operateurs::Rien) {}

Numerique::Numerique(double c) : m_constante(c), m_variable("0"), m_valeurs({}), m_operateur(Operateurs::Rien) {}

Numerique::Numerique(std::string v) : m_constante(0), m_variable(v), m_valeurs({}), m_operateur(Operateurs::Rien) {}

Numerique::Numerique(Numerique * v1, Operateurs op, Numerique * v2) : m_constante(0), m_variable("0"), m_valeurs({v1,v2}), m_operateur(op) {}

double Numerique::getNum() const{
  if(this->m_operateur != Operateurs::Rien){ // Si nous avons une operation
    switch(this->m_operateur){
      case Operateurs::Plus:
        return this->m_valeurs[0]->getNum() + this->m_valeurs[1]->getNum();
      break;
      case Operateurs::Moins:
        return this->m_valeurs[0]->getNum() - this->m_valeurs[1]->getNum();
      break;
      case Operateurs::Fois:
        return this->m_valeurs[0]->getNum() * this->m_valeurs[1]->getNum();
      break;
      case Operateurs::Divise:
        return this->m_valeurs[0]->getNum() / this->m_valeurs[1]->getNum();
      break;
      case Operateurs::Ou:
        return this->m_valeurs[0]->getNum() || this->m_valeurs[1]->getNum();
      break;
      case Operateurs::Et:
        return this->m_valeurs[0]->getNum() && this->m_valeurs[1]->getNum();
      break;
      case Operateurs::Superieur:
        return this->m_valeurs[0]->getNum() > this->m_valeurs[1]->getNum();
      break;
      case Operateurs::SuperieurEgal:
        return this->m_valeurs[0]->getNum() >= this->m_valeurs[1]->getNum();
      break;
      case Operateurs::Egal:
        return this->m_valeurs[0]->getNum() == this->m_valeurs[1]->getNum();
      break;
      case Operateurs::InferieurEgal:
        return this->m_valeurs[0]->getNum() <= this->m_valeurs[1]->getNum();
      break;
      case Operateurs::Inferieur:
        return this->m_valeurs[0]->getNum() < this->m_valeurs[1]->getNum();
      break;
      case Operateurs::Different:
        return this->m_valeurs[0]->getNum() != this->m_valeurs[1]->getNum();
      break;
    }
  }
  // Else
  if(this->m_variable != "0"){ // Si nous avons une chaine alors c'est une variable
    return variables[this->m_variable];
  }
  // Else
  return m_constante;
}

std::string Numerique::getVarName() const{
  return this->m_variable;
}

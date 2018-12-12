#ifndef NUMERIQUE_H
#define NUMERIQUE_H

#include <string>
#include <vector>
#include <map>

extern std::map<std::string, double> variables;

enum class Operateurs {
  Rien,
  Plus,
  Moins,
  Fois,
  Divise,
  Ou,
  Et,
  Superieur,
  SuperieurEgal,
  Egal,
  InferieurEgal,
  Inferieur,
  Different,
  Sinus,
  Cosinus
};

class Numerique {
  public:
    // Constructeurs / Si Numerique est une constante ou une variable
    Numerique();
    Numerique(double c);
    Numerique(std::string v);

    // Constructeur / Si Numerique est une operation entre deux expressions numeriques
    Numerique(Numerique * v1, Operateurs op, Numerique * v2);

    //Accesseurs
    double getNum() const; // Retourne la constante / variable / ou le resultat de l'operation
    std::string getVarName() const; // Retourne le nom de la variable

  private:
    double m_constante;
    std::string m_variable; // On considerera "0" comme une chaine vide

    std::vector<Numerique *> m_valeurs; // Nombres numeriques a appliquer sur l'operateurs
    Operateurs m_operateur; // On considerera "Operateurs::Rien" comme un operateur vide
};

#endif

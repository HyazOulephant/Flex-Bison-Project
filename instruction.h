#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "numerique.h"
#include <vector>

enum class IDs {
  // Instructions de Grammaire
  Rien,
  ConsoleEcho,
  Si,
  FinSi,
  Sinon,
  Repete,
  FinRepete,
  VariableSet,
  // Instructions de la SDL
  Couleur,
  Position,
  Inclinaison,
  Avancer,
  Droite,
  Gauche,
  Haut,
  Bas,
  LigneCoord,
  Epaisseur,
  Delai
};

class Instruction {
  public:
    // Constructeurs
    Instruction();
    Instruction(IDs id, std::vector<Numerique *> parametres);

    //Accesseurs et mutateurs
    void setId(IDs id);
    void setParametres(std::vector<Numerique *> parametres);
    IDs getId() const;
    std::vector<Numerique *> getParametres() const;

  private:
    IDs m_id;
    std::vector<Numerique *> m_parametres;
};

#endif

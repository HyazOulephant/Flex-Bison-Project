#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <vector>

enum class IDs {
  Rien,
  ConsoleEcho,
  Position,
  Si,
  FinSi,
  Sinon,
  Repete,
  FinRepete
};

class Instruction {
  public:
    // Constructeurs
    Instruction();
    Instruction(IDs id, std::vector<double> parametres);

    //Accesseurs et mutateurs
    void setId(IDs id);
    void setParametres(std::vector<double> parametres);
    IDs getId() const;
    std::vector<double> getParametres() const;

  private:
    IDs m_id;
    std::vector<double> m_parametres;
};

#endif

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <vector>

enum class IDs {
  Rien,
  Position,
  Si,
  FinSi,
  Sinon
};

class Instruction {
  public:
    // Constructeurs
    Instruction();
    Instruction(IDs id, std::vector<int> parametres);

    //Accesseurs et mutateurs
    void setId(IDs id);
    void setParametres(std::vector<int> parametres);
    IDs getId() const;
    std::vector<int> getParametres() const;

  private:
    IDs m_id;
    std::vector<int> m_parametres;
};

#endif

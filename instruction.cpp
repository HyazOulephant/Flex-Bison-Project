#include "instruction.h"

Instruction::Instruction() : m_id(IDs::Rien), m_parametres({}) {}

Instruction::Instruction(IDs id, std::vector<int> parametres) : m_id(id), m_parametres(parametres) {}

void Instruction::setId(IDs id)
{
    this->m_id = id;
}

void Instruction::setParametres(std::vector<int> parametres)
{
    this->m_parametres = parametres;
}

IDs Instruction::getId() const
{
    return this->m_id;
}

std::vector<int> Instruction::getParametres() const
{
    return this->m_parametres;
}

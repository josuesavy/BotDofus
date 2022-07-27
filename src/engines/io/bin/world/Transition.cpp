#include "Transition.h"

Transition::Transition()
{

}

Transition::Transition(int type, int direction, int skillId, QString criterion, double transitionMapId, int cell, int id)
{
    m_type = type;
    m_direction = direction;
    m_skillId = skillId;
    m_criterion = criterion;
    m_transitionMapId = transitionMapId;
    m_cell = cell;
    m_id = id;
}

int Transition::getType()
{
    return m_type;
}

int Transition::getDirection()
{
    return m_direction;
}

int Transition::getSkillId()
{
    return m_skillId;
}

QString Transition::getCriterion()
{
    return m_criterion;
}

double Transition::getTransitionMapId()
{
    return m_transitionMapId;
}

int Transition::getCell()
{
    return m_cell;
}

int Transition::getId()
{
    return m_id;
}

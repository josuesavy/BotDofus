#ifndef TRANSITION_H
#define TRANSITION_H

#include <QString>

class Transition
{
public:
    Transition();
    Transition(int type, int direction, int skillId, QString criterion, double transitionMapId, int cell, int id);

    int getType();
    int getDirection();
    int getSkillId();
    QString getCriterion();
    double getTransitionMapId();
    int getCell();
    int getId();

private:
    int m_type;
    int m_direction;
    int m_skillId;
    QString m_criterion;
    double m_transitionMapId;
    int m_cell;
    int m_id;
};

#endif // TRANSITION_H

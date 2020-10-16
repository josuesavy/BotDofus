#ifndef CHARACTERXPMAPPINGDATA_H
#define CHARACTERXPMAPPINGDATA_H

#include "src/Engines/IO/D2O/AbstractGameData.h"

class CharacterXPMappingData : public AbstractGameData
{
public:
  int getLevel() const;
  double getExperiencePoints() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_level;
  double m_experiencePoints;
};

#endif // CHARACTERXPMAPPINGDATA_H
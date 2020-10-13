#ifndef SERVERGAMETYPEDATA_H
#define SERVERGAMETYPEDATA_H

#include "src/Engines/IO/D2O/AbstractGameData.h"

class ServerGameTypeData : public AbstractGameData
{
public:
  int getId() const;
  bool getSelectableByPlayer() const;
  uint getNameId() const;
  uint getRulesId() const;
  uint getDescriptionId() const;
  QString getName() const;
  QString getRules() const;
  QString getDescription() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  bool m_selectableByPlayer;
  uint m_nameId;
  uint m_rulesId;
  uint m_descriptionId;
};

#endif // SERVERGAMETYPEDATA_H
#ifndef CHALLENGEDATA_H
#define CHALLENGEDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"

class ChallengeData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  uint getDescriptionId() const;
  QList<uint> getIncompatibleChallenges() const;
  int getCategoryId() const;
  uint getIconId() const;
  QString getActivationCriterion() const;
  QString getCompletionCriterion() const;
  uint getTargetMonsterId() const;
  QString getName() const;
  QString getDescription() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  uint m_descriptionId;
  QList<uint> m_incompatibleChallenges;
  int m_categoryId;
  uint m_iconId;
  QString m_activationCriterion;
  QString m_completionCriterion;
  uint m_targetMonsterId;
};

#endif // CHALLENGEDATA_H
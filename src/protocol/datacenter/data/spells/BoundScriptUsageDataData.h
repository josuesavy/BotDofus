#ifndef BOUNDSCRIPTUSAGEDATADATA_H
#define BOUNDSCRIPTUSAGEDATADATA_H

#include "src/protocol/datacenter/AbstractGameData.h"

class BoundScriptUsageDataData : public AbstractGameData
{
public:
  int getId() const;
  int getScriptId() const;
  QList<uint> getSpellLevels() const;
  QString getCriterion() const;
  QString getCasterMask() const;
  QString getTargetMask() const;
  QString getTargetZone() const;
  QString getActivationMask() const;
  QString getActivationZone() const;
  int getRandom() const;
  int getRandomGroup() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  int m_scriptId;
  QList<uint> m_spellLevels;
  QString m_criterion;
  QString m_casterMask;
  QString m_targetMask;
  QString m_targetZone;
  QString m_activationMask;
  QString m_activationZone;
  int m_random;
  int m_randomGroup;
};

#endif // BOUNDSCRIPTUSAGEDATADATA_H
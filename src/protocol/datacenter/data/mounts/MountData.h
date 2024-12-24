#ifndef MOUNTDATA_H
#define MOUNTDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"
#include "src/protocol/datacenter/data/effects/EffectInstanceData.h"

class MountData : public AbstractGameData
{
public:
  uint getId() const;
  uint getFamilyId() const;
  uint getNameId() const;
  QString getLook() const;
  uint getCertificateId() const;
  QList<EffectInstanceData> getEffects() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_familyId;
  uint m_nameId;
  QString m_look;
  uint m_certificateId;
  QList<EffectInstanceData> m_effects;
};

#endif // MOUNTDATA_H
#ifndef EFFECTZONEDATA_H
#define EFFECTZONEDATA_H

#include "src/protocol/datacenter/AbstractGameData.h"

class EffectZoneData : public AbstractGameData
{
public:
  uint getId() const;
  bool getIsDefaultPreviewZoneHidden() const;
  QString getCasterMask() const;
  QString getActivationMask() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_id;
  bool m_isDefaultPreviewZoneHidden;
  QString m_casterMask;
  QString m_activationMask;
};

#endif // EFFECTZONEDATA_H
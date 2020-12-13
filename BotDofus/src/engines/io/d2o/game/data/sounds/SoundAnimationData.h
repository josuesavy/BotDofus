#ifndef SOUNDANIMATIONDATA_H
#define SOUNDANIMATIONDATA_H

#include "src/engines/io/d2o/AbstractGameData.h"

class SoundAnimationData : public AbstractGameData
{
public:
  QString getMODULE() const;
  uint getId() const;
  QString getName() const;
  QString getLabel() const;
  QString getFilename() const;
  int getVolume() const;
  int getRolloff() const;
  int getAutomationDuration() const;
  int getAutomationVolume() const;
  int getAutomationFadeIn() const;
  int getAutomationFadeOut() const;
  bool getNoCutSilence() const;
  uint getStartFrame() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  QString m_MODULE;
  uint m_id;
  QString m_name;
  QString m_label;
  QString m_filename;
  int m_volume;
  int m_rolloff;
  int m_automationDuration;
  int m_automationVolume;
  int m_automationFadeIn;
  int m_automationFadeOut;
  bool m_noCutSilence;
  uint m_startFrame;
};

#endif // SOUNDANIMATIONDATA_H
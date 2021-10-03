#ifndef CHATCHANNELDATA_H
#define CHATCHANNELDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class ChatChannelData : public AbstractGameData
{
public:
  uint getId() const;
  uint getNameId() const;
  uint getDescriptionId() const;
  QString getShortcut() const;
  QString getShortcutKey() const;
  bool getIsPrivate() const;
  bool getAllowObjects() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_nameId;
  uint m_descriptionId;
  QString m_shortcut;
  QString m_shortcutKey;
  bool m_isPrivate;
  bool m_allowObjects;
};

#endif // CHATCHANNELDATA_H
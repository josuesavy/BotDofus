#ifndef INFOMESSAGEDATA_H
#define INFOMESSAGEDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class InfoMessageData : public AbstractGameData
{
public:
  uint getTypeId() const;
  uint getMessageId() const;
  uint getTextId() const;
  QString getText() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  uint m_typeId;
  uint m_messageId;
  uint m_textId;
};

#endif // INFOMESSAGEDATA_H
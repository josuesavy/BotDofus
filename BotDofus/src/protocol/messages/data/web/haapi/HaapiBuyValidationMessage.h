#ifndef HAAPIBUYVALIDATIONMESSAGE_H
#define HAAPIBUYVALIDATIONMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/web/haapi/HaapiValidationMessage.h"

class HaapiBuyValidationMessage : public HaapiValidationMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HaapiBuyValidationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HaapiBuyValidationMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HaapiBuyValidationMessage(FuncTree tree);
  HaapiBuyValidationMessage();

  double amount;
  QString email;

private:
  void _amountFunc(Reader *input);
  void _emailFunc(Reader *input);
};

#endif // HAAPIBUYVALIDATIONMESSAGE_H
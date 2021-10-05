#ifndef HAAPICONFIRMATIONMESSAGE_H
#define HAAPICONFIRMATIONMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class HaapiConfirmationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HaapiConfirmationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HaapiConfirmationMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HaapiConfirmationMessage(FuncTree tree);
  HaapiConfirmationMessage();

  double kamas;
  double amount;
  uint rate;
  uint action;
  QString transaction;

private:
  void _kamasFunc(Reader *input);
  void _amountFunc(Reader *input);
  void _rateFunc(Reader *input);
  void _actionFunc(Reader *input);
  void _transactionFunc(Reader *input);
};

#endif // HAAPICONFIRMATIONMESSAGE_H
#ifndef ACCOUNTINFORMATIONSUPDATEMESSAGE_H
#define ACCOUNTINFORMATIONSUPDATEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class AccountInformationsUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AccountInformationsUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AccountInformationsUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AccountInformationsUpdateMessage(FuncTree tree);
  AccountInformationsUpdateMessage();

  double subscriptionEndDate;

private:
  void _subscriptionEndDateFunc(Reader *input);
};

#endif // ACCOUNTINFORMATIONSUPDATEMESSAGE_H
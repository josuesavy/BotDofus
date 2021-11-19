#ifndef ACCOUNTINFORMATIONSUPDATEMESSAGE_H
#define ACCOUNTINFORMATIONSUPDATEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

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
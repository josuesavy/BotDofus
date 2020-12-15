#ifndef EXCHANGELEAVEMESSAGE_H
#define EXCHANGELEAVEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/dialog/LeaveDialogMessage.h"

class ExchangeLeaveMessage : public LeaveDialogMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeLeaveMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeLeaveMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeLeaveMessage(FuncTree tree);
  ExchangeLeaveMessage();

  bool success;

private:
  void _successFunc(Reader *input);
};

#endif // EXCHANGELEAVEMESSAGE_H
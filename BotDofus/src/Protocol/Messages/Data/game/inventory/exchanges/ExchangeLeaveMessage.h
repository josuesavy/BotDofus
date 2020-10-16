#ifndef EXCHANGELEAVEMESSAGE_H
#define EXCHANGELEAVEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/dialog/LeaveDialogMessage.h"

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
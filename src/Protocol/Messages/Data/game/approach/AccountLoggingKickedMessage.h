#ifndef ACCOUNTLOGGINGKICKEDMESSAGE_H
#define ACCOUNTLOGGINGKICKEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class AccountLoggingKickedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AccountLoggingKickedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AccountLoggingKickedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AccountLoggingKickedMessage(FuncTree tree);
  AccountLoggingKickedMessage();

  uint days;
  uint hours;
  uint minutes;

private:
  void _daysFunc(Reader *input);
  void _hoursFunc(Reader *input);
  void _minutesFunc(Reader *input);
};

#endif // ACCOUNTLOGGINGKICKEDMESSAGE_H
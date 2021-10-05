#ifndef NUMERICWHOISMESSAGE_H
#define NUMERICWHOISMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class NumericWhoIsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_NumericWhoIsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_NumericWhoIsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_NumericWhoIsMessage(FuncTree tree);
  NumericWhoIsMessage();

  double playerId;
  uint accountId;

private:
  void _playerIdFunc(Reader *input);
  void _accountIdFunc(Reader *input);
};

#endif // NUMERICWHOISMESSAGE_H
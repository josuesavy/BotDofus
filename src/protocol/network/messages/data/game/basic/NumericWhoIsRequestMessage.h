#ifndef NUMERICWHOISREQUESTMESSAGE_H
#define NUMERICWHOISREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class NumericWhoIsRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_NumericWhoIsRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_NumericWhoIsRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_NumericWhoIsRequestMessage(FuncTree tree);
  NumericWhoIsRequestMessage();

  double playerId;

private:
  void _playerIdFunc(Reader *input);
};

#endif // NUMERICWHOISREQUESTMESSAGE_H
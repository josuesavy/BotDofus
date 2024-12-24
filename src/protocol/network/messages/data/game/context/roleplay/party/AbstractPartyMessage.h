#ifndef ABSTRACTPARTYMESSAGE_H
#define ABSTRACTPARTYMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class AbstractPartyMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AbstractPartyMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AbstractPartyMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AbstractPartyMessage(FuncTree tree);
  AbstractPartyMessage();

  uint partyId;

private:
  void _partyIdFunc(Reader *input);
};

#endif // ABSTRACTPARTYMESSAGE_H
#ifndef PARTYNAMESETERRORMESSAGE_H
#define PARTYNAMESETERRORMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyNameSetErrorMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyNameSetErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyNameSetErrorMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyNameSetErrorMessage(FuncTree tree);
  PartyNameSetErrorMessage();

  uint result;

private:
  void _resultFunc(Reader *input);
};

#endif // PARTYNAMESETERRORMESSAGE_H
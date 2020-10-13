#ifndef PARTYNAMESETERRORMESSAGE_H
#define PARTYNAMESETERRORMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

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
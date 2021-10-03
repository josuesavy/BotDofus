#ifndef CHARACTERCANBECREATEDREQUESTMESSAGE_H
#define CHARACTERCANBECREATEDREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class CharacterCanBeCreatedRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterCanBeCreatedRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterCanBeCreatedRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterCanBeCreatedRequestMessage(FuncTree tree);
  CharacterCanBeCreatedRequestMessage();
};

#endif // CHARACTERCANBECREATEDREQUESTMESSAGE_H
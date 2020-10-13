#ifndef CHARACTERSLISTREQUESTMESSAGE_H
#define CHARACTERSLISTREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class CharactersListRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharactersListRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharactersListRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharactersListRequestMessage(FuncTree tree);
  CharactersListRequestMessage();
};

#endif // CHARACTERSLISTREQUESTMESSAGE_H
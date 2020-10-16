#ifndef CHARACTERNAMESUGGESTIONREQUESTMESSAGE_H
#define CHARACTERNAMESUGGESTIONREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class CharacterNameSuggestionRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterNameSuggestionRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterNameSuggestionRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterNameSuggestionRequestMessage(FuncTree tree);
  CharacterNameSuggestionRequestMessage();
};

#endif // CHARACTERNAMESUGGESTIONREQUESTMESSAGE_H
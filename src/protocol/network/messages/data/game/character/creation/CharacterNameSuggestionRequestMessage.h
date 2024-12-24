#ifndef CHARACTERNAMESUGGESTIONREQUESTMESSAGE_H
#define CHARACTERNAMESUGGESTIONREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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
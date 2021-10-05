#ifndef CHARACTERNAMESUGGESTIONSUCCESSMESSAGE_H
#define CHARACTERNAMESUGGESTIONSUCCESSMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class CharacterNameSuggestionSuccessMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterNameSuggestionSuccessMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterNameSuggestionSuccessMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterNameSuggestionSuccessMessage(FuncTree tree);
  CharacterNameSuggestionSuccessMessage();

  QString suggestion;

private:
  void _suggestionFunc(Reader *input);
};

#endif // CHARACTERNAMESUGGESTIONSUCCESSMESSAGE_H
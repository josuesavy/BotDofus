#ifndef CHARACTERNAMESUGGESTIONFAILUREMESSAGE_H
#define CHARACTERNAMESUGGESTIONFAILUREMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class CharacterNameSuggestionFailureMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterNameSuggestionFailureMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterNameSuggestionFailureMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterNameSuggestionFailureMessage(FuncTree tree);
  CharacterNameSuggestionFailureMessage();

  uint reason;

private:
  void _reasonFunc(Reader *input);
};

#endif // CHARACTERNAMESUGGESTIONFAILUREMESSAGE_H
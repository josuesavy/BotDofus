#ifndef CHARACTERLEVELUPMESSAGE_H
#define CHARACTERLEVELUPMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class CharacterLevelUpMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterLevelUpMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterLevelUpMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterLevelUpMessage(FuncTree tree);
  CharacterLevelUpMessage();

  uint newLevel;

private:
  void _newLevelFunc(Reader *input);
};

#endif // CHARACTERLEVELUPMESSAGE_H
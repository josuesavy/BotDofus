#ifndef CHARACTERLEVELUPINFORMATIONMESSAGE_H
#define CHARACTERLEVELUPINFORMATIONMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/character/stats/CharacterLevelUpMessage.h"

class CharacterLevelUpInformationMessage : public CharacterLevelUpMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterLevelUpInformationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterLevelUpInformationMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterLevelUpInformationMessage(FuncTree tree);
  CharacterLevelUpInformationMessage();

  QString name;
  double id;

private:
  void _nameFunc(Reader *input);
  void _idFunc(Reader *input);
};

#endif // CHARACTERLEVELUPINFORMATIONMESSAGE_H
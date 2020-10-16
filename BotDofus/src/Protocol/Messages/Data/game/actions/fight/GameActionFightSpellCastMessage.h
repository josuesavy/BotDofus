#ifndef GAMEACTIONFIGHTSPELLCASTMESSAGE_H
#define GAMEACTIONFIGHTSPELLCASTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/actions/fight/AbstractGameActionFightTargetedAbilityMessage.h"

class GameActionFightSpellCastMessage : public AbstractGameActionFightTargetedAbilityMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionFightSpellCastMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionFightSpellCastMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionFightSpellCastMessage(FuncTree tree);
  GameActionFightSpellCastMessage();

  uint spellId;
  int spellLevel;
  QList<int> portalsIds;

private:
  void _spellIdFunc(Reader *input);
  void _spellLevelFunc(Reader *input);
  void _portalsIdstreeFunc(Reader *input);
  void _portalsIdsFunc(Reader *input);

  FuncTree _portalsIdstree;
};

#endif // GAMEACTIONFIGHTSPELLCASTMESSAGE_H
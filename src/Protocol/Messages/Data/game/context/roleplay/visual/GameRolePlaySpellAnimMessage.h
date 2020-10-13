#ifndef GAMEROLEPLAYSPELLANIMMESSAGE_H
#define GAMEROLEPLAYSPELLANIMMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GameRolePlaySpellAnimMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlaySpellAnimMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlaySpellAnimMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlaySpellAnimMessage(FuncTree tree);
  GameRolePlaySpellAnimMessage();

  double casterId;
  uint targetCellId;
  uint spellId;
  int spellLevel;

private:
  void _casterIdFunc(Reader *input);
  void _targetCellIdFunc(Reader *input);
  void _spellIdFunc(Reader *input);
  void _spellLevelFunc(Reader *input);
};

#endif // GAMEROLEPLAYSPELLANIMMESSAGE_H
#ifndef GAMEROLEPLAYNPCQUESTFLAG_H
#define GAMEROLEPLAYNPCQUESTFLAG_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/utils/io/type/FuncTree.h"

class GameRolePlayNpcQuestFlag : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameRolePlayNpcQuestFlag(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameRolePlayNpcQuestFlag(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameRolePlayNpcQuestFlag(FuncTree tree);
  GameRolePlayNpcQuestFlag();
  bool operator==(const GameRolePlayNpcQuestFlag &compared);

  QList<uint> questsToValidId;
  QList<uint> questsToStartId;

private:
  void _questsToValidIdtreeFunc(Reader *input);
  void _questsToValidIdFunc(Reader *input);
  void _questsToStartIdtreeFunc(Reader *input);
  void _questsToStartIdFunc(Reader *input);

  FuncTree _questsToValidIdtree;
  FuncTree _questsToStartIdtree;
};

#endif // GAMEROLEPLAYNPCQUESTFLAG_H
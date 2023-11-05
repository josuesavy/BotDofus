#ifndef MONSTERINGROUPINFORMATIONS_H
#define MONSTERINGROUPINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/look/EntityLook.h"
#include "src/protocol/types/data/game/context/roleplay/MonsterInGroupLightInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"

class MonsterInGroupInformations : public MonsterInGroupLightInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MonsterInGroupInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MonsterInGroupInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MonsterInGroupInformations(FuncTree tree);
  MonsterInGroupInformations();
  bool operator==(const MonsterInGroupInformations &compared);

  EntityLook look;

private:
  void _looktreeFunc(Reader *input);

  FuncTree _looktree;
};

#endif // MONSTERINGROUPINFORMATIONS_H
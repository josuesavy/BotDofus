#ifndef MONSTERINGROUPINFORMATIONS_H
#define MONSTERINGROUPINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/look/EntityLook.h"
#include "src/Protocol/Types/Data/game/context/roleplay/MonsterInGroupLightInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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

  QSharedPointer<EntityLook> look;

private:
  void _looktreeFunc(Reader *input);

  FuncTree _looktree;
};

#endif // MONSTERINGROUPINFORMATIONS_H
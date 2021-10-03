#ifndef GROUPMONSTERSTATICINFORMATIONS_H
#define GROUPMONSTERSTATICINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/roleplay/MonsterInGroupLightInformations.h"
#include "src/protocol/types/data/game/context/roleplay/MonsterInGroupInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"

class GroupMonsterStaticInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GroupMonsterStaticInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GroupMonsterStaticInformations(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GroupMonsterStaticInformations(FuncTree tree);
  GroupMonsterStaticInformations();
  bool operator==(const GroupMonsterStaticInformations &compared);

  MonsterInGroupLightInformations mainCreatureLightInfos;
  QList<QSharedPointer<MonsterInGroupInformations>> underlings;

private:
  void _mainCreatureLightInfostreeFunc(Reader *input);
  void _underlingstreeFunc(Reader *input);
  void _underlingsFunc(Reader *input);

  FuncTree _mainCreatureLightInfostree;
  FuncTree _underlingstree;
};

#endif // GROUPMONSTERSTATICINFORMATIONS_H
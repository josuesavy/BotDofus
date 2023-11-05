#ifndef GROUPMONSTERSTATICINFORMATIONSWITHALTERNATIVES_H
#define GROUPMONSTERSTATICINFORMATIONSWITHALTERNATIVES_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/roleplay/GroupMonsterStaticInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"

class GroupMonsterStaticInformationsWithAlternatives : public GroupMonsterStaticInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GroupMonsterStaticInformationsWithAlternatives(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GroupMonsterStaticInformationsWithAlternatives(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GroupMonsterStaticInformationsWithAlternatives(FuncTree tree);
  GroupMonsterStaticInformationsWithAlternatives();
  bool operator==(const GroupMonsterStaticInformationsWithAlternatives &compared);

  QList<> alternatives;

private:
  void _alternativestreeFunc(Reader *input);
  void _alternativesFunc(Reader *input);

  FuncTree _alternativestree;
};

#endif // GROUPMONSTERSTATICINFORMATIONSWITHALTERNATIVES_H
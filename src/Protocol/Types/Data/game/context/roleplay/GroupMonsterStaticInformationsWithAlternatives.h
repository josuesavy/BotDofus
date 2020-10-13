#ifndef GROUPMONSTERSTATICINFORMATIONSWITHALTERNATIVES_H
#define GROUPMONSTERSTATICINFORMATIONSWITHALTERNATIVES_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/roleplay/AlternativeMonstersInGroupLightInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/GroupMonsterStaticInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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

  QList<AlternativeMonstersInGroupLightInformations> alternatives;

private:
  void _alternativestreeFunc(Reader *input);
  void _alternativesFunc(Reader *input);

  FuncTree _alternativestree;
};

#endif // GROUPMONSTERSTATICINFORMATIONSWITHALTERNATIVES_H
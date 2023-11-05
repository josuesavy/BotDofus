#ifndef PARTYENTITYBASEINFORMATION_H
#define PARTYENTITYBASEINFORMATION_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/look/EntityLook.h"
#include "src/engines/io/network/utils/FuncTree.h"

class PartyEntityBaseInformation : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyEntityBaseInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyEntityBaseInformation(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyEntityBaseInformation(FuncTree tree);
  PartyEntityBaseInformation();
  bool operator==(const PartyEntityBaseInformation &compared);

  uint indexId;
  uint entityModelId;
  EntityLook entityLook;

private:
  void _indexIdFunc(Reader *input);
  void _entityModelIdFunc(Reader *input);
  void _entityLooktreeFunc(Reader *input);

  FuncTree _entityLooktree;
};

#endif // PARTYENTITYBASEINFORMATION_H
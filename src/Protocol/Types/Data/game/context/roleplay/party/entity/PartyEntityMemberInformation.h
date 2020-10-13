#ifndef PARTYENTITYMEMBERINFORMATION_H
#define PARTYENTITYMEMBERINFORMATION_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/roleplay/party/entity/PartyEntityBaseInformation.h"
#include "src/Protocol/Types/Data/game/look/EntityLook.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class PartyEntityMemberInformation : public PartyEntityBaseInformation
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyEntityMemberInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyEntityMemberInformation(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyEntityMemberInformation(FuncTree tree);
  PartyEntityMemberInformation();
  bool operator==(const PartyEntityMemberInformation &compared);

  uint initiative;
  uint lifePoints;
  uint maxLifePoints;
  uint prospecting;
  uint regenRate;

private:
  void _initiativeFunc(Reader *input);
  void _lifePointsFunc(Reader *input);
  void _maxLifePointsFunc(Reader *input);
  void _prospectingFunc(Reader *input);
  void _regenRateFunc(Reader *input);
};

#endif // PARTYENTITYMEMBERINFORMATION_H
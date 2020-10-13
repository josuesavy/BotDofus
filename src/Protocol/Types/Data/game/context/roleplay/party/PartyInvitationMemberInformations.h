#ifndef PARTYINVITATIONMEMBERINFORMATIONS_H
#define PARTYINVITATIONMEMBERINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/roleplay/party/entity/PartyEntityBaseInformation.h"
#include "src/Protocol/Types/Data/game/character/choice/CharacterBaseInformations.h"
#include "src/Protocol/Types/Data/game/look/EntityLook.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class PartyInvitationMemberInformations : public CharacterBaseInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyInvitationMemberInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyInvitationMemberInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyInvitationMemberInformations(FuncTree tree);
  PartyInvitationMemberInformations();
  bool operator==(const PartyInvitationMemberInformations &compared);

  int worldX;
  int worldY;
  double mapId;
  uint subAreaId;
  QList<QSharedPointer<PartyEntityBaseInformation>> entities;

private:
  void _worldXFunc(Reader *input);
  void _worldYFunc(Reader *input);
  void _mapIdFunc(Reader *input);
  void _subAreaIdFunc(Reader *input);
  void _entitiestreeFunc(Reader *input);
  void _entitiesFunc(Reader *input);

  FuncTree _entitiestree;
};

#endif // PARTYINVITATIONMEMBERINFORMATIONS_H
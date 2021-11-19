#ifndef PARTYINVITATIONMEMBERINFORMATIONS_H
#define PARTYINVITATIONMEMBERINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/roleplay/party/entity/PartyEntityBaseInformation.h"
#include "src/protocol/types/data/game/character/choice/CharacterBaseInformations.h"
#include "src/protocol/types/data/game/look/EntityLook.h"
#include "src/engines/io/network/utils/FuncTree.h"

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
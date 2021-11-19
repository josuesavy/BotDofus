#ifndef PARTYMEMBERINFORMATIONS_H
#define PARTYMEMBERINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/character/status/PlayerStatus.h"
#include "src/protocol/types/data/game/context/roleplay/party/entity/PartyEntityBaseInformation.h"
#include "src/protocol/types/data/game/character/choice/CharacterBaseInformations.h"
#include "src/protocol/types/data/game/look/EntityLook.h"
#include "src/protocol/types/ClassManager.h"
#include "src/engines/io/network/utils/FuncTree.h"

class PartyMemberInformations : public CharacterBaseInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyMemberInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyMemberInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyMemberInformations(FuncTree tree);
  PartyMemberInformations();
  bool operator==(const PartyMemberInformations &compared);

  uint lifePoints;
  uint maxLifePoints;
  uint prospecting;
  uint regenRate;
  uint initiative;
  int alignmentSide;
  int worldX;
  int worldY;
  double mapId;
  uint subAreaId;
  QSharedPointer<PlayerStatus> status;
  QList<QSharedPointer<PartyEntityBaseInformation>> entities;

private:
  void _lifePointsFunc(Reader *input);
  void _maxLifePointsFunc(Reader *input);
  void _prospectingFunc(Reader *input);
  void _regenRateFunc(Reader *input);
  void _initiativeFunc(Reader *input);
  void _alignmentSideFunc(Reader *input);
  void _worldXFunc(Reader *input);
  void _worldYFunc(Reader *input);
  void _mapIdFunc(Reader *input);
  void _subAreaIdFunc(Reader *input);
  void _statustreeFunc(Reader *input);
  void _entitiestreeFunc(Reader *input);
  void _entitiesFunc(Reader *input);

  FuncTree _statustree;
  FuncTree _entitiestree;
};

#endif // PARTYMEMBERINFORMATIONS_H
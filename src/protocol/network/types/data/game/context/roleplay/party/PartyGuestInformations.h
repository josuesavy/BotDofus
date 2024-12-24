#ifndef PARTYGUESTINFORMATIONS_H
#define PARTYGUESTINFORMATIONS_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/look/EntityLook.h"
#include "src/protocol/network/types/data/game/character/status/PlayerStatus.h"
#include "src/protocol/network/types/data/game/context/roleplay/party/entity/PartyEntityBaseInformation.h"
#include "src/protocol/network/types/ClassManager.h"
#include "src/utils/io/type/FuncTree.h"

class PartyGuestInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyGuestInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyGuestInformations(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyGuestInformations(FuncTree tree);
  PartyGuestInformations();
  bool operator==(const PartyGuestInformations &compared);

  double guestId;
  double hostId;
  QString name;
  QSharedPointer<EntityLook> guestLook;
  int breed;
  bool sex;
  QSharedPointer<PlayerStatus> status;
  QList<QSharedPointer<PartyEntityBaseInformation>> entities;

private:
  void _guestIdFunc(Reader *input);
  void _hostIdFunc(Reader *input);
  void _nameFunc(Reader *input);
  void _guestLooktreeFunc(Reader *input);
  void _breedFunc(Reader *input);
  void _sexFunc(Reader *input);
  void _statustreeFunc(Reader *input);
  void _entitiestreeFunc(Reader *input);
  void _entitiesFunc(Reader *input);

  FuncTree _guestLooktree;
  FuncTree _statustree;
  FuncTree _entitiestree;
};

#endif // PARTYGUESTINFORMATIONS_H
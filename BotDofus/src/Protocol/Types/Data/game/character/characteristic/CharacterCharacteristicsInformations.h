#ifndef CHARACTERCHARACTERISTICSINFORMATIONS_H
#define CHARACTERCHARACTERISTICSINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/character/alignment/ActorExtendedAlignmentInformations.h"
#include "src/protocol/types/data/game/character/characteristic/CharacterCharacteristic.h"
#include "src/protocol/types/data/game/character/characteristic/CharacterSpellModification.h"
#include "src/protocol/types/ClassManager.h"
#include "src/engines/io/network/utils/FuncTree.h"

class CharacterCharacteristicsInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterCharacteristicsInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterCharacteristicsInformations(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterCharacteristicsInformations(FuncTree tree);
  CharacterCharacteristicsInformations();
  bool operator==(const CharacterCharacteristicsInformations &compared);

  double experience;
  double experienceLevelFloor;
  double experienceNextLevelFloor;
  double experienceBonusLimit;
  double kamas;
  ActorExtendedAlignmentInformations alignmentInfos;
  uint criticalHitWeapon;
  QList<QSharedPointer<CharacterCharacteristic>> characteristics;
  QList<QSharedPointer<CharacterSpellModification>> spellModifications;
  uint probationTime;

private:
  void _experienceFunc(Reader *input);
  void _experienceLevelFloorFunc(Reader *input);
  void _experienceNextLevelFloorFunc(Reader *input);
  void _experienceBonusLimitFunc(Reader *input);
  void _kamasFunc(Reader *input);
  void _alignmentInfostreeFunc(Reader *input);
  void _criticalHitWeaponFunc(Reader *input);
  void _characteristicstreeFunc(Reader *input);
  void _characteristicsFunc(Reader *input);
  void _spellModificationstreeFunc(Reader *input);
  void _spellModificationsFunc(Reader *input);
  void _probationTimeFunc(Reader *input);

  FuncTree _alignmentInfostree;
  FuncTree _characteristicstree;
  FuncTree _spellModificationstree;
};

#endif // CHARACTERCHARACTERISTICSINFORMATIONS_H
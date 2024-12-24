#ifndef CHARACTERCHARACTERISTICSINFORMATIONS_H
#define CHARACTERCHARACTERISTICSINFORMATIONS_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/character/alignment/ActorExtendedAlignmentInformations.h"
#include "src/protocol/network/types/data/game/character/characteristic/CharacterCharacteristic.h"
#include "src/protocol/network/types/data/game/character/spellmodifier/SpellModifierMessage.h"
#include "src/protocol/network/types/ClassManager.h"
#include "src/utils/io/type/FuncTree.h"

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
  QList<SpellModifierMessage> spellModifiers;
  double probationTime;

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
  void _spellModifierstreeFunc(Reader *input);
  void _spellModifiersFunc(Reader *input);
  void _probationTimeFunc(Reader *input);

  FuncTree _alignmentInfostree;
  FuncTree _characteristicstree;
  FuncTree _spellModifierstree;
};

#endif // CHARACTERCHARACTERISTICSINFORMATIONS_H
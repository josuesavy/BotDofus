#ifndef TAXCOLLECTORINFORMATIONS_H
#define TAXCOLLECTORINFORMATIONS_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/context/roleplay/AllianceInformation.h"
#include "src/protocol/network/types/data/game/collector/tax/AdditionalTaxCollectorInformation.h"
#include "src/protocol/network/types/data/game/look/EntityLook.h"
#include "src/protocol/network/types/data/game/collector/tax/TaxCollectorComplementaryInformations.h"
#include "src/protocol/network/types/data/game/character/characteristic/CharacterCharacteristics.h"
#include "src/protocol/network/types/data/game/data/items/ObjectItem.h"
#include "src/protocol/network/types/data/game/collector/tax/TaxCollectorOrderedSpell.h"
#include "src/protocol/network/types/ClassManager.h"
#include "src/utils/io/type/FuncTree.h"

class TaxCollectorInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TaxCollectorInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TaxCollectorInformations(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TaxCollectorInformations(FuncTree tree);
  TaxCollectorInformations();
  bool operator==(const TaxCollectorInformations &compared);

  double uniqueId;
  uint firstNameId;
  uint lastNameId;
  QSharedPointer<AllianceInformation> allianceIdentity;
  AdditionalTaxCollectorInformation additionalInfos;
  int worldX;
  int worldY;
  uint subAreaId;
  uint state;
  QSharedPointer<EntityLook> look;
  QList<QSharedPointer<TaxCollectorComplementaryInformations>> complements;
  QSharedPointer<CharacterCharacteristics> characteristics;
  QList<QSharedPointer<ObjectItem>> equipments;
  QList<TaxCollectorOrderedSpell> spells;

private:
  void _uniqueIdFunc(Reader *input);
  void _firstNameIdFunc(Reader *input);
  void _lastNameIdFunc(Reader *input);
  void _allianceIdentitytreeFunc(Reader *input);
  void _additionalInfostreeFunc(Reader *input);
  void _worldXFunc(Reader *input);
  void _worldYFunc(Reader *input);
  void _subAreaIdFunc(Reader *input);
  void _stateFunc(Reader *input);
  void _looktreeFunc(Reader *input);
  void _complementstreeFunc(Reader *input);
  void _complementsFunc(Reader *input);
  void _characteristicstreeFunc(Reader *input);
  void _equipmentstreeFunc(Reader *input);
  void _equipmentsFunc(Reader *input);
  void _spellstreeFunc(Reader *input);
  void _spellsFunc(Reader *input);

  FuncTree _allianceIdentitytree;
  FuncTree _additionalInfostree;
  FuncTree _looktree;
  FuncTree _complementstree;
  FuncTree _characteristicstree;
  FuncTree _equipmentstree;
  FuncTree _spellstree;
};

#endif // TAXCOLLECTORINFORMATIONS_H
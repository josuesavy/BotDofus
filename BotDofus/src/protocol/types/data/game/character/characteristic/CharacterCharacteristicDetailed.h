#ifndef CHARACTERCHARACTERISTICDETAILED_H
#define CHARACTERCHARACTERISTICDETAILED_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/character/characteristic/CharacterCharacteristic.h"
#include "src/engines/io/network/utils/FuncTree.h"

class CharacterCharacteristicDetailed : public CharacterCharacteristic
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterCharacteristicDetailed(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterCharacteristicDetailed(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterCharacteristicDetailed(FuncTree tree);
  CharacterCharacteristicDetailed();
  bool operator==(const CharacterCharacteristicDetailed &compared);

  int base;
  int additional;
  int objectsAndMountBonus;
  int alignGiftBonus;
  int contextModif;

private:
  void _baseFunc(Reader *input);
  void _additionalFunc(Reader *input);
  void _objectsAndMountBonusFunc(Reader *input);
  void _alignGiftBonusFunc(Reader *input);
  void _contextModifFunc(Reader *input);
};

#endif // CHARACTERCHARACTERISTICDETAILED_H
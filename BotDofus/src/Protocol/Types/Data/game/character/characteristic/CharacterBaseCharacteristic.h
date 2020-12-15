#ifndef CHARACTERBASECHARACTERISTIC_H
#define CHARACTERBASECHARACTERISTIC_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class CharacterBaseCharacteristic : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterBaseCharacteristic(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterBaseCharacteristic(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterBaseCharacteristic(FuncTree tree);
  CharacterBaseCharacteristic();
  bool operator==(const CharacterBaseCharacteristic &compared);

  int base;
  int additionnal;
  int objectsAndMountBonus;
  int alignGiftBonus;
  int contextModif;

private:
  void _baseFunc(Reader *input);
  void _additionnalFunc(Reader *input);
  void _objectsAndMountBonusFunc(Reader *input);
  void _alignGiftBonusFunc(Reader *input);
  void _contextModifFunc(Reader *input);
};

#endif // CHARACTERBASECHARACTERISTIC_H
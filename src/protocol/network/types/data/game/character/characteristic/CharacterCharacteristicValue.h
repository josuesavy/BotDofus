#ifndef CHARACTERCHARACTERISTICVALUE_H
#define CHARACTERCHARACTERISTICVALUE_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/character/characteristic/CharacterCharacteristic.h"
#include "src/utils/io/type/FuncTree.h"

class CharacterCharacteristicValue : public CharacterCharacteristic
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterCharacteristicValue(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterCharacteristicValue(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterCharacteristicValue(FuncTree tree);
  CharacterCharacteristicValue();
  bool operator==(const CharacterCharacteristicValue &compared);

  int total;

private:
  void _totalFunc(Reader *input);
};

#endif // CHARACTERCHARACTERISTICVALUE_H
#ifndef CHARACTERCHARACTERISTIC_H
#define CHARACTERCHARACTERISTIC_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/utils/io/type/FuncTree.h"

class CharacterCharacteristic : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterCharacteristic(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterCharacteristic(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterCharacteristic(FuncTree tree);
  CharacterCharacteristic();
  bool operator==(const CharacterCharacteristic &compared);

  int characteristicId;

private:
  void _characteristicIdFunc(Reader *input);
};

#endif // CHARACTERCHARACTERISTIC_H
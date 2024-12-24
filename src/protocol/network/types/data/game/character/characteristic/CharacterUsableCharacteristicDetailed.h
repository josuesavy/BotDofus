#ifndef CHARACTERUSABLECHARACTERISTICDETAILED_H
#define CHARACTERUSABLECHARACTERISTICDETAILED_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/character/characteristic/CharacterCharacteristicDetailed.h"
#include "src/utils/io/type/FuncTree.h"

class CharacterUsableCharacteristicDetailed : public CharacterCharacteristicDetailed
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterUsableCharacteristicDetailed(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterUsableCharacteristicDetailed(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterUsableCharacteristicDetailed(FuncTree tree);
  CharacterUsableCharacteristicDetailed();
  bool operator==(const CharacterUsableCharacteristicDetailed &compared);

  uint used;

private:
  void _usedFunc(Reader *input);
};

#endif // CHARACTERUSABLECHARACTERISTICDETAILED_H
#ifndef CHARACTERBASEINFORMATIONS_H
#define CHARACTERBASEINFORMATIONS_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/character/CharacterMinimalPlusLookInformations.h"
#include "src/protocol/network/types/data/game/look/EntityLook.h"
#include "src/utils/io/type/FuncTree.h"

class CharacterBaseInformations : public CharacterMinimalPlusLookInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterBaseInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterBaseInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterBaseInformations(FuncTree tree);
  CharacterBaseInformations();
  bool operator==(const CharacterBaseInformations &compared);

  bool sex;

private:
  void _sexFunc(Reader *input);
};

#endif // CHARACTERBASEINFORMATIONS_H
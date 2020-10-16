#ifndef CHARACTERBASEINFORMATIONS_H
#define CHARACTERBASEINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/character/CharacterMinimalPlusLookInformations.h"
#include "src/Protocol/Types/Data/game/look/EntityLook.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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
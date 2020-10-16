#ifndef CHARACTERMINIMALINFORMATIONS_H
#define CHARACTERMINIMALINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/character/CharacterBasicMinimalInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class CharacterMinimalInformations : public CharacterBasicMinimalInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterMinimalInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterMinimalInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterMinimalInformations(FuncTree tree);
  CharacterMinimalInformations();
  bool operator==(const CharacterMinimalInformations &compared);

  uint level;

private:
  void _levelFunc(Reader *input);
};

#endif // CHARACTERMINIMALINFORMATIONS_H
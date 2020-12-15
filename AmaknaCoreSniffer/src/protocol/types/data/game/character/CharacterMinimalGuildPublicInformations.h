#ifndef CHARACTERMINIMALGUILDPUBLICINFORMATIONS_H
#define CHARACTERMINIMALGUILDPUBLICINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/character/CharacterMinimalInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"

class CharacterMinimalGuildPublicInformations : public CharacterMinimalInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterMinimalGuildPublicInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterMinimalGuildPublicInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterMinimalGuildPublicInformations(FuncTree tree);
  CharacterMinimalGuildPublicInformations();
  bool operator==(const CharacterMinimalGuildPublicInformations &compared);

  uint rank;

private:
  void _rankFunc(Reader *input);
};

#endif // CHARACTERMINIMALGUILDPUBLICINFORMATIONS_H
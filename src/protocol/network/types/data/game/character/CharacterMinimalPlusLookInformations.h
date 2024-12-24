#ifndef CHARACTERMINIMALPLUSLOOKINFORMATIONS_H
#define CHARACTERMINIMALPLUSLOOKINFORMATIONS_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/look/EntityLook.h"
#include "src/protocol/network/types/data/game/character/CharacterMinimalInformations.h"
#include "src/utils/io/type/FuncTree.h"

class CharacterMinimalPlusLookInformations : public CharacterMinimalInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterMinimalPlusLookInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterMinimalPlusLookInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterMinimalPlusLookInformations(FuncTree tree);
  CharacterMinimalPlusLookInformations();
  bool operator==(const CharacterMinimalPlusLookInformations &compared);

  QSharedPointer<EntityLook> entityLook;
  int breed;

private:
  void _entityLooktreeFunc(Reader *input);
  void _breedFunc(Reader *input);

  FuncTree _entityLooktree;
};

#endif // CHARACTERMINIMALPLUSLOOKINFORMATIONS_H
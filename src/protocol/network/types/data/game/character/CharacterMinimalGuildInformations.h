#ifndef CHARACTERMINIMALGUILDINFORMATIONS_H
#define CHARACTERMINIMALGUILDINFORMATIONS_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/context/roleplay/BasicGuildInformations.h"
#include "src/protocol/network/types/data/game/character/CharacterMinimalPlusLookInformations.h"
#include "src/protocol/network/types/data/game/look/EntityLook.h"
#include "src/utils/io/type/FuncTree.h"

class CharacterMinimalGuildInformations : public CharacterMinimalPlusLookInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterMinimalGuildInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterMinimalGuildInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterMinimalGuildInformations(FuncTree tree);
  CharacterMinimalGuildInformations();
  bool operator==(const CharacterMinimalGuildInformations &compared);

  QSharedPointer<BasicGuildInformations> guild;

private:
  void _guildtreeFunc(Reader *input);

  FuncTree _guildtree;
};

#endif // CHARACTERMINIMALGUILDINFORMATIONS_H
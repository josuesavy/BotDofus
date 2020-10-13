#ifndef CHARACTERMINIMALGUILDINFORMATIONS_H
#define CHARACTERMINIMALGUILDINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/roleplay/BasicGuildInformations.h"
#include "src/Protocol/Types/Data/game/character/CharacterMinimalPlusLookInformations.h"
#include "src/Protocol/Types/Data/game/look/EntityLook.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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
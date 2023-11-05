#ifndef CHARACTERMINIMALSOCIALPUBLICINFORMATIONS_H
#define CHARACTERMINIMALSOCIALPUBLICINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/guild/RankPublicInformation.h"
#include "src/protocol/types/data/game/character/CharacterMinimalInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"

class CharacterMinimalSocialPublicInformations : public CharacterMinimalInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterMinimalSocialPublicInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterMinimalSocialPublicInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterMinimalSocialPublicInformations(FuncTree tree);
  CharacterMinimalSocialPublicInformations();
  bool operator==(const CharacterMinimalSocialPublicInformations &compared);

  RankPublicInformation rank;

private:
  void _ranktreeFunc(Reader *input);

  FuncTree _ranktree;
};

#endif // CHARACTERMINIMALSOCIALPUBLICINFORMATIONS_H
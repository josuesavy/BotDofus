#ifndef CHARACTERMINIMALPLUSLOOKANDGRADEINFORMATIONS_H
#define CHARACTERMINIMALPLUSLOOKANDGRADEINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/character/CharacterMinimalPlusLookInformations.h"
#include "src/protocol/types/data/game/look/EntityLook.h"
#include "src/engines/io/network/utils/FuncTree.h"

class CharacterMinimalPlusLookAndGradeInformations : public CharacterMinimalPlusLookInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterMinimalPlusLookAndGradeInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterMinimalPlusLookAndGradeInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterMinimalPlusLookAndGradeInformations(FuncTree tree);
  CharacterMinimalPlusLookAndGradeInformations();
  bool operator==(const CharacterMinimalPlusLookAndGradeInformations &compared);

  uint grade;

private:
  void _gradeFunc(Reader *input);
};

#endif // CHARACTERMINIMALPLUSLOOKANDGRADEINFORMATIONS_H
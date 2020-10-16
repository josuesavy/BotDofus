#ifndef CHARACTERMINIMALPLUSLOOKANDGRADEINFORMATIONS_H
#define CHARACTERMINIMALPLUSLOOKANDGRADEINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/character/CharacterMinimalPlusLookInformations.h"
#include "src/Protocol/Types/Data/game/look/EntityLook.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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
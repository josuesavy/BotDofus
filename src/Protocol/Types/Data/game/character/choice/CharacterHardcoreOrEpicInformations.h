#ifndef CHARACTERHARDCOREOREPICINFORMATIONS_H
#define CHARACTERHARDCOREOREPICINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/character/choice/CharacterBaseInformations.h"
#include "src/Protocol/Types/Data/game/look/EntityLook.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class CharacterHardcoreOrEpicInformations : public CharacterBaseInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterHardcoreOrEpicInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterHardcoreOrEpicInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterHardcoreOrEpicInformations(FuncTree tree);
  CharacterHardcoreOrEpicInformations();
  bool operator==(const CharacterHardcoreOrEpicInformations &compared);

  uint deathState;
  uint deathCount;
  uint deathMaxLevel;

private:
  void _deathStateFunc(Reader *input);
  void _deathCountFunc(Reader *input);
  void _deathMaxLevelFunc(Reader *input);
};

#endif // CHARACTERHARDCOREOREPICINFORMATIONS_H
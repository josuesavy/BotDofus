#ifndef CHARACTERSPELLMODIFICATION_H
#define CHARACTERSPELLMODIFICATION_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/character/characteristic/CharacterBaseCharacteristic.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class CharacterSpellModification : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterSpellModification(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterSpellModification(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterSpellModification(FuncTree tree);
  CharacterSpellModification();
  bool operator==(const CharacterSpellModification &compared);

  uint modificationType;
  uint spellId;
  CharacterBaseCharacteristic value;

private:
  void _modificationTypeFunc(Reader *input);
  void _spellIdFunc(Reader *input);
  void _valuetreeFunc(Reader *input);

  FuncTree _valuetree;
};

#endif // CHARACTERSPELLMODIFICATION_H
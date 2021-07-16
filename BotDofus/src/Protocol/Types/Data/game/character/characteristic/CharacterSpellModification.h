#ifndef CHARACTERSPELLMODIFICATION_H
#define CHARACTERSPELLMODIFICATION_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/character/characteristic/CharacterCharacteristicDetailed.h"
#include "src/engines/io/network/utils/FuncTree.h"

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
  QSharedPointer<CharacterCharacteristicDetailed> value;

private:
  void _modificationTypeFunc(Reader *input);
  void _spellIdFunc(Reader *input);
  void _valuetreeFunc(Reader *input);

  FuncTree _valuetree;
};

#endif // CHARACTERSPELLMODIFICATION_H
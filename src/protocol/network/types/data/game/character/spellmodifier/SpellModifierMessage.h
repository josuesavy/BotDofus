#ifndef SPELLMODIFIERMESSAGE_H
#define SPELLMODIFIERMESSAGE_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/utils/io/type/FuncTree.h"

class SpellModifierMessage : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SpellModifierMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SpellModifierMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SpellModifierMessage(FuncTree tree);
  SpellModifierMessage();
  bool operator==(const SpellModifierMessage &compared);

  uint spellId;
  uint actionType;
  uint modifierType;
  int context;
  int equipment;

private:
  void _spellIdFunc(Reader *input);
  void _actionTypeFunc(Reader *input);
  void _modifierTypeFunc(Reader *input);
  void _contextFunc(Reader *input);
  void _equipmentFunc(Reader *input);
};

#endif // SPELLMODIFIERMESSAGE_H
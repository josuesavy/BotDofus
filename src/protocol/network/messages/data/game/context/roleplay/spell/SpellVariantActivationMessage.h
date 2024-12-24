#ifndef SPELLVARIANTACTIVATIONMESSAGE_H
#define SPELLVARIANTACTIVATIONMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class SpellVariantActivationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SpellVariantActivationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SpellVariantActivationMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SpellVariantActivationMessage(FuncTree tree);
  SpellVariantActivationMessage();

  uint spellId;
  bool result;

private:
  void _spellIdFunc(Reader *input);
  void _resultFunc(Reader *input);
};

#endif // SPELLVARIANTACTIVATIONMESSAGE_H
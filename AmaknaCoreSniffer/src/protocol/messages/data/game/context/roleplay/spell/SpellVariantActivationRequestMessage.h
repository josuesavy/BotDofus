#ifndef SPELLVARIANTACTIVATIONREQUESTMESSAGE_H
#define SPELLVARIANTACTIVATIONREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class SpellVariantActivationRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SpellVariantActivationRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SpellVariantActivationRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SpellVariantActivationRequestMessage(FuncTree tree);
  SpellVariantActivationRequestMessage();

  uint spellId;

private:
  void _spellIdFunc(Reader *input);
};

#endif // SPELLVARIANTACTIVATIONREQUESTMESSAGE_H
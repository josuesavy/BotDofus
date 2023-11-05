#ifndef REMOVETAXCOLLECTORPRESETSPELLMESSAGE_H
#define REMOVETAXCOLLECTORPRESETSPELLMESSAGE_H

#include "src/protocol/types/data/game/uuid.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class RemoveTaxCollectorPresetSpellMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_RemoveTaxCollectorPresetSpellMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_RemoveTaxCollectorPresetSpellMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_RemoveTaxCollectorPresetSpellMessage(FuncTree tree);
  RemoveTaxCollectorPresetSpellMessage();

  uuid presetId;
  uint slot;

private:
  void _presetIdtreeFunc(Reader *input);
  void _slotFunc(Reader *input);

  FuncTree _presetIdtree;
};

#endif // REMOVETAXCOLLECTORPRESETSPELLMESSAGE_H
#ifndef REMOVETAXCOLLECTORPRESETSPELLMESSAGE_H
#define REMOVETAXCOLLECTORPRESETSPELLMESSAGE_H

#include "src/protocol/network/types/data/game/Uuid.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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

  Uuid presetId;
  uint slot;

private:
  void _presetIdtreeFunc(Reader *input);
  void _slotFunc(Reader *input);

  FuncTree _presetIdtree;
};

#endif // REMOVETAXCOLLECTORPRESETSPELLMESSAGE_H
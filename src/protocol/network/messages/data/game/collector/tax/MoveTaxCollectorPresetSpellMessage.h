#ifndef MOVETAXCOLLECTORPRESETSPELLMESSAGE_H
#define MOVETAXCOLLECTORPRESETSPELLMESSAGE_H

#include "src/protocol/types/data/game/uuid.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class MoveTaxCollectorPresetSpellMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MoveTaxCollectorPresetSpellMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MoveTaxCollectorPresetSpellMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MoveTaxCollectorPresetSpellMessage(FuncTree tree);
  MoveTaxCollectorPresetSpellMessage();

  uuid presetId;
  uint movedFrom;
  uint movedTo;

private:
  void _presetIdtreeFunc(Reader *input);
  void _movedFromFunc(Reader *input);
  void _movedToFunc(Reader *input);

  FuncTree _presetIdtree;
};

#endif // MOVETAXCOLLECTORPRESETSPELLMESSAGE_H
#ifndef MOVETAXCOLLECTORPRESETSPELLMESSAGE_H
#define MOVETAXCOLLECTORPRESETSPELLMESSAGE_H

#include "src/protocol/network/types/data/game/Uuid.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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

  Uuid presetId;
  uint movedFrom;
  uint movedTo;

private:
  void _presetIdtreeFunc(Reader *input);
  void _movedFromFunc(Reader *input);
  void _movedToFunc(Reader *input);

  FuncTree _presetIdtree;
};

#endif // MOVETAXCOLLECTORPRESETSPELLMESSAGE_H
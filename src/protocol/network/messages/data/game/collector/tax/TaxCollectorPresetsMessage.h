#ifndef TAXCOLLECTORPRESETSMESSAGE_H
#define TAXCOLLECTORPRESETSMESSAGE_H

#include "src/protocol/types/data/game/collector/tax/TaxCollectorPreset.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class TaxCollectorPresetsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TaxCollectorPresetsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TaxCollectorPresetsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TaxCollectorPresetsMessage(FuncTree tree);
  TaxCollectorPresetsMessage();

  QList<TaxCollectorPreset> presets;

private:
  void _presetstreeFunc(Reader *input);
  void _presetsFunc(Reader *input);

  FuncTree _presetstree;
};

#endif // TAXCOLLECTORPRESETSMESSAGE_H
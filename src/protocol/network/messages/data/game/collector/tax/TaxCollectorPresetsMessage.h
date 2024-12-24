#ifndef TAXCOLLECTORPRESETSMESSAGE_H
#define TAXCOLLECTORPRESETSMESSAGE_H

#include "src/protocol/network/types/data/game/collector/tax/TaxCollectorPreset.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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

  QList<QSharedPointer<TaxCollectorPreset>> presets;

private:
  void _presetstreeFunc(Reader *input);
  void _presetsFunc(Reader *input);

  FuncTree _presetstree;
};

#endif // TAXCOLLECTORPRESETSMESSAGE_H
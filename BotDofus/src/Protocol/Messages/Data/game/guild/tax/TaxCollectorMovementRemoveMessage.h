#ifndef TAXCOLLECTORMOVEMENTREMOVEMESSAGE_H
#define TAXCOLLECTORMOVEMENTREMOVEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class TaxCollectorMovementRemoveMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TaxCollectorMovementRemoveMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TaxCollectorMovementRemoveMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TaxCollectorMovementRemoveMessage(FuncTree tree);
  TaxCollectorMovementRemoveMessage();

  double collectorId;

private:
  void _collectorIdFunc(Reader *input);
};

#endif // TAXCOLLECTORMOVEMENTREMOVEMESSAGE_H
#ifndef TAXCOLLECTORREMOVEDMESSAGE_H
#define TAXCOLLECTORREMOVEDMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class TaxCollectorRemovedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TaxCollectorRemovedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TaxCollectorRemovedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TaxCollectorRemovedMessage(FuncTree tree);
  TaxCollectorRemovedMessage();

  double collectorId;

private:
  void _collectorIdFunc(Reader *input);
};

#endif // TAXCOLLECTORREMOVEDMESSAGE_H
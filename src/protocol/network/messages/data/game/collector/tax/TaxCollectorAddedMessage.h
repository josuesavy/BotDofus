#ifndef TAXCOLLECTORADDEDMESSAGE_H
#define TAXCOLLECTORADDEDMESSAGE_H

#include "src/protocol/types/ClassManager.h"
#include "src/protocol/types/data/game/collector/tax/TaxCollectorInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class TaxCollectorAddedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TaxCollectorAddedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TaxCollectorAddedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TaxCollectorAddedMessage(FuncTree tree);
  TaxCollectorAddedMessage();

  double callerId;
  QSharedPointer<TaxCollectorInformations> description;

private:
  void _callerIdFunc(Reader *input);
  void _descriptiontreeFunc(Reader *input);

  FuncTree _descriptiontree;
};

#endif // TAXCOLLECTORADDEDMESSAGE_H
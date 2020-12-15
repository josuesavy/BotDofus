#ifndef TAXCOLLECTORMOVEMENTADDMESSAGE_H
#define TAXCOLLECTORMOVEMENTADDMESSAGE_H

#include "src/protocol/types/data/game/guild/tax/TaxCollectorInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/types/ClassManager.h"
#include "src/protocol/messages/AbstractMessage.h"

class TaxCollectorMovementAddMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TaxCollectorMovementAddMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TaxCollectorMovementAddMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TaxCollectorMovementAddMessage(FuncTree tree);
  TaxCollectorMovementAddMessage();

  QSharedPointer<TaxCollectorInformations> informations;

private:
  void _informationstreeFunc(Reader *input);

  FuncTree _informationstree;
};

#endif // TAXCOLLECTORMOVEMENTADDMESSAGE_H
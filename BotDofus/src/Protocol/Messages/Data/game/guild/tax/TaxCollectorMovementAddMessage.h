#ifndef TAXCOLLECTORMOVEMENTADDMESSAGE_H
#define TAXCOLLECTORMOVEMENTADDMESSAGE_H

#include "src/Protocol/Types/Data/game/guild/tax/TaxCollectorInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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
#ifndef TAXCOLLECTORMOVEMENTSOFFLINEMESSAGE_H
#define TAXCOLLECTORMOVEMENTSOFFLINEMESSAGE_H

#include "src/Protocol/Types/Data/game/guild/tax/TaxCollectorMovement.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class TaxCollectorMovementsOfflineMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TaxCollectorMovementsOfflineMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TaxCollectorMovementsOfflineMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TaxCollectorMovementsOfflineMessage(FuncTree tree);
  TaxCollectorMovementsOfflineMessage();

  QList<TaxCollectorMovement> movements;

private:
  void _movementstreeFunc(Reader *input);
  void _movementsFunc(Reader *input);

  FuncTree _movementstree;
};

#endif // TAXCOLLECTORMOVEMENTSOFFLINEMESSAGE_H
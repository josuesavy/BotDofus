#ifndef TAXCOLLECTORMOVEMENTSOFFLINEMESSAGE_H
#define TAXCOLLECTORMOVEMENTSOFFLINEMESSAGE_H

#include "src/protocol/network/types/data/game/collector/tax/TaxCollectorMovement.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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
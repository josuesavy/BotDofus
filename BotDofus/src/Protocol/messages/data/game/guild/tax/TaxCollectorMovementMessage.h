#ifndef TAXCOLLECTORMOVEMENTMESSAGE_H
#define TAXCOLLECTORMOVEMENTMESSAGE_H

#include "src/protocol/types/data/game/guild/tax/TaxCollectorBasicInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class TaxCollectorMovementMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TaxCollectorMovementMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TaxCollectorMovementMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TaxCollectorMovementMessage(FuncTree tree);
  TaxCollectorMovementMessage();

  uint movementType;
  TaxCollectorBasicInformations basicInfos;
  double playerId;
  QString playerName;

private:
  void _movementTypeFunc(Reader *input);
  void _basicInfostreeFunc(Reader *input);
  void _playerIdFunc(Reader *input);
  void _playerNameFunc(Reader *input);

  FuncTree _basicInfostree;
};

#endif // TAXCOLLECTORMOVEMENTMESSAGE_H
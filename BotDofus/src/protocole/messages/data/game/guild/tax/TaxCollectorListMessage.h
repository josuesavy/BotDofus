#ifndef TAXCOLLECTORLISTMESSAGE_H
#define TAXCOLLECTORLISTMESSAGE_H

#include "src/protocol/types/data/game/guild/tax/TaxCollectorFightersInformation.h"
#include "src/protocol/types/data/game/guild/tax/TaxCollectorInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/guild/tax/AbstractTaxCollectorListMessage.h"

class TaxCollectorListMessage : public AbstractTaxCollectorListMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TaxCollectorListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TaxCollectorListMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TaxCollectorListMessage(FuncTree tree);
  TaxCollectorListMessage();

  uint nbcollectorMax;
  QList<QSharedPointer<TaxCollectorFightersInformation>> fightersInformations;
  uint infoType;

private:
  void _nbcollectorMaxFunc(Reader *input);
  void _fightersInformationstreeFunc(Reader *input);
  void _fightersInformationsFunc(Reader *input);
  void _infoTypeFunc(Reader *input);

  FuncTree _fightersInformationstree;
};

#endif // TAXCOLLECTORLISTMESSAGE_H
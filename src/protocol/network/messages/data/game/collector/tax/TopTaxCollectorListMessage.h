#ifndef TOPTAXCOLLECTORLISTMESSAGE_H
#define TOPTAXCOLLECTORLISTMESSAGE_H

#include "src/protocol/types/ClassManager.h"
#include "src/protocol/types/data/game/collector/tax/TaxCollectorInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class TopTaxCollectorListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TopTaxCollectorListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TopTaxCollectorListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TopTaxCollectorListMessage(FuncTree tree);
  TopTaxCollectorListMessage();

  QList<QSharedPointer<TaxCollectorInformations>> dungeonTaxCollectorsInformation;
  QList<QSharedPointer<TaxCollectorInformations>> worldTaxCollectorsInformation;

private:
  void _dungeonTaxCollectorsInformationtreeFunc(Reader *input);
  void _dungeonTaxCollectorsInformationFunc(Reader *input);
  void _worldTaxCollectorsInformationtreeFunc(Reader *input);
  void _worldTaxCollectorsInformationFunc(Reader *input);

  FuncTree _dungeonTaxCollectorsInformationtree;
  FuncTree _worldTaxCollectorsInformationtree;
};

#endif // TOPTAXCOLLECTORLISTMESSAGE_H
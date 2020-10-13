#ifndef TAXCOLLECTORLISTMESSAGE_H
#define TAXCOLLECTORLISTMESSAGE_H

#include "src/Protocol/Types/Data/game/guild/tax/TaxCollectorFightersInformation.h"
#include "src/Protocol/Types/Data/game/guild/tax/TaxCollectorInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/guild/tax/AbstractTaxCollectorListMessage.h"

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
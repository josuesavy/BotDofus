#ifndef ABSTRACTTAXCOLLECTORLISTMESSAGE_H
#define ABSTRACTTAXCOLLECTORLISTMESSAGE_H

#include "src/Protocol/Types/Data/game/guild/tax/TaxCollectorInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class AbstractTaxCollectorListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AbstractTaxCollectorListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AbstractTaxCollectorListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AbstractTaxCollectorListMessage(FuncTree tree);
  AbstractTaxCollectorListMessage();

  QList<QSharedPointer<TaxCollectorInformations>> informations;

private:
  void _informationstreeFunc(Reader *input);
  void _informationsFunc(Reader *input);

  FuncTree _informationstree;
};

#endif // ABSTRACTTAXCOLLECTORLISTMESSAGE_H
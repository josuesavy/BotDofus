#ifndef TAXCOLLECTORHARVESTEDMESSAGE_H
#define TAXCOLLECTORHARVESTEDMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class TaxCollectorHarvestedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TaxCollectorHarvestedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TaxCollectorHarvestedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TaxCollectorHarvestedMessage(FuncTree tree);
  TaxCollectorHarvestedMessage();

  double taxCollectorId;
  double harvesterId;
  QString harvesterName;

private:
  void _taxCollectorIdFunc(Reader *input);
  void _harvesterIdFunc(Reader *input);
  void _harvesterNameFunc(Reader *input);
};

#endif // TAXCOLLECTORHARVESTEDMESSAGE_H
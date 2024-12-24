#ifndef STOPLISTENTAXCOLLECTORUPDATESMESSAGE_H
#define STOPLISTENTAXCOLLECTORUPDATESMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class StopListenTaxCollectorUpdatesMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_StopListenTaxCollectorUpdatesMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_StopListenTaxCollectorUpdatesMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_StopListenTaxCollectorUpdatesMessage(FuncTree tree);
  StopListenTaxCollectorUpdatesMessage();

  double taxCollectorId;

private:
  void _taxCollectorIdFunc(Reader *input);
};

#endif // STOPLISTENTAXCOLLECTORUPDATESMESSAGE_H
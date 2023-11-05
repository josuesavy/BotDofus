#ifndef STARTLISTENTAXCOLLECTORUPDATESMESSAGE_H
#define STARTLISTENTAXCOLLECTORUPDATESMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class StartListenTaxCollectorUpdatesMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_StartListenTaxCollectorUpdatesMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_StartListenTaxCollectorUpdatesMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_StartListenTaxCollectorUpdatesMessage(FuncTree tree);
  StartListenTaxCollectorUpdatesMessage();

  double taxCollectorId;

private:
  void _taxCollectorIdFunc(Reader *input);
};

#endif // STARTLISTENTAXCOLLECTORUPDATESMESSAGE_H
#ifndef STOPLISTENTAXCOLLECTORPRESETSUPDATESMESSAGE_H
#define STOPLISTENTAXCOLLECTORPRESETSUPDATESMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class StopListenTaxCollectorPresetsUpdatesMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_StopListenTaxCollectorPresetsUpdatesMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_StopListenTaxCollectorPresetsUpdatesMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_StopListenTaxCollectorPresetsUpdatesMessage(FuncTree tree);
  StopListenTaxCollectorPresetsUpdatesMessage();
};

#endif // STOPLISTENTAXCOLLECTORPRESETSUPDATESMESSAGE_H
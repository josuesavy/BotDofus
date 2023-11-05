#ifndef STARTLISTENTAXCOLLECTORPRESETSUPDATESMESSAGE_H
#define STARTLISTENTAXCOLLECTORPRESETSUPDATESMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class StartListenTaxCollectorPresetsUpdatesMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_StartListenTaxCollectorPresetsUpdatesMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_StartListenTaxCollectorPresetsUpdatesMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_StartListenTaxCollectorPresetsUpdatesMessage(FuncTree tree);
  StartListenTaxCollectorPresetsUpdatesMessage();
};

#endif // STARTLISTENTAXCOLLECTORPRESETSUPDATESMESSAGE_H
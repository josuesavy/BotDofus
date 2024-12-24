#ifndef TAXCOLLECTORSTATEUPDATEMESSAGE_H
#define TAXCOLLECTORSTATEUPDATEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class TaxCollectorStateUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TaxCollectorStateUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TaxCollectorStateUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TaxCollectorStateUpdateMessage(FuncTree tree);
  TaxCollectorStateUpdateMessage();

  double uniqueId;
  uint state;

private:
  void _uniqueIdFunc(Reader *input);
  void _stateFunc(Reader *input);
};

#endif // TAXCOLLECTORSTATEUPDATEMESSAGE_H
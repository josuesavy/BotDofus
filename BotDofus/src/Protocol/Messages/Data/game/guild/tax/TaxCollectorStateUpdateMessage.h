#ifndef TAXCOLLECTORSTATEUPDATEMESSAGE_H
#define TAXCOLLECTORSTATEUPDATEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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
  int state;

private:
  void _uniqueIdFunc(Reader *input);
  void _stateFunc(Reader *input);
};

#endif // TAXCOLLECTORSTATEUPDATEMESSAGE_H
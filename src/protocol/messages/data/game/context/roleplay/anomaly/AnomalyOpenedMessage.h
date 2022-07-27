#ifndef ANOMALYOPENEDMESSAGE_H
#define ANOMALYOPENEDMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AnomalyOpenedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AnomalyOpenedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AnomalyOpenedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AnomalyOpenedMessage(FuncTree tree);
  AnomalyOpenedMessage();

  uint subAreaId;

private:
  void _subAreaIdFunc(Reader *input);
};

#endif // ANOMALYOPENEDMESSAGE_H
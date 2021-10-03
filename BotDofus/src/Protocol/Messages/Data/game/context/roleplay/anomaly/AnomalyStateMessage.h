#ifndef ANOMALYSTATEMESSAGE_H
#define ANOMALYSTATEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AnomalyStateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AnomalyStateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AnomalyStateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AnomalyStateMessage(FuncTree tree);
  AnomalyStateMessage();

  uint subAreaId;
  bool open;
  double closingTime;

private:
  void _subAreaIdFunc(Reader *input);
  void _openFunc(Reader *input);
  void _closingTimeFunc(Reader *input);
};

#endif // ANOMALYSTATEMESSAGE_H
#ifndef STATSUPGRADEREQUESTMESSAGE_H
#define STATSUPGRADEREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class StatsUpgradeRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_StatsUpgradeRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_StatsUpgradeRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_StatsUpgradeRequestMessage(FuncTree tree);
  StatsUpgradeRequestMessage();

  bool useAdditionnal;
  uint statId;
  uint boostPoint;

private:
  void _useAdditionnalFunc(Reader *input);
  void _statIdFunc(Reader *input);
  void _boostPointFunc(Reader *input);
};

#endif // STATSUPGRADEREQUESTMESSAGE_H
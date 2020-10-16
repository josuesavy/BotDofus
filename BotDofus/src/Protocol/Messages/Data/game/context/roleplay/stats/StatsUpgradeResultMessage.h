#ifndef STATSUPGRADERESULTMESSAGE_H
#define STATSUPGRADERESULTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class StatsUpgradeResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_StatsUpgradeResultMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_StatsUpgradeResultMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_StatsUpgradeResultMessage(FuncTree tree);
  StatsUpgradeResultMessage();

  int result;
  uint nbCharacBoost;

private:
  void _resultFunc(Reader *input);
  void _nbCharacBoostFunc(Reader *input);
};

#endif // STATSUPGRADERESULTMESSAGE_H
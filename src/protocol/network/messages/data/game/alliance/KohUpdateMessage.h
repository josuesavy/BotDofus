#ifndef KOHUPDATEMESSAGE_H
#define KOHUPDATEMESSAGE_H

#include "src/protocol/types/data/game/alliance/KohAllianceInfo.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class KohUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_KohUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_KohUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_KohUpdateMessage(FuncTree tree);
  KohUpdateMessage();

  QList<QSharedPointer<KohAllianceInfo>> kohAllianceInfo;
  uint startingAvaTimestamp;
  double nextTickTime;

private:
  void _kohAllianceInfotreeFunc(Reader *input);
  void _kohAllianceInfoFunc(Reader *input);
  void _startingAvaTimestampFunc(Reader *input);
  void _nextTickTimeFunc(Reader *input);

  FuncTree _kohAllianceInfotree;
};

#endif // KOHUPDATEMESSAGE_H
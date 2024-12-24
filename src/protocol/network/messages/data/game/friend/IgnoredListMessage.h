#ifndef IGNOREDLISTMESSAGE_H
#define IGNOREDLISTMESSAGE_H

#include "src/protocol/network/types/ClassManager.h"
#include "src/protocol/network/types/data/game/friend/IgnoredInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class IgnoredListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_IgnoredListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_IgnoredListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_IgnoredListMessage(FuncTree tree);
  IgnoredListMessage();

  QList<QSharedPointer<IgnoredInformations>> ignoredList;

private:
  void _ignoredListtreeFunc(Reader *input);
  void _ignoredListFunc(Reader *input);

  FuncTree _ignoredListtree;
};

#endif // IGNOREDLISTMESSAGE_H
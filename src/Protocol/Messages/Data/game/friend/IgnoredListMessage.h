#ifndef IGNOREDLISTMESSAGE_H
#define IGNOREDLISTMESSAGE_H

#include "src/Protocol/Types/Data/game/friend/IgnoredInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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
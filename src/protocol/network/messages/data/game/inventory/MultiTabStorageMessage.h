#ifndef MULTITABSTORAGEMESSAGE_H
#define MULTITABSTORAGEMESSAGE_H

#include "src/protocol/network/types/data/game/inventory/StorageTabInformation.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class MultiTabStorageMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MultiTabStorageMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MultiTabStorageMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MultiTabStorageMessage(FuncTree tree);
  MultiTabStorageMessage();

  QList<StorageTabInformation> tabs;

private:
  void _tabstreeFunc(Reader *input);
  void _tabsFunc(Reader *input);

  FuncTree _tabstree;
};

#endif // MULTITABSTORAGEMESSAGE_H
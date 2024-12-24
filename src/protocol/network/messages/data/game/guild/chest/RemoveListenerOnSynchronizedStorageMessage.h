#ifndef REMOVELISTENERONSYNCHRONIZEDSTORAGEMESSAGE_H
#define REMOVELISTENERONSYNCHRONIZEDSTORAGEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class RemoveListenerOnSynchronizedStorageMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_RemoveListenerOnSynchronizedStorageMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_RemoveListenerOnSynchronizedStorageMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_RemoveListenerOnSynchronizedStorageMessage(FuncTree tree);
  RemoveListenerOnSynchronizedStorageMessage();

  QString player;

private:
  void _playerFunc(Reader *input);
};

#endif // REMOVELISTENERONSYNCHRONIZEDSTORAGEMESSAGE_H
#ifndef ADDLISTENERONSYNCHRONIZEDSTORAGEMESSAGE_H
#define ADDLISTENERONSYNCHRONIZEDSTORAGEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class AddListenerOnSynchronizedStorageMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AddListenerOnSynchronizedStorageMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AddListenerOnSynchronizedStorageMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AddListenerOnSynchronizedStorageMessage(FuncTree tree);
  AddListenerOnSynchronizedStorageMessage();

  QString player;

private:
  void _playerFunc(Reader *input);
};

#endif // ADDLISTENERONSYNCHRONIZEDSTORAGEMESSAGE_H
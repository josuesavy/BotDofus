#ifndef LISTENERSOFSYNCHRONIZEDSTORAGEMESSAGE_H
#define LISTENERSOFSYNCHRONIZEDSTORAGEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ListenersOfSynchronizedStorageMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ListenersOfSynchronizedStorageMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ListenersOfSynchronizedStorageMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ListenersOfSynchronizedStorageMessage(FuncTree tree);
  ListenersOfSynchronizedStorageMessage();

  QList<QString> players;

private:
  void _playerstreeFunc(Reader *input);
  void _playersFunc(Reader *input);

  FuncTree _playerstree;
};

#endif // LISTENERSOFSYNCHRONIZEDSTORAGEMESSAGE_H
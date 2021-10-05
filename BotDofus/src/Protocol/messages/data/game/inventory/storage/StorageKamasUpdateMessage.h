#ifndef STORAGEKAMASUPDATEMESSAGE_H
#define STORAGEKAMASUPDATEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class StorageKamasUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_StorageKamasUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_StorageKamasUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_StorageKamasUpdateMessage(FuncTree tree);
  StorageKamasUpdateMessage();

  double kamasTotal;

private:
  void _kamasTotalFunc(Reader *input);
};

#endif // STORAGEKAMASUPDATEMESSAGE_H
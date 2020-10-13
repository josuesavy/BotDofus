#ifndef STORAGEKAMASUPDATEMESSAGE_H
#define STORAGEKAMASUPDATEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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
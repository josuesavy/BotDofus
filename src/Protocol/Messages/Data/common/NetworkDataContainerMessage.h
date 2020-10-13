#ifndef NETWORKDATACONTAINERMESSAGE_H
#define NETWORKDATACONTAINERMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class NetworkDataContainerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_NetworkDataContainerMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAs_NetworkDataContainerMessage(Reader *input);
  void deserializeAsyncAs_RawDataMessage(FuncTree tree);
  NetworkDataContainerMessage();

  QByteArray content;

private:
  QByteArray _content;
};

#endif // NETWORKDATACONTAINERMESSAGE_H
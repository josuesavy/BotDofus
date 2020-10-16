#ifndef HAAPIBUFFERLISTMESSAGE_H
#define HAAPIBUFFERLISTMESSAGE_H

#include "src/Protocol/Types/Data/web/haapi/BufferInformation.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class HaapiBufferListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HaapiBufferListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HaapiBufferListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HaapiBufferListMessage(FuncTree tree);
  HaapiBufferListMessage();

  QList<BufferInformation> buffers;

private:
  void _bufferstreeFunc(Reader *input);
  void _buffersFunc(Reader *input);

  FuncTree _bufferstree;
};

#endif // HAAPIBUFFERLISTMESSAGE_H
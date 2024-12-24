#ifndef HAAPIBUFFERLISTMESSAGE_H
#define HAAPIBUFFERLISTMESSAGE_H

#include "src/protocol/network/types/data/web/haapi/BufferInformation.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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
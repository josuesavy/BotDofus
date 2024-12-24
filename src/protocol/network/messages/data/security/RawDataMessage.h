#ifndef RAWDATAMESSAGE_H
#define RAWDATAMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class RawDataMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_RawDataMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAs_RawDataMessage(Reader *input);
  void deserializeAsyncAs_RawDataMessage(FuncTree tree);
  RawDataMessage();

  QByteArray content;
};

#endif // RAWDATAMESSAGE_H
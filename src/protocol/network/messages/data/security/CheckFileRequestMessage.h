#ifndef CHECKFILEREQUESTMESSAGE_H
#define CHECKFILEREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class CheckFileRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CheckFileRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CheckFileRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CheckFileRequestMessage(FuncTree tree);
  CheckFileRequestMessage();

  QString filename;
  uint type;

private:
  void _filenameFunc(Reader *input);
  void _typeFunc(Reader *input);
};

#endif // CHECKFILEREQUESTMESSAGE_H
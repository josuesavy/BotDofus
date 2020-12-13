#ifndef ACCESSORYPREVIEWREQUESTMESSAGE_H
#define ACCESSORYPREVIEWREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AccessoryPreviewRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AccessoryPreviewRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AccessoryPreviewRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AccessoryPreviewRequestMessage(FuncTree tree);
  AccessoryPreviewRequestMessage();

  QList<uint> genericId;

private:
  void _genericIdtreeFunc(Reader *input);
  void _genericIdFunc(Reader *input);

  FuncTree _genericIdtree;
};

#endif // ACCESSORYPREVIEWREQUESTMESSAGE_H
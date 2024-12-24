#ifndef MIMICRYOBJECTERASEREQUESTMESSAGE_H
#define MIMICRYOBJECTERASEREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class MimicryObjectEraseRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MimicryObjectEraseRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MimicryObjectEraseRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MimicryObjectEraseRequestMessage(FuncTree tree);
  MimicryObjectEraseRequestMessage();

  uint hostUID;
  uint hostPos;

private:
  void _hostUIDFunc(Reader *input);
  void _hostPosFunc(Reader *input);
};

#endif // MIMICRYOBJECTERASEREQUESTMESSAGE_H
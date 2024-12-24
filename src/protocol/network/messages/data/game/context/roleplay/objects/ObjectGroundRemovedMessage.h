#ifndef OBJECTGROUNDREMOVEDMESSAGE_H
#define OBJECTGROUNDREMOVEDMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ObjectGroundRemovedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectGroundRemovedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectGroundRemovedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectGroundRemovedMessage(FuncTree tree);
  ObjectGroundRemovedMessage();

  uint cell;

private:
  void _cellFunc(Reader *input);
};

#endif // OBJECTGROUNDREMOVEDMESSAGE_H
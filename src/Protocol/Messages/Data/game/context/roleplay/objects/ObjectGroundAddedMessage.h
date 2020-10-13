#ifndef OBJECTGROUNDADDEDMESSAGE_H
#define OBJECTGROUNDADDEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ObjectGroundAddedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectGroundAddedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectGroundAddedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectGroundAddedMessage(FuncTree tree);
  ObjectGroundAddedMessage();

  uint cellId;
  uint objectGID;

private:
  void _cellIdFunc(Reader *input);
  void _objectGIDFunc(Reader *input);
};

#endif // OBJECTGROUNDADDEDMESSAGE_H
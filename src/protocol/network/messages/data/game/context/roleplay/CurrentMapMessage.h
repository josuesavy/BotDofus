#ifndef CURRENTMAPMESSAGE_H
#define CURRENTMAPMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class CurrentMapMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CurrentMapMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CurrentMapMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CurrentMapMessage(FuncTree tree);
  CurrentMapMessage();

  double mapId;

private:
  void _mapIdFunc(Reader *input);
};

#endif // CURRENTMAPMESSAGE_H
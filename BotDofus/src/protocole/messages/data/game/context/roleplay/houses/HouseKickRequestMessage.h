#ifndef HOUSEKICKREQUESTMESSAGE_H
#define HOUSEKICKREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class HouseKickRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HouseKickRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HouseKickRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HouseKickRequestMessage(FuncTree tree);
  HouseKickRequestMessage();

  double id;

private:
  void _idFunc(Reader *input);
};

#endif // HOUSEKICKREQUESTMESSAGE_H
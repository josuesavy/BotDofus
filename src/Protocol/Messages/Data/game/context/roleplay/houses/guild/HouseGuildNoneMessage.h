#ifndef HOUSEGUILDNONEMESSAGE_H
#define HOUSEGUILDNONEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class HouseGuildNoneMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HouseGuildNoneMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HouseGuildNoneMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HouseGuildNoneMessage(FuncTree tree);
  HouseGuildNoneMessage();

  uint houseId;
  uint instanceId;
  bool secondHand;

private:
  void _houseIdFunc(Reader *input);
  void _instanceIdFunc(Reader *input);
  void _secondHandFunc(Reader *input);
};

#endif // HOUSEGUILDNONEMESSAGE_H
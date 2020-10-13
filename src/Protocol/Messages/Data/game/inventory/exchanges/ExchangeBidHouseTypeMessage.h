#ifndef EXCHANGEBIDHOUSETYPEMESSAGE_H
#define EXCHANGEBIDHOUSETYPEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ExchangeBidHouseTypeMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeBidHouseTypeMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeBidHouseTypeMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeBidHouseTypeMessage(FuncTree tree);
  ExchangeBidHouseTypeMessage();

  uint type;
  bool follow;

private:
  void _typeFunc(Reader *input);
  void _followFunc(Reader *input);
};

#endif // EXCHANGEBIDHOUSETYPEMESSAGE_H
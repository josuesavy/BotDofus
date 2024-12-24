#ifndef EXCHANGECRAFTRESULTMAGICWITHOBJECTDESCMESSAGE_H
#define EXCHANGECRAFTRESULTMAGICWITHOBJECTDESCMESSAGE_H

#include "src/protocol/network/types/data/game/data/items/ObjectItemNotInContainer.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/inventory/exchanges/ExchangeCraftResultWithObjectDescMessage.h"

class ExchangeCraftResultMagicWithObjectDescMessage : public ExchangeCraftResultWithObjectDescMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeCraftResultMagicWithObjectDescMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeCraftResultMagicWithObjectDescMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeCraftResultMagicWithObjectDescMessage(FuncTree tree);
  ExchangeCraftResultMagicWithObjectDescMessage();

  int magicPoolStatus;

private:
  void _magicPoolStatusFunc(Reader *input);
};

#endif // EXCHANGECRAFTRESULTMAGICWITHOBJECTDESCMESSAGE_H
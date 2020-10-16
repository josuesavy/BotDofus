#ifndef EXCHANGECRAFTRESULTMAGICWITHOBJECTDESCMESSAGE_H
#define EXCHANGECRAFTRESULTMAGICWITHOBJECTDESCMESSAGE_H

#include "src/Protocol/Types/Data/game/data/items/ObjectItemNotInContainer.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/inventory/exchanges/ExchangeCraftResultWithObjectDescMessage.h"

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
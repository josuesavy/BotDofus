#ifndef EXCHANGECRAFTRESULTWITHOBJECTDESCMESSAGE_H
#define EXCHANGECRAFTRESULTWITHOBJECTDESCMESSAGE_H

#include "src/protocol/network/types/data/game/data/items/ObjectItemNotInContainer.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/inventory/exchanges/ExchangeCraftResultMessage.h"

class ExchangeCraftResultWithObjectDescMessage : public ExchangeCraftResultMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeCraftResultWithObjectDescMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeCraftResultWithObjectDescMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeCraftResultWithObjectDescMessage(FuncTree tree);
  ExchangeCraftResultWithObjectDescMessage();

  QSharedPointer<ObjectItemNotInContainer> objectInfo;

private:
  void _objectInfotreeFunc(Reader *input);

  FuncTree _objectInfotree;
};

#endif // EXCHANGECRAFTRESULTWITHOBJECTDESCMESSAGE_H
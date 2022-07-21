#ifndef ALTERATIONADDEDMESSAGE_H
#define ALTERATIONADDEDMESSAGE_H

#include "src/protocol/types/data/game/character/alteration/AlterationInfo.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AlterationAddedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AlterationAddedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AlterationAddedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AlterationAddedMessage(FuncTree tree);
  AlterationAddedMessage();

  QSharedPointer<AlterationInfo> alteration;

private:
  void _alterationtreeFunc(Reader *input);

  FuncTree _alterationtree;
};

#endif // ALTERATIONADDEDMESSAGE_H
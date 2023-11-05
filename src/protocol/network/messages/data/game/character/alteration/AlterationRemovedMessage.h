#ifndef ALTERATIONREMOVEDMESSAGE_H
#define ALTERATIONREMOVEDMESSAGE_H

#include "src/protocol/types/data/game/character/alteration/AlterationInfo.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AlterationRemovedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AlterationRemovedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AlterationRemovedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AlterationRemovedMessage(FuncTree tree);
  AlterationRemovedMessage();

  QSharedPointer<AlterationInfo> alteration;

private:
  void _alterationtreeFunc(Reader *input);

  FuncTree _alterationtree;
};

#endif // ALTERATIONREMOVEDMESSAGE_H
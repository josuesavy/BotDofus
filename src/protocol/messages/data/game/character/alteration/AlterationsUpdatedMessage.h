#ifndef ALTERATIONSUPDATEDMESSAGE_H
#define ALTERATIONSUPDATEDMESSAGE_H

#include "src/protocol/types/data/game/character/alteration/AlterationInfo.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AlterationsUpdatedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AlterationsUpdatedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AlterationsUpdatedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AlterationsUpdatedMessage(FuncTree tree);
  AlterationsUpdatedMessage();

  QList<QSharedPointer<AlterationInfo>> alterations;

private:
  void _alterationstreeFunc(Reader *input);
  void _alterationsFunc(Reader *input);

  FuncTree _alterationstree;
};

#endif // ALTERATIONSUPDATEDMESSAGE_H
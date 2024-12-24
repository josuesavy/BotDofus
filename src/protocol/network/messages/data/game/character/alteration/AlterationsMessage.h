#ifndef ALTERATIONSMESSAGE_H
#define ALTERATIONSMESSAGE_H

#include "src/protocol/network/types/data/game/character/alteration/AlterationInfo.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class AlterationsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AlterationsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AlterationsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AlterationsMessage(FuncTree tree);
  AlterationsMessage();

  QList<QSharedPointer<AlterationInfo>> alterations;

private:
  void _alterationstreeFunc(Reader *input);
  void _alterationsFunc(Reader *input);

  FuncTree _alterationstree;
};

#endif // ALTERATIONSMESSAGE_H
#ifndef SPOUSEINFORMATIONSMESSAGE_H
#define SPOUSEINFORMATIONSMESSAGE_H

#include "src/protocol/network/types/ClassManager.h"
#include "src/protocol/network/types/data/game/friend/FriendSpouseInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class SpouseInformationsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SpouseInformationsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SpouseInformationsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SpouseInformationsMessage(FuncTree tree);
  SpouseInformationsMessage();

  QSharedPointer<FriendSpouseInformations> spouse;

private:
  void _spousetreeFunc(Reader *input);

  FuncTree _spousetree;
};

#endif // SPOUSEINFORMATIONSMESSAGE_H
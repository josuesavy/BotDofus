#ifndef SPOUSEINFORMATIONSMESSAGE_H
#define SPOUSEINFORMATIONSMESSAGE_H

#include "src/Protocol/Types/Data/game/friend/FriendSpouseInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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
#ifndef ACQUAINTANCESLISTMESSAGE_H
#define ACQUAINTANCESLISTMESSAGE_H

#include "src/Protocol/Types/Data/game/friend/AcquaintanceInformation.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class AcquaintancesListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AcquaintancesListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AcquaintancesListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AcquaintancesListMessage(FuncTree tree);
  AcquaintancesListMessage();

  QList<QSharedPointer<AcquaintanceInformation>> acquaintanceList;

private:
  void _acquaintanceListtreeFunc(Reader *input);
  void _acquaintanceListFunc(Reader *input);

  FuncTree _acquaintanceListtree;
};

#endif // ACQUAINTANCESLISTMESSAGE_H
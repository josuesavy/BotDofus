#ifndef BASICWHOISREQUESTMESSAGE_H
#define BASICWHOISREQUESTMESSAGE_H

#include "src/protocol/types/data/common/AbstractPlayerSearchInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/types/ClassManager.h"
#include "src/protocol/messages/AbstractMessage.h"

class BasicWhoIsRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BasicWhoIsRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BasicWhoIsRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BasicWhoIsRequestMessage(FuncTree tree);
  BasicWhoIsRequestMessage();

  bool verbose;
  QSharedPointer<AbstractPlayerSearchInformation> target;

private:
  void _verboseFunc(Reader *input);
  void _targettreeFunc(Reader *input);

  FuncTree _targettree;
};

#endif // BASICWHOISREQUESTMESSAGE_H
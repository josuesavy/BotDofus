#ifndef BASICWHOISREQUESTMESSAGE_H
#define BASICWHOISREQUESTMESSAGE_H

#include "src/protocol/network/types/ClassManager.h"
#include "src/protocol/network/types/data/common/AbstractPlayerSearchInformation.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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
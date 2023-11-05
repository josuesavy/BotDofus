#ifndef BASICWHOISNOMATCHMESSAGE_H
#define BASICWHOISNOMATCHMESSAGE_H

#include "src/protocol/types/ClassManager.h"
#include "src/protocol/types/data/common/AbstractPlayerSearchInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class BasicWhoIsNoMatchMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BasicWhoIsNoMatchMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BasicWhoIsNoMatchMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BasicWhoIsNoMatchMessage(FuncTree tree);
  BasicWhoIsNoMatchMessage();

  QSharedPointer<AbstractPlayerSearchInformation> target;

private:
  void _targettreeFunc(Reader *input);

  FuncTree _targettree;
};

#endif // BASICWHOISNOMATCHMESSAGE_H
#ifndef BASICSTATWITHDATAMESSAGE_H
#define BASICSTATWITHDATAMESSAGE_H

#include "src/protocol/network/types/ClassManager.h"
#include "src/protocol/network/types/data/common/basic/StatisticData.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/common/basic/BasicStatMessage.h"

class BasicStatWithDataMessage : public BasicStatMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BasicStatWithDataMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BasicStatWithDataMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BasicStatWithDataMessage(FuncTree tree);
  BasicStatWithDataMessage();

  QList<QSharedPointer<StatisticData>> datas;

private:
  void _datastreeFunc(Reader *input);
  void _datasFunc(Reader *input);

  FuncTree _datastree;
};

#endif // BASICSTATWITHDATAMESSAGE_H